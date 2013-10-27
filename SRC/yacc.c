/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "SRC/yacc.y" /* yacc.c:339  */

  #include "kernel.h"

  extern int yylex(void);
  extern void yyerror(const char *str);
  
  /* Table principale. */
  Hashtable *hashtable;

  /* Données. */
  Array *array;
  Structure *structure;
  

#line 81 "SRC/yacc.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "yacc.h".  */
#ifndef YY_YY_SRC_YACC_H_INCLUDED
# define YY_YY_SRC_YACC_H_INCLUDED
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
    VIDE = 258,
    RAND = 259,
    ECRIRE = 260,
    LIRE = 261,
    CROCHET_OUVRANT = 262,
    CROCHET_FERMANT = 263,
    VIRGULE = 264,
    POINT_VIRGULE = 265,
    POINT = 266,
    PARENTHESE_OUVRANTE = 267,
    PARENTHESE_FERMANTE = 268,
    DEUX_POINTS = 269,
    POINT_ET_POINT = 270,
    INTERROGATION = 271,
    OPAFF = 272,
    PROG = 273,
    ACC_DEBUT = 274,
    ACC_FIN = 275,
    SI = 276,
    ALORS = 277,
    SINON = 278,
    TANT_QUE = 279,
    POUR = 280,
    FAIRE = 281,
    RETOURNE = 282,
    STRUCT = 283,
    FSTRUCT = 284,
    TABLEAU = 285,
    TYPE = 286,
    DE = 287,
    PROCEDURE = 288,
    FONCTION = 289,
    VARIABLE = 290,
    SWITCH = 291,
    CASE = 292,
    DEFAULT = 293,
    ENTIER = 294,
    REEL = 295,
    BOOLEEN = 296,
    CARACTERE = 297,
    CHAINE = 298,
    PLUS = 299,
    MOINS = 300,
    MULTIPLICATION = 301,
    DIVISION = 302,
    MODULO = 303,
    PLUS_ET_PLUS = 304,
    MOINS_ET_MOINS = 305,
    NEGATION = 306,
    PLUS_EGAL = 307,
    MOINS_EGAL = 308,
    MULT_EGAL = 309,
    DIV_EGAL = 310,
    MODULO_EGAL = 311,
    INFERIEUR = 312,
    SUPERIEUR = 313,
    INFERIEUR_OU_EGAL = 314,
    SUPERIEUR_OU_EGAL = 315,
    EGAL = 316,
    DIFFERENT = 317,
    ET = 318,
    OU = 319,
    CONTINUE = 320,
    BREAK = 321,
    START = 322,
    CSTE_ENTIERE = 323,
    CSTE_REELLE = 324,
    CSTE_CARACTERE = 325,
    CSTE_BOOLEENNE = 326,
    CSTE_CHAINE = 327,
    IDF = 328
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "SRC/yacc.y" /* yacc.c:355  */

  int val_i; 
  float val_f; 
  char val_c; 
  char *val_s; 
  Hashkey hkey;
  Syntax_tree *node;

