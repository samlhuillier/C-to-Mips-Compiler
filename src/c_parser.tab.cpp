/* A Bison parser, made by GNU Bison 3.5.3.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/c_parser.y"

  #include "ast.hpp"

  #include <cassert>

  extern TreeNode* g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *);

#line 126 "src/c_parser.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_PP = 259,
    T_PE = 260,
    T_MM = 261,
    T_ME = 262,
    T_DE = 263,
    T_TE = 264,
    T_MODE = 265,
    T_AE = 266,
    T_OE = 267,
    T_RSE = 268,
    T_LSE = 269,
    T_XE = 270,
    T_ASSIGN = 271,
    T_BAND = 272,
    T_BOR = 273,
    T_NOT = 274,
    T_XOR = 275,
    T_LESS = 276,
    T_GREAT = 277,
    T_LAND = 278,
    T_LOR = 279,
    T_ARS = 280,
    T_ALS = 281,
    T_TWOLESS = 282,
    T_TWOGREAT = 283,
    T_LESSEQUAL = 284,
    T_GREATEQUAL = 285,
    T_TIMES = 286,
    T_DIVIDE = 287,
    T_PLUS = 288,
    T_MINUS = 289,
    T_MOD = 290,
    T_LBRACKET = 291,
    T_RBRACKET = 292,
    T_OPEN = 293,
    T_CLOSE = 294,
    T_COMMA = 295,
    T_LSQ = 296,
    T_RSQ = 297,
    T_COLON = 298,
    T_DOT = 299,
    T_NUMBER = 300,
    T_VARIABLE = 301,
    T_IF = 302,
    T_ELSE = 303,
    T_EOL = 304,
    T_RETURN = 305,
    T_WHILE = 306,
    T_FOR = 307,
    T_BREAK = 308,
    T_CONT = 309,
    T_SWITCH = 310,
    T_CASE = 311,
    T_DEFAULT = 312,
    T_VOID = 313,
    T_UNSIGNED = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "src/c_parser.y"

  TreeNode* node;
  std::string *string;

#line 202 "src/c_parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

#define YYUNDEFTOK  2
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    40,    41,    42,    43,    44,    45,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      87,    88,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   128,
     129,   130,   131,   132,   134,   135,   136,   137,   146,   148,
     149,   154,   155,   157,   158,   161,   162,   164,   165,   167,
     168,   170,   171,   172,   174,   175,   176,   178,   179,   180,
     181,   182,   186,   187,   188,   190,   191,   192,   193,   195,
     196,   198,   199,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_PP", "T_PE", "T_MM", "T_ME",
  "T_DE", "T_TE", "T_MODE", "T_AE", "T_OE", "T_RSE", "T_LSE", "T_XE",
  "T_ASSIGN", "T_BAND", "T_BOR", "T_NOT", "T_XOR", "T_LESS", "T_GREAT",
  "T_LAND", "T_LOR", "T_ARS", "T_ALS", "T_TWOLESS", "T_TWOGREAT",
  "T_LESSEQUAL", "T_GREATEQUAL", "T_TIMES", "T_DIVIDE", "T_PLUS",
  "T_MINUS", "T_MOD", "T_LBRACKET", "T_RBRACKET", "T_OPEN", "T_CLOSE",
  "T_COMMA", "T_LSQ", "T_RSQ", "T_COLON", "T_DOT", "T_NUMBER",
  "T_VARIABLE", "T_IF", "T_ELSE", "T_EOL", "T_RETURN", "T_WHILE", "T_FOR",
  "T_BREAK", "T_CONT", "T_SWITCH", "T_CASE", "T_DEFAULT", "T_VOID",
  "T_UNSIGNED", "$accept", "ROOT", "FUNCTIONS", "FUNCT", "LINES", "LINE",
  "AN_UNSIGNED", "SWITCH_BODY", "LINE2", "FINALPARAMS", "PARAMS", "E1",
  "E12", "E21", "E2", "E3", "E4", "C1", "C2", "EXPR", "TERM", "UNARY",
  "IDK", "FACTOR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF (-156)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,   -44,    23,     7,    74,    70,  -156,    65,    38,    53,
     363,    84,  -156,  -156,  -156,   167,   363,    11,   170,    65,
      72,    69,   186,   220,   156,   363,  -156,    15,   -12,   228,
     255,   270,   291,   169,    98,   328,   201,   236,  -156,  -156,
      17,   123,    24,   126,    -6,   264,   200,   279,   289,  -156,
      28,  -156,  -156,  -156,  -156,  -156,    39,  -156,  -156,    -1,
     363,   363,    65,   363,   363,   363,   363,   363,   363,   296,
     303,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     227,    28,  -156,   295,    28,  -156,    65,   298,    28,  -156,
    -156,   287,   -21,   313,   248,   306,   363,   329,   330,   321,
     323,   344,   342,    28,   339,    -2,  -156,  -156,   206,    88,
     228,  -156,   255,   270,   291,   169,    98,    98,   363,   363,
     201,   201,   201,   201,   236,   236,  -156,  -156,  -156,    28,
    -156,   347,    28,   354,  -156,   392,   359,    65,   356,    -3,
     384,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   152,   363,   363,    16,   363,    28,  -156,  -156,   363,
    -156,  -156,   387,  -156,  -156,   363,  -156,   328,   328,   366,
    -156,   368,  -156,  -156,  -156,  -156,    -8,   363,   365,  -156,
     363,    67,    73,    79,    95,   101,   102,   103,   105,   124,
     147,   367,   150,   194,   129,  -156,   139,    28,   213,   363,
     245,  -156,  -156,   394,  -156,   158,   372,   160,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,   369,  -156,
     396,    54,   174,   370,   379,   182,  -156,   363,   373,  -156,
     371,  -156,  -156,   363,    28,   374,   241,  -156,   175,   386,
     397,   -33,  -156,   277,   375,  -156,   190,   388,   275,  -156,
     389,   363,   363,   301,   380,   383,   390,  -156,   363,  -156,
    -156,   382,    28,  -156,  -156,   397,   198,    28,  -156,   391,
      28,  -156,   278,   337,   393,   415,   398,    28,  -156,  -156,
     363,    28,  -156,  -156,   363,  -156,   -33,   397,   128,   399,
     397,  -156,  -156,   363,  -156,   397
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    59,     0,     2,     3,     0,     0,
       0,     0,    60,     1,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,     0,    71,
      73,    75,    77,    79,    81,    84,    87,    92,    95,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
      39,    13,   113,   114,   117,   100,     0,   115,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    14,     0,    39,    19,     0,    70,    39,    15,
      68,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,   111,   105,     0,     0,
      72,     7,    74,    76,    78,    80,    83,    82,     0,     0,
      88,    90,    89,    91,    93,    94,    96,    97,    98,    39,
      16,     0,    39,     0,     6,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    43,    42,     0,
       9,    20,     0,    25,   106,     0,   112,    85,    86,     0,
      10,     0,    17,    69,    11,     5,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    39,     0,     0,
       0,    12,    18,     0,    55,     0,     0,     0,    44,    45,
      47,    46,    48,    51,    49,    53,    52,    50,     0,    23,
     112,    39,    39,    67,     0,     0,   107,     0,     0,    22,
       0,    58,    57,     0,    39,    31,     0,    28,   104,     0,
      65,     0,    24,     0,     0,    37,     0,     0,    39,    30,
       0,     0,     0,    39,     0,     0,     0,   108,     0,    56,
      38,    34,    39,    32,    29,    64,     0,    39,    40,     0,
      39,    54,     0,    39,     0,   112,     0,    39,    63,   109,
       0,    39,    35,    33,     0,    41,    62,   101,     0,     0,
      66,    61,   110,     0,    36,   102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,    10,  -156,   -77,  -155,     9,   149,  -156,   288,
     304,   -10,   381,   377,   385,   376,   378,   230,   205,   290,
     269,   300,  -156,   409
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,   102,   103,   104,   256,   239,    20,
      47,   105,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   288,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,   197,     9,    21,   131,    22,    44,   133,   203,     8,
     138,   136,    61,   177,    45,    56,     8,    14,    61,    57,
      45,    58,    61,   254,   255,   139,   161,    45,     8,    49,
      23,    92,    21,    24,    22,    25,   107,    62,   178,    10,
      61,   204,   223,    86,    26,    27,   179,   163,    46,   108,
     109,    59,   169,    11,    80,   171,    60,    92,    21,    93,
      22,    83,    24,    61,    25,   195,   235,   237,     1,    16,
      13,     8,   111,    26,    94,    95,   106,    12,    96,    97,
      98,    99,   100,   101,    15,    93,   154,     4,    24,    17,
      25,    61,   234,   263,    18,     8,   134,    61,   268,    26,
      94,    95,    19,    61,    96,    97,    98,    99,   100,   101,
      50,     2,    61,     4,    69,    52,   208,    70,   282,    61,
      40,    51,   209,     3,     4,    61,    61,    61,   210,    61,
     166,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   192,   193,   194,   211,   196,     8,   175,    61,   198,
     212,   213,   214,    61,   215,   200,    21,   247,    22,   250,
      21,    81,    22,    61,    84,   292,   221,   205,   293,   191,
     207,    61,    82,   216,    61,    85,   222,    92,    21,    57,
      22,    58,    61,    23,    61,   274,    24,    23,    25,   225,
     276,   251,    25,   278,    67,    68,   217,    26,    27,   219,
     286,    26,    27,    42,   289,    93,    61,   229,    24,   231,
      25,    59,   236,   240,    61,    48,   252,   243,    61,    26,
      94,    95,    61,   246,    96,    97,    98,    99,   100,   101,
      61,   242,    53,     4,    75,    76,   220,    61,    88,   260,
     275,   265,   266,   164,    92,    21,   165,    22,   272,    89,
     224,    63,    57,   141,    58,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   129,    54,    77,    78,    61,
     287,    79,    93,    64,   290,    24,   130,    25,    92,    21,
     249,    22,   226,   295,    59,   227,    26,    94,    95,   152,
      65,    96,    97,    98,    99,   100,   101,   116,   117,    41,
       4,    61,    61,    43,    92,    21,    93,    22,    66,    24,
      87,    25,   118,   262,   257,   279,    90,   258,   280,   119,
      26,    94,    95,   167,   168,    96,    97,    98,    99,   100,
     101,    91,    93,   132,     4,    24,   137,    25,   135,   267,
      92,    21,   153,    22,   124,   125,    26,    94,    95,    71,
      72,    96,    97,    98,    99,   100,   101,    73,    74,   140,
       4,   120,   121,   122,   123,   155,   156,    21,    93,    22,
     157,    24,   158,    25,    21,   281,    22,   126,   127,   128,
     159,   160,    26,    94,    95,   162,   170,    96,    97,    98,
      99,   100,   101,   172,    23,    45,     4,    24,   174,    25,
     180,    23,   176,   199,    24,   201,    25,   202,    26,    27,
     206,   228,   233,   218,   230,    26,   238,   241,   232,   244,
     245,    61,   248,   253,   259,   269,   270,   261,   264,   271,
     273,   284,   283,    55,   277,   291,     0,   285,   294,   173,
     112,   114,   110,     0,   115,     0,     0,     0,     0,   113
};

static const yytype_int16 yycheck[] =
{
      10,   156,    46,     4,    81,     6,    16,    84,    16,     0,
      31,    88,    24,    16,     3,    25,     7,     7,    24,     4,
       3,     6,    24,    56,    57,    46,   103,     3,    19,    19,
      31,     3,     4,    34,     6,    36,    37,    49,    41,    16,
      24,    49,   197,    49,    45,    46,    49,    49,    37,    59,
      60,    36,   129,    46,    37,   132,    41,     3,     4,    31,
       6,    37,    34,    24,    36,    49,   221,   222,     3,    16,
       0,    62,    62,    45,    46,    47,    37,     3,    50,    51,
      52,    53,    54,    55,    46,    31,    96,    59,    34,    36,
      36,    24,    38,   248,    41,    86,    86,    24,   253,    45,
      46,    47,    49,    24,    50,    51,    52,    53,    54,    55,
      38,    46,    24,    59,    16,    46,    49,    19,   273,    24,
      36,    49,    49,    58,    59,    24,    24,    24,    49,    24,
      42,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    49,   155,   137,   137,    24,   159,
      49,    49,    49,    24,    49,   165,     4,   234,     6,   236,
       4,    38,     6,    24,    38,    37,    37,   177,    40,    17,
     180,    24,    49,    49,    24,    49,    37,     3,     4,     4,
       6,     6,    24,    31,    24,   262,    34,    31,    36,   199,
     267,    16,    36,   270,    25,    26,    49,    45,    46,    49,
     277,    45,    46,    36,   281,    31,    24,    49,    34,    49,
      36,    36,    38,   223,    24,    45,    41,   227,    24,    45,
      46,    47,    24,   233,    50,    51,    52,    53,    54,    55,
      24,    49,    46,    59,    33,    34,    42,    24,    38,    49,
      42,   251,   252,    37,     3,     4,    40,     6,   258,    49,
      37,    23,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    38,    46,    31,    32,    24,
     280,    35,    31,    18,   284,    34,    49,    36,     3,     4,
      39,     6,    37,   293,    36,    40,    45,    46,    47,    41,
      20,    50,    51,    52,    53,    54,    55,    67,    68,    11,
      59,    24,    24,    15,     3,     4,    31,     6,    17,    34,
      46,    36,    16,    38,    37,    37,    37,    40,    40,    16,
      45,    46,    47,   118,   119,    50,    51,    52,    53,    54,
      55,    42,    31,    38,    59,    34,    49,    36,    40,    38,
       3,     4,    36,     6,    75,    76,    45,    46,    47,    21,
      22,    50,    51,    52,    53,    54,    55,    29,    30,    46,
      59,    71,    72,    73,    74,    36,    36,     4,    31,     6,
      49,    34,    49,    36,     4,    38,     6,    77,    78,    79,
      36,    39,    45,    46,    47,    46,    39,    50,    51,    52,
      53,    54,    55,    39,    31,     3,    59,    34,    39,    36,
      16,    31,    46,    16,    34,    39,    36,    39,    45,    46,
      45,    17,    16,    46,    42,    45,    46,    38,    49,    46,
      49,    24,    48,    37,    49,    45,    43,    39,    39,    39,
      48,    16,    39,    24,    43,   286,    -1,    39,    39,   135,
      63,    65,    61,    -1,    66,    -1,    -1,    -1,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,    58,    59,    61,    62,    63,    66,    46,
      16,    46,     3,     0,    62,    46,    16,    36,    41,    49,
      69,     4,     6,    31,    34,    36,    45,    46,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    83,
      36,    69,    36,    69,    71,     3,    37,    70,    45,    62,
      38,    49,    46,    46,    46,    83,    71,     4,     6,    36,
      41,    24,    49,    23,    18,    20,    17,    25,    26,    16,
      19,    21,    22,    29,    30,    33,    34,    31,    32,    35,
      37,    38,    49,    37,    38,    49,    49,    46,    38,    49,
      37,    42,     3,    31,    46,    47,    50,    51,    52,    53,
      54,    55,    64,    65,    66,    71,    37,    37,    71,    71,
      72,    62,    73,    74,    75,    76,    77,    77,    16,    16,
      79,    79,    79,    79,    80,    80,    81,    81,    81,    38,
      49,    64,    38,    64,    62,    40,    64,    49,    31,    46,
      46,     5,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    41,    36,    71,    36,    36,    49,    49,    36,
      39,    64,    46,    49,    37,    40,    42,    78,    78,    64,
      39,    64,    39,    70,    39,    62,    46,    16,    41,    49,
      16,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    17,    71,    71,    71,    49,    71,    65,    71,    16,
      71,    39,    39,    16,    49,    71,    45,    71,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    46,    49,
      42,    37,    37,    65,    37,    71,    37,    40,    17,    49,
      42,    49,    49,    16,    38,    65,    38,    65,    46,    68,
      71,    38,    49,    71,    46,    49,    71,    64,    48,    39,
      64,    16,    41,    37,    56,    57,    67,    37,    40,    49,
      49,    39,    38,    65,    39,    71,    71,    38,    65,    45,
      43,    39,    71,    48,    64,    42,    64,    43,    64,    37,
      40,    38,    65,    39,    16,    39,    64,    71,    82,    64,
      71,    67,    37,    40,    39,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    77,    77,    77,    78,    78,    78,
      78,    78,    79,    79,    79,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     7,     6,     5,     4,     6,
       6,     7,     7,     4,     4,     5,     5,     6,     7,     4,
       2,     1,     5,     4,     5,     2,     3,     3,     5,     7,
       6,     5,     7,     9,     7,     9,    11,     6,     7,     0,
       7,     9,     2,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     7,     4,     7,     5,     5,     1,
       2,     5,     4,     3,     3,     1,     6,     0,     3,     4,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     4,     4,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     1,     3,     1,     1,     3,     4,     6,     8,    10,
      12,     3,     4,     2,     2,     2,     2,     2
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 38 "src/c_parser.y"
                 { g_root = (yyvsp[0].node); }
#line 1598 "src/c_parser.tab.cpp"
    break;

  case 3:
#line 40 "src/c_parser.y"
                                                                  { (yyval.node) = new Body(NULL, (yyvsp[0].node), true); }
#line 1604 "src/c_parser.tab.cpp"
    break;

  case 4:
#line 41 "src/c_parser.y"
                                                                  { (yyval.node) = new Body((yyvsp[0].node), (yyvsp[-1].node)); }
#line 1610 "src/c_parser.tab.cpp"
    break;

  case 5:
#line 42 "src/c_parser.y"
                                                                  { (yyval.node) = new Body((yyvsp[0].node), new GlobArray(*(yyvsp[-5].string), *(yyvsp[-3].string))); }
#line 1616 "src/c_parser.tab.cpp"
    break;

  case 6:
#line 43 "src/c_parser.y"
                                                                             { (yyval.node) = new Body((yyvsp[0].node), new Assign(*(yyvsp[-4].string), (yyvsp[-2].node), NULL,true)); }
#line 1622 "src/c_parser.tab.cpp"
    break;

  case 7:
#line 44 "src/c_parser.y"
                                                                           { (yyval.node) = new Body((yyvsp[0].node), new Assign(*(yyvsp[-4].string), (yyvsp[-2].node), NULL,true)); }
#line 1628 "src/c_parser.tab.cpp"
    break;

  case 8:
#line 45 "src/c_parser.y"
                                            { (yyval.node) = new Body((yyvsp[0].node), new Assign(*(yyvsp[-2].string), new Primitive(0, "0", NULL, NULL, NULL, NULL, NULL), NULL, true)); }
#line 1634 "src/c_parser.tab.cpp"
    break;

  case 9:
#line 63 "src/c_parser.y"
                                                                          { (yyval.node) = new Function(*(yyvsp[-4].string), (yyvsp[-1].node), (yyvsp[-3].node)); }
#line 1640 "src/c_parser.tab.cpp"
    break;

  case 10:
#line 64 "src/c_parser.y"
                                                                           { (yyval.node) = new Function(*(yyvsp[-4].string), (yyvsp[-1].node), (yyvsp[-3].node)); }
#line 1646 "src/c_parser.tab.cpp"
    break;

  case 11:
#line 65 "src/c_parser.y"
                                                                                    { (yyval.node) = new Function(*(yyvsp[-5].string), (yyvsp[-1].node), NULL); }
#line 1652 "src/c_parser.tab.cpp"
    break;

  case 12:
#line 66 "src/c_parser.y"
                                                                                     { (yyval.node) = new Function(*(yyvsp[-5].string), (yyvsp[-1].node), NULL); }
#line 1658 "src/c_parser.tab.cpp"
    break;

  case 13:
#line 67 "src/c_parser.y"
                                                                                                                                                                                { (yyval.node) = new Nothing();}
#line 1664 "src/c_parser.tab.cpp"
    break;

  case 14:
#line 68 "src/c_parser.y"
                                                                                                                                                                                 { (yyval.node) = new Nothing();}
#line 1670 "src/c_parser.tab.cpp"
    break;

  case 15:
#line 69 "src/c_parser.y"
                                                                                                                                                                                          { (yyval.node) = new Nothing();}
#line 1676 "src/c_parser.tab.cpp"
    break;

  case 16:
#line 70 "src/c_parser.y"
                                                                                                                                                                                           { (yyval.node) = new Nothing();}
#line 1682 "src/c_parser.tab.cpp"
    break;

  case 17:
#line 71 "src/c_parser.y"
                                                                                { (yyval.node) = new Function(*(yyvsp[-4].string), (yyvsp[-1].node), (yyvsp[-3].node)); }
#line 1688 "src/c_parser.tab.cpp"
    break;

  case 18:
#line 72 "src/c_parser.y"
                                                                                          { (yyval.node) = new Function(*(yyvsp[-5].string), (yyvsp[-1].node), NULL); }
#line 1694 "src/c_parser.tab.cpp"
    break;

  case 19:
#line 73 "src/c_parser.y"
                                                                                                                                                                                      { (yyval.node) = new Nothing();}
#line 1700 "src/c_parser.tab.cpp"
    break;

  case 20:
#line 87 "src/c_parser.y"
                                                  { (yyval.node) = new Body((yyvsp[0].node), (yyvsp[-1].node)); }
#line 1706 "src/c_parser.tab.cpp"
    break;

  case 21:
#line 88 "src/c_parser.y"
                                                  { (yyval.node) = new Body(NULL, (yyvsp[0].node)); }
#line 1712 "src/c_parser.tab.cpp"
    break;

  case 22:
#line 90 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), (yyvsp[-1].node), NULL); }
#line 1718 "src/c_parser.tab.cpp"
    break;

  case 23:
#line 91 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), (yyvsp[-1].node), NULL); }
#line 1724 "src/c_parser.tab.cpp"
    break;

  case 24:
#line 92 "src/c_parser.y"
                                                                                         { (yyval.node) = new Assign(*(yyvsp[-3].string), (yyvsp[-1].node), NULL, false, "unsigned"); }
#line 1730 "src/c_parser.tab.cpp"
    break;

  case 25:
#line 93 "src/c_parser.y"
                                                                                        { (yyval.node) = (yyvsp[-1].node); }
#line 1736 "src/c_parser.tab.cpp"
    break;

  case 26:
#line 94 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-1].string), new Primitive(0, "0", NULL, NULL, NULL, NULL, NULL), NULL); }
#line 1742 "src/c_parser.tab.cpp"
    break;

  case 27:
#line 95 "src/c_parser.y"
                                                                                        { (yyval.node) = new Return((yyvsp[-1].node)); }
#line 1748 "src/c_parser.tab.cpp"
    break;

  case 28:
#line 96 "src/c_parser.y"
                                                                                        { (yyval.node) = new While((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1754 "src/c_parser.tab.cpp"
    break;

  case 29:
#line 97 "src/c_parser.y"
                                                                                        { (yyval.node) = new While((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1760 "src/c_parser.tab.cpp"
    break;

  case 30:
#line 98 "src/c_parser.y"
                                                                                        { (yyval.node) = new While((yyvsp[-3].node), NULL); }
#line 1766 "src/c_parser.tab.cpp"
    break;

  case 31:
#line 99 "src/c_parser.y"
                                                                                        { (yyval.node) = new If((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1772 "src/c_parser.tab.cpp"
    break;

  case 32:
#line 100 "src/c_parser.y"
                                                                                        { (yyval.node) = new If((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1778 "src/c_parser.tab.cpp"
    break;

  case 33:
#line 101 "src/c_parser.y"
                                                                                        { (yyval.node) = new If((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1784 "src/c_parser.tab.cpp"
    break;

  case 34:
#line 102 "src/c_parser.y"
                                                                                        { (yyval.node) = new If((yyvsp[-4].node), (yyvsp[-1].node), NULL); }
#line 1790 "src/c_parser.tab.cpp"
    break;

  case 35:
#line 103 "src/c_parser.y"
                                                                                        { (yyval.node) = new If((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[0].node)); }
#line 1796 "src/c_parser.tab.cpp"
    break;

  case 36:
#line 104 "src/c_parser.y"
                                                                                        { (yyval.node) = new If((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node)); }
#line 1802 "src/c_parser.tab.cpp"
    break;

  case 37:
#line 105 "src/c_parser.y"
                                                                                        { (yyval.node) = new Array(*(yyvsp[-4].string), *(yyvsp[-2].string)); }
#line 1808 "src/c_parser.tab.cpp"
    break;

  case 38:
#line 106 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-6].string), (yyvsp[-1].node), (yyvsp[-4].node)); }
#line 1814 "src/c_parser.tab.cpp"
    break;

  case 39:
#line 107 "src/c_parser.y"
                                                                                        { (yyval.node) = new Nothing(); }
#line 1820 "src/c_parser.tab.cpp"
    break;

  case 40:
#line 108 "src/c_parser.y"
                                                                                        { (yyval.node) = new For((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1826 "src/c_parser.tab.cpp"
    break;

  case 41:
#line 109 "src/c_parser.y"
                                                                                        { (yyval.node) = new For((yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1832 "src/c_parser.tab.cpp"
    break;

  case 42:
#line 110 "src/c_parser.y"
                                                                                        { (yyval.node) = new Continue(); }
#line 1838 "src/c_parser.tab.cpp"
    break;

  case 43:
#line 111 "src/c_parser.y"
                                                                                        { (yyval.node) = new Break(); }
#line 1844 "src/c_parser.tab.cpp"
    break;

  case 44:
#line 112 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new AddOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1850 "src/c_parser.tab.cpp"
    break;

  case 45:
#line 113 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new SubOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1856 "src/c_parser.tab.cpp"
    break;

  case 46:
#line 114 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new MultOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1862 "src/c_parser.tab.cpp"
    break;

  case 47:
#line 115 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new DivOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1868 "src/c_parser.tab.cpp"
    break;

  case 48:
#line 116 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new ModOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1874 "src/c_parser.tab.cpp"
    break;

  case 49:
#line 117 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new BorOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1880 "src/c_parser.tab.cpp"
    break;

  case 50:
#line 118 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new XorOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1886 "src/c_parser.tab.cpp"
    break;

  case 51:
#line 119 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new BandOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1892 "src/c_parser.tab.cpp"
    break;

  case 52:
#line 120 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new ALSOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1898 "src/c_parser.tab.cpp"
    break;

  case 53:
#line 121 "src/c_parser.y"
                                                                                        { (yyval.node) = new Assign(*(yyvsp[-3].string), new ARSOperator(new Primitive(1, *(yyvsp[-3].string), NULL, NULL, NULL, NULL, NULL), (yyvsp[-1].node)), NULL); }
#line 1904 "src/c_parser.tab.cpp"
    break;

  case 54:
#line 122 "src/c_parser.y"
                                                                                        { (yyval.node) = new Switch((yyvsp[-1].node), (yyvsp[-4].node)); }
#line 1910 "src/c_parser.tab.cpp"
    break;

  case 55:
#line 123 "src/c_parser.y"
                                                                                        { (yyval.node) = new Nothing(); }
#line 1916 "src/c_parser.tab.cpp"
    break;

  case 56:
#line 124 "src/c_parser.y"
                                                                                        { (yyval.node) = new Pointer(*(yyvsp[-4].string), *(yyvsp[-1].string)); }
#line 1922 "src/c_parser.tab.cpp"
    break;

  case 57:
#line 125 "src/c_parser.y"
                                                                                        { (yyval.node) = new Pointer(*(yyvsp[-4].string), *(yyvsp[-1].string)); }
#line 1928 "src/c_parser.tab.cpp"
    break;

  case 58:
#line 126 "src/c_parser.y"
                                                                                        { (yyval.node) = new PAss(*(yyvsp[-3].string), (yyvsp[-1].node)); }
#line 1934 "src/c_parser.tab.cpp"
    break;

  case 59:
#line 128 "src/c_parser.y"
                         {;}
#line 1940 "src/c_parser.tab.cpp"
    break;

  case 60:
#line 129 "src/c_parser.y"
                               {;}
#line 1946 "src/c_parser.tab.cpp"
    break;

  case 61:
#line 130 "src/c_parser.y"
                                                                                        { (yyval.node) = new SwitchBody((yyvsp[0].node), (yyvsp[-1].node), *(yyvsp[-3].string)); }
#line 1952 "src/c_parser.tab.cpp"
    break;

  case 62:
#line 131 "src/c_parser.y"
                                                                                        { (yyval.node) = new SwitchBody(NULL, (yyvsp[0].node), *(yyvsp[-2].string)); }
#line 1958 "src/c_parser.tab.cpp"
    break;

  case 63:
#line 132 "src/c_parser.y"
                                                                                        { (yyval.node) = new SwitchBody(NULL, (yyvsp[0].node), ""); }
#line 1964 "src/c_parser.tab.cpp"
    break;

  case 64:
#line 134 "src/c_parser.y"
                                                                                   { (yyval.node) = new Assign(*(yyvsp[-2].string), (yyvsp[0].node), NULL); }
#line 1970 "src/c_parser.tab.cpp"
    break;

  case 65:
#line 135 "src/c_parser.y"
                                                                                   { (yyval.node) = (yyvsp[0].node); }
#line 1976 "src/c_parser.tab.cpp"
    break;

  case 66:
#line 136 "src/c_parser.y"
                                                                                   { (yyval.node) = new Assign(*(yyvsp[-5].string) + "[0]", (yyvsp[0].node), (yyvsp[-3].node)); }
#line 1982 "src/c_parser.tab.cpp"
    break;

  case 67:
#line 137 "src/c_parser.y"
                                                                                   { (yyval.node) = new Nothing(); }
#line 1988 "src/c_parser.tab.cpp"
    break;

  case 68:
#line 146 "src/c_parser.y"
                                           {(yyval.node) = (yyvsp[-1].node);}
#line 1994 "src/c_parser.tab.cpp"
    break;

  case 69:
#line 148 "src/c_parser.y"
                                                  { (yyval.node) = new Paramset((yyvsp[0].node), new PAR(*(yyvsp[-2].string))); }
#line 2000 "src/c_parser.tab.cpp"
    break;

  case 70:
#line 149 "src/c_parser.y"
                                       { (yyval.node) = new Paramset(NULL, new PAR(*(yyvsp[0].string)) ); }
#line 2006 "src/c_parser.tab.cpp"
    break;

  case 71:
#line 154 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2012 "src/c_parser.tab.cpp"
    break;

  case 72:
#line 155 "src/c_parser.y"
                                                  { (yyval.node) = new LorOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2018 "src/c_parser.tab.cpp"
    break;

  case 73:
#line 157 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2024 "src/c_parser.tab.cpp"
    break;

  case 74:
#line 158 "src/c_parser.y"
                                                  { (yyval.node) = new LandOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2030 "src/c_parser.tab.cpp"
    break;

  case 75:
#line 161 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2036 "src/c_parser.tab.cpp"
    break;

  case 76:
#line 162 "src/c_parser.y"
                                                  { (yyval.node) = new BorOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2042 "src/c_parser.tab.cpp"
    break;

  case 77:
#line 164 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2048 "src/c_parser.tab.cpp"
    break;

  case 78:
#line 165 "src/c_parser.y"
                                                  { (yyval.node) = new XorOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2054 "src/c_parser.tab.cpp"
    break;

  case 79:
#line 167 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2060 "src/c_parser.tab.cpp"
    break;

  case 80:
#line 168 "src/c_parser.y"
                                                  { (yyval.node) = new BandOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2066 "src/c_parser.tab.cpp"
    break;

  case 81:
#line 170 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2072 "src/c_parser.tab.cpp"
    break;

  case 82:
#line 171 "src/c_parser.y"
                                                  { (yyval.node) = new ALSOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2078 "src/c_parser.tab.cpp"
    break;

  case 83:
#line 172 "src/c_parser.y"
                                                  { (yyval.node) = new ARSOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2084 "src/c_parser.tab.cpp"
    break;

  case 84:
#line 174 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2090 "src/c_parser.tab.cpp"
    break;

  case 85:
#line 175 "src/c_parser.y"
                                                  { (yyval.node) = new EqualOperator((yyvsp[-3].node), (yyvsp[0].node)); }
#line 2096 "src/c_parser.tab.cpp"
    break;

  case 86:
#line 176 "src/c_parser.y"
                                                  { (yyval.node) = new NequalOperator((yyvsp[-3].node), (yyvsp[0].node)); }
#line 2102 "src/c_parser.tab.cpp"
    break;

  case 87:
#line 178 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2108 "src/c_parser.tab.cpp"
    break;

  case 88:
#line 179 "src/c_parser.y"
                                                  { (yyval.node) = new LessOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2114 "src/c_parser.tab.cpp"
    break;

  case 89:
#line 180 "src/c_parser.y"
                                              { (yyval.node) = new LequalOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2120 "src/c_parser.tab.cpp"
    break;

  case 90:
#line 181 "src/c_parser.y"
                                                  { (yyval.node) = new GreatOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2126 "src/c_parser.tab.cpp"
    break;

  case 91:
#line 182 "src/c_parser.y"
                                              { (yyval.node) = new GequalOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2132 "src/c_parser.tab.cpp"
    break;

  case 92:
#line 186 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2138 "src/c_parser.tab.cpp"
    break;

  case 93:
#line 187 "src/c_parser.y"
                                                  { (yyval.node) = new AddOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2144 "src/c_parser.tab.cpp"
    break;

  case 94:
#line 188 "src/c_parser.y"
                                                  { (yyval.node) = new SubOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2150 "src/c_parser.tab.cpp"
    break;

  case 95:
#line 190 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2156 "src/c_parser.tab.cpp"
    break;

  case 96:
#line 191 "src/c_parser.y"
                                                  { (yyval.node) = new MultOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2162 "src/c_parser.tab.cpp"
    break;

  case 97:
#line 192 "src/c_parser.y"
                                                  { (yyval.node) = new DivOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2168 "src/c_parser.tab.cpp"
    break;

  case 98:
#line 193 "src/c_parser.y"
                                                  { (yyval.node) = new ModOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2174 "src/c_parser.tab.cpp"
    break;

  case 99:
#line 195 "src/c_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2180 "src/c_parser.tab.cpp"
    break;

  case 100:
#line 196 "src/c_parser.y"
                                                  { (yyval.node) = new NegOp((yyvsp[0].node)); }
#line 2186 "src/c_parser.tab.cpp"
    break;

  case 101:
#line 198 "src/c_parser.y"
                                                  { (yyval.node) = new Idk((yyvsp[0].node)); }
#line 2192 "src/c_parser.tab.cpp"
    break;

  case 102:
#line 199 "src/c_parser.y"
                                                  { (yyval.node) = new Exprset((yyvsp[-2].node), new Idk((yyvsp[0].node))); }
#line 2198 "src/c_parser.tab.cpp"
    break;

  case 103:
#line 201 "src/c_parser.y"
                                                                              { (yyval.node) = new Primitive(0, *(yyvsp[0].string), NULL, NULL, NULL, NULL, NULL); }
#line 2204 "src/c_parser.tab.cpp"
    break;

  case 104:
#line 202 "src/c_parser.y"
                                                                              { (yyval.node) = new Primitive(1, *(yyvsp[0].string), NULL, NULL, NULL, NULL, NULL); }
#line 2210 "src/c_parser.tab.cpp"
    break;

  case 105:
#line 203 "src/c_parser.y"
                                                                              { (yyval.node) = new Primitive(2, *(yyvsp[-2].string), NULL, NULL, NULL, NULL, NULL); }
#line 2216 "src/c_parser.tab.cpp"
    break;

  case 106:
#line 204 "src/c_parser.y"
                                                                              { (yyval.node) = new Primitive(2, *(yyvsp[-3].string), (yyvsp[-1].node), NULL, NULL, NULL, NULL); }
#line 2222 "src/c_parser.tab.cpp"
    break;

  case 107:
#line 205 "src/c_parser.y"
                                                                              { (yyval.node) = new Primitive(2, *(yyvsp[-5].string), (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL, NULL); }
#line 2228 "src/c_parser.tab.cpp"
    break;

  case 108:
#line 206 "src/c_parser.y"
                                                                              { (yyval.node) = new Primitive(2, *(yyvsp[-7].string), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL); }
#line 2234 "src/c_parser.tab.cpp"
    break;

  case 109:
#line 207 "src/c_parser.y"
                                                                              { (yyval.node) = new Primitive(2, *(yyvsp[-9].string), (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL); }
#line 2240 "src/c_parser.tab.cpp"
    break;

  case 110:
#line 208 "src/c_parser.y"
                                                                                          { (yyval.node) = new Primitive(2, *(yyvsp[-11].string), (yyvsp[-9].node), (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2246 "src/c_parser.tab.cpp"
    break;

  case 111:
#line 209 "src/c_parser.y"
                                                                              { (yyval.node) = (yyvsp[-1].node); }
#line 2252 "src/c_parser.tab.cpp"
    break;

  case 112:
#line 210 "src/c_parser.y"
                                                                              { (yyval.node) = new Primitive(1, *(yyvsp[-3].string), (yyvsp[-1].node), NULL, NULL, NULL, NULL); }
#line 2258 "src/c_parser.tab.cpp"
    break;

  case 113:
#line 211 "src/c_parser.y"
                                                                              { (yyval.node) = new Body(new Primitive(1, *(yyvsp[0].string), NULL, NULL, NULL, NULL, NULL), new Assign(*(yyvsp[0].string), new AddOperator(new Primitive(1, *(yyvsp[0].string), NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
#line 2264 "src/c_parser.tab.cpp"
    break;

  case 114:
#line 212 "src/c_parser.y"
                                                                              { (yyval.node) = new Body(new Primitive(1, *(yyvsp[0].string), NULL, NULL, NULL, NULL, NULL), new Assign(*(yyvsp[0].string), new SubOperator(new Primitive(1, *(yyvsp[0].string), NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
#line 2270 "src/c_parser.tab.cpp"
    break;

  case 115:
#line 213 "src/c_parser.y"
                                                                              { (yyval.node) = new Body(new SubOperator(new Primitive(1, *(yyvsp[-1].string), NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), new Assign(*(yyvsp[-1].string), new AddOperator(new Primitive(1, *(yyvsp[-1].string), NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
#line 2276 "src/c_parser.tab.cpp"
    break;

  case 116:
#line 214 "src/c_parser.y"
                                                                              { (yyval.node) = new Body(new AddOperator(new Primitive(1, *(yyvsp[-1].string), NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), new Assign(*(yyvsp[-1].string), new SubOperator(new Primitive(1, *(yyvsp[-1].string), NULL, NULL, NULL, NULL, NULL), new Primitive(0, "1", NULL, NULL, NULL, NULL, NULL)), NULL)); }
#line 2282 "src/c_parser.tab.cpp"
    break;

  case 117:
#line 215 "src/c_parser.y"
                                                                              { (yyval.node) = new Deref(*(yyvsp[0].string)); }
#line 2288 "src/c_parser.tab.cpp"
    break;


#line 2292 "src/c_parser.tab.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 235 "src/c_parser.y"


TreeNode* g_root; // Definition of variable (to match declaration earlier)

TreeNode* parseAST(char* input_file)
{
  g_root = 0;
  yyin = fopen(input_file, "r");
  if (yyin){
    yyparse();
  }

  fclose(yyin);
  return g_root;
}
