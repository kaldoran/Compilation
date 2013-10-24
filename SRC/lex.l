%{
  #include "kernel.h"
  #include "yacc.h"

  #ifdef YY_NEED_STRLEN
    #undef YY_NEED_STRLEN
  #endif

  /* ansi. */
  extern int fileno(FILE *stream);
  int yyerror(const char *s);

  /* Numéro de ligne. */
  static int line_num = 1;

  /* Table. */
  extern Hashtable *hashtable;
%}

%option nounput
%option noinput
%option noyywrap

%%

\/\*([^\"\*\/]|\*|(\**\"[^\"]*\"))*\*+\/ ;
\#.* ;
--.*-- ;
\/\/.* ;

".." {return(POINT_ET_POINT);}
"["  {return(CROCHET_OUVRANT);}
"]"  {return(CROCHET_FERMANT);}
","  {return(VIRGULE);}
";"  {return(POINT_VIRGULE);}
"("  {return(PARENTHESE_OUVRANTE);}
")"  {return(PARENTHESE_FERMANTE);}
":"  {return(DEUX_POINTS);}
"="  {return(OPAFF);}

\./[a-zA-Z_][a-zA-Z0-9_]* {return(POINT);}

\"(\\.|[^\"])*\" {
                   if((yylval.val_s = mystrdup(yytext)) == NULL)
                     yyerror("Bad alloc: String");
                   return(CSTE_CHAINE);
                 }

'[^'\\]' {
          yylval.val_c = *yytext; 
          return(CSTE_CARACTERE);
        }

'\\' {
       yylval.val_c = '\\'; 
       return(CSTE_CARACTERE);
     }

'\\t' {
       yylval.val_c = '\t'; 
       return(CSTE_CARACTERE);
     }

'\\n' {
       yylval.val_c = '\n'; 
       return(CSTE_CARACTERE);
     }

'\\r' {
       yylval.val_c = '\r'; 
       return(CSTE_CARACTERE);
     }

(0|[1-9][0-9]*) {
                  yylval.val_i = atoi(yytext);
                  return(CSTE_ENTIERE);
                }

(0|[1-9][0-9]*)?\.[0-9]+ {
                           yylval.val_f = atof(yytext);
                           return(CSTE_REELLE);
                         }

"true"|"false" {
                 yylval.val_b = yyleng == 4;
                 return(CSTE_BOOLEENNE);
               }

rand  {return(RAND);}
write {return(ECRIRE);}
read  {return(LIRE);} 

%[A-Z _0-9]*% {return(PROG);}

"{"         {return(ACC_DEBUT);}
"}"         {return(ACC_FIN);}
if          {return(SI);}
then        {return(ALORS);}
else        {return(SINON);}
while       {return(TANT_QUE);}
for         {return(POUR);}
do          {return(FAIRE);}
return      {return(RETOURNE);}
struct      {return(STRUCT);}
end\ struct {return(FSTRUCT);}
array       {return(TABLEAU);}
type        {return(TYPE);}
of          {return(DE);}
proc        {return(PROCEDURE);}
function    {return(FONCTION);}
var         {return(VARIABLE);}
switch      {return(SWITCH);}
case        {return(CASE);}
default     {return(DEFAULT);}
start       {return(START);}
continue    {return(CONTINUE);}
break       {return(BREAK);}

int    {return(ENTIER);}
float  {return(REEL);}
bool   {return(BOOLEEN);}
char   {return(CARACTERE);}
string {return(CHAINE);}

"+=" {return(PLUS_EGAL);}
"-=" {return(MOINS_EGAL);}
"*=" {return(MULT_EGAL);}
"/=" {return(DIV_EGAL);}
"%=" {return(MODULO_EGAL);}

"++"      {return(PLUS_ET_PLUS);}
"--"      {return(MOINS_ET_MOINS);}
"+"       {return(PLUS);}
"-"       {return(MOINS);}
"*"       {return(MULTIPLICATION);}
"/"       {return(DIVISION);}
"%"       {return(MODULO);}
"!"|"not" {return(NEGATION);}
"?"       {return(INTERROGATION);}

"<"   {return(INFERIEUR);}
"<="  {return(INFERIEUR_OU_EGAL);}
">"   {return(SUPERIEUR);}
">="  {return(SUPERIEUR_OU_EGAL);}
"=="  {return(EGAL);}
"!="  {return(DIFFERENT);}

and {return(ET);}
or  {return(OU);}

[a-zA-Z_][a-zA-Z0-9_]* {
                         if((yylval.hkey = lexeme_table_add(hashtable, yytext)) == NULL)
                           yyerror("Bad alloc: Lexeme");
                         return(IDF);
                       }

" "|\t ;

\n {++line_num;}

%%

int yyerror(const char *s)
{                                                     
  printf("Line %d - Error: %s\n", line_num, s);
  return 0;
}