#line 204 "SRC/yacc.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_YACC_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "SRC/yacc.c" /* yacc.c:358  */

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   143,   144,   145,   152,   153,   156,   157,
     158,   159,   162,   170,   184,   187,   188,   191,   204,   205,
     208,   221,   224,   228,   238,   241,   244,   245,   246,   249,
     250,   253,   260,   261,   264,   265,   266,   267,   268,   275,
     278,   279,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   295,   296,   298,   306,   307,   310,   311,
     312,   315,   316,   317,   318,   321,   322,   323,   324,   325,
     328,   331,   333,   334,   341,   343,   345,   353,   357,   359,
     363,   366,   367,   370,   371,   374,   382,   390,   394,   397,
     400,   402,   406,   407,   408,   415,   418,   419,   422,   423,
     426,   433,   436,   437,   444,   445,   452,   453,   456,   458,
     460,   462,   463,   466,   468,   470,   472,   474,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   491,   492,   493,   496,   499,   500,   501,   502,   503,
     504
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VIDE", "RAND", "ECRIRE", "LIRE",
  "CROCHET_OUVRANT", "CROCHET_FERMANT", "VIRGULE", "POINT_VIRGULE",
  "POINT", "PARENTHESE_OUVRANTE", "PARENTHESE_FERMANTE", "DEUX_POINTS",
  "POINT_ET_POINT", "INTERROGATION", "OPAFF", "PROG", "ACC_DEBUT",
  "ACC_FIN", "SI", "ALORS", "SINON", "TANT_QUE", "POUR", "FAIRE",
  "RETOURNE", "STRUCT", "FSTRUCT", "TABLEAU", "TYPE", "DE", "PROCEDURE",
  "FONCTION", "VARIABLE", "SWITCH", "CASE", "DEFAULT", "ENTIER", "REEL",
  "BOOLEEN", "CARACTERE", "CHAINE", "PLUS", "MOINS", "MULTIPLICATION",
  "DIVISION", "MODULO", "PLUS_ET_PLUS", "MOINS_ET_MOINS", "NEGATION",
  "PLUS_EGAL", "MOINS_EGAL", "MULT_EGAL", "DIV_EGAL", "MODULO_EGAL",
  "INFERIEUR", "SUPERIEUR", "INFERIEUR_OU_EGAL", "SUPERIEUR_OU_EGAL",
  "EGAL", "DIFFERENT", "ET", "OU", "CONTINUE", "BREAK", "START",
  "CSTE_ENTIERE", "CSTE_REELLE", "CSTE_CARACTERE", "CSTE_BOOLEENNE",
  "CSTE_CHAINE", "IDF", "$accept", "programme", "corps",
  "liste_declarations", "declaration", "declaration_type", "dimension",
  "liste_dimensions", "une_dimension", "liste_champs", "un_champ",
  "declaration_variable", "declaration_suite_variable",
  "declaration_procedure", "declaration_fonction", "liste_parametres",
  "liste_param", "un_param", "nom_type", "type_simple",
  "liste_instructions", "suite_liste_inst", "instruction", "instr_pre",
  "affectation", "affectation_base", "incr_bin", "op_rac", "variable",
  "suite_variable", "condition", "tant_que", "pour", "pour_cont", "pour_a",
  "pour_e", "faire_tant_que", "ternaire", "switch", "suite_switch",
  "default", "appel", "liste_arguments", "liste_args", "un_arg", "format",
  "suite_ecriture", "liste_variables", "resultat_retourne", "expression",
  "expression2", "expression3", "test", "test_comp", YY_NULL
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
     325,   326,   327,   328
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,     8,    40,    -2,     6,    24,    30,    37,  -158,    73,
     105,  -158,  -158,  -158,  -158,  -158,   104,   127,   127,    22,
    -158,   174,  -158,    37,   126,  -158,    17,     3,     8,   129,
      30,   298,  -158,   152,   160,   161,  -158,   120,   120,    -1,
      37,   120,   120,    68,    68,   135,    60,  -158,   164,   166,
    -158,  -158,   265,  -158,  -158,  -158,  -158,  -158,   171,  -158,
    -158,   110,   178,  -158,   172,    15,  -158,  -158,   327,  -158,
    -158,  -158,  -158,  -158,   180,  -158,  -158,  -158,   181,   125,
      68,   120,     0,   120,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,    80,  -158,   329,    65,  -158,  -158,   350,   -29,    23,
    -158,   170,   192,   179,   196,   358,    -7,  -158,  -158,   120,
     134,   216,  -158,  -158,  -158,  -158,  -158,  -158,   120,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,   120,  -158,   194,   -15,
     199,   146,   185,   298,   157,  -158,     8,   168,  -158,  -158,
     231,  -158,   114,   212,   265,   239,   246,  -158,  -158,  -158,
    -158,    37,   120,   120,  -158,  -158,  -158,  -158,  -158,  -158,
     120,   120,   120,   120,   120,   120,    37,   240,    37,   120,
     120,  -158,   217,   211,    23,  -158,   154,  -158,   358,  -158,
     320,   358,   298,  -158,   250,  -158,   248,   140,  -158,   298,
    -158,  -158,  -158,   256,   120,   261,    68,  -158,  -158,  -158,
    -158,   120,   253,    65,    65,    65,    65,  -158,  -158,  -158,
    -158,  -158,   251,  -158,   268,   358,   235,   120,   124,    23,
    -158,   120,  -158,  -158,  -158,   215,  -158,   146,  -158,  -158,
      93,  -158,  -158,   267,    69,    37,   -29,  -158,   288,   120,
     284,   280,  -158,  -158,  -158,  -158,  -158,   120,  -158,  -158,
    -158,  -158,    95,   299,    95,  -158,   358,  -158,  -158,    95,
    -158,  -158,  -158,  -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     8,     9,    10,    11,     1,     0,    26,    26,     0,
      21,     0,     4,     0,     0,     6,     0,     0,     5,     0,
       0,     0,    50,     0,     0,     0,    42,     0,     0,    82,
       0,   106,     0,     0,     0,    73,     0,    40,     0,     0,
      56,    57,     0,    44,    45,    46,    47,    48,     0,     3,
       7,     0,     0,    27,     0,     0,    29,    24,     0,    23,
      34,    35,    36,    37,     0,    33,    22,    32,     0,     0,
       0,     0,     0,     0,   119,   120,   121,   122,   123,   127,
     128,   129,   126,     0,   111,   117,   112,     0,    82,    73,
      81,     0,     0,     0,     0,   107,     0,    63,    64,     0,
       0,     0,    70,    95,    39,    41,    52,    43,     0,    61,
      62,    65,    66,    67,    68,    69,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    28,     5,     0,    53,   101,
     103,   105,     0,     0,   129,     0,     0,   124,   125,   130,
     133,     0,     0,     0,   135,   137,   136,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    51,     0,     0,    73,    96,     0,    98,   100,    59,
      58,    60,     0,    13,     0,    18,     0,     0,    15,     0,
      31,    30,    25,     0,     0,     0,     0,    55,   131,   132,
     118,     0,    74,   108,   109,   110,   134,   113,   114,   115,
     116,    77,     0,    78,     0,    83,     0,     0,    94,    73,
      72,     0,    97,    20,    19,     0,    14,     0,    12,    38,
     103,    54,   104,     0,     0,     0,    82,    85,     0,     0,
       0,     0,    71,    99,    17,    16,   102,     0,    75,    76,
      79,    80,     0,     0,     0,    87,    86,    90,    91,     0,
      92,    93,    88,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,   -19,  -158,   292,  -158,  -158,  -158,    82,  -158,
     187,  -158,   293,  -158,  -158,   304,  -158,   200,  -100,   262,
      -8,  -158,   -41,   -17,   -31,   254,   -20,  -158,   -21,  -157,
     108,  -158,  -158,   255,   118,  -158,  -158,   237,  -158,  -158,
    -158,   -11,  -158,  -158,   141,  -158,   142,  -158,  -158,   -35,
      97,   -70,  -158,  -158
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,   132,   187,   188,   129,
     130,    12,    20,    13,    14,    28,    65,    66,    76,    77,
      22,    46,    47,    89,    49,    50,    90,   126,    91,   112,
      53,    54,    55,   101,   102,   214,    56,   145,    57,   218,
     241,    92,   113,   176,   177,   140,   195,   142,   104,   178,
      94,    95,    96,   161
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      52,    51,    93,    97,    48,   115,   105,   106,   100,    67,
      58,    98,   172,   150,   183,    59,    63,   220,    52,    51,
      43,    44,   107,   108,   134,    52,    51,     1,   135,    48,
     109,    30,   103,   190,   110,    58,    31,   152,   153,     3,
      15,     4,     5,     6,    99,    61,   146,    62,    43,    44,
     154,   155,   156,   157,   158,   159,    21,   160,   128,   141,
     144,   149,   242,    32,    33,    34,    35,   100,   147,   148,
      36,    16,    99,    99,   173,     7,    64,    52,    51,    17,
     114,    37,   223,   180,    38,    39,    40,    41,    21,   228,
      37,   181,   207,   208,   209,   210,    42,    18,    32,    33,
      34,    35,   194,    19,     3,    36,     4,     5,     6,    43,
      44,   162,   163,   164,    21,    25,    37,   192,    26,    38,
      39,    40,    41,   196,    33,    34,    35,   197,   165,   119,
     120,    42,    81,    45,   215,   216,    60,   152,   153,    27,
      23,    99,   109,   202,    43,    44,   110,   111,   226,   227,
     154,   155,   156,   157,   158,   159,    68,   160,   211,   230,
     213,   239,   240,   221,    78,    82,   233,   222,    45,    43,
      44,    83,    79,    80,   116,   232,   117,    32,    33,    34,
      35,   127,   238,   128,    36,   131,   133,   137,    84,    85,
      86,    87,    88,    45,   138,    37,   168,   139,    38,    39,
      40,    41,   169,   170,   253,   100,   171,   174,   182,   185,
      42,   258,   256,   261,   186,    52,    51,   189,   263,   219,
      33,    34,    35,    43,    44,   198,   248,   250,    81,   175,
      64,    52,    51,    52,    51,    48,   193,    48,    52,    51,
     194,    58,    48,    58,   257,   237,   260,    45,    58,   203,
     204,   262,   199,   212,   217,   152,   153,   205,   206,   200,
     224,    82,   201,   225,   229,    43,    44,    83,   154,   155,
     156,   157,   158,   159,   231,   160,   234,   235,   236,   152,
     153,   247,   118,   244,    84,    85,    86,    87,    88,    45,
     152,   153,   154,   155,   156,   157,   158,   159,   254,   160,
     255,    24,   252,   154,   155,   156,   157,   158,   159,   245,
     160,   152,   153,   259,   119,   120,   184,   121,   122,   123,
     124,   125,    29,    69,   154,   155,   156,   157,   158,   159,
     136,   160,   152,   153,   191,   143,   201,    70,    71,    72,
      73,    74,   249,   152,   153,   154,   155,   156,   157,   158,
     159,   151,   160,   167,   251,   179,   154,   155,   156,   157,
     158,   159,   243,   160,   152,   153,    70,    71,    72,    73,
      74,    75,   246,   152,   153,     0,   166,   154,   155,   156,
     157,   158,   159,     0,   160,     0,   154,   155,   156,   157,
     158,   159,     0,   160,   152,   153,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,     0,   154,   155,   156,
     157,   158,   159,     0,   160,   154,   155,   156,   157,   158,
     159,     0,   160
};

