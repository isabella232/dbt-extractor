from functools import reduce
import src.compiler
import src.type_check

parser = src.compiler.get_parser()

def print_errors(errors):
    print(":::::::::: Type Check Errors ::::::::::")
    for error in errors:
        print(f"- {error}")
    print(":::::::::::::::::::::::::::::::::::::::")

# throws away the type check error message if there is one
# prevents poluting stdout when many tests fail
def type_checks(source_text):
    return type_checks_debug(source_text, False)

# use this to print the error messages from the typechecker
def type_checks_debug(source_text, debug=True):
    tree = parser.parse(bytes(source_text, "utf8"))
    # If we couldn't parse the source we can't typecheck it.
    if src.compiler.error_count(tree.root_node, 0) > 0:
        if debug:
            print_errors(["parser failed"])
        return False
    res = src.type_check.type_check(tree.root_node)
    # if it returned a list of errors, it didn't typecheck
    if isinstance(res, list):
        if debug:
            print_errors(res)
        return False
    else:
        return True

# same as `type_checks` but operates on a list of source strings
def type_checks_all(l):
    return reduce(lambda x, y: x and y, map(type_checks, l))

# same as `type_checks_all` but also prints the list of error messages
def type_checks_all_debug(l):
    return reduce(lambda x, y: x and y, map(type_checks_debug, l))
    
def test_recognizes_ref_source_config():
    assert type_checks_all([
        "select * from {{ ref('my_table') }}",
        "{{ config('str') }}"
        "{{ source('a', 'b') }}"
    ])

def test_config_all_inputs():
    assert type_checks_all([
        "{{ config('str') }}",
        "{{ config(key='value') }}",
        "{{ config(['list']) }}"
        "{{ config({'dict2': 'v'}) }}"
    ])
