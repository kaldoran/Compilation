%{
  #include "kernel.h"

  extern int yylex(void);
  extern void yyerror(const char *txt);
  
  Hashtable *hashtable;
%}

%union
{
  int val_i; 
  float val_f; 
  char val_c; 
  char val_b;
  char *val_s; 
  Hashkey hkey;
  Syntax_tree *node;
}

/* -----------------------------------------------------*/
/* TOKENS                                               */
/* -----------------------------------------------------*/

/* Vide */
%token VIDE

/* Fonctions prédefinies */
%token RAND ECRIRE LIRE

/* Ponctuation */
%token CROCHET_OUVRANT CROCHET_FERMANT
%token VIRGULE POINT_VIRGULE POINT
%token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE 
%token DEUX_POINTS 
%token POINT_ET_POINT
%token INTERROGATION

/* Affectation */
%token OPAFF

/* Mots clefs */
%token PROG ACC_DEBUT ACC_FIN
%token SI ALORS SINON 
%token TANT_QUE POUR FAIRE
%token RETOURNE
%token STRUCT FSTRUCT
%token TABLEAU 
%token TYPE
%token DE
%token PROCEDURE FONCTION
%token VARIABLE
%token SWITCH CASE DEFAULT

/* Types */
%token ENTIER REEL BOOLEEN CARACTERE CHAINE

/* Opérateurs */ 
%token PLUS MOINS MULTIPLICATION DIVISION MODULO

 /* Opérateurs binaires */
%token PLUS_ET_PLUS MOINS_ET_MOINS
%token NEGATION

/* Opérateurs raccourcis */
%token PLUS_EGAL MOINS_EGAL MULT_EGAL DIV_EGAL MODULO_EGAL

/* Comparateurs */
%token INFERIEUR 
%token SUPERIEUR 
%token INFERIEUR_OU_EGAL
%token SUPERIEUR_OU_EGAL
%token EGAL 
%token DIFFERENT 
%token ET 
%token OU

/* Break & Continue */
%token CONTINUE
%token BREAK

%token START

/* -----------------------------------------------------*/
/* VALEURS TOKENS                                       */
/* -----------------------------------------------------*/

/* Constantes */
%token <val_i> CSTE_ENTIERE
%token <val_f> CSTE_REELLE
%token <val_c> CSTE_CARACTERE
%token <val_b> CSTE_BOOLEENNE
%token <val_s> CSTE_CHAINE

/* IDF */
%token <hkey> IDF 

%type <hkey> nom_type type_simple
%type <node> corps liste_instructions suite_liste_inst instruction appel

%type <hkey> variable

/* ------------------- */

/* Expressions. */
%type <node> test expression expression2 expression3

/* Boucles. */
%type <node> tant_que pour_cont pour_a pour_e

/* Retour. */
%type <node> resultat_retourne

/* Opérateurs/Affectations/Comparaisons. */
%type <val_i> op_rac test_comp
%type <node> incr_bin affectation affectation_base

%%

/* -----------------------------------------------------*/
/* Programme général                                    */
/* -----------------------------------------------------*/

programme: PROG corps
         ;
          
corps: liste_declarations START liste_instructions {$$ = $3;}
     | START liste_instructions                    {$$ = $2;}
     |                                             {$$ = syntax_tree_node_new(AT_EMPTY);}
     ;

/* -----------------------------------------------------*/
/* Déclarations                                         */
/* -----------------------------------------------------*/

liste_declarations: declaration POINT_VIRGULE
                  | liste_declarations declaration POINT_VIRGULE 
                  ;

declaration: declaration_type
           | declaration_variable
           | declaration_procedure
           | declaration_fonction
           ;
          
declaration_type: TYPE IDF DEUX_POINTS suite_declaration_type
                ;
          
suite_declaration_type: TABLEAU dimension DE nom_type
                      | STRUCT liste_champs FSTRUCT
                      ;

/* -----------------------------------------------------*/
/* Déclarations : TABLEAUX                              */
/* -----------------------------------------------------*/                

dimension: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT
         ;
                                                 
liste_dimensions: une_dimension
                | liste_dimensions VIRGULE une_dimension
                ;
                                                 
une_dimension: expression POINT_ET_POINT expression
             ;
                
/* -----------------------------------------------------*/
/* Déclarations : STRUCTURES                            */
/* -----------------------------------------------------*/
               
liste_champs: un_champ POINT_VIRGULE 
            | liste_champs un_champ POINT_VIRGULE
            ;

un_champ: IDF DEUX_POINTS nom_type
        ;
     
/* -----------------------------------------------------*/
/* Déclarations : VARIABLES                            */
/* -----------------------------------------------------*/     

declaration_variable: VARIABLE declaration_suite_variable DEUX_POINTS nom_type
                    ;
          
