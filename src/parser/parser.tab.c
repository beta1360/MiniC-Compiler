/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */
   
	#include "parser.h"


#line 71 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tconst = 258,
    telse = 259,
    tif = 260,
    tint = 261,
    treturn = 262,
    tvoid = 263,
    twhile = 264,
    tand = 265,
    tor = 266,
    taddAssign = 267,
    tsubAssign = 268,
    tmulAssign = 269,
    tdivAssign = 270,
    tmodAssign = 271,
    tfor = 272,
    tswitch = 273,
    tcase = 274,
    tdefault = 275,
    tbreak = 276,
    tcontinue = 277,
    TIFX = 278,
    tgreate = 279,
    tlesse = 280,
    tequal = 281,
    tnotequ = 282,
    tinc = 283,
    tdec = 284,
    uminus = 285,
    tident = 286,
    tnumber = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 5 "parser.y" /* yacc.c:355  */

    struct nodeType *node;
    int value;
    char* string;

#line 150 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 167 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    49,     2,     2,
      39,    40,    32,    30,    41,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    44,
      29,    45,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    34,    35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tconst", "telse", "tif", "tint",
  "treturn", "tvoid", "twhile", "tand", "tor", "taddAssign", "tsubAssign",
  "tmulAssign", "tdivAssign", "tmodAssign", "tfor", "tswitch", "tcase",
  "tdefault", "tbreak", "tcontinue", "TIFX", "tgreate", "tlesse", "tequal",
  "tnotequ", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "tinc", "tdec",
  "uminus", "tident", "tnumber", "'('", "')'", "','", "'{'", "'}'", "';'",
  "'='", "'['", "']'", "':'", "'%'", "'!'", "$accept", "mini_c",
  "translation_unit", "external_dcl", "function_def", "function_header",
  "dcl_spec", "dcl_specifiers", "dcl_specifier", "type_qualifier",
  "type_specifier", "function_name", "formal_param", "opt_formal_param",
  "formal_param_list", "param_dcl", "compound_st", "opt_dcl_list",
  "declaration_list", "declaration", "init_dcl_list", "init_declarator",
  "declarator", "opt_number", "opt_stat_list", "statement_list",
  "statement", "expression_st", "opt_expression", "loop_st",
  "condition_st", "flow_st", "if_st", "while_st", "return_st", "for_st",
  "for_dcl", "for_dcl_list", "for_exp", "for_inc", "for_inc_list",
  "continue_st", "break_st", "switch_st", "switch_list", "switch_compound",
  "case_list", "switch_case", "expression", "assignment_exp",
  "logical_or_exp", "logical_and_exp", "equality_exp", "relational_exp",
  "additive_exp", "multiplicative_exp", "unary_exp", "postfix_exp",
  "opt_actual_param", "actual_param", "actual_param_list", "primary_exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    62,    60,
      43,    45,    42,    47,   283,   284,   285,   286,   287,    40,
      41,    44,   123,   125,    59,    61,    91,    93,    58,    37,
      33
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -92

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,   -93,   -93,   -93,    24,    20,   -93,   -93,    -1,    -8,
      20,   -93,   -93,   -93,   -93,   -93,   -93,    20,   -93,    -2,
      37,    14,   -93,     0,   -93,    41,   112,    20,   -93,    42,
      20,   -93,    41,   -93,    44,    54,    64,   157,    67,    76,
      77,    58,    74,   157,   157,   157,   -93,   -93,   157,   157,
     -93,    80,   112,   -93,   -93,    83,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   117,   121,
      13,    28,    19,   -22,     6,     8,   -93,   -93,   -93,    85,
      41,    95,    96,   -93,   -93,   -93,   157,    92,   157,   157,
      41,   -93,   -93,   -93,   -93,   -93,    98,   -93,   -93,   -93,
     -93,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     -93,   -93,   157,   157,   -93,   -93,   -93,    20,    99,   -93,
     100,    97,   104,   -93,   108,   -93,   121,   -93,    13,    28,
      28,    19,    19,    19,    19,   -22,   -22,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   118,   -93,   111,
     113,   -93,   148,   148,   157,   157,   119,   -93,   157,   -93,
     155,   -93,   120,   117,    63,   -93,    66,   -93,   148,   157,
     125,   123,    -7,   -93,    70,   -93,   -93,   127,   131,   -93,
     126,   -93,   -93,   -93,   112,   -93,   148,   157,   -93,   -93,
     -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,    15,    16,     0,     2,     3,     5,     0,     0,
       9,    10,    12,    13,     6,     1,     4,    26,     7,    34,
       0,     0,    30,    32,    11,     0,    39,    25,    27,    37,
      20,     8,     0,    29,     0,    34,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   126,     0,     0,
      42,     0,    38,    40,    43,     0,    45,    44,    46,    52,
      51,    54,    50,    55,    56,    53,    48,    83,    84,    91,
      93,    95,    98,   103,   106,   110,   115,    28,    36,     0,
       0,     0,    19,    21,    31,    33,     0,     0,     0,    63,
       0,    74,    73,   111,   113,   114,     0,   112,    24,    41,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,   119,   121,     0,    35,    23,    18,     0,     0,    60,
       0,     0,    62,    65,     0,   127,    92,   106,    94,    96,
      97,   101,   102,    99,   100,   104,   105,   107,   108,   109,
      86,    87,    88,    89,    90,    85,   123,     0,   120,   122,
       0,    22,    49,    49,    68,     0,     0,   117,     0,   116,
      57,    59,     0,    66,    67,    64,     0,   124,    49,    70,
       0,     0,     0,    77,    49,    80,    58,     0,    69,    71,
       0,    82,    75,    76,    78,    79,    49,     0,    81,    61,
      72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   163,   -93,   -93,   -13,   -93,   165,   -93,
     -93,   -93,   -93,   -93,   -93,    46,   168,   -93,   -93,   -11,
     -93,   145,   -65,   -93,   -93,    -6,   -52,   -93,   143,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,     2,   -93,    -3,   -40,   -84,
      25,   -92,    91,   -10,    -9,    15,   -42,   -93,   -93,   -93,
     -93,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    20,    31,    81,    82,    83,    50,    26,    27,    14,
      21,    22,    23,    79,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   131,   132,   172,   187,
     188,    63,    64,    65,   182,   183,   184,   185,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   157,   158,
     159,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      99,    93,    94,    95,    25,   133,    28,    97,    96,   136,
     111,   112,   180,   181,    25,   125,    77,    80,   114,   115,
     116,   117,   118,     1,    15,   134,     2,   113,     3,    19,
     150,   151,   152,   153,   154,   155,   192,   -17,   156,   103,
     104,    17,   120,   121,    29,    34,   128,   122,   130,   109,
     110,   119,   105,   106,   123,    32,   107,   108,    33,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   147,
     148,   149,   174,   102,   -91,    36,    30,    37,    35,    38,
      78,   175,    85,   160,   177,   180,   181,    39,    40,   180,
     181,    41,    42,   139,   140,   189,   141,   142,   143,   144,
      29,    43,    91,    86,    44,    45,    88,    46,    47,    48,
     170,   171,    17,   200,    80,    89,    90,    36,    92,    37,
      49,    38,   137,    98,   145,   146,   186,   100,   101,    39,
      40,   102,   124,    41,    42,   126,   129,   127,   135,   162,
     163,   164,    99,    43,   199,   165,    44,    45,   166,    46,
      47,    48,   168,    36,    17,    37,   -49,    38,   167,   178,
     169,   176,    49,   190,   179,    39,    40,   196,    16,    41,
      42,   191,   197,   161,   198,    24,    18,    84,   194,    43,
      87,   195,    44,    45,   193,    46,    47,    48,    43,   173,
      17,    44,    45,   138,    46,    47,    48,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,    49
};

