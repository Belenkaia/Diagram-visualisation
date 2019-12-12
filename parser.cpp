/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include <stdio.h>
	#include <stdarg.h> 
	#include <set>
	#include <string>
	#include <list>

	#include "common.h"

    extern int yylex();
	int yyerror(const char *s);

	extern ASTNode* program;

#line 85 "parser.cpp"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    TPROGR = 258,
    TTACT = 259,
    TCONST = 260,
    TENUM = 261,
    TINPUT = 262,
    TOUTPUT = 263,
    TPROC = 264,
    TLOCAL = 265,
    TFOR = 266,
    TALL = 267,
    TFROM = 268,
    TSTATE = 269,
    TSWITCH = 270,
    TCASE = 271,
    TBREAK = 272,
    TIF = 273,
    TELSE = 274,
    TSTART = 275,
    TSTOP = 276,
    TERROR = 277,
    TRESTART = 278,
    TLOOP = 279,
    TSET = 280,
    TNEXT = 281,
    TRESET = 282,
    TTIMEOUT = 283,
    TIN = 284,
    TIS = 285,
    TACTIVE = 286,
    TINACTIVE = 287,
    TBOOL = 288,
    TVOID = 289,
    TFLOAT = 290,
    TDOUBLE = 291,
    TSIGNED = 292,
    TUNSIGNED = 293,
    TSHORT = 294,
    TLONG = 295,
    TINT = 296,
    TIDENTIFIER = 297,
    TFCONST = 298,
    TICONST = 299,
    TLPAREN = 300,
    TRPAREN = 301,
    TLBRACKET = 302,
    TRBRACKET = 303,
    TSEMIC = 304,
    TLBRACE = 305,
    TRBRACE = 306,
    TCOLON = 307,
    TASSGN = 308,
    TCOMMA = 309,
    TPERIOD = 310,
    TAND = 311,
    TNOT = 312,
    TTILDE = 313,
    TMINUS = 314,
    TPLUS = 315,
    TMUL = 316,
    TDIV = 317,
    TPERC = 318,
    TLT = 319,
    TGT = 320,
    TXOR = 321,
    TOR = 322,
    TQMARK = 323,
    TEQ = 324,
    TNEQ = 325,
    TLE = 326,
    TGE = 327,
    TINC = 328,
    TDEC = 329,
    TRSHIFT = 330,
    TLSHIFT = 331,
    TLOR = 332,
    TLAND = 333,
    TR_ASSGN = 334,
    TL_ASSGN = 335,
    TPLUS_ASSGN = 336,
    TMINUS_ASSGN = 337,
    TSTAR_ASSGN = 338,
    TDIV_ASSGN = 339,
    TPERC_ASSGN = 340,
    TAND_ASSGN = 341,
    TXOR_ASSGN = 342,
    TOR_ASSGN = 343,
    XIF = 344,
    UMINUS = 345
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

    std::string* string;
	int token;
	ASTNode* ast_node;
	ASTNodeList* node_list;

#line 226 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  195
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  310

#define YYUNDEFTOK  2
#define YYMAXUTOK   345

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   261,   261,   282,   283,   285,   286,   287,   288,   289,
     290,   294,   306,   307,   315,   316,   319,   328,   335,   340,
     350,   359,   370,   379,   387,   387,   387,   387,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     390,   391,   392,   396,   404,   410,   417,   422,   434,   439,
     447,   452,   460,   465,   473,   483,   493,   504,   509,   514,
     519,   528,   533,   541,   549,   558,   565,   570,   580,   589,
     594,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   612,   619,   626,   632,   639,   645,   649,
     657,   666,   675,   689,   696,   710,   717,   725,   731,   738,
     744,   754,   757,   758,   770,   771,   783,   784,   795,   796,
     805,   815,   826,   832,   839,   847,   855,   866,   872,   878,
     884,   890,   898,   899,   911,   911,   912,   912,   912,   912,
     912,   912,   912,   912,   912,   912,   912,   912,   912,   912,
     912,   912,   912,   912,   913,   913,   913,   913,   913,   914,
     914,   914,   914,   914,   914,   914,   914,   914,   914,   914,
     917,   917,   917,   917,   918,   919,   921,   921,   922,   922,
     922,   930,   937,   947,   961,   968,   975,   981,   988,  1000,
    1020,  1025,  1032,  1040,  1046,  1053,  1062,  1068,  1075,  1088,
    1103,  1104,  1107,  1120,  1127,  1136
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"PROGR\"", "\"TACT\"", "\"CONST\"",
  "\"ENUM\"", "\"INPUT\"", "\"OUTPUT\"", "\"PROC\"", "\"LOCAL\"",
  "\"FOR\"", "\"ALL\"", "\"FROM\"", "\"STATE\"", "\"SWITCH\"", "\"CASE\"",
  "\"BREAK\"", "\"IF\\t\"", "\"ELSE\"", "\"START\"", "\"STOP\"",
  "\"ERROR\"", "\"RESTART\"", "\"LOOP\"", "\"SET\"", "\"NEXT\"",
  "\"RESET\"", "\"TIMEOUT\"", "\"IN\"", "\"IS\"", "\"ACTIVE\"",
  "\"INACTIVE\"", "\"BOOL\"", "\"VOID\"", "\"FLOAT\"", "\"DOUBLE\"",
  "\"SIGNED\"", "\"UNSIGNED\"", "\"SHORT\"", "\"LONG\"", "\"INT\"",
  "\"identifier\"", "\"floating-point constant\"", "\"integer constant\"",
  "\"left parentheses\"", "\"right parentheses\"", "\"left bracket\"",
  "\"right bracket\"", "\"semicolon\"", "\"left brace\"",
  "\"right brace\"", "\"colon\"", "\"=\"", "\"comma\"", "\".\"", "\"&\"",
  "\"!\"", "\"~\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"", "\"<\"",
  "\">\"", "\"^\"", "\"|\"", "\"?\"", "\"==\"", "\"!=\"", "\"<=\"",
  "\">=\"", "\"++\"", "\"--\"", "\">>\"", "\"<<\"", "\"||\"", "\"&&\"",
  "\">>=\"", "\"<<=\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"",
  "\"&=\"", "\"^=\"", "\"|=\"", "XIF", "UMINUS", "$accept", "program",
  "program_body", "tact", "const_enum_list", "const_or_enum_spec",
  "const_spec", "const_id", "const_exp_body", "infix_term_list",
  "const_pref_term", "const_prefix", "const_infix", "const_term",
  "enum_def", "enum_list", "enumerator", "func_decl_list",
  "register_def_list", "proc_def_list", "proc_def", "proc_id", "var_list",
  "state_def_list", "state_def", "state_id", "statements_list",
  "timeout_statement", "timeout_arg", "statement", "restart_statement",
  "reset_statement", "state_transition", "expression_statement",
  "if_statement", "switch_statement", "labeled_statement",
  "loop_statement", "compound_statement", "start_statement",
  "stop_statement", "error_statement", "expr", "assignment_expr",
  "binary_expr", "unary_expr", "postfix_expr", "arg_expr_list",
  "primary_expr", "cast_expr", "postfix_op", "binary_op", "unary_op",
  "assignement_op", "c_type_spec", "singness_spec", "size_spec", "var_def",
  "phys_var_def", "var_id", "reg_id", "reg_bits_spec_list",
  "reg_bits_spec", "calc_var_def", "scope_spec", "proc_id_list",
  "var_decl", "var_id_list", "register_def", "reg_addr", "register_size",
  "func_decl", "func_id", "c_type_spec_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345
};
# endif

