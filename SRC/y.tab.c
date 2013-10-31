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
#line 1 "SRC/y.tab.y" /* yacc.c:339  */

  #include "kernel.h"

  extern int yylex(void);
  extern void yyerror(const char *str);
  
  /* Retourne un champ de déclaration d'une Hashkey */
  #define SYMBOL_OF(HKEY) symbol_table_get(hashtable, HKEY)

  /* Table principale. */
  Hashtable *hashtable;

  /* Données. */
  Array *array;
  Structure *structure;
  Function *function;
  Procedure *procedure;
  unsigned int level = 0;
  int region;


#line 88 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
/* Tokens.  */
#define VIDE 258
#define RAND 259
#define ECRIRE 260
#define LIRE 261
#define CROCHET_OUVRANT 262
#define CROCHET_FERMANT 263
#define VIRGULE 264
#define POINT_VIRGULE 265
#define POINT 266
#define PARENTHESE_OUVRANTE 267
#define PARENTHESE_FERMANTE 268
#define DEUX_POINTS 269
#define POINT_ET_POINT 270
#define INTERROGATION 271
#define OPAFF 272
#define PROG 273
#define ACC_DEBUT 274
#define ACC_FIN 275
#define SI 276
#define ALORS 277
#define SINON 278
#define TANT_QUE 279
#define POUR 280
#define FAIRE 281
#define RETOURNE 282
#define STRUCT 283
#define FSTRUCT 284
#define TABLEAU 285
#define TYPE 286
#define DE 287
#define PROCEDURE 288
#define FONCTION 289
#define VARIABLE 290
#define SWITCH 291
#define CASE 292
#define DEFAULT 293
#define ENTIER 294
#define REEL 295
#define BOOLEEN 296
#define CARACTERE 297
#define CHAINE 298
#define PLUS 299
#define MOINS 300
#define MULTIPLICATION 301
#define DIVISION 302
#define MODULO 303
#define PLUS_ET_PLUS 304
#define MOINS_ET_MOINS 305
#define NEGATION 306
#define PLUS_EGAL 307
#define MOINS_EGAL 308
#define MULT_EGAL 309
#define DIV_EGAL 310
#define MODULO_EGAL 311
#define INFERIEUR 312
#define SUPERIEUR 313
#define INFERIEUR_OU_EGAL 314
#define SUPERIEUR_OU_EGAL 315
#define EGAL 316
#define DIFFERENT 317
#define ET 318
#define OU 319
#define CONTINUE 320
#define BREAK 321
#define START 322
#define CSTE_ENTIERE 323
#define CSTE_REELLE 324
#define CSTE_CARACTERE 325
#define CSTE_BOOLEENNE 326
#define CSTE_CHAINE 327
#define IDF 328

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 24 "SRC/y.tab.y" /* yacc.c:355  */

  int val_i; 
  float val_f; 
  char val_c; 
  char *val_s; 
  Hashkey hkey;
  Syntax_tree *node;

#line 283 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 298 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   435

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  266

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
       0,   146,   146,   150,   151,   152,   159,   160,   163,   164,
     165,   166,   169,   177,   191,   194,   195,   198,   211,   212,
     215,   228,   231,   237,   249,   249,   272,   272,   294,   295,
     296,   299,   300,   303,   312,   313,   316,   317,   318,   319,
     320,   327,   330,   331,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   347,   348,   350,   358,   359,
     362,   363,   364,   367,   368,   369,   370,   373,   374,   375,
     376,   377,   380,   383,   385,   386,   393,   395,   400,   409,
     413,   415,   419,   422,   423,   426,   427,   430,   438,   446,
     450,   453,   456,   458,   462,   463,   464,   471,   474,   475,
     478,   479,   482,   489,   492,   493,   500,   501,   508,   509,
     512,   514,   516,   518,   519,   522,   524,   526,   528,   530,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   547,   548,   549,   552,   555,   556,   557,
     558,   559,   560
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
  "declaration_procedure", "$@1", "declaration_fonction", "$@2",
  "liste_parametres", "liste_param", "un_param", "nom_type", "type_simple",
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