static const yytype_int16 yycheck[] =
{
      52,    43,    44,    45,    17,    89,    17,    49,    48,   101,
      32,    33,    19,    20,    27,    80,    27,    30,    12,    13,
      14,    15,    16,     3,     0,    90,     6,    49,     8,    37,
     114,   115,   116,   117,   118,   119,    43,    39,   122,    26,
      27,    42,    34,    35,    46,    45,    86,    39,    88,    30,
      31,    45,    24,    25,    46,    41,    28,    29,    44,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   164,    10,    11,     5,    39,     7,    37,     9,
      38,   165,    38,   123,   168,    19,    20,    17,    18,    19,
      20,    21,    22,   103,   104,   179,   105,   106,   107,   108,
      46,    31,    44,    39,    34,    35,    39,    37,    38,    39,
     162,   163,    42,   197,   127,    39,    39,     5,    44,     7,
      50,     9,   164,    43,   109,   110,   178,    44,    11,    17,
      18,    10,    47,    21,    22,    40,    44,    41,    40,    40,
      40,    44,   194,    31,   196,    41,    34,    35,    40,    37,
      38,    39,    41,     5,    42,     7,    44,     9,    40,     4,
      47,    42,    50,    38,    44,    17,    18,    40,     5,    21,
      22,    48,    41,   127,    48,    10,     8,    32,   184,    31,
      37,   184,    34,    35,   182,    37,    38,    39,    31,   164,
      42,    34,    35,   102,    37,    38,    39,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     8,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    70,     0,    54,    42,    67,    37,
      62,    71,    72,    73,    59,    57,    68,    69,    70,    46,
      39,    63,    41,    44,    45,    37,     5,     7,     9,    17,
      18,    21,    22,    31,    34,    35,    37,    38,    39,    50,
      67,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    92,    93,    94,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   112,    70,    38,    74,
      57,    64,    65,    66,    72,    38,    39,    79,    39,    39,
      39,    44,    44,   107,   107,   107,    99,   107,    43,    77,
      44,    11,    10,    26,    27,    24,    25,    28,    29,    30,
      31,    32,    33,    49,    12,    13,    14,    15,    16,    45,
      34,    35,    39,    46,    47,    73,    40,    41,    99,    44,
      99,    87,    88,   100,    73,    40,   102,   107,   103,   104,
     104,   105,   105,   105,   105,   106,   106,   107,   107,   107,
     100,   100,   100,   100,   100,   100,   100,   109,   110,   111,
      99,    66,    40,    40,    44,    41,    40,    40,    41,    47,
      77,    77,    89,   101,   102,   100,    42,   100,     4,    44,
      19,    20,    95,    96,    97,    98,    77,    90,    91,   100,
      38,    48,    43,    96,    76,    98,    40,    41,    48,    77,
     100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    56,    57,
      58,    58,    59,    59,    60,    61,    61,    62,    63,    64,
      64,    65,    65,    66,    67,    68,    68,    69,    69,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    82,    83,    83,    84,
      85,    86,    87,    87,    88,    88,    89,    89,    89,    90,
      90,    91,    91,    92,    93,    94,    95,    95,    96,    97,
      97,    98,    98,    99,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     107,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     109,   109,   110,   111,   111,   112,   112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     1,     3,     2,     4,     1,     0,     1,     2,     3,
       1,     3,     1,     3,     1,     4,     1,     0,     1,     0,
       1,     2,     1,     1,     1,     1,     1,     2,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     5,
       3,     9,     1,     0,     3,     1,     1,     1,     0,     1,
       0,     1,     3,     2,     2,     7,     2,     1,     2,     2,
       1,     3,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     2,     1,     4,     4,     2,     2,
       1,     0,     1,     1,     3,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 33 "parser.y" /* yacc.c:1646  */
    {root = buildTree(PROGRAM, (yyvsp[0].node));}
#line 1407 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 34 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 35 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 1419 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 36 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1425 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 37 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1431 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 38 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = buildTree(FUNC_DEF, (yyvsp[-1].node));}
#line 1437 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 39 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[-1].node)); appendNext((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = buildTree(FUNC_HEAD, (yyvsp[-2].node));}
#line 1443 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 40 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(DCL_SPEC, (yyvsp[0].node));}
#line 1449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 41 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 42 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 1461 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 43 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 44 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 45 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(CONST_TYPE, NULL);}
#line 1479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 46 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(INT_TYPE, NULL);}
#line 1485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 47 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(VOID_TYPE, NULL);}
#line 1491 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 48 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildNode(IDENT, (yyvsp[0].string)); }
#line 1497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 49 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(FORMAL_PARA, (yyvsp[-1].node));}
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 50 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 51 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1515 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 52 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1521 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 53 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node));  (yyval.node) = (yyvsp[-2].node);}
#line 1527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 54 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = buildTree(PARAM_DCL, (yyvsp[-1].node));}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 55 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = buildTree(COMPOUND_ST, (yyvsp[-2].node));}
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 56 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(DCL_LIST, (yyvsp[0].node));}
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 57 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(DCL_LIST, NULL);}
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 58 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 59 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 1563 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 60 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = buildTree(DCL, (yyvsp[-2].node));}
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 61 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 62 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node);}
#line 1581 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 63 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 64 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node)->son, buildNode(IDENT, (yyvsp[0].string))); (yyval.node) = (yyvsp[-2].node);}
#line 1593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 65 "parser.y" /* yacc.c:1646  */
    {Node* ptr = buildTree(SIMPLE_VAR, buildNode(IDENT, (yyvsp[0].string))); (yyval.node) = buildTree(DCL_ITEM, ptr);}