#define YYPACT_NINF -230

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-230)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,    11,   109,    68,  -230,   123,   110,   164,   107,   121,
     118,   131,   131,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,   176,   164,  -230,  -230,  -230,   305,    97,   151,
      38,  -230,  -230,  -230,  -230,  -230,   132,   121,  -230,   170,
     170,   174,    -4,  -230,  -230,   305,    97,    97,  -230,  -230,
    -230,   178,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
     177,   314,    87,  -230,   184,    72,  -230,  -230,   170,   170,
    -230,   175,  -230,  -230,    97,   360,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,   314,
     132,  -230,   132,  -230,   121,   183,   183,   195,  -230,   -23,
     132,  -230,  -230,  -230,  -230,   189,   194,   235,   207,   195,
      -8,  -230,   208,  -230,     7,     7,  -230,   203,   360,  -230,
    -230,  -230,   174,  -230,   209,    -1,  -230,  -230,  -230,  -230,
    -230,   200,  -230,    10,   212,   219,  -230,  -230,   208,   242,
    -230,   223,  -230,  -230,   220,  -230,  -230,  -230,    45,   174,
     230,   236,   231,   174,    47,    51,   228,   233,    -5,   255,
     243,  -230,  -230,    24,  -230,   137,  -230,  -230,  -230,  -230,
    -230,    92,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,   240,  -230,   291,   244,    59,
    -230,  -230,   263,   131,   174,  -230,   208,   115,   236,   238,
     236,   247,  -230,   249,  -230,   253,  -230,  -230,   207,   254,
     262,    29,   258,   268,  -230,   197,   -10,  -230,   266,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,   236,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,   236,  -230,  -230,  -230,   236,  -230,   271,    74,  -230,
    -230,  -230,   319,   116,   273,   242,   288,  -230,  -230,  -230,
     286,  -230,  -230,  -230,  -230,    30,  -230,   236,  -230,  -230,
    -230,   242,  -230,  -230,  -230,  -230,   304,  -230,   131,   156,
    -230,  -230,   242,  -230,   242,  -230,  -230,   236,  -230,  -230,
     301,  -230,  -230,  -230,  -230,   340,  -230,  -230,   242,  -230
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     3,     0,     0,
       0,     0,     0,   160,   161,   162,   163,   166,   167,   168,
     170,   169,     0,     8,    13,    14,    15,     9,    10,     0,
       0,   165,    51,    49,    11,    17,     0,     0,   175,     0,
       0,     0,     0,    52,    12,     5,     6,     7,    48,    50,
     193,     0,   164,    41,    40,    25,    24,    27,    26,    42,
       0,    18,     0,    23,    46,     0,    45,   190,     0,     0,
      56,     0,     2,    53,     4,     0,    16,    35,    29,    28,
      30,    31,    32,    36,    37,    34,    33,    39,    38,    19,
       0,    22,     0,    43,     0,     0,     0,     0,   195,     0,
       0,    21,    47,    44,   191,     0,     0,     0,     0,     0,
       0,    61,     0,    59,     0,     0,    60,     0,     0,    20,
     188,   189,     0,    65,     0,     0,    57,    58,    55,    62,
     174,   179,   180,     0,     0,     0,   192,   194,     0,     0,
      54,     0,   181,   184,   182,   171,   172,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,   115,   114,     0,    88,     0,   148,   147,   146,   144,
     145,     0,    67,    80,    81,    79,    82,    75,    76,    77,
      78,    71,    72,    73,    74,     0,   101,   102,   122,   106,
     108,   104,     0,     0,     0,   185,     0,     0,     0,     0,
       0,     0,    98,     0,   100,     0,    83,    93,     0,     0,
       0,     0,     0,     0,    95,     0,     0,    64,     0,    66,
      87,   130,   140,   139,   141,   142,   143,   133,   134,   129,
     128,   131,   132,   135,   136,   138,   137,   126,   127,     0,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   124,   125,   111,     0,   107,     0,     0,   177,
     183,   186,     0,     0,     0,     0,     0,    96,    97,    99,
       0,    86,    84,   109,   113,     0,   117,     0,    94,    69,
      70,     0,    63,   122,   105,   103,     0,   173,     0,     0,
     120,   121,     0,    92,     0,    85,   110,     0,   123,    68,
       0,   176,   118,   119,    91,    90,   112,   178,     0,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,  -230,  -230,  -230,   341,  -230,    -9,   279,  -230,
     -74,  -230,   276,   310,  -230,  -230,   284,   356,    -3,  -230,
     342,  -114,  -230,   274,   -95,   179,   217,  -230,  -230,  -170,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -149,  -207,  -230,  -185,  -230,  -230,  -230,  -229,
    -230,  -230,  -230,  -230,   -72,  -230,   355,   277,  -230,  -126,
     172,  -230,   100,  -230,   287,  -230,   294,  -230,    93,   -13,
     308,   -16,  -230,  -230
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    22,     7,    23,    24,    25,    59,    60,    89,
      61,    62,    90,    63,    26,    65,    66,    27,    28,    42,
      43,    71,   109,   110,   111,   124,   171,   218,   281,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   275,   190,   191,
     254,   239,   192,   251,    29,    30,    31,   113,   114,   131,
     257,   258,   259,   115,   134,   144,   116,   148,    32,    68,
     105,    33,    51,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      36,   219,   199,    98,   274,    41,   108,   256,   138,   208,
     284,    48,   147,   108,   212,   129,   101,   132,   133,   143,
      46,   209,   142,   117,    47,   112,   119,    69,    64,    48,
     129,   118,    35,   149,   279,   197,     1,   112,   149,   201,
     203,   205,    74,   128,   285,   219,   137,    72,   298,   264,
     140,   266,    70,     3,   283,    95,    96,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   160,   161,   162,   163,
     261,   160,   161,   162,   163,   273,   296,    19,    20,    21,
     260,   166,   167,   168,   297,    64,   166,   167,   168,    70,
     306,   213,   283,    70,   195,   293,   202,   169,   170,   196,
     204,   149,   169,   170,    11,    12,   212,   150,   151,     4,
     152,   299,   153,   154,   155,   156,   157,   158,     5,   159,
     216,    49,   304,    93,   305,   287,    94,     6,   288,    35,
      53,    54,   252,   253,   160,   161,   162,   163,   309,    49,
      49,   164,   165,   217,   262,   263,   149,   290,   291,   166,
     167,   168,   150,   151,     8,   152,    34,   153,   154,   155,
     156,   157,   158,    35,   159,   169,   170,    49,    37,     9,
      10,    11,    12,    38,    35,    53,    54,   302,   303,   160,
     161,   162,   163,    39,    40,    41,   164,   165,   214,    55,
      56,    57,    58,    50,   166,   167,   168,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   149,   280,   107,   108,
     169,   170,   150,   151,    67,   152,    70,   153,   154,   155,
     156,   157,   158,    75,   159,    97,    76,   104,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    92,   120,   160,
     161,   162,   163,   121,   122,   149,   164,   165,   278,   123,
     130,   149,   136,   141,   166,   167,   168,   150,   151,   139,
     152,   145,   153,   154,   155,   156,   157,   158,   146,   159,
     169,   170,   149,   193,   194,   198,   200,   206,   160,   161,
     162,   163,   207,   210,   160,   161,   162,   163,   211,   220,
     265,   164,   165,   166,   167,   168,   267,   240,   268,   166,
     167,   168,   269,   271,   276,   160,   161,   162,   255,   169,
     170,   272,    11,    12,   277,   169,   170,   282,   286,   292,
     166,   167,   168,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   289,   294,   295,   169,   170,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   221,   300,   307,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   308,
     231,   232,   233,   234,    44,   100,   235,   236,   237,   238,
      77,   102,    91,    78,    79,    80,    81,    82,   103,    45,
      83,    84,   215,   125,    73,    52,   126,   270,   301,    85,
      86,    87,    88,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   135,   127,   106
};

