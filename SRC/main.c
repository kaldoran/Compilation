/* ---------------------------------------------------------------------- */
/* Filename: main.c                                                       */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-21 - 17:25:41                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

#include "kernel.h"
#include "save.h"
#include "getopt.h"
#include "exec.h"

/** Fichier de sortie par défaut du programme. */
#define OUTPUT_FILENAME "myout"

/** Options de compilation. */
#define OPT_A 1
#define OPT_E 2
#define OPT_S 4
#define OPT_C 8
#define OPT_O 16

/** Tailles des noms de fichiers. */
#define BUFFER_SIZE_MAX 255

extern int yyparse(void);
extern int yylex_destroy(void);

#define PRINT_TITLE(STR) \
  printf("\n# ------------------------------\n%s\n# ------------------------------\n\n", STR);

#define PRINT_LOG()                 \
  do {                              \
    PRINT_TITLE("LEXEMES");         \
    lexeme_table_print(hashtable);  \
                                    \
    PRINT_TITLE("SYMBOLS");         \
    symbol_table_print(hashtable);  \
                                    \
    PRINT_TITLE("REGIONS");         \
    regions_table_print();          \
  }                                 \
  while(0)

void usage(const char *arg)
{
  fprintf(stderr, "Usage : %s <options>\n", arg);
  fprintf(stderr, "-c <filename> : Compile filename.\n");
  fprintf(stderr, "-o <output filename> : Rename the output.\n");
  fprintf(stderr, "                       By default the name is : %s\n", OUTPUT_FILENAME);
  fprintf(stderr, "-a : Print the compilation log.\n");
  fprintf(stderr, "-e : Run the program after compilation.\n");
  fprintf(stderr, "-s <filename> : Run a compiled program.\n");
  fprintf(stderr, "-h : Help.\n");
  fprintf(stderr, "\nPossible: -c -<oae>\n");
  fprintf(stderr, "          -s -<a>\n");

  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
  int optch;

  extern FILE *yyin;           /* getopt */
  extern char *optarg;         /* getopt */
  extern Hashtable *hashtable; /* yacc */
  extern bool bad_compil;      /* symbol_table */

  int ret = 0;
  int options = 0;

  char input[BUFFER_SIZE_MAX] = "";
  char output[BUFFER_SIZE_MAX] = OUTPUT_FILENAME;

  char format[] = "c:o:aes:h";

  while((optch = getopt(argc, argv, format)) != -1)
    switch(optch)
    {
      case 'a': options |= OPT_A;
        break;
      case 'e': options |= OPT_E;
        break;
      case 'c': options |= OPT_C;
        strcpy(input, optarg);
        break;
      case 'o': options |= OPT_O;
        strcpy(output, optarg);
        break;
      case 's': options |= OPT_S;
        strcpy(input, optarg);
        break;
      case '?':
      case 'h': usage(*argv);
    }

  /* Execution. */
  if(options == OPT_S || options == (OPT_S | OPT_A))
  {
    hashtable = load(input);
    regions_table_load(hashtable, strcat(output, ".reg"));
    symbol_table_init_by_load(hashtable);
    index_array_free(); /* array crée par load */

    if((options & OPT_A) != 0)
      PRINT_LOG();

    /* Execution
       exec(hashtable); */
  }

  /* Compilation. */
  else if((options & OPT_C) != 0 && (options & OPT_S) == 0)
  {
    if((hashtable = hashtable_new()) == NULL)
      fatal_error("main");

    symbol_table_init(hashtable);
    lexeme_table_init(hashtable);

    if((yyin = fopen(input, "r+")) == NULL)
    {
      hashtable_free(hashtable, symbol_table_free);
      fatal_error("main");
    }

    /* Sauvegarde. */
    if(!(ret = yyparse()))
    {
      if(!bad_compil)
      {
        index_array_new(hashtable);
        save(output, hashtable);
        regions_table_save(strcat(output, ".reg"));
        index_array_free();

        if((options & OPT_A) != 0)
          PRINT_LOG();

	/* Execution */
	if((options & OPT_E) != 0)
	  exec(hashtable);
      }
      else
        fprintf(stderr, "ATTENTION : Compilation aborted.\n");
    }

    fclose(yyin);
  }

  /* Erreur. */
  else
    usage(*argv);

  /* Libération */
  yylex_destroy();
  hashtable_free(hashtable, symbol_table_free);
  regions_table_free();

  exit(ret);
}
