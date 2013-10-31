/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "SRC/y.tab.y"

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



/* Line 268 of yacc.c  */
#line 94 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 24 "SRC/y.tab.y"

  int val_i; 
  float val_f; 
  char val_c; 
  char *val_s; 
  Hashkey hkey;
  Syntax_tree *node;



/* Line 293 of yacc.c  */
#line 287 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 299 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  266

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    13,    14,    17,    21,    23,
      25,    27,    29,    37,    44,    48,    50,    54,    58,    61,
      65,    69,    72,    76,    80,    81,    87,    88,    96,    97,
     100,   104,   106,   110,   114,   116,   118,   120,   122,   124,
     126,   131,   135,   137,   140,   142,   145,   147,   149,   151,
     153,   155,   158,   160,   164,   167,   171,   177,   182,   184,
     186,   190,   194,   198,   201,   204,   207,   210,   212,   214,
     216,   218,   220,   223,   228,   232,   233,   238,   245,   252,
     257,   262,   269,   275,   277,   278,   280,   281,   287,   293,
     300,   306,   312,   317,   322,   326,   330,   331,   334,   337,
     341,   343,   347,   349,   351,   355,   356,   360,   362,   364,
     365,   369,   373,   377,   379,   381,   385,   389,   393,   397,
     399,   403,   405,   407,   409,   411,   413,   416,   419,   421,
     423,   425,   427,   430,   434,   438,   441,   445,   447,   449,
     451,   453,   455
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      75,     0,    -1,    18,    76,    -1,    77,    67,    96,    -1,
      67,    96,    -1,    -1,    78,    10,    -1,    77,    78,    10,
      -1,    79,    -1,    85,    -1,    87,    -1,    89,    -1,    31,
      73,    14,    30,    80,    32,    94,    -1,    31,    73,    14,
      28,    83,    29,    -1,     7,    81,     8,    -1,    82,    -1,
      81,     9,    82,    -1,    68,    15,    68,    -1,    84,    10,
      -1,    83,    84,    10,    -1,    73,    14,    94,    -1,    35,
      86,    -1,    73,    14,    94,    -1,    73,     9,    86,    -1,
      -1,    33,    73,    91,    88,    76,    -1,    -1,    34,    73,
      91,    27,    95,    90,    76,    -1,    -1,    12,    13,    -1,
      12,    92,    13,    -1,    93,    -1,    92,     9,    93,    -1,
      73,    14,    94,    -1,    95,    -1,    73,    -1,    39,    -1,
      40,    -1,    41,    -1,    42,    -1,    43,     7,    68,     8,
      -1,    19,    97,    20,    -1,    98,    -1,    97,    98,    -1,
      10,    -1,   100,    10,    -1,   106,    -1,   107,    -1,   108,
      -1,   112,    -1,   114,    -1,   117,    10,    -1,     3,    -1,
      27,   124,    10,    -1,    99,    10,    -1,     4,    12,    13,
      -1,     5,    12,   121,   122,    13,    -1,     6,    12,   123,
      13,    -1,   101,    -1,   102,    -1,   104,    17,   125,    -1,
     104,    17,   113,    -1,   104,   103,   125,    -1,   104,    49,
      -1,   104,    50,    -1,    49,   104,    -1,    50,   104,    -1,
      52,    -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,
      73,   105,    -1,     7,   125,     8,   105,    -1,    11,    73,
     105,    -1,    -1,    21,   125,    22,    96,    -1,    21,   125,
      22,    96,    23,    96,    -1,    21,   125,    22,    96,    23,
     106,    -1,    24,   125,    26,    96,    -1,    25,   109,    26,
      96,    -1,    25,    12,   109,    13,    26,    96,    -1,   110,
      10,   111,    10,   110,    -1,   100,    -1,    -1,   125,    -1,
      -1,    26,    96,    24,   125,    10,    -1,   125,    16,   125,
      14,   125,    -1,    36,   125,    19,   115,   116,    20,    -1,
     115,    37,   125,    14,    96,    -1,   115,    37,   125,    14,
      98,    -1,    37,   125,    14,    96,    -1,    37,   125,    14,
      98,    -1,    38,    14,    96,    -1,    38,    14,    98,    -1,
      -1,    73,   118,    -1,    12,    13,    -1,    12,   119,    13,
      -1,   120,    -1,   119,     9,   120,    -1,   125,    -1,    72,
      -1,     9,   125,   122,    -1,    -1,   123,     9,   104,    -1,
     104,    -1,   125,    -1,    -1,   125,    44,   126,    -1,   125,
      45,   126,    -1,   125,    64,   126,    -1,   126,    -1,   128,
      -1,   126,    46,   127,    -1,   126,    47,   127,    -1,   126,
      48,   127,    -1,   126,    63,   127,    -1,   127,    -1,    12,
     125,    13,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,    72,    -1,    45,    68,    -1,    45,    69,    -1,   117,
      -1,    99,    -1,   102,    -1,   104,    -1,    45,   104,    -1,
      12,   101,    13,    -1,    12,   113,    13,    -1,    51,   127,
      -1,   125,   129,   126,    -1,    57,    -1,    59,    -1,    58,
      -1,    60,    -1,    61,    -1,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "expression2", "expression3", "test", "test_comp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
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

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -163
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

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
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