#define YYPACT_NINF -163

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-163)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,    22,    62,   -37,    -1,     6,     9,    69,  -163,   137,
      88,  -163,  -163,  -163,  -163,  -163,    91,    95,    95,   104,
    -163,   174,  -163,    69,   109,  -163,     0,    -4,  -163,    87,
       9,   100,  -163,   135,   138,   146,  -163,   260,   260,     2,
      69,   260,   260,   113,   113,    36,    60,  -163,   183,   192,
    -163,  -163,    99,  -163,  -163,  -163,  -163,  -163,   193,  -163,
    -163,   132,   175,  -163,   194,    18,  -163,    22,   123,  -163,
    -163,  -163,  -163,  -163,   202,  -163,  -163,  -163,   198,   140,
     113,   260,    35,   260,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,   -33,  -163,   342,    -9,  -163,  -163,   363,   -29,    38,
    -163,   190,   209,   197,   212,   371,   334,  -163,  -163,   260,
     152,   250,  -163,  -163,  -163,  -163,  -163,  -163,   260,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,   260,  -163,   213,    -5,
     220,   163,   200,   100,   169,  -163,  -163,  -163,   181,  -163,
    -163,   242,  -163,   121,   239,    99,   244,   280,  -163,  -163,
    -163,  -163,    69,   260,   260,  -163,  -163,  -163,  -163,  -163,
    -163,   260,   260,   260,   260,   260,   260,    69,   245,    69,
     260,   260,  -163,   222,   130,    38,  -163,   172,  -163,   371,
    -163,   311,   371,   100,  -163,   257,  -163,   255,   148,  -163,
     100,  -163,  -163,    22,   263,   260,   266,   113,  -163,  -163,
    -163,  -163,   260,   264,    -9,    -9,    -9,    -9,  -163,  -163,
    -163,  -163,  -163,   265,  -163,   279,   371,   216,   260,   159,
      38,  -163,   260,  -163,  -163,  -163,   226,  -163,   163,  -163,
    -163,  -163,    67,  -163,  -163,   224,    52,    69,   -29,  -163,
     290,   260,   276,   272,  -163,  -163,  -163,  -163,  -163,   260,
    -163,  -163,  -163,  -163,    96,   301,    96,  -163,   371,  -163,
    -163,    96,  -163,  -163,  -163,  -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     8,     9,    10,    11,     1,     0,    28,    28,     0,
      21,     0,     4,     0,     0,     6,     0,     0,    24,     0,
       0,     0,    52,     0,     0,     0,    44,     0,     0,    84,
       0,   109,     0,     0,     0,    75,     0,    42,     0,     0,
      58,    59,     0,    46,    47,    48,    49,    50,     0,     3,
       7,     0,     0,    29,     0,     0,    31,     5,     0,    23,
      36,    37,    38,    39,     0,    35,    22,    34,     0,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,   129,
     130,   131,   128,     0,   113,   119,   114,     0,    84,    75,
      83,     0,     0,     0,     0,   108,     0,    65,    66,     0,
       0,     0,    72,    97,    41,    43,    54,    45,     0,    63,
      64,    67,    68,    69,    70,    71,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    30,    25,    26,     0,    55,
     103,   105,   107,     0,     0,   131,     0,     0,   126,   127,
     132,   135,     0,     0,     0,   137,   139,   138,   140,   141,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,     0,    53,     0,     0,    75,    98,     0,   100,   102,
      61,    60,    62,     0,    13,     0,    18,     0,     0,    15,
       0,    33,    32,     5,     0,     0,     0,     0,    57,   133,
     134,   120,     0,    76,   110,   111,   112,   136,   115,   116,
     117,   118,    79,     0,    80,     0,    85,     0,     0,    96,
      75,    74,     0,    99,    20,    19,     0,    14,     0,    12,
      27,    40,   105,    56,   106,     0,     0,     0,    84,    87,
       0,     0,     0,     0,    73,   101,    17,    16,   104,     0,
      77,    78,    81,    82,     0,     0,     0,    89,    88,    92,
      93,     0,    94,    95,    90,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,   -56,  -163,   288,  -163,  -163,  -163,    70,  -163,
     173,  -163,   273,  -163,  -163,  -163,  -163,   289,  -163,   178,
     -93,   238,    -8,  -163,   -41,   -17,   -31,   227,   -20,  -163,
     -21,  -162,    77,  -163,  -163,   218,    76,  -163,  -163,   199,
    -163,  -163,  -163,   -11,  -163,  -163,   114,  -163,    94,  -163,
    -163,   -35,  -120,   -71,  -163,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,   132,   188,   189,   129,
     130,    12,    20,    13,    67,    14,   193,    28,    65,    66,
      76,    77,    22,    46,    47,    89,    49,    50,    90,   126,
      91,   112,    53,    54,    55,   101,   102,   215,    56,   146,
      57,   219,   243,    92,   113,   177,   178,   141,   196,   143,
     104,   179,    94,    95,    96,   162
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      52,    51,    93,    97,    48,   115,   105,   106,   100,    63,
      58,   136,   151,   221,    98,    59,   119,   120,    52,    51,
      43,    44,   107,   108,   184,    52,    51,   134,    61,    48,
      62,   135,   103,   204,   205,    58,    16,   163,   164,   165,
     191,   206,   207,   109,    99,   109,   147,   110,   111,   110,
       1,    43,    44,     3,   166,     4,     5,     6,   244,   142,
     145,   150,    15,    32,    33,    34,    35,   100,   128,    64,
      36,    21,    17,    37,   174,    99,   195,    52,    51,    18,
     114,    37,    19,   181,    38,    39,    40,    41,    21,     7,
     224,   182,   208,   209,   210,   211,    42,   229,    25,    32,
      33,    34,    35,   148,   149,    26,    36,    27,    99,    43,
      44,   153,   154,    30,    68,    21,   118,    37,    31,    60,
      38,    39,    40,    41,   155,   156,   157,   158,   159,   160,
     197,   161,    42,    45,   198,   216,   217,   230,   220,    70,
      71,    72,    73,    74,   203,    43,    44,    78,   119,   120,
      79,   121,   122,   123,   124,   125,   227,   228,    80,   212,
     232,   214,    70,    71,    72,    73,    74,   235,     3,    45,
       4,     5,     6,    75,   153,   154,   234,    32,    33,    34,
      35,   222,   131,   240,    36,   223,    99,   155,   156,   157,
     158,   159,   160,   116,   161,    37,   241,   242,    38,    39,
      40,    41,   117,   127,    23,   128,   255,   100,   133,   138,
      42,   139,   140,   260,   258,   263,   169,    52,    51,   170,
     265,   171,   172,    43,    44,   175,   239,   183,   250,   252,
     186,   187,   190,    52,    51,    52,    51,    48,   249,    48,
      52,    51,    64,    58,    48,    58,   259,    45,   262,   194,
      58,   195,   199,   264,    33,    34,    35,   200,   213,   218,
     153,   154,    81,   176,    33,    34,    35,   225,   153,   154,
     226,   231,    81,   155,   156,   157,   158,   159,   160,   233,
     161,   155,   156,   157,   158,   159,   160,   236,   161,   238,
     256,   237,   257,   201,   246,    82,   202,    24,   247,    43,
      44,    83,   185,    69,   254,    82,   137,    29,   144,    43,
      44,    83,   192,   251,   253,   261,   168,   180,    84,    85,
      86,    87,    88,    45,   153,   154,   248,   202,    84,    85,
      86,    87,    88,    45,   153,   154,   245,   155,   156,   157,
     158,   159,   160,     0,   161,   153,   154,   155,   156,   157,
     158,   159,   160,   173,   161,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   152,   161,     0,     0,   155,   156,
     157,   158,   159,   160,     0,   161,     0,     0,   153,   154,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   167,
       0,   155,   156,   157,   158,   159,   160,     0,   161,   155,
     156,   157,   158,   159,   160,     0,   161,   153,   154,     0,
       0,     0,     0,     0,     0,   153,   154,     0,     0,     0,
     155,   156,   157,   158,   159,   160,     0,   161,   155,   156,
     157,   158,   159,   160,     0,   161
};