declaration_suite_variable: IDF
                          | declaration_suite_variable VIRGULE IDF
                          ;

/* -----------------------------------------------------*/
/* Déclarations  : PROCEDURES/ FONCTIONS                */
/* -----------------------------------------------------*/

declaration_procedure: PROCEDURE IDF liste_parametres corps
                     ;
      
declaration_fonction: FONCTION IDF liste_parametres RETOURNE type_simple corps
                    ;
          
liste_parametres:
                | PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
                | PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
                ;
          
liste_param: un_param
           | liste_param VIRGULE un_param
           ;
          
un_param: IDF DEUX_POINTS nom_type
        ;

/* -----------------------------------------------------*/
/* Déclarations  : TYPES                                */
/* -----------------------------------------------------*/

nom_type: type_simple {$$ = $1;}
        | IDF         {$$ = $1;}
        ;
          
type_simple: ENTIER
           | REEL
           | BOOLEEN
           | CARACTERE
           | CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT /* Chaîne constante */
           ;

/* -----------------------------------------------------*/
/* Instructions                                         */
/* -----------------------------------------------------*/

liste_instructions: ACC_DEBUT suite_liste_inst ACC_FIN {$$ = $2;}
                  ;
          
suite_liste_inst: instruction                  {$$ = $1;}
                | suite_liste_inst instruction 
                ;
                                                             
instruction: POINT_VIRGULE
           | affectation POINT_VIRGULE
           | condition
           | tant_que
           | pour
           | faire_tant_que
           | switch
           | appel POINT_VIRGULE
           | VIDE
           | RETOURNE resultat_retourne POINT_VIRGULE
           | instr_pre POINT_VIRGULE
           ;
     
instr_pre: RAND PARENTHESE_OUVRANTE PARENTHESE_FERMANTE 
         | ECRIRE PARENTHESE_OUVRANTE format suite_ecriture PARENTHESE_FERMANTE 
         | LIRE PARENTHESE_OUVRANTE liste_variables PARENTHESE_FERMANTE 
	 ;

/* -----------------------------------------------------*/
/* Affectation                                          */
/* -----------------------------------------------------*/
  
affectation: affectation_base {$$ = $1;}
           | incr_bin         {$$ = $1;}
           ; 

affectation_base: variable OPAFF expression  {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_EQUAL), syntax_tree_add_brother($1, $3 ));}
                | variable OPAFF ternaire    /* ???????? */
                | variable op_rac expression {$$ = syntax_tree_add_son(syntax_tree_node_new($2), syntax_tree_add_brother($1, $3));}
                ;
 
incr_bin: variable PLUS_ET_PLUS   {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OB_INC), $1);}
        | variable MOINS_ET_MOINS {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OB_DEC), $1);}
        | PLUS_ET_PLUS variable   {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PINC), $2);}
        | MOINS_ET_MOINS variable {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OB_PDEC), $2);}
        ;

op_rac: PLUS_EGAL   {$$ = AT_OPR_PLUSE;}
      | MOINS_EGAL  {$$ = AT_OPR_MINE;}
      | MULT_EGAL   {$$ = AT_OPR_MULTE;}
      | DIV_EGAL    {$$ = AT_OPR_DIVE;}
      | MODULO_EGAL {$$ = AT_OPR_MODE;}
      ;

variable: IDF suite_variable
        ;

suite_variable: suite_variable CROCHET_OUVRANT expression CROCHET_FERMANT
              | suite_variable POINT IDF 
              |
              ;

/* -----------------------------------------------------*/
/* Condition                                            */
/* -----------------------------------------------------*/
  
condition: SI expression ALORS liste_instructions
         | SI expression ALORS liste_instructions SINON liste_instructions
	 | SI expression ALORS liste_instructions SINON condition
         ;

/* -----------------------------------------------------*/
/* Tant que/pour/faire tant que                         */
/* -----------------------------------------------------*/

tant_que: TANT_QUE expression FAIRE liste_instructions {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_CTL_WHILE), 
										 syntax_tree_add_brother($2, $4));}
        ;
    
pour: POUR pour_cont FAIRE liste_instructions
    | POUR PARENTHESE_OUVRANTE pour_cont PARENTHESE_FERMANTE FAIRE liste_instructions
    ;

pour_cont: pour_a POINT_VIRGULE pour_e POINT_VIRGULE pour_a {$$ = syntax_tree_add_brother(syntax_tree_add_brother($1, $3), $5);}
         ;

pour_a: affectation {$$ = $1;}
      |             {$$ = syntax_tree_node_new(AT_EMPTY);}
      ;

pour_e: expression {$$ = $1;}
      |            {$$ = syntax_tree_node_new(AT_EMPTY);}
      ;

faire_tant_que: FAIRE liste_instructions TANT_QUE expression POINT_VIRGULE
              ;