static const yytype_uint16 yycheck[] =
{
       9,   171,   151,    75,   211,     9,    14,   192,   122,    14,
     239,    27,   138,    14,   163,   110,    90,    10,    11,   133,
      23,    26,    12,    46,    27,    97,   100,    40,    37,    45,
     125,    54,    42,     9,    44,   149,     3,   109,     9,   153,
     154,   155,    45,    51,   251,   215,   118,    51,   277,   198,
      51,   200,    42,    42,   239,    68,    69,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     196,    42,    43,    44,    45,    46,    46,    39,    40,    41,
     194,    57,    58,    59,    54,    94,    57,    58,    59,    42,
     297,   163,   277,    42,    49,   265,    49,    73,    74,    54,
      49,     9,    73,    74,     7,     8,   255,    15,    16,     0,
      18,   281,    20,    21,    22,    23,    24,    25,    50,    27,
      28,    28,   292,    51,   294,    51,    54,     4,    54,    42,
      43,    44,    73,    74,    42,    43,    44,    45,   308,    46,
      47,    49,    50,    51,    29,    30,     9,    31,    32,    57,
      58,    59,    15,    16,    44,    18,    49,    20,    21,    22,
      23,    24,    25,    42,    27,    73,    74,    74,    50,     5,
       6,     7,     8,    42,    42,    43,    44,    21,    22,    42,
      43,    44,    45,    11,    12,     9,    49,    50,    51,    57,
      58,    59,    60,    42,    57,    58,    59,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     9,   216,    13,    14,
      73,    74,    15,    16,    44,    18,    42,    20,    21,    22,
      23,    24,    25,    45,    27,    50,    49,    44,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    53,    49,    42,
      43,    44,    45,    49,     9,     9,    49,    50,    51,    42,
      42,     9,    49,    53,    57,    58,    59,    15,    16,    50,
      18,    49,    20,    21,    22,    23,    24,    25,    49,    27,
      73,    74,     9,    50,    54,    45,    45,    49,    42,    43,
      44,    45,    49,    28,    42,    43,    44,    45,    45,    49,
      52,    49,    50,    57,    58,    59,    49,    53,    49,    57,
      58,    59,    49,    49,    46,    42,    43,    44,    45,    73,
      74,    49,     7,     8,    46,    73,    74,    51,    47,    46,
      57,    58,    59,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    14,    46,    49,    73,    74,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    56,    44,    48,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    19,
      69,    70,    71,    72,    23,    89,    75,    76,    77,    78,
      56,    92,    62,    59,    60,    61,    62,    63,    94,    23,
      66,    67,   165,   109,    42,    30,   109,   208,   288,    75,
      76,    77,    78,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   115,   109,    96
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    92,    42,     0,    50,     4,    94,    44,     5,
       6,     7,     8,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    93,    95,    96,    97,   105,   108,   109,   145,
     146,   147,   159,   162,    49,    42,    98,    50,    42,   151,
     151,     9,   110,   111,    96,   108,   109,   109,   162,   159,
      42,   163,   147,    43,    44,    57,    58,    59,    60,    98,
      99,   101,   102,   104,    98,   106,   107,    44,   160,   160,
      42,   112,    51,   111,   109,    45,    49,    56,    59,    60,
      61,    62,    63,    66,    67,    75,    76,    77,    78,   100,
     103,   104,    53,    51,    54,   160,   160,    50,   145,   164,
     103,   101,    99,   107,    44,   161,   161,    13,    14,   113,
     114,   115,   145,   148,   149,   154,   157,    46,    54,   101,
      49,    49,     9,    42,   116,   114,   148,   157,    51,   115,
      42,   150,    10,    11,   155,   155,    49,   145,   112,    50,
      51,    53,    12,   112,   156,    49,    49,   150,   158,     9,
      15,    16,    18,    20,    21,    22,    23,    24,    25,    27,
      42,    43,    44,    45,    49,    50,    57,    58,    59,    73,
      74,   117,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     139,   140,   143,    50,    54,    49,    54,   112,    45,   133,
      45,   112,    49,   112,    49,   112,    49,    49,    14,    26,
      28,    45,   133,   145,    51,   117,    28,    51,   118,   120,
      49,    56,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    69,    70,    71,    72,    75,    76,    77,    78,   142,
      53,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,   144,    73,    74,   141,    45,   136,   151,   152,   153,
     112,   150,    29,    30,   133,    52,   133,    49,    49,    49,
     116,    49,    49,    46,   134,   138,    46,    46,    51,    44,
      98,   119,    51,   136,   140,   134,    47,    51,    54,    14,
      31,    32,    46,   120,    46,    49,    46,    54,   140,   120,
      44,   153,    21,    22,   120,   120,   134,    48,    19,   120
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    94,    95,    95,    96,    96,    97,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   102,   102,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   104,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   112,   113,   113,   113,
     113,   114,   114,   115,   115,   116,   117,   117,   118,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   122,   123,   123,   124,   124,   125,
     125,   126,   127,   128,   129,   129,   130,   131,   131,   132,
     132,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     137,   137,   138,   138,   139,   139,   139,   139,   139,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   143,   143,   143,   143,   143,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   145,   145,   145,   145,   145,   146,   146,   147,   147,
     147,   148,   148,   149,   150,   151,   152,   152,   153,   154,
     155,   155,   155,   156,   156,   157,   158,   158,   159,   159,
     160,   161,   162,   163,   164,   164
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     0,     3,     2,     2,     2,     1,     1,
       1,     3,     2,     1,     1,     1,     4,     1,     1,     2,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     1,     1,     3,     2,     1,
       2,     1,     1,     2,     6,     5,     1,     2,     2,     1,
       1,     1,     2,     6,     5,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     3,     2,     1,     7,
       5,     5,     4,     2,     3,     2,     3,     3,     2,     3,
       2,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       4,     2,     3,     1,     1,     1,     1,     3,     5,     5,
       4,     4,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     6,     1,     1,     3,     1,     4,     2,
       1,     2,     2,     3,     1,     5,     3,     1,     6,     6,
       1,     1,     6,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
  switch (yytype)
    {
    case 3: /* "PROGR"  */
#line 213 "parser.y"
      {}
#line 1343 "parser.cpp"
        break;

    case 4: /* "TACT"  */
#line 213 "parser.y"
      {}
#line 1349 "parser.cpp"
        break;

    case 5: /* "CONST"  */
#line 213 "parser.y"
      {}
#line 1355 "parser.cpp"
        break;

    case 6: /* "ENUM"  */
#line 213 "parser.y"
      {}
#line 1361 "parser.cpp"
        break;

    case 9: /* "PROC"  */
#line 213 "parser.y"
      {}
#line 1367 "parser.cpp"
        break;

    case 13: /* "FROM"  */
#line 213 "parser.y"
      {}
#line 1373 "parser.cpp"
        break;

    case 14: /* "STATE"  */
#line 213 "parser.y"
      {}
#line 1379 "parser.cpp"
        break;

    case 15: /* "SWITCH"  */
#line 213 "parser.y"
      {}
#line 1385 "parser.cpp"
        break;

    case 16: /* "CASE"  */
#line 213 "parser.y"
      {}
#line 1391 "parser.cpp"
        break;

    case 17: /* "BREAK"  */
#line 213 "parser.y"
      {}
#line 1397 "parser.cpp"
        break;

    case 18: /* "IF\t"  */
#line 213 "parser.y"
      {}
#line 1403 "parser.cpp"
        break;

    case 19: /* "ELSE"  */
#line 213 "parser.y"
      {}
#line 1409 "parser.cpp"
        break;

    case 20: /* "START"  */
#line 213 "parser.y"
      {}
#line 1415 "parser.cpp"
        break;

    case 21: /* "STOP"  */
#line 213 "parser.y"
      {}
#line 1421 "parser.cpp"
        break;

    case 22: /* "ERROR"  */
#line 213 "parser.y"
      {}
#line 1427 "parser.cpp"
        break;

    case 23: /* "RESTART"  */
#line 213 "parser.y"
      {}
#line 1433 "parser.cpp"
        break;

    case 24: /* "LOOP"  */
#line 213 "parser.y"
      {}
#line 1439 "parser.cpp"
        break;

    case 25: /* "SET"  */
#line 213 "parser.y"
      {}
#line 1445 "parser.cpp"
        break;

    case 26: /* "NEXT"  */
#line 213 "parser.y"
      {}
#line 1451 "parser.cpp"
        break;

    case 27: /* "RESET"  */
#line 213 "parser.y"
      {}
#line 1457 "parser.cpp"
        break;

    case 28: /* "TIMEOUT"  */
#line 213 "parser.y"
      {}
#line 1463 "parser.cpp"
        break;

    case 29: /* "IN"  */
#line 213 "parser.y"
      {}
#line 1469 "parser.cpp"
        break;

    case 30: /* "IS"  */
#line 213 "parser.y"
      {}
#line 1475 "parser.cpp"
        break;

    case 31: /* "ACTIVE"  */
#line 213 "parser.y"
      {}
#line 1481 "parser.cpp"
        break;

    case 32: /* "INACTIVE"  */
#line 213 "parser.y"
      {}
#line 1487 "parser.cpp"
        break;

    case 45: /* "left parentheses"  */
#line 213 "parser.y"
      {}
#line 1493 "parser.cpp"
        break;

    case 46: /* "right parentheses"  */
#line 213 "parser.y"
      {}
#line 1499 "parser.cpp"
        break;

    case 47: /* "left bracket"  */
#line 213 "parser.y"
      {}
#line 1505 "parser.cpp"
        break;

    case 48: /* "right bracket"  */
#line 213 "parser.y"
      {}
#line 1511 "parser.cpp"
        break;

    case 49: /* "semicolon"  */
#line 213 "parser.y"
      {}
#line 1517 "parser.cpp"
        break;

    case 50: /* "left brace"  */
#line 213 "parser.y"
      {}
#line 1523 "parser.cpp"
        break;

    case 51: /* "right brace"  */
#line 213 "parser.y"
      {}
#line 1529 "parser.cpp"
        break;

    case 52: /* "colon"  */
#line 213 "parser.y"
      {}
#line 1535 "parser.cpp"
        break;

    case 93: /* program_body  */
#line 215 "parser.y"
      {
	if(NULL != ((*yyvaluep).node_list))
	{
		while(!((*yyvaluep).node_list)->empty())
		{
			delete ((*yyvaluep).node_list)->back();
			((*yyvaluep).node_list)->back() = NULL;
			((*yyvaluep).node_list)->pop_back();
		}
		delete ((*yyvaluep).node_list);
		((*yyvaluep).node_list) = NULL;
	}
}
#line 1553 "parser.cpp"
        break;

    case 94: /* tact  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1570 "parser.cpp"
        break;

    case 95: /* const_enum_list  */
#line 215 "parser.y"
      {
	if(NULL != ((*yyvaluep).node_list))
	{
		while(!((*yyvaluep).node_list)->empty())
		{
			delete ((*yyvaluep).node_list)->back();
			((*yyvaluep).node_list)->back() = NULL;
			((*yyvaluep).node_list)->pop_back();
		}
		delete ((*yyvaluep).node_list);
		((*yyvaluep).node_list) = NULL;
	}
}
#line 1588 "parser.cpp"
        break;

    case 96: /* const_or_enum_spec  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1605 "parser.cpp"
        break;

    case 97: /* const_spec  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1622 "parser.cpp"
        break;

    case 98: /* const_id  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1639 "parser.cpp"
        break;

    case 99: /* const_exp_body  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1656 "parser.cpp"
        break;

    case 100: /* infix_term_list  */
#line 215 "parser.y"
      {
	if(NULL != ((*yyvaluep).node_list))
	{
		while(!((*yyvaluep).node_list)->empty())
		{
			delete ((*yyvaluep).node_list)->back();
			((*yyvaluep).node_list)->back() = NULL;
			((*yyvaluep).node_list)->pop_back();
		}
		delete ((*yyvaluep).node_list);
		((*yyvaluep).node_list) = NULL;
	}
}
#line 1674 "parser.cpp"
        break;

    case 101: /* const_pref_term  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1691 "parser.cpp"
        break;

    case 104: /* const_term  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1708 "parser.cpp"
        break;

    case 105: /* enum_def  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1725 "parser.cpp"
        break;

    case 106: /* enum_list  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1742 "parser.cpp"
        break;

    case 107: /* enumerator  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1759 "parser.cpp"
        break;

    case 108: /* func_decl_list  */
#line 215 "parser.y"
      {
	if(NULL != ((*yyvaluep).node_list))
	{
		while(!((*yyvaluep).node_list)->empty())
		{
			delete ((*yyvaluep).node_list)->back();
			((*yyvaluep).node_list)->back() = NULL;
			((*yyvaluep).node_list)->pop_back();
		}
		delete ((*yyvaluep).node_list);
		((*yyvaluep).node_list) = NULL;
	}
}
#line 1777 "parser.cpp"
        break;

    case 109: /* register_def_list  */
#line 215 "parser.y"
      {
	if(NULL != ((*yyvaluep).node_list))
	{
		while(!((*yyvaluep).node_list)->empty())
		{
			delete ((*yyvaluep).node_list)->back();
			((*yyvaluep).node_list)->back() = NULL;
			((*yyvaluep).node_list)->pop_back();
		}
		delete ((*yyvaluep).node_list);
		((*yyvaluep).node_list) = NULL;
	}
}
#line 1795 "parser.cpp"
        break;

    case 110: /* proc_def_list  */
#line 215 "parser.y"
      {
	if(NULL != ((*yyvaluep).node_list))
	{
		while(!((*yyvaluep).node_list)->empty())
		{
			delete ((*yyvaluep).node_list)->back();
			((*yyvaluep).node_list)->back() = NULL;
			((*yyvaluep).node_list)->pop_back();
		}
		delete ((*yyvaluep).node_list);
		((*yyvaluep).node_list) = NULL;
	}
}
#line 1813 "parser.cpp"
        break;

    case 111: /* proc_def  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1830 "parser.cpp"
        break;

    case 112: /* proc_id  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1847 "parser.cpp"
        break;

    case 113: /* var_list  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1864 "parser.cpp"
        break;

    case 114: /* state_def_list  */
#line 215 "parser.y"
      {
	if(NULL != ((*yyvaluep).node_list))
	{
		while(!((*yyvaluep).node_list)->empty())
		{
			delete ((*yyvaluep).node_list)->back();
			((*yyvaluep).node_list)->back() = NULL;
			((*yyvaluep).node_list)->pop_back();
		}
		delete ((*yyvaluep).node_list);
		((*yyvaluep).node_list) = NULL;
	}
}
#line 1882 "parser.cpp"
        break;

    case 115: /* state_def  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1899 "parser.cpp"
        break;

    case 116: /* state_id  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1916 "parser.cpp"
        break;

    case 117: /* statements_list  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1933 "parser.cpp"
        break;

    case 118: /* timeout_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1950 "parser.cpp"
        break;

    case 119: /* timeout_arg  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1967 "parser.cpp"
        break;

    case 120: /* statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 1984 "parser.cpp"
        break;

    case 121: /* restart_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2001 "parser.cpp"
        break;

    case 122: /* reset_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2018 "parser.cpp"
        break;

    case 123: /* state_transition  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2035 "parser.cpp"
        break;

    case 124: /* expression_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2052 "parser.cpp"
        break;

    case 125: /* if_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2069 "parser.cpp"
        break;

    case 126: /* switch_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2086 "parser.cpp"
        break;

    case 127: /* labeled_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2103 "parser.cpp"
        break;

    case 128: /* loop_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2120 "parser.cpp"
        break;

    case 129: /* compound_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2137 "parser.cpp"
        break;

    case 130: /* start_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2154 "parser.cpp"
        break;

    case 131: /* stop_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2171 "parser.cpp"
        break;

    case 132: /* error_statement  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2188 "parser.cpp"
        break;

    case 133: /* expr  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2205 "parser.cpp"
        break;

    case 134: /* assignment_expr  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2222 "parser.cpp"
        break;

    case 135: /* binary_expr  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2239 "parser.cpp"
        break;

    case 136: /* unary_expr  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2256 "parser.cpp"
        break;

    case 137: /* postfix_expr  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2273 "parser.cpp"
        break;

    case 138: /* arg_expr_list  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2290 "parser.cpp"
        break;

    case 139: /* primary_expr  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2307 "parser.cpp"
        break;

    case 140: /* cast_expr  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2324 "parser.cpp"
        break;

    case 148: /* var_def  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2341 "parser.cpp"
        break;

    case 149: /* phys_var_def  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2358 "parser.cpp"
        break;

    case 150: /* var_id  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2375 "parser.cpp"
        break;

    case 151: /* reg_id  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2392 "parser.cpp"
        break;

    case 152: /* reg_bits_spec_list  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2409 "parser.cpp"
        break;

    case 153: /* reg_bits_spec  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2426 "parser.cpp"
        break;

    case 154: /* calc_var_def  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2443 "parser.cpp"
        break;

    case 155: /* scope_spec  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2460 "parser.cpp"
        break;

    case 156: /* proc_id_list  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2477 "parser.cpp"
        break;

    case 157: /* var_decl  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2494 "parser.cpp"
        break;

    case 158: /* var_id_list  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2511 "parser.cpp"
        break;

    case 159: /* register_def  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2528 "parser.cpp"
        break;

    case 160: /* reg_addr  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2545 "parser.cpp"
        break;

    case 161: /* register_size  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2562 "parser.cpp"
        break;

    case 162: /* func_decl  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2579 "parser.cpp"
        break;

    case 163: /* func_id  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2596 "parser.cpp"
        break;

    case 164: /* c_type_spec_list  */
#line 229 "parser.y"
      {
	if(NULL != ((*yyvaluep).ast_node))
	{
		for(ASTNodeList::iterator i=((*yyvaluep).ast_node)->children.begin();i!=((*yyvaluep).ast_node)->children.end();i++)
		{
			delete *i;
			*i = NULL;
		}
		delete ((*yyvaluep).ast_node);
		((*yyvaluep).ast_node) = NULL;
	}
}
#line 2613 "parser.cpp"
        break;

      default:
        break;
    }
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 262 "parser.y"
    {
						ASTNode* program_name = new ASTNode(ASTNODE_IDENTIFIER);
						program_name->val = (yyvsp[-5].string);

						program = new ASTNode(ASTNODE_PROGRAM);
						program->children.push_back(program_name);
						if(NULL != (yyvsp[-3].ast_node)) program->children.push_back((yyvsp[-3].ast_node));//tact

						//For lists - merge them with program's children
						//(no such nodes in AST as lists of items)
						if(NULL != (yyvsp[-2].node_list)) program->children.splice(program->children.end(), *(yyvsp[-2].node_list)); //program_body
						if(NULL != (yyvsp[-1].node_list)) program->children.splice(program->children.end(), *(yyvsp[-1].node_list)); //proc_def_list

						delete (yyvsp[-2].node_list);
						delete (yyvsp[-1].node_list);
						(yyvsp[-6].token);(yyvsp[-4].token);(yyvsp[0].token);
					}
#line 2895 "parser.cpp"
    break;

  case 3:
#line 282 "parser.y"
    {(yyval.node_list)=NULL;}
#line 2901 "parser.cpp"
    break;

  case 4:
#line 284 "parser.y"
    {(yyval.node_list)=new ASTNodeList;(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[-2].node_list));(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[-1].node_list));(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[0].node_list));delete (yyvsp[-2].node_list);delete (yyvsp[-1].node_list);delete (yyvsp[0].node_list);}