static const yytype_int16 yycheck[] =
{
      21,    21,    37,    38,    21,    46,    41,    42,    39,    28,
      21,    12,    19,    83,    29,    23,    13,   174,    39,    39,
      49,    50,    43,    44,     9,    46,    46,    18,    13,    46,
       7,     9,    40,   133,    11,    46,    14,    44,    45,    31,
       0,    33,    34,    35,    73,    28,    81,    30,    49,    50,
      57,    58,    59,    60,    61,    62,    19,    64,    73,    80,
      81,    82,   219,     3,     4,     5,     6,    98,    68,    69,
      10,    73,    73,    73,   109,    67,    73,    98,    98,    73,
      20,    21,   182,   118,    24,    25,    26,    27,    19,   189,
      21,   126,   162,   163,   164,   165,    36,    73,     3,     4,
       5,     6,     9,    73,    31,    10,    33,    34,    35,    49,
      50,    46,    47,    48,    19,    10,    21,   136,    14,    24,
      25,    26,    27,     9,     4,     5,     6,    13,    63,    49,
      50,    36,    12,    73,   169,   170,    10,    44,    45,    12,
      67,    73,     7,   151,    49,    50,    11,    12,     8,     9,
      57,    58,    59,    60,    61,    62,    27,    64,   166,   194,
     168,    37,    38,     9,    12,    45,   201,    13,    73,    49,
      50,    51,    12,    12,    10,   196,    10,     3,     4,     5,
       6,    10,   217,    73,    10,     7,    14,     7,    68,    69,
      70,    71,    72,    73,    13,    21,    26,    72,    24,    25,
      26,    27,    10,    24,   239,   236,    10,    73,    14,    10,
      36,   252,   247,   254,    68,   236,   236,    32,   259,     8,
       4,     5,     6,    49,    50,    13,   234,   235,    12,    13,
      73,   252,   252,   254,   254,   252,    68,   254,   259,   259,
       9,   252,   259,   254,   252,    10,   254,    73,   259,   152,
     153,   259,    13,    13,    37,    44,    45,   160,   161,    13,
      10,    45,    16,    15,     8,    49,    50,    51,    57,    58,
      59,    60,    61,    62,    13,    64,    23,    26,    10,    44,
      45,    14,    17,    68,    68,    69,    70,    71,    72,    73,
      44,    45,    57,    58,    59,    60,    61,    62,    14,    64,
      20,     9,    14,    57,    58,    59,    60,    61,    62,   227,
      64,    44,    45,    14,    49,    50,   129,    52,    53,    54,
      55,    56,    18,    30,    57,    58,    59,    60,    61,    62,
      68,    64,    44,    45,   134,    81,    16,    39,    40,    41,
      42,    43,   234,    44,    45,    57,    58,    59,    60,    61,
      62,    22,    64,    98,   236,   118,    57,    58,    59,    60,
      61,    62,   221,    64,    44,    45,    39,    40,    41,    42,
      43,    73,   230,    44,    45,    -1,    26,    57,    58,    59,
      60,    61,    62,    -1,    64,    -1,    57,    58,    59,    60,
      61,    62,    -1,    64,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    -1,    64,    57,    58,    59,    60,    61,
      62,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    75,    31,    33,    34,    35,    67,    76,    77,
      78,    79,    85,    87,    88,     0,    73,    73,    73,    73,
      86,    19,    94,    67,    78,    10,    14,    12,    89,    89,
       9,    14,     3,     4,     5,     6,    10,    21,    24,    25,
      26,    27,    36,    49,    50,    73,    95,    96,    97,    98,
      99,   100,   102,   104,   105,   106,   110,   112,   115,    94,
      10,    28,    30,    13,    73,    90,    91,    76,    27,    86,
      39,    40,    41,    42,    43,    73,    92,    93,    12,    12,
      12,    12,    45,    51,    68,    69,    70,    71,    72,    97,
     100,   102,   115,   123,   124,   125,   126,   123,    12,    73,
      98,   107,   108,    94,   122,   123,   123,   102,   102,     7,
      11,    12,   103,   116,    20,    96,    10,    10,    17,    49,
      50,    52,    53,    54,    55,    56,   101,    10,    73,    83,
      84,     7,    80,    14,     9,    13,    93,     7,    13,    72,
     119,   102,   121,    99,   102,   111,   123,    68,    69,   102,
     125,    22,    44,    45,    57,    58,    59,    60,    61,    62,
      64,   127,    46,    47,    48,    63,    26,   107,    26,    10,
      24,    10,    19,   123,    73,    13,   117,   118,   123,   111,
     123,   123,    14,    29,    84,    10,    68,    81,    82,    32,
      92,    91,    76,    68,     9,   120,     9,    13,    13,    13,
      13,    16,    94,   124,   124,   124,   124,   125,   125,   125,
     125,    94,    13,    94,   109,   123,   123,    37,   113,     8,
     103,     9,    13,    92,    10,    15,     8,     9,    92,     8,
     123,    13,   102,   123,    23,    26,    10,    10,   123,    37,
      38,   114,   103,   118,    68,    82,   120,    14,    94,   104,
      94,   108,    14,   123,    14,    20,   123,    94,    96,    14,
      94,    96,    94,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    79,    79,    80,    81,    81,    82,    83,    83,
      84,    85,    86,    86,    87,    88,    89,    89,    89,    90,
      90,    91,    92,    92,    93,    93,    93,    93,    93,    94,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    98,    98,    99,    99,
      99,   100,   100,   100,   100,   101,   101,   101,   101,   101,
     102,   103,   103,   103,   104,   104,   104,   105,   106,   106,
     107,   108,   108,   109,   109,   110,   111,   112,   113,   113,
     113,   113,   114,   114,   114,   115,   116,   116,   117,   117,
     118,   119,   120,   120,   121,   121,   122,   122,   123,   123,
     123,   123,   123,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   127,   127,   127,   127,   127,
     127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     0,     2,     3,     1,     1,
       1,     1,     7,     6,     3,     1,     3,     3,     2,     3,
       3,     2,     3,     3,     4,     6,     0,     2,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     4,     3,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       1,     3,     2,     3,     5,     4,     1,     1,     3,     3,
       3,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     4,     3,     0,     4,     6,     6,     4,     4,     6,
       5,     1,     0,     1,     0,     5,     5,     6,     5,     5,
       4,     4,     3,     3,     0,     2,     2,     3,     1,     3,
       1,     1,     3,     0,     3,     1,     0,     1,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     3,     3,     2,     3,     1,     1,     1,     1,     1,
       1
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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
#line 139 "SRC/yacc.y" /* yacc.c:1646  */
    {if(regions_table_add(0, 0, (yyvsp[0].node)) == BAD_REGION) 
		         fatal_error("regions_table");}
#line 1518 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 3:
#line 143 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1524 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 4:
#line 144 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1530 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 5:
#line 145 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1536 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 12:
#line 162 "SRC/yacc.y" /* yacc.c:1646  */
    {if((array = array_new(dimensions_buffer_get_size(), (yyvsp[0].hkey))) == NULL)
									fatal_error("array_new");
								      dimensions_buffer_copy(array->dimension);
					                              dimensions_buffer_reset();

								      if(!symbol_table_add(hashtable, (yyvsp[-5].hkey), SYMBOL_TYPE_ARRAY, 0, array, 0))
									fatal_error("symbol_table_add");
                                                                     }
#line 1549 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 13:
#line 170 "SRC/yacc.y" /* yacc.c:1646  */
    {if((structure = structure_new(variables_buffer_get_size())) == NULL)
		                                                        fatal_error("structure_new");
                                                                      variables_buffer_copy(structure->field);
								      variables_buffer_reset();

								      if(!symbol_table_add(hashtable, (yyvsp[-4].hkey), SYMBOL_TYPE_STRUCT, 0, structure, 0))
									fatal_error("symbol_table_add");
                                                                     }
#line 1562 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 17:
#line 191 "SRC/yacc.y" /* yacc.c:1646  */
    {if(dimensions_buffer_push((yyvsp[-2].val_i), (yyvsp[0].val_i)) == -1)
                                                         {
							   fprintf(stderr, "Error: The buffer has reached its limit (%d)\n", 
								   MAX_DIMENSIONS_BUFFER_SIZE);
							   exit(EXIT_FAILURE);
							 }
                                                        }
#line 1574 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 20:
#line 208 "SRC/yacc.y" /* yacc.c:1646  */
    {if(variables_buffer_push((yyvsp[-2].hkey), (yyvsp[0].hkey)) == -1)
                                    {
				      fprintf(stderr, "Error: The buffer has reached its limit (%d)\n", 
					      MAX_VARIABLES_BUFFER_SIZE);
				      exit(EXIT_FAILURE);
				    }
                                   }
#line 1586 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 22:
#line 224 "SRC/yacc.y" /* yacc.c:1646  */
    {if(!symbol_table_add(hashtable, (yyvsp[-2].hkey), SYMBOL_TYPE_VAR, 
											 regions_stack_top(), (yyvsp[0].hkey), 0))
                                                                      fatal_error("symbol_table_add");
                                                                    (yyval.hkey) = (yyvsp[0].hkey);}
#line 1595 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 23:
#line 228 "SRC/yacc.y" /* yacc.c:1646  */
    {if(!symbol_table_add(hashtable, (yyvsp[-2].hkey), SYMBOL_TYPE_VAR, 
											 regions_stack_top(), (yyvsp[0].hkey), 0))
                                                                      fatal_error("symbol_table_add");
                                                                    (yyval.hkey) = (yyvsp[0].hkey);}
#line 1604 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 31:
#line 253 "SRC/yacc.y" /* yacc.c:1646  */
    {variables_buffer_push((yyvsp[-2].hkey), symbol_table_get(hashtable, (yyvsp[0].hkey), regions_stack_top()));}
#line 1610 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 32:
#line 260 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = (yyvsp[0].hkey);}
#line 1616 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 33:
#line 261 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = (yyvsp[0].hkey);}
#line 1622 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 34:
#line 264 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_INT;}
#line 1628 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 35:
#line 265 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_FLOAT;}
#line 1634 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 36:
#line 266 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_BOOL;}
#line 1640 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 37:
#line 267 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_CHAR;}
#line 1646 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 38:
#line 268 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_CHAR;}
#line 1652 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 39:
#line 275 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1658 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 40:
#line 278 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1664 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 41:
#line 279 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1670 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 42:
#line 282 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1676 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1682 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 44:
#line 284 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1688 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 45:
#line 285 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1694 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 46:
#line 286 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1700 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 47:
#line 287 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1706 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 48:
#line 288 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1712 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 49:
#line 289 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1718 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 50:
#line 290 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1724 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 51:
#line 291 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_RETURN), (yyvsp[-1].node));}
#line 1730 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 52:
#line 292 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1736 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 53:
#line 295 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_FUN_READ);}
#line 1742 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 54:
#line 296 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_FUN_WRITE), 
													  syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[-1].node)));}
