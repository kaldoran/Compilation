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
  char val_b;
  char *val_s; 
  Hashkey hkey;
  Syntax_tree *node;

#line 199 "SRC/yacc.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_YACC_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 214 "SRC/yacc.c" /* yacc.c:358  */

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
#define YYLAST   479

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

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
       0,   124,   124,   127,   128,   129,   136,   137,   140,   141,
     142,   143,   146,   149,   150,   157,   160,   161,   164,   171,
     172,   175,   182,   185,   186,   193,   196,   199,   200,   201,
     204,   205,   208,   215,   216,   219,   220,   221,   222,   223,
     230,   233,   234,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   250,   251,   252,   259,   260,   263,
     264,   265,   268,   269,   270,   271,   274,   275,   276,   277,
     278,   281,   284,   285,   286,   293,   294,   295,   302,   306,
     307,   310,   313,   314,   317,   318,   321,   328,   335,   338,
     339,   340,   341,   344,   345,   346,   353,   356,   357,   360,
     361,   364,   371,   374,   375,   382,   383,   390,   391,   394,
     396,   398,   400,   401,   404,   406,   408,   410,   412,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   433,   436,   437,   438,   439,
     440,   441
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

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    77,    27,   -37,    13,    16,    24,    82,  -110,   133,
     104,  -110,  -110,  -110,  -110,  -110,   103,   107,   107,  -110,
      19,   126,  -110,    82,   111,  -110,    28,     4,    77,   110,
      65,    -2,  -110,   128,   131,   134,  -110,   247,   247,    -1,
      82,   247,   247,    72,    72,   142,    49,  -110,   145,   146,
    -110,  -110,   414,  -110,  -110,  -110,  -110,  -110,   150,  -110,
    -110,    88,   156,  -110,  -110,   157,     3,  -110,  -110,   153,
    -110,  -110,  -110,  -110,  -110,   166,  -110,  -110,  -110,   164,
     106,    72,   247,    15,   247,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,    -4,  -110,   392,    18,  -110,  -110,   218,   -29,
    -110,  -110,   154,   169,   173,   178,   415,   368,  -110,  -110,
     215,    23,  -110,  -110,  -110,  -110,  -110,   247,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,   247,  -110,   184,   -16,   191,
     247,   170,    -2,   132,  -110,    77,   138,  -110,  -110,   198,
    -110,    54,   195,   414,   196,   287,  -110,  -110,  -110,  -110,
      82,   247,   247,  -110,  -110,  -110,  -110,  -110,  -110,   247,
     247,   247,   247,   247,   247,    82,   200,    82,   247,   247,
    -110,   179,  -110,    87,  -110,   415,   247,   149,  -110,   347,
     415,    -2,  -110,   213,  -110,    98,  -110,   339,    -2,  -110,
    -110,  -110,   216,   247,   222,    72,  -110,  -110,  -110,  -110,
     247,   206,    18,    18,    18,    18,  -110,  -110,  -110,  -110,
    -110,   220,  -110,   229,   415,   279,   247,    90,   247,  -110,
     210,  -110,  -110,  -110,  -110,   247,   247,  -110,  -110,   249,
    -110,  -110,   125,    94,    82,   -29,  -110,   308,   247,   234,
     236,  -110,  -110,  -110,   415,  -110,   247,  -110,  -110,  -110,
    -110,    99,   316,    99,  -110,   415,  -110,  -110,    99,  -110,
    -110,  -110,  -110
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
       0,    71,    96,    40,    42,    53,    44,     0,    62,    63,
      66,    67,    68,    69,    70,     0,    50,     0,     0,     0,
       0,     0,     0,     0,    29,     5,     0,    54,   102,   104,
     106,     0,     0,   130,     0,     0,   125,   126,   131,   134,
       0,     0,     0,   136,   138,   137,   139,   140,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
      52,     0,    97,     0,    99,   101,     0,     0,    60,    59,
      61,     0,    14,     0,    19,     0,    16,     0,     0,    32,
      31,    26,     0,     0,     0,     0,    56,   132,   133,   119,
       0,    75,   109,   110,   111,   135,   114,   115,   116,   117,
      78,     0,    79,     0,    84,     0,     0,    95,     0,    98,
       0,    73,    21,    20,    15,     0,     0,    13,    39,   104,
      55,   105,     0,     0,     0,    83,    86,     0,     0,     0,
       0,   100,    72,    17,    18,   103,     0,    76,    77,    80,
      81,     0,     0,     0,    88,    87,    91,    92,     0,    93,
      94,    89,    90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,   -19,  -110,   240,  -110,  -110,  -110,  -110,    32,
    -110,   162,  -110,  -110,  -110,  -110,   243,  -110,   140,  -101,
     212,    -8,  -110,   -41,   -17,   -31,   209,   -20,  -110,   -21,
    -110,    62,  -110,  -110,   202,    64,  -110,  -110,   185,  -110,
    -110,  -110,   -11,  -110,  -110,    86,  -110,    76,  -110,  -110,
     -35,  -109,   -70,  -110,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,    63,   131,   185,   186,
     128,   129,    12,    20,    13,    14,    28,    66,    67,    77,
      78,    22,    46,    47,    90,    49,    50,    91,   125,    92,
     111,    53,    54,    55,   102,   103,   213,    56,   144,    57,
     217,   240,    93,   112,   173,   174,   139,   194,   141,   105,
     175,    95,    96,    97,   160
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      52,    51,    94,    98,    48,   114,   106,   107,   101,    68,
      58,    99,   133,   182,   149,    59,   134,    64,    52,    51,
      43,    44,   108,   109,     1,    52,    51,    15,    30,    48,
     176,   189,   104,    31,   177,    58,    16,    71,    72,    73,
      74,    75,   202,   203,   100,   118,   119,   145,    43,    44,
     204,   205,    32,    33,    34,    35,    61,   127,    62,    36,
     140,   143,   148,   195,   161,   162,   163,   196,   101,   113,
      37,    76,   100,    38,    39,    40,    41,    65,    52,    51,
     222,   164,   179,   146,   147,    42,    17,   227,   100,    18,
     180,   206,   207,   208,   209,   187,   218,    19,    43,    44,
     219,    21,    32,    33,    34,    35,   224,   225,     3,    36,
       4,     5,     6,    21,    25,    37,   191,    26,    21,    27,
      37,    60,    45,    38,    39,    40,    41,   238,   239,    32,
      33,    34,    35,   214,   215,    42,    36,    69,    70,   246,
      79,   220,   201,    80,     7,   100,    81,    37,    43,    44,
      38,    39,    40,    41,   110,   115,   116,   210,   229,   212,
     126,   127,    42,   130,     3,   232,     4,     5,     6,   151,
     152,   132,    45,   136,   231,    43,    44,   137,   138,   168,
     167,   237,   153,   154,   155,   156,   157,   158,   170,   159,
     187,   244,    71,    72,    73,    74,    75,   169,   181,    45,
      23,   184,   188,   252,   101,    65,   192,   193,   197,   198,
     257,   255,   260,   211,    52,    51,   216,   262,   242,    33,
      34,    35,   221,   223,   228,   247,   249,    82,   172,   233,
      52,    51,    52,    51,    48,   230,    48,    52,    51,   235,
      58,    48,    58,   256,   165,   259,   234,    58,   253,    24,
     261,    33,    34,    35,   151,   152,   254,   243,   193,    82,
      83,    29,   151,   152,    43,    44,    84,   153,   154,   155,
     156,   157,   158,   190,   159,   153,   154,   155,   156,   157,
     158,   135,   159,    85,    86,    87,    88,    89,    45,   236,
     183,   142,    83,   151,   152,   248,    43,    44,    84,   250,
     199,   166,   178,   200,   241,   245,   153,   154,   155,   156,
     157,   158,     0,   159,     0,    85,    86,    87,    88,    89,
      45,     0,   251,   151,   152,     0,     0,     0,     0,     0,
     258,   151,   152,     0,     0,     0,   153,   154,   155,   156,
     157,   158,     0,   159,   153,   154,   155,   156,   157,   158,
       0,   159,   151,   152,   226,     0,     0,     0,     0,     0,
     151,   152,     0,   200,     0,   153,   154,   155,   156,   157,
     158,     0,   159,   153,   154,   155,   156,   157,   158,     0,
     159,     0,     0,   151,   152,     0,     0,   171,     0,     0,
       0,   151,   152,     0,     0,     0,   153,   154,   155,   156,
     157,   158,     0,   159,   153,   154,   155,   156,   157,   158,
       0,   159,   151,   152,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   117,   159,     0,     0,     0,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   158,     0,   159,     0,     0,   151,
     152,     0,     0,   118,   119,     0,   120,   121,   122,   123,
     124,     0,   153,   154,   155,   156,   157,   158,     0,   159
};

