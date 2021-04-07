#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 28
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 23
#define ALIAS_COUNT 0
#define TOKEN_COUNT 13
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 3

enum {
  anon_sym_LBRACE_LBRACE = 1,
  anon_sym_RBRACE_RBRACE = 2,
  anon_sym_LPAREN = 3,
  anon_sym_COMMA = 4,
  anon_sym_RPAREN = 5,
  anon_sym_SQUOTE = 6,
  aux_sym_lit_string_token1 = 7,
  anon_sym_DQUOTE = 8,
  aux_sym_lit_string_token2 = 9,
  sym__identifier = 10,
  anon_sym_EQ = 11,
  sym__text = 12,
  sym_source_file = 13,
  sym__jinja_block = 14,
  sym__expr = 15,
  sym_fn_call = 16,
  sym_argument_list = 17,
  sym_lit_string = 18,
  sym_identifier = 19,
  sym_kwarg = 20,
  aux_sym_source_file_repeat1 = 21,
  aux_sym_argument_list_repeat1 = 22,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LBRACE_LBRACE] = "{{",
  [anon_sym_RBRACE_RBRACE] = "}}",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_lit_string_token1] = "lit_string_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_lit_string_token2] = "lit_string_token2",
  [sym__identifier] = "_identifier",
  [anon_sym_EQ] = "=",
  [sym__text] = "_text",
  [sym_source_file] = "source_file",
  [sym__jinja_block] = "_jinja_block",
  [sym__expr] = "_expr",
  [sym_fn_call] = "fn_call",
  [sym_argument_list] = "argument_list",
  [sym_lit_string] = "lit_string",
  [sym_identifier] = "identifier",
  [sym_kwarg] = "kwarg",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LBRACE_LBRACE] = anon_sym_LBRACE_LBRACE,
  [anon_sym_RBRACE_RBRACE] = anon_sym_RBRACE_RBRACE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_lit_string_token1] = aux_sym_lit_string_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_lit_string_token2] = aux_sym_lit_string_token2,
  [sym__identifier] = sym__identifier,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym__text] = sym__text,
  [sym_source_file] = sym_source_file,
  [sym__jinja_block] = sym__jinja_block,
  [sym__expr] = sym__expr,
  [sym_fn_call] = sym_fn_call,
  [sym_argument_list] = sym_argument_list,
  [sym_lit_string] = sym_lit_string,
  [sym_identifier] = sym_identifier,
  [sym_kwarg] = sym_kwarg,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_argument_list_repeat1] = aux_sym_argument_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LBRACE_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_lit_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_lit_string_token2] = {
    .visible = false,
    .named = false,
  },
  [sym__identifier] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym__text] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__jinja_block] = {
    .visible = false,
    .named = true,
  },
  [sym__expr] = {
    .visible = false,
    .named = true,
  },
  [sym_fn_call] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_list] = {
    .visible = true,
    .named = true,
  },
  [sym_lit_string] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_kwarg] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_argument_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_arg = 1,
  field_argument_list = 2,
  field_fn_name = 3,
  field_value = 4,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_arg] = "arg",
  [field_argument_list] = "argument_list",
  [field_fn_name] = "fn_name",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_argument_list, 1},
    {field_fn_name, 0},
  [2] =
    {field_arg, 0},
    {field_value, 2},
};

static TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == '"') ADVANCE(13);
      if (lookahead == '\'') ADVANCE(10);
      if (lookahead == '(') ADVANCE(7);
      if (lookahead == ')') ADVANCE(9);
      if (lookahead == ',') ADVANCE(8);
      if (lookahead == '=') ADVANCE(17);
      if (lookahead == '{') ADVANCE(1);
      if (lookahead == '}') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 1:
      if (lookahead == '{') ADVANCE(5);
      END_STATE();
    case 2:
      if (lookahead == '}') ADVANCE(6);
      END_STATE();
    case 3:
      if (eof) ADVANCE(4);
      if (lookahead == '{') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(19);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_lit_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(12);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_lit_string_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_lit_string_token2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(15);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_lit_string_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym__identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym__text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym__text);
      if (lookahead != 0 &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(19);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 3},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 3},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 11},
  [26] = {.lex_state = 14},
  [27] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__identifier] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(27),
    [sym__jinja_block] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(5),
    [sym__text] = ACTIONS(7),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(9), 1,
      anon_sym_RPAREN,
    ACTIONS(11), 1,
      anon_sym_SQUOTE,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      sym__identifier,
    STATE(17), 1,
      sym_identifier,
    STATE(11), 4,
      sym__expr,
      sym_fn_call,
      sym_lit_string,
      sym_kwarg,
  [22] = 5,
    ACTIONS(11), 1,
      anon_sym_SQUOTE,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(15), 1,
      sym__identifier,
    STATE(17), 1,
      sym_identifier,
    STATE(20), 4,
      sym__expr,
      sym_fn_call,
      sym_lit_string,
      sym_kwarg,
  [41] = 5,
    ACTIONS(11), 1,
      anon_sym_SQUOTE,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    ACTIONS(17), 1,
      sym__identifier,
    STATE(17), 1,
      sym_identifier,
    STATE(22), 3,
      sym__expr,
      sym_fn_call,
      sym_lit_string,
  [59] = 4,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(24), 1,
      sym__text,
    STATE(5), 2,
      sym__jinja_block,
      aux_sym_source_file_repeat1,
  [73] = 4,
    ACTIONS(5), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(29), 1,
      sym__text,
    STATE(5), 2,
      sym__jinja_block,
      aux_sym_source_file_repeat1,
  [87] = 1,
    ACTIONS(31), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [93] = 2,
    ACTIONS(35), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      sym__text,
  [101] = 1,
    ACTIONS(37), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [107] = 1,
    ACTIONS(39), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [113] = 3,
    ACTIONS(41), 1,
      anon_sym_COMMA,
    ACTIONS(43), 1,
      anon_sym_RPAREN,
    STATE(14), 1,
      aux_sym_argument_list_repeat1,
  [123] = 3,
    ACTIONS(11), 1,
      anon_sym_SQUOTE,
    ACTIONS(13), 1,
      anon_sym_DQUOTE,
    STATE(19), 1,
      sym_lit_string,
  [133] = 1,
    ACTIONS(45), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [139] = 3,
    ACTIONS(41), 1,
      anon_sym_COMMA,
    ACTIONS(47), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      aux_sym_argument_list_repeat1,
  [149] = 1,
    ACTIONS(49), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [155] = 3,
    ACTIONS(51), 1,
      anon_sym_COMMA,
    ACTIONS(54), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      aux_sym_argument_list_repeat1,
  [165] = 2,
    ACTIONS(56), 1,
      anon_sym_LPAREN,
    STATE(9), 1,
      sym_argument_list,
  [172] = 2,
    ACTIONS(58), 1,
      anon_sym_LPAREN,
    ACTIONS(60), 1,
      anon_sym_EQ,
  [179] = 1,
    ACTIONS(62), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [184] = 1,
    ACTIONS(54), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [189] = 1,
    ACTIONS(58), 1,
      anon_sym_LPAREN,
  [193] = 1,
    ACTIONS(64), 1,
      anon_sym_RBRACE_RBRACE,
  [197] = 1,
    ACTIONS(66), 1,
      anon_sym_SQUOTE,
  [201] = 1,
    ACTIONS(66), 1,
      anon_sym_DQUOTE,
  [205] = 1,
    ACTIONS(68), 1,
      aux_sym_lit_string_token1,
  [209] = 1,
    ACTIONS(70), 1,
      aux_sym_lit_string_token2,
  [213] = 1,
    ACTIONS(72), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 22,
  [SMALL_STATE(4)] = 41,
  [SMALL_STATE(5)] = 59,
  [SMALL_STATE(6)] = 73,
  [SMALL_STATE(7)] = 87,
  [SMALL_STATE(8)] = 93,
  [SMALL_STATE(9)] = 101,
  [SMALL_STATE(10)] = 107,
  [SMALL_STATE(11)] = 113,
  [SMALL_STATE(12)] = 123,
  [SMALL_STATE(13)] = 133,
  [SMALL_STATE(14)] = 139,
  [SMALL_STATE(15)] = 149,
  [SMALL_STATE(16)] = 155,
  [SMALL_STATE(17)] = 165,
  [SMALL_STATE(18)] = 172,
  [SMALL_STATE(19)] = 179,
  [SMALL_STATE(20)] = 184,
  [SMALL_STATE(21)] = 189,
  [SMALL_STATE(22)] = 193,
  [SMALL_STATE(23)] = 197,
  [SMALL_STATE(24)] = 201,
  [SMALL_STATE(25)] = 205,
  [SMALL_STATE(26)] = 209,
  [SMALL_STATE(27)] = 213,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [24] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lit_string, 3),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__jinja_block, 3),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__jinja_block, 3),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_call, 2, .production_id = 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(3),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kwarg, 3, .production_id = 2),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [72] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_dbt_jinja(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = (const uint16_t *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