#define yypact_value_is_default(yystate) \
  ((yystate) == (-163))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 146 "SRC/y.tab.y"
    {if(regions_table_add(0, 0, (yyvsp[(2) - (2)].node)) == BAD_REGION) 
                         fatal_error("regions_table");}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 150 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(3) - (3)].node);}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 151 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 152 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 169 "SRC/y.tab.y"
    {if((array = array_new(dimensions_buffer_get_size(), SYMBOL_OF((yyvsp[(7) - (7)].hkey)))) == NULL)
                                                                        fatal_error("array_new");
                                                                      dimensions_buffer_copy(array->dimension);
                                                                      dimensions_buffer_reset();

                                                                      if(!symbol_table_add(hashtable, (yyvsp[(2) - (7)].hkey), SYMBOL_TYPE_ARRAY, 0, array, 0))
                                                                        fatal_error("symbol_table_add");
                                                                     }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 177 "SRC/y.tab.y"
    {if((structure = structure_new(variables_buffer_get_size())) == NULL)
                                                                        fatal_error("structure_new");
                                                                      variables_buffer_copy(structure->field);
                                                                      variables_buffer_reset();

                                                                      if(!symbol_table_add(hashtable, (yyvsp[(2) - (6)].hkey), SYMBOL_TYPE_STRUCT, 0, structure, 0))
                                                                        fatal_error("symbol_table_add");
                                                                     }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 198 "SRC/y.tab.y"
    {if(dimensions_buffer_push((yyvsp[(1) - (3)].val_i), (yyvsp[(3) - (3)].val_i)) == -1)
                                                         {
                                                           fprintf(stderr, "Error: The buffer has reached its limit (%d)\n", 
                                                                   MAX_DIMENSIONS_BUFFER_SIZE);
                                                           exit(EXIT_FAILURE);
                                                         }
                                                        }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 215 "SRC/y.tab.y"
    {if(variables_buffer_push((yyvsp[(1) - (3)].hkey), SYMBOL_OF((yyvsp[(3) - (3)].hkey))) == -1)
                                    {
                                      fprintf(stderr, "Error: The buffer has reached its limit (%d)\n", 
                                              MAX_VARIABLES_BUFFER_SIZE);
                                      exit(EXIT_FAILURE);
                                    }
                                   }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 231 "SRC/y.tab.y"
    {
                                                                    if(!symbol_table_add(hashtable, (yyvsp[(1) - (3)].hkey), SYMBOL_TYPE_VAR, regions_stack_top(), 
                                                                                         SYMBOL_OF((yyvsp[(3) - (3)].hkey)), 0))
                                                                      fatal_error("symbol_table_add");
                                                                    (yyval.hkey) = (yyvsp[(3) - (3)].hkey);
                                                                   }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 237 "SRC/y.tab.y"
    {
                                                                    if(!symbol_table_add(hashtable, (yyvsp[(1) - (3)].hkey), SYMBOL_TYPE_VAR, regions_stack_top(), 
                                                                                         SYMBOL_OF((yyvsp[(3) - (3)].hkey)), 0))
                                                                      fatal_error("symbol_table_add");
                                                                    (yyval.hkey) = (yyvsp[(3) - (3)].hkey);
                                                                   }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 249 "SRC/y.tab.y"
    {
                                                       if((region = regions_table_add(0, ++level, NULL)) == BAD_REGION)
                                                         fatal_error("regions_table_add");
                                                       if(regions_stack_push(region) == -1)
                                                         fatal_error("regions_stack_push");
                                                      }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 256 "SRC/y.tab.y"
    {
                       if((procedure = procedure_new(variables_buffer_get_size())) == NULL)
                         fatal_error("procedure_new");
                       variables_buffer_copy(procedure->params);
                       variables_buffer_reset();
                       
                       region = regions_stack_top();
                       regions_table_set_tree(region, (yyvsp[(5) - (5)].node));
                       level--;
                       regions_stack_pop();

                       if(!symbol_table_add(hashtable, (yyvsp[(2) - (5)].hkey), SYMBOL_TYPE_PROCEDURE, regions_stack_top(), procedure, region))
                         fatal_error("symbol_table_add");
                     }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 272 "SRC/y.tab.y"
    {
                                                                          if((region = regions_table_add(0, ++level, NULL)) == BAD_REGION)
                                                                            fatal_error("regions_table_add");
                                                                          if(regions_stack_push(region) == -1)
                                                                            fatal_error("regions_stack_push");
                                                                         }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 278 "SRC/y.tab.y"
    {
                      if((function = function_new(SYMBOL_OF((yyvsp[(5) - (7)].hkey)), variables_buffer_get_size())) == NULL)
                        fatal_error("function_new");
                      variables_buffer_copy(function->params);
                      variables_buffer_reset();
                      
                      region = regions_stack_top();
                      regions_table_set_tree(region, (yyvsp[(7) - (7)].node));
                      level--;
                      regions_stack_pop();
                      
                       if(!symbol_table_add(hashtable, (yyvsp[(2) - (7)].hkey), SYMBOL_TYPE_FUNCTION, regions_stack_top(), function, region))
                         fatal_error("symbol_table_add");
                    }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 303 "SRC/y.tab.y"
    {variables_buffer_push((yyvsp[(1) - (3)].hkey), SYMBOL_OF((yyvsp[(3) - (3)].hkey)));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 312 "SRC/y.tab.y"
    {(yyval.hkey) = (yyvsp[(1) - (1)].hkey);}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 313 "SRC/y.tab.y"
    {(yyval.hkey) = (yyvsp[(1) - (1)].hkey);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 316 "SRC/y.tab.y"
    {(yyval.hkey) = LBASIC_INT;}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 317 "SRC/y.tab.y"
    {(yyval.hkey) = LBASIC_FLOAT;}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 318 "SRC/y.tab.y"
    {(yyval.hkey) = LBASIC_BOOL;}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 319 "SRC/y.tab.y"
    {(yyval.hkey) = LBASIC_CHAR;}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 320 "SRC/y.tab.y"
    {(yyval.hkey) = LBASIC_CHAR;}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 327 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 330 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 331 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 334 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 335 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 336 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 337 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 338 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 339 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 340 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 341 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 342 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 343 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_RETURN), (yyvsp[(2) - (3)].node));}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 344 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 347 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_new(AT_FUN_RAND);}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 348 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_FUN_WRITE), 
                                                                                                          syntax_tree_add_brother((yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node)));}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 350 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_FUN_READ), 
                                                                                                          (yyvsp[(3) - (4)].node));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 358 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 359 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 362 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 363 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 364 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[(2) - (3)].val_i)), syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 367 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_INC), (yyvsp[(1) - (2)].node));}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 368 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_DEC), (yyvsp[(1) - (2)].node));}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 369 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PINC), (yyvsp[(2) - (2)].node));}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 370 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PDEC), (yyvsp[(2) - (2)].node));}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 373 "SRC/y.tab.y"
    {(yyval.val_i) = AT_OPR_PLUSE;}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 374 "SRC/y.tab.y"
    {(yyval.val_i) = AT_OPR_MINE;}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 375 "SRC/y.tab.y"
    {(yyval.val_i) = AT_OPR_MULTE;}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 376 "SRC/y.tab.y"
    {(yyval.val_i) = AT_OPR_DIVE;}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 377 "SRC/y.tab.y"
    {(yyval.val_i) = AT_OPR_MODE;}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 380 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_VAR), (yyvsp[(2) - (2)].node));}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 383 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_son(
                                                                                syntax_tree_node_new(AT_ARRAY_INDEX), (yyvsp[(2) - (4)].node)), (yyvsp[(4) - (4)].node));}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 385 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_node_hkey_new((yyvsp[(2) - (3)].hkey)), (yyvsp[(3) - (3)].node));}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 386 "SRC/y.tab.y"
    {(yyval.node) = NULL;}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 393 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF),
                                                                                 syntax_tree_add_brother((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)));}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 397 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF), syntax_tree_add_brother((yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node))), 
     syntax_tree_add_son(syntax_tree_node_new(AT_CTL_ELSE), (yyvsp[(6) - (6)].node)));}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 401 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_son(syntax_tree_node_new(AT_CTL_IF), syntax_tree_add_brother((yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node))), 
     syntax_tree_add_son(syntax_tree_node_new(AT_CTL_ELSE), (yyvsp[(6) - (6)].node)));}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 409 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_WHILE), 
                                                                                 syntax_tree_add_brother((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)));}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 413 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_FOR),
                                                                                           syntax_tree_add_brother((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)));}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 415 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_FOR),
                                                                                           syntax_tree_add_brother((yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node)));}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 419 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node)), (yyvsp[(5) - (5)].node));}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 422 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 423 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 426 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 427 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 430 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DO_WHILE),
                                                                                                     syntax_tree_add_brother((yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)));}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 438 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_TERNAIRE),
                                                                           syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node)), (yyvsp[(5) - (5)].node)));}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 446 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_SWITCH),
                                                                       syntax_tree_add_brother(syntax_tree_add_brother((yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node)), (yyvsp[(5) - (6)].node)));}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 450 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother((yyvsp[(1) - (5)].node), 
                                                                                syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE),
                                                                                                    syntax_tree_add_brother((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node))));}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 453 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother((yyvsp[(1) - (5)].node), 
                                                                                syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE),
                                                                                                    syntax_tree_add_brother((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node))));}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 456 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE), 
                                                                                                    syntax_tree_add_brother((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)));}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 458 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CASE), 
                                                                                                    syntax_tree_add_brother((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)));}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 462 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DEFAULT), (yyvsp[(3) - (3)].node));}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 463 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_DEFAULT), (yyvsp[(3) - (3)].node));}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 464 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 471 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_CALL), (yyvsp[(2) - (2)].node));}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 474 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_new(AT_EMPTY);}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 475 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 478 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 479 "SRC/y.tab.y"
    {syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 482 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 489 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[(1) - (1)].val_s));}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 492 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother((yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 493 "SRC/y.tab.y"
    {(yyval.node) = NULL;}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 500 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 501 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 508 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 509 "SRC/y.tab.y"
    {(yyval.node) = NULL;}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 512 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_PLUS), 
                                                                   syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 514 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
                                                                   syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 516 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_OR), 
                                                                   syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 518 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 519 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 522 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MULT), 
                                                                              syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 524 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_DIV), 
                                                                              syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 526 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MOD), 
                                                                              syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 528 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_AND), 
                                                                              syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 530 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 533 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 534 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_int_new((yyvsp[(1) - (1)].val_i));}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 535 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_float_new((yyvsp[(1) - (1)].val_f));}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 536 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_char_new((yyvsp[(1) - (1)].val_c));}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 537 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_bool_new((yyvsp[(1) - (1)].val_c));}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 538 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_string_new((yyvsp[(1) - (1)].val_s));}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 539 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_int_new(-(yyvsp[(2) - (2)].val_i));}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 540 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_node_float_new(-(yyvsp[(2) - (2)].val_f));}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 541 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 542 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 543 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 544 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 545 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
                                                           syntax_tree_add_brother(syntax_tree_node_int_new(0), (yyvsp[(2) - (2)].node)));}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 547 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 548 "SRC/y.tab.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 549 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new(AT_CND_NOT), (yyvsp[(2) - (2)].node));}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 552 "SRC/y.tab.y"
    {(yyval.node) = syntax_tree_add_son(syntax_tree_node_new((yyvsp[(2) - (3)].val_i)), syntax_tree_add_brother((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)));}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 555 "SRC/y.tab.y"
    {(yyval.val_i) = AT_CMP_L;}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 556 "SRC/y.tab.y"
    {(yyval.val_i) = AT_CMP_LE;}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 557 "SRC/y.tab.y"
    {(yyval.val_i) = AT_CMP_G;}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 558 "SRC/y.tab.y"
    {(yyval.val_i) = AT_CMP_GE;}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 559 "SRC/y.tab.y"
    {(yyval.val_i) = AT_CMP_E;}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 560 "SRC/y.tab.y"
    {(yyval.val_i) = AT_CMP_NE;}
    break;



/* Line 1806 of yacc.c  */
#line 2788 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 563 "SRC/y.tab.y"


