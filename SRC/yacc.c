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
  extern void yyerror(const char *txt);
  
  Hashtable *hashtable;

#line 75 "SRC/yacc.c" /* yacc.c:339  */

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
#line 11 "SRC/yacc.y" /* yacc.c:355  */

  int val_i; 
  float val_f; 
  char val_c; 
  char *val_s; 
  Hashkey hkey;
  Syntax_tree *node;

#line 198 "SRC/yacc.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_YACC_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "SRC/yacc.c" /* yacc.c:358  */

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
#define YYLAST   468

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

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
       0,   133,   133,   136,   137,   138,   145,   146,   149,   150,
     151,   152,   155,   158,   159,   166,   169,   170,   173,   180,
     181,   184,   191,   194,   195,   202,   205,   208,   209,   210,
     213,   214,   217,   224,   225,   228,   229,   230,   231,   232,
     239,   242,   243,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   259,   260,   262,   270,   271,   274,
     275,   276,   279,   280,   281,   282,   285,   286,   287,   288,
     289,   292,   295,   297,   298,   305,   307,   309,   317,   321,
     323,   327,   330,   331,   334,   335,   338,   346,   354,   358,
     361,   364,   366,   370,   371,   372,   379,   382,   383,   386,
     387,   390,   397,   400,   401,   408,   409,   416,   417,   420,
     422,   424,   426,   427,   430,   432,   434,   436,   438,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   455,   456,   457,   460,   463,   464,   465,   466,
     467,   468
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
  "liste_declarations", "declaration", "declaration_type",
  "suite_declaration_type", "dimension", "liste_dimensions",
  "une_dimension", "liste_champs", "un_champ", "declaration_variable",
  "declaration_suite_variable", "declaration_procedure",
  "declaration_fonction", "liste_parametres", "liste_param", "un_param",
  "nom_type", "type_simple", "liste_instructions", "suite_liste_inst",
  "instruction", "instr_pre", "affectation", "affectation_base",
  "incr_bin", "op_rac", "variable", "suite_variable", "condition",
  "tant_que", "pour", "pour_cont", "pour_a", "pour_e", "faire_tant_que",
  "ternaire", "switch", "suite_switch", "default", "appel",
  "liste_arguments", "liste_args", "un_arg", "format", "suite_ecriture",
  "liste_variables", "resultat_retourne", "expression", "expression2",
  "expression3", "test", "test_comp", YY_NULL
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