#line 2907 "parser.cpp"
    break;

  case 5:
#line 285 "parser.y"
    {(yyval.node_list)=new ASTNodeList;(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[-1].node_list));(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[0].node_list));delete (yyvsp[-1].node_list);delete (yyvsp[0].node_list);}
#line 2913 "parser.cpp"
    break;

  case 6:
#line 286 "parser.y"
    {(yyval.node_list)=new ASTNodeList;(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[-1].node_list));(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[0].node_list));delete (yyvsp[-1].node_list);delete (yyvsp[0].node_list);}
#line 2919 "parser.cpp"
    break;

  case 7:
#line 287 "parser.y"
    {(yyval.node_list)=new ASTNodeList;(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[-1].node_list));(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[0].node_list));delete (yyvsp[-1].node_list);delete (yyvsp[0].node_list);}
#line 2925 "parser.cpp"
    break;

  case 8:
#line 288 "parser.y"
    {(yyval.node_list)=new ASTNodeList;(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[0].node_list));delete (yyvsp[0].node_list);}
#line 2931 "parser.cpp"
    break;

  case 9:
#line 289 "parser.y"
    {(yyval.node_list)=new ASTNodeList;(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[0].node_list));delete (yyvsp[0].node_list);}
#line 2937 "parser.cpp"
    break;

  case 10:
#line 290 "parser.y"
    {(yyval.node_list)=new ASTNodeList;(yyval.node_list)->splice((yyval.node_list)->end(),*(yyvsp[0].node_list));delete (yyvsp[0].node_list);}
#line 2943 "parser.cpp"
    break;

  case 11:
#line 295 "parser.y"
    {
						ASTNode* tact_const = new ASTNode(ASTNODE_ICONST);
						tact_const->val = (yyvsp[-1].string);

						(yyval.ast_node) = new ASTNode(ASTNODE_TACT);
						(yyval.ast_node)->children.push_back(tact_const);
						(yyvsp[-2].token);(yyvsp[0].token);
					}
#line 2956 "parser.cpp"
    break;

  case 12:
#line 306 "parser.y"
    {(yyvsp[-1].node_list)-> push_back((yyvsp[0].ast_node)); (yyval.node_list) = (yyvsp[-1].node_list);}
#line 2962 "parser.cpp"
    break;

  case 13:
#line 308 "parser.y"
    {
						(yyval.node_list) = new ASTNodeList;
						(yyval.node_list)->push_back((yyvsp[0].ast_node));
					}
#line 2971 "parser.cpp"
    break;

  case 14:
#line 315 "parser.y"
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2977 "parser.cpp"
    break;

  case 15:
#line 316 "parser.y"
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2983 "parser.cpp"
    break;

  case 16:
#line 320 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_CONST_SPEC);
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node)); //const_id
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node)); //const_exp_body
							(yyvsp[-3].token);(yyvsp[0].token);
						}
#line 2994 "parser.cpp"
    break;

  case 17:
#line 329 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_IDENTIFIER);
							(yyval.ast_node)->val = (yyvsp[0].string);
						}
#line 3003 "parser.cpp"
    break;

  case 18:
#line 336 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_CONST_EXP_BODY);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3012 "parser.cpp"
    break;

  case 19:
#line 341 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_CONST_EXP_BODY);
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyval.ast_node)->children.splice((yyval.ast_node)->children.end(), *(yyvsp[0].node_list));//merge lists
							delete (yyvsp[0].node_list);
						}
#line 3023 "parser.cpp"
    break;

  case 20:
#line 351 "parser.y"
    {
							ASTNode* const_infix = new ASTNode(ASTNODE_CONST_INFIX);
							const_infix->val = (yyvsp[-1].string);

							(yyvsp[-2].node_list)->push_back(const_infix);
							(yyvsp[-2].node_list)->push_back((yyvsp[0].ast_node));
							(yyval.node_list) = (yyvsp[-2].node_list);
						}
#line 3036 "parser.cpp"
    break;

  case 21:
#line 360 "parser.y"
    {
							ASTNode* const_infix = new ASTNode(ASTNODE_CONST_INFIX);
							const_infix->val = (yyvsp[-1].string);

							(yyval.node_list) = new ASTNodeList;
							(yyval.node_list)->push_back(const_infix);
							(yyval.node_list)->push_back((yyvsp[0].ast_node));
						}
#line 3049 "parser.cpp"
    break;

  case 22:
#line 371 "parser.y"
    {
							ASTNode* const_prefix = new ASTNode(ASTNODE_CONST_PREFIX);
							const_prefix->val = (yyvsp[-1].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_CONST_PREF_TERM);
							(yyval.ast_node)->children.push_back(const_prefix);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3062 "parser.cpp"
    break;

  case 23:
#line 380 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_CONST_PREF_TERM);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3071 "parser.cpp"
    break;

  case 40:
#line 390 "parser.y"
    {(yyval.ast_node)=new ASTNode(ASTNODE_CONST_TERM);(yyval.ast_node)->val=(yyvsp[0].string);}
#line 3077 "parser.cpp"
    break;

  case 41:
#line 391 "parser.y"
    {(yyval.ast_node)=new ASTNode(ASTNODE_CONST_TERM);(yyval.ast_node)->val=(yyvsp[0].string);}
#line 3083 "parser.cpp"
    break;

  case 42:
#line 392 "parser.y"
    {(yyval.ast_node)=(yyvsp[0].ast_node);}
#line 3089 "parser.cpp"
    break;

  case 43:
#line 397 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_ENUM_DEF);
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[-3].token);(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3099 "parser.cpp"
    break;

  case 44:
#line 405 "parser.y"
    {
							(yyval.ast_node) = (yyvsp[-2].ast_node);
							(yyvsp[-2].ast_node)->children.push_back((yyvsp[0].ast_node));
							delete (yyvsp[-1].string);
						}
#line 3109 "parser.cpp"
    break;

  case 45:
#line 411 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_ENUM_LIST);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3118 "parser.cpp"
    break;

  case 46:
#line 418 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_ENUM);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3127 "parser.cpp"
    break;

  case 47:
#line 423 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_ENUM);
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
							delete (yyvsp[-1].string);
						}
#line 3138 "parser.cpp"
    break;

  case 48:
#line 435 "parser.y"
    {
						(yyval.node_list) = (yyvsp[-1].node_list);
						(yyvsp[-1].node_list)->push_back((yyvsp[0].ast_node));
					}
#line 3147 "parser.cpp"
    break;

  case 49:
#line 440 "parser.y"
    {
						(yyval.node_list) = new ASTNodeList;
						(yyval.node_list)->push_back((yyvsp[0].ast_node));
					}
#line 3156 "parser.cpp"
    break;

  case 50:
#line 448 "parser.y"
    {
							(yyval.node_list) = (yyvsp[-1].node_list);
							(yyvsp[-1].node_list)->push_back((yyvsp[0].ast_node));
						}
#line 3165 "parser.cpp"
    break;

  case 51:
#line 453 "parser.y"
    {
							(yyval.node_list) = new ASTNodeList;
							(yyval.node_list)->push_back((yyvsp[0].ast_node));
						}
#line 3174 "parser.cpp"
    break;

  case 52:
#line 461 "parser.y"
    {
						(yyval.node_list) = new ASTNodeList;
						(yyval.node_list)->push_back((yyvsp[0].ast_node));
					}
#line 3183 "parser.cpp"
    break;

  case 53:
#line 466 "parser.y"
    {
						(yyvsp[-1].node_list)->push_back((yyvsp[0].ast_node));
						(yyval.node_list) = (yyvsp[-1].node_list);
					}
#line 3192 "parser.cpp"
    break;

  case 54:
#line 474 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_PROC_DEF);
							(yyval.ast_node)->children.push_back((yyvsp[-4].ast_node)); //proc_id
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node)); //var_list
							(yyval.ast_node)->children.splice((yyval.ast_node)->children.end(), *(yyvsp[-1].node_list));//add state defs as children
							delete (yyvsp[-1].node_list); //state_def_list
							(yyvsp[-5].token);(yyvsp[-3].token);(yyvsp[0].token);
						}
#line 3205 "parser.cpp"
    break;

  case 55:
#line 484 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_PROC_DEF);
							(yyval.ast_node)->children.push_back((yyvsp[-3].ast_node)); //proc_id
							(yyval.ast_node)->children.splice((yyval.ast_node)->children.end(), *(yyvsp[-1].node_list));//add state defs as children
							delete (yyvsp[-1].node_list); //state_def_list
							(yyvsp[-4].token);(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3217 "parser.cpp"
    break;

  case 56:
#line 494 "parser.y"
    {
							ASTNode* proc_id = new ASTNode(ASTNODE_IDENTIFIER);
							proc_id->val = (yyvsp[0].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_PROCID);
							(yyval.ast_node)->children.push_back(proc_id);
						}
#line 3229 "parser.cpp"
    break;

  case 57:
#line 505 "parser.y"
    {
							(yyval.ast_node) = (yyvsp[-1].ast_node);
							(yyvsp[-1].ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3238 "parser.cpp"
    break;

  case 58:
#line 510 "parser.y"
    {
							(yyval.ast_node) = (yyvsp[-1].ast_node);
							(yyvsp[-1].ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3247 "parser.cpp"
    break;

  case 59:
#line 515 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_VAR_LIST);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3256 "parser.cpp"
    break;

  case 60:
#line 520 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_VAR_LIST);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3265 "parser.cpp"
    break;

  case 61:
#line 529 "parser.y"
    {
							(yyval.node_list) = new ASTNodeList;
							(yyval.node_list)->push_back((yyvsp[0].ast_node));
						}
#line 3274 "parser.cpp"
    break;

  case 62:
#line 534 "parser.y"
    {
							(yyvsp[-1].node_list)->push_back((yyvsp[0].ast_node));
							(yyval.node_list) = (yyvsp[-1].node_list);
						}
#line 3283 "parser.cpp"
    break;

  case 63:
#line 542 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_STATE_DEF);
							(yyval.ast_node)->children.push_back((yyvsp[-4].ast_node)); //state_id
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node)); //statements_list
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node)); //timeout_statement
							(yyvsp[-5].token);(yyvsp[-3].token);(yyvsp[0].token);
						}
#line 3295 "parser.cpp"
    break;

  case 64:
#line 550 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_STATE_DEF);
							(yyval.ast_node)->children.push_back((yyvsp[-3].ast_node)); //state_id
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node)); //statements_list
							(yyvsp[-4].token);(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3306 "parser.cpp"
    break;

  case 65:
#line 559 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_STATE_ID);
							(yyval.ast_node)->val = (yyvsp[0].string);
						}
#line 3315 "parser.cpp"
    break;

  case 66:
#line 566 "parser.y"
    {
							(yyval.ast_node) = (yyvsp[-1].ast_node);
							(yyvsp[-1].ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3324 "parser.cpp"
    break;

  case 67:
#line 571 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_STATEMENTS_LIST);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3333 "parser.cpp"
    break;

  case 68:
#line 581 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_TIMEOUT);
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
							(yyvsp[-2].token);
						}
#line 3344 "parser.cpp"
    break;

  case 69:
#line 590 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_ICONST);
							(yyval.ast_node)->val = (yyvsp[0].string);
						}
#line 3353 "parser.cpp"
    break;

  case 70:
#line 594 "parser.y"
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 3359 "parser.cpp"
    break;

  case 83:
#line 613 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_RESTART_STATEMENT);
							(yyvsp[-1].token);(yyvsp[0].token);
						}
#line 3368 "parser.cpp"
    break;

  case 84:
#line 620 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_RESET_STATEMENT);
							(yyvsp[-2].token);(yyvsp[-1].token);(yyvsp[0].token);
						}
#line 3377 "parser.cpp"
    break;

  case 85:
#line 627 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_STATE_TRANSITION);
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[-3].token);(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3387 "parser.cpp"
    break;

  case 86:
#line 633 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_NEXT_STATEMENT);
							(yyvsp[-2].token);(yyvsp[-1].token);(yyvsp[0].token);
						}
#line 3396 "parser.cpp"
    break;

  case 87:
#line 640 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_EXPRESSION_STATEMENT);
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[0].token);
						}
#line 3406 "parser.cpp"
    break;

  case 88:
#line 645 "parser.y"
    {(yyval.ast_node) = new ASTNode(ASTNODE_EXPRESSION_STATEMENT);(yyvsp[0].token);}
#line 3412 "parser.cpp"
    break;

  case 89:
#line 650 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_IF_STATEMENT);
							(yyval.ast_node)->children.push_back((yyvsp[-4].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
							(yyvsp[-6].token);(yyvsp[-5].token);(yyvsp[-3].token);(yyvsp[-1].token);
						}
#line 3424 "parser.cpp"
    break;

  case 90:
#line 658 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_IF_STATEMENT);
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
							(yyvsp[-4].token);(yyvsp[-3].token);(yyvsp[-1].token);
						}