#line 1599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 66 "parser.y" /* yacc.c:1646  */
    {Node* ptr = buildNode(IDENT, (yyvsp[-3].string)); appendNext(ptr, (yyvsp[-1].node)); (yyval.node) = buildTree(DCL_ITEM, buildTree(ARRAY_VAR, ptr));}
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 67 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildNode(NUMBER, (yyvsp[0].string));}
#line 1611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 68 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 69 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(STAT_LIST, (yyvsp[0].node));}
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 70 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; }
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 71 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 72 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 74 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 75 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 77 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(EXP_ST, (yyvsp[-1].node));}
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 80 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 81 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 86 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 88 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(IF_ST, (yyvsp[-2].node));}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 89 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-4].node), (yyvsp[-2].node)); appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(IF_ELSE_ST, (yyvsp[-4].node));}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 90 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(WHILE_ST, (yyvsp[-2].node));}
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(RETURN_ST, (yyvsp[-1].node));}
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 92 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-6].node), (yyvsp[-4].node));appendNext((yyvsp[-4].node), (yyvsp[-2].node));appendNext((yyvsp[-2].node), (yyvsp[0].node));(yyval.node) = buildTree(FOR_ST,(yyvsp[-6].node));}
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(FOR_DCL, (yyvsp[0].node));}
#line 1767 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(FOR_DCL,NULL); }
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 95 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node));(yyval.node) = (yyvsp[-2].node);}
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(FOR_EXP, (yyvsp[0].node));}
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(FOR_EXP, (yyvsp[0].node));}
#line 1797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 99 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(FOR_EXP, NULL); }
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 100 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(FOR_INC, (yyvsp[0].node));}
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 101 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = buildTree(FOR_INC,NULL); }
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 103 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node));(yyval.node) = (yyvsp[-2].node);}
#line 1827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(CONTINUE_ST,NULL);}
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(BREAK_ST, NULL);}
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 106 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-4].node), (yyvsp[-1].node));(yyval.node) = buildTree(SWITCH_ST, (yyvsp[-4].node));}
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 107 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-1].node), (yyvsp[0].node));}
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 109 "parser.y" /* yacc.c:1646  */
    {Node *p = buildTree(CASE_EXP,(yyvsp[0].node)); Node *q = buildTree(CASE_LST,(yyvsp[-1].node)); appendNext(q, p); (yyval.node) = q;}
