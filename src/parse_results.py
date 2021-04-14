import itertools
import json
import compiler
from pprint import pprint


# like set difference `-` but using eq not hash so it can be used on mutable types
# a = [1,2,2,3]
# b = [2,3,4]
# print(difference(a, b)) # [1, 2]
# print(difference(b, a)) # [4]
def difference(list_a, list_b):
    list_b_copy = list(list_b)
    diff = []
    for a in list_a:
        if a in list_b_copy:
            list_b_copy.remove(a)
        else:
            diff.append(a)
    return diff

# requires the entire processed dataset to be in memory
def group_by_project(all_processed_rows):
    # local mutation only
    grouped = {}

    # files with the same project_id are assumed to be in the same project 
    # for this dataset since only one run was collected per account
    key_func = lambda x: x['project_id']
    
    for key, group in itertools.groupby(all_processed_rows, key_func):
        grouped[key] = list(group)
    
    return grouped

# [dict] -> dict
def get_project_results(grouped_results):
    # local mutation for all projects
    project_stats = {}

    for project_id, model_results in grouped_results.items():
        # scoped local mutation for a single project
        stats = {
            'project_models': 0,
            'models_parsed': 0,
            'models_unparsed': 0,
            'models_skipped': 0,
            'parsing_false_positives': 0,
            'parsing_misses': 0,
            'percent_parsable': 0,
        }

        for res in model_results:
            if('skipped' not in res.keys()):
                stats['project_models'] += 1
                if res['parsed']: 
                    stats['models_parsed'] += 1
                else:
                    stats['models_unparsed'] += 1

                stats['parsing_false_positives'] += res['parsing_false_positives']
                stats['parsing_misses'] += res['parsing_misses']
            else:
                stats['models_skipped'] += 1

        if stats['project_models'] <= 0:
            stats['percent_parsable'] = 100.0
        else:
            stats['percent_parsable'] = 100 * (stats['models_parsed'] / stats['project_models'])
        project_stats[project_id] = stats

    return project_stats

# parser -> row_fields -> dict
def process_row(parser, project_id, raw_sql, configs, refs, sources):
    res = compiler.parse_typecheck_extract(parser, raw_sql)
    skipped = { 
        'project_id': project_id,
        'skipped': True
    }
    # if the model file doesn't have a call to config() it defaults to the project.yaml
    # this shouldn't be counted for comparisons, but won't be a problem in the product.
    if not res['configs']:
        return skipped

    # the set of real parsed values minus the set we found is the set of unparsed values
    # TODO unparsed_configs = difference(configs, res['configs'])
    unparsed_refs    = difference(refs, res['refs'])
    unparsed_sources = difference(sources, res['sources'])
    unparsed_total = len(unparsed_refs) + len(unparsed_sources)
    # TODO unparsed_total = len(unparsed_configs) + len(unparsed_refs) + len(unparsed_sources)
    all_configs_refs_sources_count = len(configs) + len(refs) + len(sources)
    
    # tag equality is special because they are additive in a file
    # e.g. {{ config(tag='x') }} could result in ('tags', ['a', 'b', 'x']) where a and b came from a project yaml.
    parsed_tags = []
    for kwarg in res['configs']:
        if kwarg[0] == 'tags':
            parsed_tags = kwarg[1]

    real_tags = []
    for kwarg in configs:
        if kwarg[0] == 'tags':
            real_tags = kwarg[1]

    filtered_real_tags = list(filter(lambda tag: tag in parsed_tags, real_tags))
    tag_adjusted_configs = [('tags', filtered_real_tags)] + list(filter(lambda kwarg: kwarg[0] != 'tags', configs))

    # the set of tree-sitter parsed values minus the set of real parsed values should be empty if we made no mistakes
    misparsed_configs = difference(res['configs'], tag_adjusted_configs)
    misparsed_refs    = difference(res['refs'], refs)
    misparsed_sources = difference(res['sources'], sources)
    misparsed_total = len(misparsed_configs) + len(misparsed_refs) + len(misparsed_sources)

    # TODO remove debug lines
    # if misparsed_total > 0:
    #     print()
    #     if(len(misparsed_refs) > 0):
    #         print("::: EXPECTED REFS :::")
    #         pprint(refs)
    #         print("::: GOT REFS :::")
    #         pprint(res['refs'])
    #     if(len(misparsed_sources) > 0):
    #         print("::: EXPECTED SOURCES:::")
    #         pprint(sources)
    #         print("::: GOT SOURCES :::")
    #         pprint(res['sources'])
    #     if(len(misparsed_configs) > 0):
    #         print("::: EXPECTED CONFIGS :::")
    #         pprint(configs)
    #         print("::: GOT CONFIGS :::")
    #         pprint(res['configs'])
    #     print(":: RAW ::")
    #     pprint(raw_sql)
    #     print()

    # if there are no instances where we need python_jinja, and we didn't 
    # make any mistakes and we didn't miss any we successfully parsed the model.
    parsed = res['python_jinja'] <= 0 and misparsed_total <= 0 and unparsed_total <= 0
    return {
        'project_id': project_id,
        'parsed': parsed,
        'python_jinja': res['python_jinja'],
        'all_configs_refs_sources_count': all_configs_refs_sources_count,
        'parsing_false_positives': misparsed_total,
        'parsing_misses': unparsed_total
    }