#line 3435 "parser.cpp"
    break;

  case 91:
#line 667 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_SWITCH_STATEMENT);
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
							(yyvsp[-4].token);(yyvsp[-3].token);(yyvsp[-1].token);
						}
#line 3446 "parser.cpp"
    break;

  case 92:
#line 676 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_CASE_STATEMENT);
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
							(yyvsp[-3].token);(yyvsp[-1].token);
						}
#line 3457 "parser.cpp"
    break;

  case 93:
#line 690 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_LOOP_STATEMENT);
							(yyvsp[-1].token);(yyvsp[0].token);
						}
#line 3466 "parser.cpp"
    break;

  case 94:
#line 697 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_COMPOUND_STATEMENT);

							///version 1: with statements_list node
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));

							///version 2: without statements_list in AST
							//$$->children.splice($$->children.end(), *$2);
							//delete $2;
							//

							(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3484 "parser.cpp"
    break;

  case 95:
#line 711 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_COMPOUND_STATEMENT);
							(yyvsp[-1].token);(yyvsp[0].token);
						}
#line 3493 "parser.cpp"
    break;

  case 96:
#line 718 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_START_STATEMENT);
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3503 "parser.cpp"
    break;

  case 97:
#line 726 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_STOP_STATEMENT);
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3513 "parser.cpp"
    break;

  case 98:
#line 732 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_STOP_STATEMENT);
							(yyvsp[-1].token);(yyvsp[0].token);
						}
#line 3522 "parser.cpp"
    break;

  case 99:
#line 739 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_ERROR_STATEMENT);
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3532 "parser.cpp"
    break;

  case 100:
#line 745 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_ERROR_STATEMENT);
							(yyvsp[-1].token);(yyvsp[0].token);
						}
#line 3541 "parser.cpp"
    break;

  case 103:
#line 759 "parser.y"
    {
						ASTNode* assignment_op = new ASTNode(ASTNODE_ASSIGNMENT_OP);
						assignment_op->val = (yyvsp[-1].string);

						(yyval.ast_node) = new ASTNode(ASTNODE_ASSIGNMENT_EXPRESSION);
						(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
						(yyval.ast_node)->children.push_back(assignment_op);
						(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
					}
#line 3555 "parser.cpp"
    break;

  case 105:
#line 772 "parser.y"
    {
					ASTNode* binary_op = new ASTNode(ASTNODE_BINARY_OP);
					binary_op->val = (yyvsp[-1].string);

					(yyval.ast_node) = new ASTNode(ASTNODE_BINARY_EXPRESSION);
					(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
					(yyval.ast_node)->children.push_back(binary_op);
					(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
				}
#line 3569 "parser.cpp"
    break;

  case 107:
#line 785 "parser.y"
    {
					ASTNode* unary_op = new ASTNode(ASTNODE_UNARY_OP);
					unary_op->val = (yyvsp[-1].string);

					(yyval.ast_node) = new ASTNode(ASTNODE_UNARY_EXPRESSION);
					(yyval.ast_node)->children.push_back(unary_op);
					(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
				}
#line 3582 "parser.cpp"
    break;

  case 109:
#line 797 "parser.y"
    {
						ASTNode* func_id = new ASTNode(ASTNODE_IDENTIFIER);
						func_id->val = (yyvsp[-2].string);

						(yyval.ast_node) = new ASTNode(ASTNODE_FUNCTION_CALL);
						(yyval.ast_node)->children.push_back(func_id);
						(yyvsp[-1].token);(yyvsp[0].token);
					}
#line 3595 "parser.cpp"
    break;

  case 110:
#line 806 "parser.y"
    {
						ASTNode* func_id = new ASTNode(ASTNODE_IDENTIFIER);
						func_id->val = (yyvsp[-3].string);

						(yyval.ast_node) = new ASTNode(ASTNODE_FUNCTION_CALL);
						(yyval.ast_node)->children.push_back(func_id);
						(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node)); //arg_expr_list
						(yyvsp[-2].token);(yyvsp[0].token);
					}
#line 3609 "parser.cpp"
    break;

  case 111:
#line 816 "parser.y"
    {
						ASTNode* postfix_op = new ASTNode(ASTNODE_POSTFIX_OP);
						postfix_op->val = (yyvsp[0].string);

						(yyval.ast_node) = new ASTNode(ASTNODE_POSTFIX_EXPRESSION);
						(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
						(yyval.ast_node)->children.push_back(postfix_op);
					}
#line 3622 "parser.cpp"
    break;

  case 112:
#line 827 "parser.y"
    {
						(yyval.ast_node) = (yyvsp[-2].ast_node);
						(yyvsp[-2].ast_node)->children.push_back((yyvsp[0].ast_node));
						delete (yyvsp[-1].string);
					}
#line 3632 "parser.cpp"
    break;

  case 113:
#line 833 "parser.y"
    {
						(yyval.ast_node) = new ASTNode(ASTNODE_ARG_EXPR_LIST);
						(yyval.ast_node)->children.push_back((yyvsp[0].ast_node)); 
					}
#line 3641 "parser.cpp"
    break;

  case 114:
#line 840 "parser.y"
    {
						ASTNode* iconst = new ASTNode(ASTNODE_CONST_TERM);
						iconst->val = (yyvsp[0].string);

						(yyval.ast_node) = new ASTNode(ASTNODE_PRIMARY_EXPRESSION);
						(yyval.ast_node)->children.push_back(iconst);
					}
#line 3653 "parser.cpp"
    break;

  case 115:
#line 848 "parser.y"
    {
						ASTNode* fconst = new ASTNode(ASTNODE_CONST_TERM);
						fconst->val = (yyvsp[0].string);

						(yyval.ast_node) = new ASTNode(ASTNODE_PRIMARY_EXPRESSION);
						(yyval.ast_node)->children.push_back(fconst);
					}
#line 3665 "parser.cpp"
    break;

  case 116:
#line 856 "parser.y"
    {
						//$$ = NULL;
						///*
						ASTNode* id = new ASTNode(ASTNODE_IDENTIFIER);
						id->val = (yyvsp[0].string);

						(yyval.ast_node) = new ASTNode(ASTNODE_PRIMARY_EXPRESSION);
						(yyval.ast_node)->children.push_back(id);
						//*/
					}
#line 3680 "parser.cpp"
    break;

  case 117:
#line 867 "parser.y"
    {
						(yyval.ast_node) = new ASTNode(ASTNODE_PRIMARY_EXPRESSION);
						(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
						(yyvsp[-2].token);(yyvsp[0].token);
					}
#line 3690 "parser.cpp"
    break;

  case 118:
#line 873 "parser.y"
    {
						(yyval.ast_node) = new ASTNode(ASTNODE_STOP_CHECK);
						(yyval.ast_node)->children.push_back((yyvsp[-3].ast_node));
						(yyvsp[-4].token);(yyvsp[-2].token);(yyvsp[-1].token);(yyvsp[0].token);
					}
#line 3700 "parser.cpp"
    break;

  case 119:
#line 879 "parser.y"
    {
						(yyval.ast_node) = new ASTNode(ASTNODE_ERROR_CHECK);
						(yyval.ast_node)->children.push_back((yyvsp[-3].ast_node));
						(yyvsp[-4].token);(yyvsp[-2].token);(yyvsp[-1].token);(yyvsp[0].token);
					}
#line 3710 "parser.cpp"
    break;

  case 120:
#line 885 "parser.y"
    {
						(yyval.ast_node) = new ASTNode(ASTNODE_ACTIVE_CHECK);
						(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
						(yyvsp[-3].token);(yyvsp[-1].token);(yyvsp[0].token);
					}
#line 3720 "parser.cpp"
    break;

  case 121:
#line 891 "parser.y"
    {
						(yyval.ast_node) = new ASTNode(ASTNODE_INACTIVE_CHECK);
						(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
						(yyvsp[-3].token);(yyvsp[-1].token);(yyvsp[0].token);
					}
#line 3730 "parser.cpp"
    break;

  case 123:
#line 900 "parser.y"
    {
					ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
					c_type_spec->val = (yyvsp[-2].string);

					(yyval.ast_node) = new ASTNode(ASTNODE_CAST_EXPRESSION);
					(yyval.ast_node)->children.push_back(c_type_spec);
					(yyval.ast_node)->children.push_back((yyvsp[0].ast_node)); //cast_expr
					(yyvsp[-3].token);(yyvsp[-1].token);
				}
#line 3744 "parser.cpp"
    break;

  case 164:
#line 918 "parser.y"
    {(yyval.string) = new std::string(*(yyvsp[-1].string) + " " + *(yyvsp[0].string));delete (yyvsp[-1].string);delete (yyvsp[0].string);}
#line 3750 "parser.cpp"
    break;

  case 171:
#line 931 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_VAR_DEF);
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[0].token);
						}
#line 3761 "parser.cpp"
    break;

  case 172:
#line 938 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_VAR_DEF);
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[0].token);
						}
#line 3772 "parser.cpp"
    break;

  case 173:
#line 948 "parser.y"
    {
							ASTNode* int_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							int_type_spec->val = (yyvsp[-5].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_PHYS_VAR_DEF);
							(yyval.ast_node)->children.push_back(int_type_spec);
							(yyval.ast_node)->children.push_back((yyvsp[-4].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							delete (yyvsp[-3].string);
							(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3788 "parser.cpp"
    break;

  case 174:
#line 962 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_IDENTIFIER);
							(yyval.ast_node)->val = (yyvsp[0].string);
						}
#line 3797 "parser.cpp"
    break;

  case 175:
#line 969 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_IDENTIFIER);
							(yyval.ast_node)->val = (yyvsp[0].string);
						}
#line 3806 "parser.cpp"
    break;

  case 176:
#line 976 "parser.y"
    {
							(yyval.ast_node) = (yyvsp[-2].ast_node);
							(yyvsp[-2].ast_node)->children.push_back((yyvsp[0].ast_node));
							delete (yyvsp[-1].string);
						}
#line 3816 "parser.cpp"
    break;

  case 177:
#line 982 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_REG_BITS_SPEC_LIST);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3825 "parser.cpp"
    break;

  case 178:
#line 989 "parser.y"
    {
							ASTNode* reg_index = new ASTNode(ASTNODE_ICONST);
							reg_index->val = (yyvsp[-1].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_REG_BITS_SPEC);
							(yyval.ast_node)->children.push_back((yyvsp[-3].ast_node));
							(yyval.ast_node)->children.push_back(reg_index);
							(yyvsp[-2].token);(yyvsp[0].token);
						}
#line 3839 "parser.cpp"
    break;

  case 179:
#line 1001 "parser.y"
    {
							ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							c_type_spec->val = (yyvsp[-1].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_CALC_VAR_DEF);
							(yyval.ast_node)->children.push_back(c_type_spec);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3852 "parser.cpp"
    break;

  case 180:
#line 1021 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_SCOPE_SPEC);
							(yyval.ast_node)->val = (yyvsp[0].string);
						}
#line 3861 "parser.cpp"
    break;

  case 181:
#line 1026 "parser.y"
    {
							(yyval.ast_node)=new ASTNode(ASTNODE_SCOPE_SPEC);
							(yyval.ast_node)->val = new std::string(*(yyvsp[-1].string) + " " + *(yyvsp[0].string));
							delete (yyvsp[-1].string);
							delete (yyvsp[0].string);
						}
#line 3872 "parser.cpp"
    break;

  case 182:
#line 1033 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_SCOPE_SPEC);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
							delete (yyvsp[-1].string);
						}
#line 3882 "parser.cpp"
    break;

  case 183:
#line 1041 "parser.y"
    {
							(yyval.ast_node) = (yyvsp[-2].ast_node);
							(yyvsp[-2].ast_node)->children.push_back((yyvsp[0].ast_node));
							delete (yyvsp[-1].string);
						}
#line 3892 "parser.cpp"
    break;

  case 184:
#line 1047 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_PROC_ID_LIST);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3901 "parser.cpp"
    break;

  case 185:
#line 1054 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_VAR_DECL);
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[-4].token);(yyvsp[-3].token);(yyvsp[0].token);
						}
#line 3912 "parser.cpp"
    break;

  case 186:
#line 1063 "parser.y"
    {
							(yyval.ast_node) = (yyvsp[-2].ast_node);
							(yyvsp[-2].ast_node)->children.push_back((yyvsp[0].ast_node));
							delete (yyvsp[-1].string);
						}
#line 3922 "parser.cpp"
    break;

  case 187:
#line 1069 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_VAR_ID_LIST);
							(yyval.ast_node)->children.push_back((yyvsp[0].ast_node));
						}
#line 3931 "parser.cpp"
    break;

  case 188:
#line 1076 "parser.y"
    {
							ASTNode* dir_spec = new ASTNode(ASTNODE_DIR_SPEC);
							dir_spec->val = (yyvsp[-5].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_REGISTER_DEF);
							(yyval.ast_node)->children.push_back(dir_spec);
							(yyval.ast_node)->children.push_back((yyvsp[-4].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-3].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[0].token);
						}
#line 3948 "parser.cpp"
    break;

  case 189:
#line 1089 "parser.y"
    {
							ASTNode* dir_spec = new ASTNode(ASTNODE_DIR_SPEC);
							dir_spec->val = (yyvsp[-5].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_REGISTER_DEF);
							(yyval.ast_node)->children.push_back(dir_spec);
							(yyval.ast_node)->children.push_back((yyvsp[-4].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-3].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-1].ast_node));
							(yyvsp[0].token);
						}
