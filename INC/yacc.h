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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_YACC_H_INCLUDED  */