#define YYPACT_NINF -155

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-155)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    10,    31,   -37,   -34,   -14,    -6,    69,  -155,    52,
      81,  -155,  -155,  -155,  -155,  -155,    90,    86,    86,  -155,
      19,   104,  -155,    69,   114,  -155,    28,     0,    10,   107,
      66,   109,  -155,   129,   143,   146,  -155,   249,   249,    -1,
      69,   249,   249,    95,    95,   126,    96,  -155,   160,   161,
    -155,  -155,   401,  -155,  -155,  -155,  -155,  -155,   162,  -155,
    -155,   100,   167,  -155,  -155,   170,    21,  -155,  -155,   123,
    -155,  -155,  -155,  -155,  -155,   168,  -155,  -155,  -155,   173,
     115,    95,   249,    74,   249,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,    63,  -155,   383,    17,  -155,  -155,   220,   -33,
      35,  -155,   163,   178,   166,   181,   404,    -7,  -155,  -155,
     249,   122,   217,  -155,  -155,  -155,  -155,  -155,  -155,   249,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,   249,  -155,   183,
      -2,   188,   249,   171,   109,   131,  -155,    10,   139,  -155,
    -155,   199,  -155,    61,   196,   401,   197,   289,  -155,  -155,
    -155,  -155,    69,   249,   249,  -155,  -155,  -155,  -155,  -155,
    -155,   249,   249,   249,   249,   249,   249,    69,   202,    69,
     249,   249,  -155,   189,   212,    35,  -155,   102,  -155,   404,
    -155,   372,   404,   109,  -155,   208,  -155,   118,  -155,   350,
     109,  -155,  -155,  -155,   223,   249,   224,    95,  -155,  -155,
    -155,  -155,   249,   218,    17,    17,    17,    17,  -155,  -155,
    -155,  -155,  -155,   225,  -155,   240,   404,   281,   249,   119,
      35,  -155,   249,  -155,  -155,  -155,  -155,   249,   249,  -155,
    -155,   251,  -155,  -155,   310,    84,    69,   -33,  -155,   318,
     249,   244,   239,  -155,  -155,  -155,   404,  -155,   249,  -155,
    -155,  -155,  -155,   175,   342,   175,  -155,   404,  -155,  -155,
     175,  -155,  -155,  -155,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     8,     9,    10,    11,     1,     0,    27,    27,    23,
       0,     0,     4,     0,     0,     6,     0,     0,     5,     0,
       0,     0,    51,     0,     0,     0,    43,     0,     0,    83,
       0,   107,     0,     0,     0,    74,     0,    41,     0,     0,
      57,    58,     0,    45,    46,    47,    48,    49,     0,     3,
       7,     0,     0,    12,    28,     0,     0,    30,    25,     0,
      24,    35,    36,    37,    38,     0,    34,    22,    33,     0,
       0,     0,     0,     0,     0,   120,   121,   122,   123,   124,
     128,   129,   130,   127,     0,   112,   118,   113,     0,    83,
      74,    82,     0,     0,     0,     0,   108,     0,    64,    65,
       0,     0,     0,    71,    96,    40,    42,    53,    44,     0,
      62,    63,    66,    67,    68,    69,    70,     0,    50,     0,
       0,     0,     0,     0,     0,     0,    29,     5,     0,    54,
     102,   104,   106,     0,     0,   130,     0,     0,   125,   126,
     131,   134,     0,     0,     0,   136,   138,   137,   139,   140,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,    52,     0,     0,    74,    97,     0,    99,   101,
      60,    59,    61,     0,    14,     0,    19,     0,    16,     0,
       0,    32,    31,    26,     0,     0,     0,     0,    56,   132,
     133,   119,     0,    75,   109,   110,   111,   135,   114,   115,
     116,   117,    78,     0,    79,     0,    84,     0,     0,    95,
      74,    73,     0,    98,    21,    20,    15,     0,     0,    13,
      39,   104,    55,   105,     0,     0,     0,    83,    86,     0,
       0,     0,     0,    72,   100,    17,    18,   103,     0,    76,
      77,    80,    81,     0,     0,     0,    88,    87,    91,    92,
       0,    93,    94,    89,    90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,   -19,  -155,   254,  -155,  -155,  -155,  -155,    48,
    -155,   153,  -155,  -155,  -155,  -155,   274,  -155,   158,  -114,
     228,    -8,  -155,   -41,   -17,   -31,   219,   -20,  -155,   -21,
    -154,    68,  -155,  -155,   205,    70,  -155,  -155,   187,  -155,
    -155,  -155,   -11,  -155,  -155,    92,  -155,    85,  -155,  -155,
     -35,   -72,   -70,  -155,  -155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,    63,   133,   187,   188,
     130,   131,    12,    20,    13,    14,    28,    66,    67,    77,
      78,    22,    46,    47,    90,    49,    50,    91,   127,    92,
     113,    53,    54,    55,   102,   103,   215,    56,   146,    57,
     219,   242,    93,   114,   177,   178,   141,   196,   143,   105,
     179,    95,    96,    97,   162
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      52,    51,    94,    98,    48,   116,   106,   107,   101,    68,
      58,    99,   173,    64,   151,    59,    43,    44,    52,    51,
     191,   221,   108,   109,     1,    52,    51,   184,    30,    48,
     135,    15,   104,    31,   136,    58,    16,   153,   154,    17,
     100,     3,   110,     4,     5,     6,   111,   147,    43,    44,
     155,   156,   157,   158,   159,   160,    61,   161,    62,    18,
     142,   145,   150,   163,   164,   165,   243,    19,   101,   224,
     197,   129,   100,    65,   198,   174,   229,     7,    52,    51,
     166,   204,   205,     3,   181,     4,     5,     6,    21,   206,
     207,    25,   182,   208,   209,   210,   211,   189,    27,    32,
      33,    34,    35,    21,    26,    37,    36,    32,    33,    34,
      35,   222,   120,   121,    36,   223,   115,    37,   193,    23,
      38,    39,    40,    41,    60,    37,   226,   227,    38,    39,
      40,    41,    42,   110,    69,   216,   217,   111,   112,    70,
      42,    79,   148,   149,   203,    43,    44,   100,    71,    72,
      73,    74,    75,    43,    44,    80,   240,   241,    81,   212,
     231,   214,    71,    72,    73,    74,    75,   234,   100,    45,
     117,   118,   128,   129,   132,   138,   233,    45,    32,    33,
      34,    35,    76,   239,   134,    36,   139,   140,   170,   169,
     171,   172,   189,   246,    21,   175,    37,   183,   186,    38,
      39,    40,    41,   190,    65,   254,   101,   194,   195,   199,
     200,    42,   259,   257,   262,   213,    52,    51,   225,   264,
     220,    33,    34,    35,    43,    44,   218,   249,   251,    82,
     176,   230,    52,    51,    52,    51,    48,   232,    48,    52,
      51,   235,    58,    48,    58,   258,   167,   261,    45,    58,
     237,   236,   263,    33,    34,    35,   153,   154,   255,   256,
     195,    82,    83,    24,   153,   154,    43,    44,    84,   155,
     156,   157,   158,   159,   160,   245,   161,   155,   156,   157,
     158,   159,   160,   185,   161,    85,    86,    87,    88,    89,
      45,   238,    29,   192,    83,   153,   154,   137,    43,    44,
      84,   144,   201,   250,   168,   202,   180,   252,   155,   156,
     157,   158,   159,   160,   244,   161,   247,    85,    86,    87,
      88,    89,    45,     0,   248,   153,   154,     0,     0,     0,
       0,     0,   253,   153,   154,     0,     0,     0,   155,   156,
     157,   158,   159,   160,     0,   161,   155,   156,   157,   158,
     159,   160,     0,   161,   153,   154,   260,     0,     0,     0,
       0,     0,   153,   154,     0,   228,     0,   155,   156,   157,
     158,   159,   160,     0,   161,   155,   156,   157,   158,   159,
     160,     0,   161,     0,     0,     0,   153,   154,   202,     0,
       0,     0,     0,     0,   153,   154,     0,     0,     0,   155,
     156,   157,   158,   159,   160,   152,   161,   155,   156,   157,
     158,   159,   160,     0,   161,     0,   153,   154,   119,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,     0,   161,     0,     0,     0,
     155,   156,   157,   158,   159,   160,     0,   161,   153,   154,
     120,   121,     0,   122,   123,   124,   125,   126,     0,     0,
       0,   155,   156,   157,   158,   159,   160,     0,   161
};