#line 3965 "parser.cpp"
    break;

  case 190:
#line 1103 "parser.y"
    {(yyval.ast_node) = new ASTNode(ASTNODE_REG_ADDR);(yyval.ast_node)->val=(yyvsp[0].string);}
#line 3971 "parser.cpp"
    break;

  case 191:
#line 1104 "parser.y"
    {(yyval.ast_node) = new ASTNode(ASTNODE_REG_SIZE);(yyval.ast_node)->val=(yyvsp[0].string);}
#line 3977 "parser.cpp"
    break;

  case 192:
#line 1108 "parser.y"
    {
							ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							c_type_spec->val = (yyvsp[-5].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_FUNC_DECL);
							(yyval.ast_node)->children.push_back(c_type_spec);
							(yyval.ast_node)->children.push_back((yyvsp[-4].ast_node));
							(yyval.ast_node)->children.push_back((yyvsp[-2].ast_node));
							(yyvsp[-3].token);(yyvsp[-1].token);(yyvsp[0].token);
						}
#line 3992 "parser.cpp"
    break;

  case 193:
#line 1121 "parser.y"
    {
							(yyval.ast_node) = new ASTNode(ASTNODE_IDENTIFIER);
							(yyval.ast_node)->val = (yyvsp[0].string);
						}
#line 4001 "parser.cpp"
    break;

  case 194:
#line 1128 "parser.y"
    {
							ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							c_type_spec->val = (yyvsp[0].string);

							(yyval.ast_node) = (yyvsp[-2].ast_node);
							(yyvsp[-2].ast_node)->children.push_back(c_type_spec);
							delete (yyvsp[-1].string);
						}
#line 4014 "parser.cpp"
    break;

  case 195:
#line 1137 "parser.y"
    {
							ASTNode* c_type_spec = new ASTNode(ASTNODE_TYPE_SPEC);
							c_type_spec->val = (yyvsp[0].string);

							(yyval.ast_node) = new ASTNode(ASTNODE_TYPE_SPEC_LIST);
							(yyval.ast_node)->children.push_back(c_type_spec);
						}
#line 4026 "parser.cpp"
    break;


#line 4030 "parser.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 1146 "parser.y"


int yyerror(const char *s) 
{
	//parser_context->err_msg(s);
	std::cout<<line_num<<": "<<s<<std::endl;
	return 0;
}