static const yytype_int16 yycheck[] =
{
      21,    21,    37,    38,    21,    46,    41,    42,    39,    13,
      21,    67,    83,   175,    12,    23,    49,    50,    39,    39,
      49,    50,    43,    44,    29,    46,    46,     9,    28,    46,
      30,    13,    40,   153,   154,    46,    73,    46,    47,    48,
     133,   161,   162,     7,    73,     7,    81,    11,    12,    11,
      18,    49,    50,    31,    63,    33,    34,    35,   220,    80,
      81,    82,     0,     3,     4,     5,     6,    98,    73,    73,
      10,    19,    73,    21,   109,    73,     9,    98,    98,    73,
      20,    21,    73,   118,    24,    25,    26,    27,    19,    67,
     183,   126,   163,   164,   165,   166,    36,   190,    10,     3,
       4,     5,     6,    68,    69,    14,    10,    12,    73,    49,
      50,    44,    45,     9,    27,    19,    17,    21,    14,    10,
      24,    25,    26,    27,    57,    58,    59,    60,    61,    62,
       9,    64,    36,    73,    13,   170,   171,   193,     8,    39,
      40,    41,    42,    43,   152,    49,    50,    12,    49,    50,
      12,    52,    53,    54,    55,    56,     8,     9,    12,   167,
     195,   169,    39,    40,    41,    42,    43,   202,    31,    73,
      33,    34,    35,    73,    44,    45,   197,     3,     4,     5,
       6,     9,     7,   218,    10,    13,    73,    57,    58,    59,
      60,    61,    62,    10,    64,    21,    37,    38,    24,    25,
      26,    27,    10,    10,    67,    73,   241,   238,    14,     7,
      36,    13,    72,   254,   249,   256,    26,   238,   238,    10,
     261,    24,    10,    49,    50,    73,    10,    14,   236,   237,
      10,    68,    32,   254,   254,   256,   256,   254,    14,   256,
     261,   261,    73,   254,   261,   256,   254,    73,   256,    68,
     261,     9,    13,   261,     4,     5,     6,    13,    13,    37,
      44,    45,    12,    13,     4,     5,     6,    10,    44,    45,
      15,     8,    12,    57,    58,    59,    60,    61,    62,    13,
      64,    57,    58,    59,    60,    61,    62,    23,    64,    10,
      14,    26,    20,    13,    68,    45,    16,     9,   228,    49,
      50,    51,   129,    30,    14,    45,    68,    18,    81,    49,
      50,    51,   134,   236,   238,    14,    98,   118,    68,    69,
      70,    71,    72,    73,    44,    45,   232,    16,    68,    69,
      70,    71,    72,    73,    44,    45,   222,    57,    58,    59,
      60,    61,    62,    -1,    64,    44,    45,    57,    58,    59,
      60,    61,    62,    19,    64,    44,    45,    -1,    57,    58,
      59,    60,    61,    62,    22,    64,    -1,    -1,    57,    58,
      59,    60,    61,    62,    -1,    64,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    26,
      -1,    57,    58,    59,    60,    61,    62,    -1,    64,    57,
      58,    59,    60,    61,    62,    -1,    64,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    57,    58,
      59,    60,    61,    62,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    75,    31,    33,    34,    35,    67,    76,    77,
      78,    79,    85,    87,    89,     0,    73,    73,    73,    73,
      86,    19,    96,    67,    78,    10,    14,    12,    91,    91,
       9,    14,     3,     4,     5,     6,    10,    21,    24,    25,
      26,    27,    36,    49,    50,    73,    97,    98,    99,   100,
     101,   102,   104,   106,   107,   108,   112,   114,   117,    96,
      10,    28,    30,    13,    73,    92,    93,    88,    27,    86,
      39,    40,    41,    42,    43,    73,    94,    95,    12,    12,
      12,    12,    45,    51,    68,    69,    70,    71,    72,    99,
     102,   104,   117,   125,   126,   127,   128,   125,    12,    73,
     100,   109,   110,    96,   124,   125,   125,   104,   104,     7,
      11,    12,   105,   118,    20,    98,    10,    10,    17,    49,
      50,    52,    53,    54,    55,    56,   103,    10,    73,    83,
      84,     7,    80,    14,     9,    13,    76,    95,     7,    13,
      72,   121,   104,   123,   101,   104,   113,   125,    68,    69,
     104,   127,    22,    44,    45,    57,    58,    59,    60,    61,
      62,    64,   129,    46,    47,    48,    63,    26,   109,    26,
      10,    24,    10,    19,   125,    73,    13,   119,   120,   125,
     113,   125,   125,    14,    29,    84,    10,    68,    81,    82,
      32,    94,    93,    90,    68,     9,   122,     9,    13,    13,
      13,    13,    16,    96,   126,   126,   126,   126,   127,   127,
     127,   127,    96,    13,    96,   111,   125,   125,    37,   115,
       8,   105,     9,    13,    94,    10,    15,     8,     9,    94,
      76,     8,   125,    13,   104,   125,    23,    26,    10,    10,
     125,    37,    38,   116,   105,   120,    68,    82,   122,    14,
      96,   106,    96,   110,    14,   125,    14,    20,   125,    96,
      98,    14,    96,    98,    96,    98
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    79,    79,    80,    81,    81,    82,    83,    83,
      84,    85,    86,    86,    88,    87,    90,    89,    91,    91,
      91,    92,    92,    93,    94,    94,    95,    95,    95,    95,
      95,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,   100,   100,
     101,   101,   101,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   104,   105,   105,   105,   106,   106,   106,   107,
     108,   108,   109,   110,   110,   111,   111,   112,   113,   114,
     115,   115,   115,   115,   116,   116,   116,   117,   118,   118,
     119,   119,   120,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   128,   129,   129,   129,
     129,   129,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     0,     2,     3,     1,     1,
       1,     1,     7,     6,     3,     1,     3,     3,     2,     3,
       3,     2,     3,     3,     0,     5,     0,     7,     0,     2,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     2,     1,     3,     2,     3,     5,     4,     1,     1,
       3,     3,     3,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     2,     4,     3,     0,     4,     6,     6,     4,
       4,     6,     5,     1,     0,     1,     0,     5,     5,     6,
       5,     5,     4,     4,     3,     3,     0,     2,     2,     3,
       1,     3,     1,     1,     3,     0,     3,     1,     1,     0,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     1
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
#line 146 "SRC/y.tab.y" /* yacc.c:1646  */
    {if(regions_table_add(0, 0, (yyvsp[0].node)) == BAD_REGION) 
                         fatal_error("regions_table");}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 151 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 152 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 169 "SRC/y.tab.y" /* yacc.c:1646  */
    {if((array = array_new(dimensions_buffer_get_size(), SYMBOL_OF((yyvsp[0].hkey)))) == NULL)
                                                                        fatal_error("array_new");
                                                                      dimensions_buffer_copy(array->dimension);
                                                                      dimensions_buffer_reset();

                                                                      if(!symbol_table_add(hashtable, (yyvsp[-5].hkey), SYMBOL_TYPE_ARRAY, 0, array, 0))
                                                                        fatal_error("symbol_table_add");
                                                                     }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 177 "SRC/y.tab.y" /* yacc.c:1646  */
    {if((structure = structure_new(variables_buffer_get_size())) == NULL)
                                                                        fatal_error("structure_new");
                                                                      variables_buffer_copy(structure->field);
                                                                      variables_buffer_reset();

                                                                      if(!symbol_table_add(hashtable, (yyvsp[-4].hkey), SYMBOL_TYPE_STRUCT, 0, structure, 0))
                                                                        fatal_error("symbol_table_add");
                                                                     }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 198 "SRC/y.tab.y" /* yacc.c:1646  */
    {if(dimensions_buffer_push((yyvsp[-2].val_i), (yyvsp[0].val_i)) == -1)
                                                         {
                                                           fprintf(stderr, "Error: The buffer has reached its limit (%d)\n", 
                                                                   MAX_DIMENSIONS_BUFFER_SIZE);
                                                           exit(EXIT_FAILURE);
                                                         }
                                                        }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 215 "SRC/y.tab.y" /* yacc.c:1646  */
    {if(variables_buffer_push((yyvsp[-2].hkey), SYMBOL_OF((yyvsp[0].hkey))) == -1)
                                    {
                                      fprintf(stderr, "Error: The buffer has reached its limit (%d)\n", 
                                              MAX_VARIABLES_BUFFER_SIZE);
                                      exit(EXIT_FAILURE);
                                    }
                                   }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 231 "SRC/y.tab.y" /* yacc.c:1646  */
    {
                                                                    if(!symbol_table_add(hashtable, (yyvsp[-2].hkey), SYMBOL_TYPE_VAR, regions_stack_top(), 
                                                                                         SYMBOL_OF((yyvsp[0].hkey)), 0))
                                                                      fatal_error("symbol_table_add");
                                                                    (yyval.hkey) = (yyvsp[0].hkey);
                                                                   }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "SRC/y.tab.y" /* yacc.c:1646  */
    {
                                                                    if(!symbol_table_add(hashtable, (yyvsp[-2].hkey), SYMBOL_TYPE_VAR, regions_stack_top(), 
                                                                                         SYMBOL_OF((yyvsp[0].hkey)), 0))
                                                                      fatal_error("symbol_table_add");
                                                                    (yyval.hkey) = (yyvsp[0].hkey);
                                                                   }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 249 "SRC/y.tab.y" /* yacc.c:1646  */
    {
                                                       if((region = regions_table_add(0, ++level, NULL)) == BAD_REGION)
                                                         fatal_error("regions_table_add");
                                                       if(regions_stack_push(region) == -1)
                                                         fatal_error("regions_stack_push");
                                                      }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 256 "SRC/y.tab.y" /* yacc.c:1646  */
    {
                       if((procedure = procedure_new(variables_buffer_get_size())) == NULL)
                         fatal_error("procedure_new");
                       variables_buffer_copy(procedure->params);
                       variables_buffer_reset();
                       
                       region = regions_stack_top();
                       regions_table_set_tree(region, (yyvsp[0].node));
                       level--;
                       regions_stack_pop();

                       if(!symbol_table_add(hashtable, (yyvsp[-3].hkey), SYMBOL_TYPE_PROCEDURE, regions_stack_top(), procedure, region))
                         fatal_error("symbol_table_add");
                     }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 272 "SRC/y.tab.y" /* yacc.c:1646  */
    {
                                                                          if((region = regions_table_add(0, ++level, NULL)) == BAD_REGION)
                                                                            fatal_error("regions_table_add");
                                                                          if(regions_stack_push(region) == -1)
                                                                            fatal_error("regions_stack_push");
                                                                         }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 278 "SRC/y.tab.y" /* yacc.c:1646  */
    {
                      if((function = function_new(SYMBOL_OF((yyvsp[-2].hkey)), variables_buffer_get_size())) == NULL)
                        fatal_error("function_new");
                      variables_buffer_copy(function->params);
                      variables_buffer_reset();
                      
                      region = regions_stack_top();
                      regions_table_set_tree(region, (yyvsp[0].node));
                      level--;
                      regions_stack_pop();
                      
                       if(!symbol_table_add(hashtable, (yyvsp[-5].hkey), SYMBOL_TYPE_FUNCTION, regions_stack_top(), function, region))
                         fatal_error("symbol_table_add");
                    }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 303 "SRC/y.tab.y" /* yacc.c:1646  */
    {variables_buffer_push((yyvsp[-2].hkey), SYMBOL_OF((yyvsp[0].hkey)));}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 312 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.hkey) = (yyvsp[0].hkey);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 313 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.hkey) = (yyvsp[0].hkey);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 316 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_INT;}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 317 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_FLOAT;}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 318 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_BOOL;}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 319 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_CHAR;}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 320 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.hkey) = LBASIC_CHAR;}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 327 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 330 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 331 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 334 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 335 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 336 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 337 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 338 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 339 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 340 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 341 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 342 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 343 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_RETURN), (yyvsp[-1].node));}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 344 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 347 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_FUN_RAND);}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 348 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_FUN_WRITE), 
                                                                                                          syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[-1].node)));}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 350 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_FUN_READ), 
                                                                                                          (yyvsp[-1].node));}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 358 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 359 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 362 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 363 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 364 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[-1].val_i)), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 367 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_INC), (yyvsp[-1].node));}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 368 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_DEC), (yyvsp[-1].node));}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 369 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PINC), (yyvsp[0].node));}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 370 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PDEC), (yyvsp[0].node));}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 373 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_PLUSE;}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 374 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MINE;}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 375 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MULTE;}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 376 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_DIVE;}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 377 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MODE;}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 380 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_VAR), (yyvsp[0].node));}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 383 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_son(
                                                                                syntax_tree_node_new(AT_ARRAY_INDEX), (yyvsp[-2].node)), (yyvsp[0].node));}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 385 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_node_hkey_new((yyvsp[-1].hkey)), (yyvsp[0].node));}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 386 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 393 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF),
                                                                                 syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 397 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF), syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node))), 
     syntax_tree_add_son(syntax_tree_node_new(AT_CTL_ELSE), (yyvsp[0].node)));}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 401 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF), syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node))), 
     syntax_tree_add_son(syntax_tree_node_new(AT_CTL_ELSE), (yyvsp[0].node)));}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 409 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_WHILE), 
                                                                                 syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 413 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_FOR),
                                                                                           syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 415 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_FOR),
                                                                                           syntax_tree_add_brother((yyvsp[-3].node), (yyvsp[0].node)));}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 419 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node));}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 422 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 423 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 426 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 427 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 430 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DO_WHILE),
                                                                                                     syntax_tree_add_brother((yyvsp[-3].node), (yyvsp[-1].node)));}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 438 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_TERNAIRE),
                                                                           syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node)));}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 446 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_SWITCH),
                                                                       syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[-1].node)));}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 450 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-4].node), 
                                                                                syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE),
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 453 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-4].node), 
                                                                                syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE),
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node))));}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 456 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE), 
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 458 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE), 
                                                                                                    syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 462 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DEFAULT), (yyvsp[0].node));}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 463 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DEFAULT), (yyvsp[0].node));}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 464 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 471 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CALL), (yyvsp[0].node));}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 474 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 475 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 478 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 479 "SRC/y.tab.y" /* yacc.c:1646  */
    {syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 482 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 489 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[0].val_s));}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 492 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-1].node), (yyvsp[0].node));}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 493 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 500 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 501 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 508 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 509 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 512 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_PLUS), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 514 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 516 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_OR), 
                                                                   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 518 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 519 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 522 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MULT), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 524 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_DIV), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 526 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MOD), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 528 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_AND), 
                                                                              syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 530 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 533 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 534 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_int_new((yyvsp[0].val_i));}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 535 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_float_new((yyvsp[0].val_f));}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 536 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_char_new((yyvsp[0].val_c));}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 537 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_bool_new((yyvsp[0].val_c));}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 538 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[0].val_s));}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 539 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_int_new(-(yyvsp[0].val_i));}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 540 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_float_new(-(yyvsp[0].val_f));}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 541 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 542 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 543 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 544 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 545 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
                                                           syntax_tree_add_brother(syntax_tree_node_int_new(0), (yyvsp[0].node)));}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 547 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 548 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 549 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_NOT), (yyvsp[0].node));}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 552 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[-1].val_i)), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 555 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_L;}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 556 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_LE;}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 557 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_G;}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 558 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_GE;}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 559 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_E;}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 560 "SRC/y.tab.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_NE;}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2439 "y.tab.c" /* yacc.c:1646  */
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
#line 563 "SRC/y.tab.y" /* yacc.c:1906  */

