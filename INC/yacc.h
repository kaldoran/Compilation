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
    CSTE_ENTIERE = 272,
    CSTE_REELLE = 273,
    CSTE_BOOLEENNE = 274,
    CSTE_CARACTERE = 275,
    CSTE_CHAINE = 276,
    OPAFF = 277,
    IDF = 278,
    PROG = 279,
    ACC_DEBUT = 280,
    ACC_FIN = 281,
    SI = 282,
    ALORS = 283,
    SINON = 284,
    TANT_QUE = 285,
    POUR = 286,
    FAIRE = 287,
    RETOURNE = 288,
    STRUCT = 289,
    FSTRUCT = 290,
    TABLEAU = 291,
    TYPE = 292,
    DE = 293,
    PROCEDURE = 294,
    FONCTION = 295,
    VARIABLE = 296,
    SWITCH = 297,
    CASE = 298,
    DEFAULT = 299,
    ENTIER = 300,
    REEL = 301,
    BOOLEEN = 302,
    CARACTERE = 303,
    CHAINE = 304,
    PLUS = 305,
    MOINS = 306,
    MULTIPLICATION = 307,
    DIVISION = 308,
    MODULO = 309,
    PLUS_ET_PLUS = 310,
    MOINS_ET_MOINS = 311,
    NEGATION = 312,
    PLUS_EGAL = 313,
    MOINS_EGAL = 314,
    MULT_EGAL = 315,
    DIV_EGAL = 316,
    MODULO_EGAL = 317,
    INFERIEUR = 318,
    SUPERIEUR = 319,
    INFERIEUR_OU_EGAL = 320,
    SUPERIEUR_OU_EGAL = 321,
    EGAL = 322,
    DIFFERENT = 323,
    ET = 324,
    OU = 325,
    CONTINUE = 326,
    BREAK = 327,
    START = 328
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
#define CSTE_ENTIERE 272
#define CSTE_REELLE 273
#define CSTE_BOOLEENNE 274
#define CSTE_CARACTERE 275
#define CSTE_CHAINE 276
#define OPAFF 277
#define IDF 278
#define PROG 279
#define ACC_DEBUT 280
#define ACC_FIN 281
#define SI 282
#define ALORS 283
#define SINON 284
#define TANT_QUE 285
#define POUR 286
#define FAIRE 287
#define RETOURNE 288
#define STRUCT 289
#define FSTRUCT 290
#define TABLEAU 291
#define TYPE 292
#define DE 293
#define PROCEDURE 294
#define FONCTION 295
#define VARIABLE 296
#define SWITCH 297
#define CASE 298
#define DEFAULT 299
#define ENTIER 300
#define REEL 301
#define BOOLEEN 302
#define CARACTERE 303
#define CHAINE 304
#define PLUS 305
#define MOINS 306
#define MULTIPLICATION 307
#define DIVISION 308
#define MODULO 309
#define PLUS_ET_PLUS 310
#define MOINS_ET_MOINS 311
#define NEGATION 312
#define PLUS_EGAL 313
#define MOINS_EGAL 314
#define MULT_EGAL 315
#define DIV_EGAL 316
#define MODULO_EGAL 317
#define INFERIEUR 318
#define SUPERIEUR 319
#define INFERIEUR_OU_EGAL 320
#define SUPERIEUR_OU_EGAL 321
#define EGAL 322
#define DIFFERENT 323
#define ET 324
#define OU 325
#define CONTINUE 326
#define BREAK 327
#define START 328

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_YACC_H_INCLUDED  */