static const yytype_int16 yycheck[] =
{
      21,    21,    37,    38,    21,    46,    41,    42,    39,    28,
      21,    12,    19,    13,    84,    23,    49,    50,    39,    39,
     134,   175,    43,    44,    18,    46,    46,    29,     9,    46,
       9,     0,    40,    14,    13,    46,    73,    44,    45,    73,
      73,    31,     7,    33,    34,    35,    11,    82,    49,    50,
      57,    58,    59,    60,    61,    62,    28,    64,    30,    73,
      81,    82,    83,    46,    47,    48,   220,    73,    99,   183,
       9,    73,    73,    73,    13,   110,   190,    67,    99,    99,
      63,   153,   154,    31,   119,    33,    34,    35,    19,   161,
     162,    10,   127,   163,   164,   165,   166,   132,    12,     3,
       4,     5,     6,    19,    14,    21,    10,     3,     4,     5,
       6,     9,    49,    50,    10,    13,    20,    21,   137,    67,
      24,    25,    26,    27,    10,    21,     8,     9,    24,    25,
      26,    27,    36,     7,    27,   170,   171,    11,    12,    73,
      36,    12,    68,    69,   152,    49,    50,    73,    39,    40,
      41,    42,    43,    49,    50,    12,    37,    38,    12,   167,
     195,   169,    39,    40,    41,    42,    43,   202,    73,    73,
      10,    10,    10,    73,     7,     7,   197,    73,     3,     4,
       5,     6,    73,   218,    14,    10,    13,    72,    10,    26,
      24,    10,   227,   228,    19,    73,    21,    14,    10,    24,
      25,    26,    27,    32,    73,   240,   237,    68,     9,    13,
      13,    36,   253,   248,   255,    13,   237,   237,    10,   260,
       8,     4,     5,     6,    49,    50,    37,   235,   236,    12,
      13,     8,   253,   253,   255,   255,   253,    13,   255,   260,
     260,    23,   253,   260,   255,   253,    26,   255,    73,   260,
      10,    26,   260,     4,     5,     6,    44,    45,    14,    20,
       9,    12,    45,     9,    44,    45,    49,    50,    51,    57,
      58,    59,    60,    61,    62,   227,    64,    57,    58,    59,
      60,    61,    62,   130,    64,    68,    69,    70,    71,    72,
      73,    10,    18,   135,    45,    44,    45,    69,    49,    50,
      51,    82,    13,   235,    99,    16,   119,   237,    57,    58,
      59,    60,    61,    62,   222,    64,   231,    68,    69,    70,
      71,    72,    73,    -1,    14,    44,    45,    -1,    -1,    -1,
      -1,    -1,    14,    44,    45,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    -1,    64,    57,    58,    59,    60,
      61,    62,    -1,    64,    44,    45,    14,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    15,    -1,    57,    58,    59,
      60,    61,    62,    -1,    64,    57,    58,    59,    60,    61,
      62,    -1,    64,    -1,    -1,    -1,    44,    45,    16,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    22,    64,    57,    58,    59,
      60,    61,    62,    -1,    64,    -1,    44,    45,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    57,
      58,    59,    60,    61,    62,    -1,    64,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    44,    45,
      49,    50,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    75,    31,    33,    34,    35,    67,    76,    77,
      78,    79,    86,    88,    89,     0,    73,    73,    73,    73,
      87,    19,    95,    67,    78,    10,    14,    12,    90,    90,
       9,    14,     3,     4,     5,     6,    10,    21,    24,    25,
      26,    27,    36,    49,    50,    73,    96,    97,    98,    99,
     100,   101,   103,   105,   106,   107,   111,   113,   116,    95,
      10,    28,    30,    80,    13,    73,    91,    92,    76,    27,
      73,    39,    40,    41,    42,    43,    73,    93,    94,    12,
      12,    12,    12,    45,    51,    68,    69,    70,    71,    72,
      98,   101,   103,   116,   124,   125,   126,   127,   124,    12,
      73,    99,   108,   109,    95,   123,   124,   124,   103,   103,
       7,    11,    12,   104,   117,    20,    97,    10,    10,    17,
      49,    50,    52,    53,    54,    55,    56,   102,    10,    73,
      84,    85,     7,    81,    14,     9,    13,    94,     7,    13,
      72,   120,   103,   122,   100,   103,   112,   124,    68,    69,
     103,   126,    22,    44,    45,    57,    58,    59,    60,    61,
      62,    64,   128,    46,    47,    48,    63,    26,   108,    26,
      10,    24,    10,    19,   124,    73,    13,   118,   119,   124,
     112,   124,   124,    14,    29,    85,    10,    82,    83,   124,
      32,    93,    92,    76,    68,     9,   121,     9,    13,    13,
      13,    13,    16,    95,   125,   125,   125,   125,   126,   126,
     126,   126,    95,    13,    95,   110,   124,   124,    37,   114,
       8,   104,     9,    13,    93,    10,     8,     9,    15,    93,
       8,   124,    13,   103,   124,    23,    26,    10,    10,   124,
      37,    38,   115,   104,   119,    83,   124,   121,    14,    95,
     105,    95,   109,    14,   124,    14,    20,   124,    95,    97,
      14,    95,    97,    95,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    79,    80,    80,    81,    82,    82,    83,    84,
      84,    85,    86,    87,    87,    88,    89,    90,    90,    90,
      91,    91,    92,    93,    93,    94,    94,    94,    94,    94,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    99,    99,   100,
     100,   100,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   103,   104,   104,   104,   105,   105,   105,   106,   107,
     107,   108,   109,   109,   110,   110,   111,   112,   113,   114,
     114,   114,   114,   115,   115,   115,   116,   117,   117,   118,
     118,   119,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   125,   125,   125,   125,   125,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   127,   128,   128,   128,   128,
     128,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     0,     2,     3,     1,     1,
       1,     1,     4,     4,     3,     3,     1,     3,     3,     2,
       3,     3,     4,     1,     3,     4,     6,     0,     2,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     4,
       3,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     3,     5,     4,     1,     1,     3,
       3,     3,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     4,     3,     0,     4,     6,     6,     4,     4,
       6,     5,     1,     0,     1,     0,     5,     5,     6,     5,
       5,     4,     4,     3,     3,     0,     2,     2,     3,     1,
       3,     1,     1,     3,     0,     3,     1,     0,     1,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     2,     3,     3,     2,     3,     1,     1,     1,     1,
       1,     1
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
#line 133 "SRC/yacc.y" /* yacc.c:1646  */
    {if(regions_table_add(0, 0, (yyvsp[0].node)) == BAD_REGION) fatal_error("regions_table");}
#line 1520 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 3:
#line 136 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1526 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 4:
#line 137 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1532 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1538 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = (yyvsp[0].hkey);}
#line 1544 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 34:
#line 225 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = (yyvsp[0].hkey);}
#line 1550 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 40:
#line 239 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1556 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1562 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 42:
#line 243 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1568 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 43:
#line 246 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1574 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 44:
#line 247 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1580 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 45:
#line 248 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1586 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 46:
#line 249 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1592 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 47:
#line 250 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1598 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 48:
#line 251 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1604 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 49:
#line 252 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1610 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 50:
#line 253 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1616 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 51:
#line 254 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1622 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 52:
#line 255 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_RETURN), (yyvsp[-1].node));}
#line 1628 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 53:
#line 256 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1634 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 54:
#line 259 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_FUN_READ);}
#line 1640 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 55:
#line 260 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_FUN_WRITE), 
													  syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[-1].node)));}