static const yytype_int16 yycheck[] =
{
      21,    21,    37,    38,    21,    46,    41,    42,    39,    28,
      21,    12,     9,    29,    84,    23,    13,    13,    39,    39,
      49,    50,    43,    44,    18,    46,    46,     0,     9,    46,
       7,   132,    40,    14,    11,    46,    73,    39,    40,    41,
      42,    43,   151,   152,    73,    49,    50,    82,    49,    50,
     159,   160,     3,     4,     5,     6,    28,    73,    30,    10,
      81,    82,    83,     9,    46,    47,    48,    13,    99,    20,
      21,    73,    73,    24,    25,    26,    27,    73,    99,    99,
     181,    63,   117,    68,    69,    36,    73,   188,    73,    73,
     125,   161,   162,   163,   164,   130,     9,    73,    49,    50,
      13,    19,     3,     4,     5,     6,     8,     9,    31,    10,
      33,    34,    35,    19,    10,    21,   135,    14,    19,    12,
      21,    10,    73,    24,    25,    26,    27,    37,    38,     3,
       4,     5,     6,   168,   169,    36,    10,    27,    73,    14,
      12,   176,   150,    12,    67,    73,    12,    21,    49,    50,
      24,    25,    26,    27,    12,    10,    10,   165,   193,   167,
      10,    73,    36,     7,    31,   200,    33,    34,    35,    44,
      45,    14,    73,     7,   195,    49,    50,    13,    72,    10,
      26,   216,    57,    58,    59,    60,    61,    62,    10,    64,
     225,   226,    39,    40,    41,    42,    43,    24,    14,    73,
      67,    10,    32,   238,   235,    73,    68,     9,    13,    13,
     251,   246,   253,    13,   235,   235,    37,   258,     8,     4,
       5,     6,    73,    10,     8,   233,   234,    12,    13,    23,
     251,   251,   253,   253,   251,    13,   253,   258,   258,    10,
     251,   258,   253,   251,    26,   253,    26,   258,    14,     9,
     258,     4,     5,     6,    44,    45,    20,   225,     9,    12,
      45,    18,    44,    45,    49,    50,    51,    57,    58,    59,
      60,    61,    62,   133,    64,    57,    58,    59,    60,    61,
      62,    69,    64,    68,    69,    70,    71,    72,    73,    10,
     128,    82,    45,    44,    45,   233,    49,    50,    51,   235,
      13,    99,   117,    16,   218,   229,    57,    58,    59,    60,
      61,    62,    -1,    64,    -1,    68,    69,    70,    71,    72,
      73,    -1,    14,    44,    45,    -1,    -1,    -1,    -1,    -1,
      14,    44,    45,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    -1,    64,    57,    58,    59,    60,    61,    62,
      -1,    64,    44,    45,    15,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    16,    -1,    57,    58,    59,    60,    61,
      62,    -1,    64,    57,    58,    59,    60,    61,    62,    -1,
      64,    -1,    -1,    44,    45,    -1,    -1,    19,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    -1,    64,    57,    58,    59,    60,    61,    62,
      -1,    64,    44,    45,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    17,    64,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    -1,    64,    -1,    -1,    44,
      45,    -1,    -1,    49,    50,    -1,    52,    53,    54,    55,
      56,    -1,    57,    58,    59,    60,    61,    62,    -1,    64
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
      12,   104,   117,    20,    97,    10,    10,    17,    49,    50,
      52,    53,    54,    55,    56,   102,    10,    73,    84,    85,
       7,    81,    14,     9,    13,    94,     7,    13,    72,   120,
     103,   122,   100,   103,   112,   124,    68,    69,   103,   126,
      22,    44,    45,    57,    58,    59,    60,    61,    62,    64,
     128,    46,    47,    48,    63,    26,   108,    26,    10,    24,
      10,    19,    13,   118,   119,   124,     7,    11,   112,   124,
     124,    14,    29,    85,    10,    82,    83,   124,    32,    93,
      92,    76,    68,     9,   121,     9,    13,    13,    13,    13,
      16,    95,   125,   125,   125,   125,   126,   126,   126,   126,
      95,    13,    95,   110,   124,   124,    37,   114,     9,    13,
     124,    73,    93,    10,     8,     9,    15,    93,     8,   124,
      13,   103,   124,    23,    26,    10,    10,   124,    37,    38,
     115,   119,     8,    83,   124,   121,    14,    95,   105,    95,
     109,    14,   124,    14,    20,   124,    95,    97,    14,    95,
      97,    95,    97
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
        case 3:
#line 127 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1523 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 4:
#line 128 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1529 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 5:
#line 129 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1535 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 33:
#line 215 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = (yyvsp[0].hkey);}
#line 1541 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 34:
#line 216 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.hkey) = (yyvsp[0].hkey);}
#line 1547 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 40:
#line 230 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1553 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 41:
#line 233 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1559 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 57:
#line 259 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1565 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 58:
#line 260 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1571 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 59:
#line 263 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[-2].hkey), (yyvsp[0].node) ));}
#line 1577 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 61:
#line 265 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[-1].val_i)), syntax_tree_add_brother((yyvsp[-2].hkey), (yyvsp[0].node)));}
#line 1583 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 62:
#line 268 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_INC), (yyvsp[-1].hkey));}
#line 1589 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 63:
#line 269 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_DEC), (yyvsp[-1].hkey));}
#line 1595 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 64:
#line 270 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PINC), (yyvsp[0].hkey));}
#line 1601 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 65:
#line 271 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PDEC), (yyvsp[0].hkey));}
#line 1607 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 66:
#line 274 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_PLUSE;}
#line 1613 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 67:
#line 275 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MINE;}
#line 1619 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 68:
#line 276 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MULTE;}
#line 1625 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 69:
#line 277 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_DIVE;}
#line 1631 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 70:
#line 278 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_OPR_MODE;}
#line 1637 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 78:
#line 302 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_WHILE), 
										 syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1644 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 81:
#line 310 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node));}
#line 1650 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 82:
#line 313 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1656 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 83:
#line 314 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1662 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 84:
#line 317 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1668 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 85:
#line 318 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
#line 1674 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 107:
#line 390 "SRC/yacc.y" /* yacc.c:1646  */
    {syntax_tree_node_new(AT_EMPTY);}
#line 1680 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 108:
#line 391 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1686 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 109:
#line 394 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_PLUS), 
								   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1693 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 110:
#line 396 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
								   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1700 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 111:
#line 398 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_OR), 
								   syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1707 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 112:
#line 400 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1713 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 113:
#line 401 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1719 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 114:
#line 404 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MULT), 
									      syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1726 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 115:
#line 406 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_DIV), 
									      syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1733 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 116:
#line 408 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MOD), 
									      syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1740 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 117:
#line 410 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_AND), 
									      syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1747 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 118:
#line 412 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1753 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 120:
#line 416 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_int_new((yyvsp[0].val_i));}
#line 1759 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 121:
#line 417 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_float_new((yyvsp[0].val_f));}
#line 1765 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 122:
#line 418 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_char_new((yyvsp[0].val_c));}
#line 1771 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 123:
#line 419 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_bool_new((yyvsp[0].val_b));}
#line 1777 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 124:
#line 420 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[0].val_s));}
#line 1783 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 125:
#line 421 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_int_new(-(yyvsp[0].val_i));}
#line 1789 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 126:
#line 422 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_node_float_new(-(yyvsp[0].val_f));}
#line 1795 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 127:
#line 423 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1801 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 130:
#line 426 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].hkey);}
#line 1807 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 134:
#line 430 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_NOT), (yyvsp[0].node));}
#line 1813 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 135:
#line 433 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[-1].val_i)), syntax_tree_add_brother((yyvsp[-2].node), (yyvsp[0].node)));}
#line 1819 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 136:
#line 436 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_L;}
#line 1825 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 137:
#line 437 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_LE;}
#line 1831 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 138:
#line 438 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_G;}
#line 1837 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 139:
#line 439 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_GE;}
#line 1843 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 140:
#line 440 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_E;}
#line 1849 "SRC/yacc.c" /* yacc.c:1646  */
    break;

  case 141:
#line 441 "SRC/yacc.y" /* yacc.c:1646  */
    {(yyval.val_i) = AT_CMP_NE;}
#line 1855 "SRC/yacc.c" /* yacc.c:1646  */
    break;


#line 1859 "SRC/yacc.c" /* yacc.c:1646  */
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
#line 444 "SRC/yacc.y" /* yacc.c:1906  */