# change data_path to your own path TODO use args
def run_on(data_path):
    def apply_row(parser, row):
        # defaults for runs that don't include these fields
        row_config  = {}
        row_refs    = []
        row_sources = set()

        try:
            row_config = row['config']
        except:
            pass

        try:
            row_refs = row['refs']
        except:
            pass

        try:
            row_sources = row['sources']
        except:
            pass

        base_config = {
            'alias': None,
            'column_types': {},
            'copy_grants': True,
            'database': None,
            'enabled': True,
            'full_refresh': None,
            'persist_docs': {},
            'post-hook': [],
            'pre-hook': [],
            'quoting': {},
            'schema': None,
            'tags': [],
            'vars': {}
        }

        # remove default values for configs
        row_config = list(filter(lambda kv: kv not in base_config.items(), row_config.items()))

        # reshape sources from lists of length 2 to tuples.
        row_sources = set(map(lambda list: (list[0], list[1]), row_sources))

        return process_row(parser, row['manifest_file_name'], row['raw_sql'], row_config, row_refs, row_sources)

    # read whole file in
    with open(data_path, 'r') as f:
        all_rows = json.loads(f.read())

    parser = compiler.get_parser()
    all_results = list(map(lambda row: apply_row(parser, row), all_rows))
    grouped_results = group_by_project(all_results)
    all_project_results = get_project_results(grouped_results)

    all_project_stats = {
        'model_count': 0,
        'models_parsed': 0,
        'percentage_models_parseable': 0,
        'models_with_misses': 0,
        'models_with_false_positives': 0,
        'percentage_models_false_positives': 0,
        'project_count': 0,
        'projects_parsed': 0,
        'percentage_projects_parseable': 0,
        'projects_completely_unparsed': 0,
        'percentage_projects_completely_unparsed': 0,
        'projects_with_misses': 0,
        'projects_with_false_positives': 0,
        'percentage_projects_false_positives': 0
    }

    for project_id, stats in all_project_results.items():
        all_project_stats['model_count'] += stats['project_models']
        all_project_stats['models_parsed'] += stats['models_parsed']
        if stats['models_parsed'] == 0 and stats['models_skipped'] <= 0:
            all_project_stats['projects_completely_unparsed'] += 1
        all_project_stats['models_with_false_positives'] += stats['parsing_false_positives']
        all_project_stats['models_with_misses'] += 1
        all_project_stats['model_count'] += 1
        if stats['models_parsed'] == stats['project_models']:
            all_project_stats['projects_parsed'] += 1
        if stats['parsing_false_positives'] > 0:
            all_project_stats['projects_with_false_positives'] += 1
        if stats['parsing_misses'] > 0:
            all_project_stats['projects_with_misses'] += 1

    all_project_stats['project_count'] = len(all_project_results.keys())
    if all_project_stats['model_count'] == 0:
        all_project_stats['percentage_models_parseable'] = 100.0
        all_project_stats['percentage_models_false_positives'] = 0.0
    else:
        all_project_stats['percentage_models_parseable'] = 100 * all_project_stats['models_parsed'] / all_project_stats['model_count']
        all_project_stats['percentage_models_false_positives'] = 100 * all_project_stats['models_with_false_positives'] / all_project_stats['model_count']

    if all_project_stats['project_count'] == 0:
        all_project_stats['percentage_projects_parseable'] = 100.0
        all_project_stats['percentage_projects_false_positives'] = 0.0
        all_project_stats['percentage_projects_completely_unparsed'] = 0.0
    else:
        all_project_stats['percentage_projects_parseable'] = 100 * all_project_stats['projects_parsed'] / all_project_stats['project_count']
        all_project_stats['percentage_projects_false_positives'] = 100 * all_project_stats['projects_with_false_positives'] / all_project_stats['project_count']
        all_project_stats['percentage_projects_completely_unparsed'] = 100 * all_project_stats['projects_completely_unparsed'] / all_project_stats['project_count']

    # manually printing so they come out in the right order
    field_order = [
        'model_count',
        'models_parsed',
        'percentage_models_parseable',
        'models_with_misses',
        'models_with_false_positives',
        'percentage_models_false_positives',
        'project_count',
        'projects_parsed',
        'percentage_projects_parseable',
        'projects_completely_unparsed',
        'percentage_projects_completely_unparsed',
        'projects_with_misses',
        'projects_with_false_positives',
        'percentage_projects_false_positives'
    ]

    for field in field_order:
        print(f"{field} : {all_project_stats[field]}")