#line 1647 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 56:
#line 262 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_FUN_READ), 
													  (yyvsp[-1].node));}
#line 1654 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 57:
#line 270 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1660 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 58:
#line 271 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1666 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 59:
#line 274 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1672 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 60:
#line 275 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1678 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 61:
#line 276 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[-1].val_i)), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1684 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 62:
#line 279 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_INC), (yyvsp[-1].node));}
#line 1690 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 63:
#line 280 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_DEC), (yyvsp[-1].node));}
#line 1696 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 64:
#line 281 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PINC), (yyvsp[0].node));}
#line 1702 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 65:
#line 282 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PDEC), (yyvsp[0].node));}
#line 1708 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 66:
#line 285 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_PLUSE;}
#line 1714 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 67:
#line 286 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MINE;}
#line 1720 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 68:
#line 287 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MULTE;}
#line 1726 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 69:
#line 288 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_DIVE;}
#line 1732 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 70:
#line 289 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MODE;}
#line 1738 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 71:
#line 292 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_VAR), (yyvsp[0].node));}
#line 1744 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 72:
#line 295 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_son(
									        syntax_tree_node_new(AT_ARRAY_INDEX), (yyvsp[-2].node)), (yyvsp[0].node));}
#line 1751 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 73:
#line 297 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_node_hkey_new((yyvsp[-1].hkey)), (yyvsp[0].node));}
#line 1757 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 74:
#line 298 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1763 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 75:
#line 305 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF),
                                                                                 syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1770 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 76:
#line 307 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF_ELSE),
	     			       					         syntax_tree_add_brother((yyvsp[-4].node), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 1777 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 77:
#line 309 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF_ELSE),
									         syntax_tree_add_brother((yyvsp[-4].node), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 1784 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 78:
#line 317 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_WHILE), 
                                                                                 syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1791 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 79:
#line 321 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_FOR),
                                                                                           syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1798 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 80:
#line 323 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_FOR),
                                                                                           syntax_tree_add_brother((yyvsp[-3].node), (yyvsp[0].node)));}
#line 1805 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 81:
#line 327 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node));}
#line 1811 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 82:
#line 330 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1817 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 83:
#line 331 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1823 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 84:
#line 334 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1829 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 85:
#line 335 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1835 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 86:
#line 338 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DO_WHILE),
                                                                                                     syntax_tree_add_brother((yyvsp[-3].node), (yyvsp[-1].node)));}
#line 1842 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 87:
#line 346 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_TERNAIRE),
                                                                           syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node)));}
#line 1849 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 88:
#line 354 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_SWITCH),
                                                                       syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[-1].node)));}
#line 1856 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 89:
#line 358 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-4].node), 
                                                                                syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE),
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 1864 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 90:
#line 361 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-4].node), 
                                                                                syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE),
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 1872 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 91:
#line 364 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE), 
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1879 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 92:
#line 366 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE), 
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1886 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 93:
#line 370 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DEFAULT), (yyvsp[0].node));}
#line 1892 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 94:
#line 371 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DEFAULT), (yyvsp[0].node));}
#line 1898 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 95:
#line 372 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1904 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 96:
#line 379 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CALL), (yyvsp[0].node));}
#line 1910 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 97:
#line 382 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1916 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 98:
#line 383 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1922 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 99:
#line 386 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1928 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 100:
#line 387 "SRC/yacc.y" /* yacc.c:1646  */
    {syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1934 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 101:
#line 390 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1940 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 102:
#line 397 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[0].val_s));}
#line 1946 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 103:
#line 400 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1952 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 104:
#line 401 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1958 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 105:
#line 408 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1964 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 106:
#line 409 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1970 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 107:
#line 416 "SRC/yacc.y" /* yacc.c:1646  */
    {syntax_tree_node_new(AT_EMPTY);}
#line 1976 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 108:
#line 417 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1982 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 109:
#line 420 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_PLUS), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1989 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 110:
#line 422 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1996 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 111:
#line 424 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_OR), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2003 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 112:
#line 426 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2009 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 113:
#line 427 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2015 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 114:
#line 430 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MULT), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2022 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 115:
#line 432 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_DIV), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2029 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 116:
#line 434 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MOD), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2036 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 117:
#line 436 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_AND), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2043 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 118:
#line 438 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2049 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 119:
#line 441 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2055 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 120:
#line 442 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_int_new((yyvsp[0].val_i));}
#line 2061 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 121:
#line 443 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_float_new((yyvsp[0].val_f));}
#line 2067 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 122:
#line 444 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_char_new((yyvsp[0].val_c));}
#line 2073 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 123:
#line 445 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_bool_new((yyvsp[0].val_c));}
#line 2079 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 124:
#line 446 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[0].val_s));}
#line 2085 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 125:
#line 447 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_int_new(-(yyvsp[0].val_i));}
#line 2091 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 126:
#line 448 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_float_new(-(yyvsp[0].val_f));}
#line 2097 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 127:
#line 449 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2103 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 128:
#line 450 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2109 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 129:
#line 451 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2115 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 130:
#line 452 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2121 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 131:
#line 453 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
                                                           syntax_tree_add_brother(syntax_tree_node_int_new(0), (yyvsp[0].node)));}
#line 2128 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 132:
#line 455 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2134 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 133:
#line 456 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2140 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 134:
#line 457 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_NOT), (yyvsp[0].node));}
#line 2146 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 135:
#line 460 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[-1].val_i)), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2152 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 136:
#line 463 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_L;}
#line 2158 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 137:
#line 464 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_LE;}
#line 2164 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 138:
#line 465 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_G;}
#line 2170 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 139:
#line 466 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_GE;}
#line 2176 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 140:
#line 467 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_E;}
#line 2182 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 141:
#line 468 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_NE;}
#line 2188 "SRC/yacc.c" /* yacc.c:1646  */
    break;


#line 2192 "SRC/yacc.c" /* yacc.c:1646  */
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
#line 471 "SRC/yacc.y" /* yacc.c:1906  */