#line 1863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 110 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-1].node), (yyvsp[0].node));}
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 112 "parser.y" /* yacc.c:1646  */
    {Node * son = buildNode(NUMBER, (yyvsp[-1].string)); (yyval.node) = buildTree(CASE_ST, son);}
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(DEFAULT_ST, NULL);}
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 116 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(ASSIGN_OP, (yyvsp[-2].node));}
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 117 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(ADD_ASSIGN, (yyvsp[-2].node));}
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 118 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(SUB_ASSIGN, (yyvsp[-2].node));}
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 119 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(MUL_ASSIGN, (yyvsp[-2].node));}
#line 1923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 120 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(DIV_ASSIGN, (yyvsp[-2].node));}
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 121 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(MOD_ASSIGN, (yyvsp[-2].node));}
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 123 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(LOGICAL_OR, (yyvsp[-2].node));}
#line 1947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 125 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(LOGICAL_AND, (yyvsp[-2].node));}
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 127 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(EQ, (yyvsp[-2].node));}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 128 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(NE, (yyvsp[-2].node));}
#line 1977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 130 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(GT, (yyvsp[-2].node));}
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 131 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(LT, (yyvsp[-2].node));}
#line 1995 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 132 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(GE, (yyvsp[-2].node));}
#line 2001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 133 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(LE, (yyvsp[-2].node));}
#line 2007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2013 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 135 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(ADD, (yyvsp[-2].node));}
#line 2019 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 136 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(SUB, (yyvsp[-2].node));}
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 138 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(MUL, (yyvsp[-2].node));}
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 139 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(DIV, (yyvsp[-2].node));}
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 140 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = buildTree(MOD, (yyvsp[-2].node));}
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2055 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 142 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(UNARY_MINUS, (yyvsp[0].node));}
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(LOGICAL_NOT, (yyvsp[0].node));}
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(PRE_INC, (yyvsp[0].node));}
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(PRE_DEC, (yyvsp[0].node));}
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 147 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-3].node), (yyvsp[-1].node)); (yyval.node) = buildTree(INDEX, (yyvsp[-3].node));}
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 148 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-3].node), (yyvsp[-1].node)); (yyval.node) = buildTree(CALL, (yyvsp[-3].node));}
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(POST_INC, (yyvsp[-1].node));}
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(POST_DEC, (yyvsp[-1].node));}
#line 2109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 151 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2115 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; }
#line 2121 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildTree(ACTUAL_PARAM, (yyvsp[0].node));}
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 154 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2133 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 155 "parser.y" /* yacc.c:1646  */
    {appendNext((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node);}
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 156 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildNode(IDENT, (yyvsp[0].string));}
#line 2145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = buildNode(NUMBER, (yyvsp[0].string));}
#line 2151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2157 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2161 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 159 "parser.y" /* yacc.c:1906  */


int main(int argc, char *argv[]) {
	Node * root;
	FILE *inFile;
	FILE *astFile;
	
	if((inFile = fopen(argv[1], "r")) == NULL){
        printf("File path error: Invalid file path(%s).\n",argv[1]);
        return -1;
    }
	if((astFile = fopen(strcat(strtok(argv[1], "."), ".ast"), "w"))==NULL){
        printf("Making ast file error: Don\'t make ast file.\n");
        return -1;
    }
	
	root = parse(inFile);
	printTree(root, 0, astFile);
	    
	fclose(inFile);
	fclose(astFile);
	
	return 0;
}