#line 1749 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 55:
#line 298 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_FUN_READ), 
													  (yyvsp[-1].node));}
#line 1756 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 56:
#line 306 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1762 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 57:
#line 307 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1768 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 58:
#line 310 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1774 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 59:
#line 311 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1780 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 60:
#line 312 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[-1].val_i)), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1786 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 61:
#line 315 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_INC), (yyvsp[-1].node));}
#line 1792 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 62:
#line 316 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_DEC), (yyvsp[-1].node));}
#line 1798 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 63:
#line 317 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PINC), (yyvsp[0].node));}
#line 1804 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 64:
#line 318 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PDEC), (yyvsp[0].node));}
#line 1810 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 65:
#line 321 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_PLUSE;}
#line 1816 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 66:
#line 322 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MINE;}
#line 1822 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 67:
#line 323 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MULTE;}
#line 1828 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 68:
#line 324 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_DIVE;}
#line 1834 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 69:
#line 325 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MODE;}
#line 1840 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 70:
#line 328 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_VAR), (yyvsp[0].node));}
#line 1846 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 71:
#line 331 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_son(
									        syntax_tree_node_new(AT_ARRAY_INDEX), (yyvsp[-2].node)), (yyvsp[0].node));}
#line 1853 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 72:
#line 333 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_node_hkey_new((yyvsp[-1].hkey)), (yyvsp[0].node));}
#line 1859 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 73:
#line 334 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1865 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 74:
#line 341 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF),
                                                                                 syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1872 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 75:
#line 343 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF_ELSE),
	     			       					         syntax_tree_add_brother((yyvsp[-4].node), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 1879 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 76:
#line 345 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF_ELSE),
									         syntax_tree_add_brother((yyvsp[-4].node), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 1886 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 77:
#line 353 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_WHILE), 
                                                                                 syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1893 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 78:
#line 357 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_FOR),
                                                                                           syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1900 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 79:
#line 359 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_FOR),
                                                                                           syntax_tree_add_brother((yyvsp[-3].node), (yyvsp[0].node)));}
#line 1907 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 80:
#line 363 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node));}
#line 1913 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 81:
#line 366 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1919 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 82:
#line 367 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1925 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 83:
#line 370 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1931 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 84:
#line 371 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1937 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 85:
#line 374 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DO_WHILE),
                                                                                                     syntax_tree_add_brother((yyvsp[-3].node), (yyvsp[-1].node)));}
#line 1944 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 86:
#line 382 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_TERNAIRE),
                                                                           syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node)));}
#line 1951 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 87:
#line 390 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_SWITCH),
                                                                       syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[-1].node)));}
#line 1958 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 88:
#line 394 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-4].node), 
                                                                                syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE),
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 1966 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 89:
#line 397 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-4].node), 
                                                                                syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE),
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 1974 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 90:
#line 400 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE), 
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1981 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 91:
#line 402 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE), 
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1988 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 92:
#line 406 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DEFAULT), (yyvsp[0].node));}
#line 1994 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 93:
#line 407 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DEFAULT), (yyvsp[0].node));}
#line 2000 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 94:
#line 408 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 2006 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 95:
#line 415 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CALL), (yyvsp[0].node));}
#line 2012 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 96:
#line 418 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 2018 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 97:
#line 419 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2024 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 98:
#line 422 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2030 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 99:
#line 423 "SRC/yacc.y" /* yacc.c:1646  */
    {syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2036 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 100:
#line 426 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2042 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 101:
#line 433 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[0].val_s));}
#line 2048 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 102:
#line 436 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-1].node), (yyvsp[0].node));}
#line 2054 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 103:
#line 437 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 2060 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 104:
#line 444 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2066 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 105:
#line 445 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2072 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 106:
#line 452 "SRC/yacc.y" /* yacc.c:1646  */
    {syntax_tree_node_new(AT_EMPTY);}
#line 2078 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 107:
#line 453 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2084 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 108:
#line 456 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_PLUS), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2091 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 109:
#line 458 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2098 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 110:
#line 460 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_OR), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2105 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 111:
#line 462 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2111 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 112:
#line 463 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2117 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 113:
#line 466 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MULT), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2124 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 114:
#line 468 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_DIV), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2131 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 115:
#line 470 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MOD), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2138 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 116:
#line 472 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_AND), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2145 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 117:
#line 474 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2151 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 118:
#line 477 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2157 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 119:
#line 478 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_int_new((yyvsp[0].val_i));}
#line 2163 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 120:
#line 479 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_float_new((yyvsp[0].val_f));}
#line 2169 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 121:
#line 480 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_char_new((yyvsp[0].val_c));}
#line 2175 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 122:
#line 481 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_bool_new((yyvsp[0].val_c));}
#line 2181 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 123:
#line 482 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[0].val_s));}
#line 2187 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 124:
#line 483 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_int_new(-(yyvsp[0].val_i));}
#line 2193 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 125:
#line 484 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_float_new(-(yyvsp[0].val_f));}
#line 2199 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 126:
#line 485 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2205 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 127:
#line 486 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2211 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 128:
#line 487 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2217 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 129:
#line 488 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2223 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 130:
#line 489 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
                                                           syntax_tree_add_brother(syntax_tree_node_int_new(0), (yyvsp[0].node)));}
#line 2230 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 131:
#line 491 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2236 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 132:
#line 492 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2242 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 133:
#line 493 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_NOT), (yyvsp[0].node));}
#line 2248 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 134:
#line 496 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[-1].val_i)), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2254 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 135:
#line 499 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_L;}
#line 2260 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 136:
#line 500 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_LE;}
#line 2266 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 137:
#line 501 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_G;}
#line 2272 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 138:
#line 502 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_GE;}
#line 2278 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 139:
#line 503 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_E;}
#line 2284 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 140:
#line 504 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_NE;}
#line 2290 "SRC/yacc.c" /* yacc.c:1646  */
    break;


#line 2294 "SRC/yacc.c" /* yacc.c:1646  */
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
#line 507 "SRC/yacc.y" /* yacc.c:1906  */