/* -----------------------------------------------------*/
/* Ternaire                                             */
/* -----------------------------------------------------*/

ternaire: expression INTERROGATION expression DEUX_POINTS expression
        ;

/* -----------------------------------------------------*/
/* Switch                                               */
/* -----------------------------------------------------*/

switch: SWITCH expression ACC_DEBUT suite_switch default ACC_FIN
      ;

suite_switch: suite_switch CASE expression DEUX_POINTS liste_instructions
            | suite_switch CASE expression DEUX_POINTS instruction
            | CASE expression DEUX_POINTS liste_instructions
            | CASE expression DEUX_POINTS instruction
            ;

default: DEFAULT DEUX_POINTS liste_instructions
       | DEFAULT DEUX_POINTS instruction 
       |
       ;

/* -----------------------------------------------------*/
/* Appel                                                */
/* -----------------------------------------------------*/

appel: IDF liste_arguments
     ;
          
liste_arguments: PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
               | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
               ;

liste_args: un_arg
          | liste_args VIRGULE un_arg
          ;
          
un_arg: expression
      ;

/* -----------------------------------------------------*/
/* WRITE                                                */
/* -----------------------------------------------------*/

format: CSTE_CHAINE /* ???????? */
      ;
 
suite_ecriture: VIRGULE expression suite_ecriture /* ???????? */
	      |                                   /* ???????? */
              ;

/* -----------------------------------------------------*/
/* READ                                                 */
/* -----------------------------------------------------*/

liste_variables: liste_variables VIRGULE variable /* ???????? */
               | variable                         /* ???????? */
               ;
  
/* -----------------------------------------------------*/
/* EXPRESSIONS                                          */
/* -----------------------------------------------------*/
       
resultat_retourne:            {syntax_tree_node_new(AT_EMPTY);}
                 | expression {$$ = $1;}
                 ;
             
expression: expression PLUS expression2  {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OP_PLUS), 
								   syntax_tree_add_brother($1, $3));}
          | expression MOINS expression2 {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MINUS), 
								   syntax_tree_add_brother($1, $3));}
          | expression OU expression2    {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_CND_OR), 
								   syntax_tree_add_brother($1, $3));}
          | expression2                  {$$ = $1;}
          | test                         {$$ = $1;}
          ;
          
expression2: expression2 MULTIPLICATION expression3 {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MULT), 
									      syntax_tree_add_brother($1, $3));}
           | expression2 DIVISION expression3       {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OP_DIV), 
									      syntax_tree_add_brother($1, $3));}
	   | expression2 MODULO expression3         {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_OP_MOD), 
									      syntax_tree_add_brother($1, $3));}
           | expression2 ET expression3             {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_CND_AND), 
									      syntax_tree_add_brother($1, $3));}
           | expression3                            {$$ = $1;}
           ; 

expression3: PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE
           | CSTE_ENTIERE                                             {$$ = syntax_tree_node_int_new($1);}
           | CSTE_REELLE                                              {$$ = syntax_tree_node_float_new($1);}
           | CSTE_CARACTERE                                           {$$ = syntax_tree_node_char_new($1);}
           | CSTE_BOOLEENNE                                           {$$ = syntax_tree_node_bool_new($1);}
           | CSTE_CHAINE                                              {$$ = syntax_tree_node_string_new($1);}
           | MOINS CSTE_ENTIERE                                       {$$ = syntax_tree_node_int_new(-$2);}
           | MOINS CSTE_REELLE                                        {$$ = syntax_tree_node_float_new(-$2);}
           | appel                                                    {$$ = $1;}
           | instr_pre                                                /* ???????? */
           | incr_bin                                                 /* ???????? */ 
           | variable                                                 {$$ = $1;}
           | MOINS variable                                           /* ???????? */
           | PARENTHESE_OUVRANTE affectation_base PARENTHESE_FERMANTE /* ???????? */
           | PARENTHESE_OUVRANTE ternaire PARENTHESE_FERMANTE         /* ???????? */
           | NEGATION expression3                                     {$$ = syntax_tree_add_son(syntax_tree_node_new(AT_CND_NOT), $2);}
           ;   

test: expression test_comp expression2 {$$ = syntax_tree_add_son(syntax_tree_node_new($2), syntax_tree_add_brother($1, $3));}
    ;

test_comp: INFERIEUR         {$$ = AT_CMP_L;}
         | INFERIEUR_OU_EGAL {$$ = AT_CMP_LE;}
         | SUPERIEUR         {$$ = AT_CMP_G;}
         | SUPERIEUR_OU_EGAL {$$ = AT_CMP_GE;}
         | EGAL              {$$ = AT_CMP_E;}
         | DIFFERENT         {$$ = AT_CMP_NE;}
         ;

%%
