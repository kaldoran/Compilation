/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

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
#line 12 "SRC/yacc.y" /* yacc.c:1909  */

  int val_i; 
  float val_f; 
  char val_c; 
  char val_b;
  char *val_s; 
  Hashkey hkey;
  Syntax_tree *node;

#line 210 "SRC/yacc.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_YACC_H_INCLUDED  */
