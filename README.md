Projet de Compilation L3 - Info (Jean Monnet)
============================================

INSTALLATION
------------

Décompresser l'archive dans le dossier de votre choix ou cloner le repository.

Puis, dans le dossier créé, lancer la commande suivante pour compiler : 
    make

Un exécutable au nom de "prog" sera créé dans le dossier BIN.

En cas de soucis essayer la commande 
    make rebuild
Si le soucis persiste, merci de contacter Reynaud Nicolas au 06 79 00...

DÉSINSTALLATION
---------------
Se déplacer à la racine du dossier (dans le répertoire du Makefile) puis exécuter la commande suivante : 
    make mrproper
Cette commande supprimera le contenu du fichier OBJ et l'exécutable "prog".
	
	
UTILISATION
-----------
	Uilisez simplement la commande suivante pour exécuter un programme : 
    ./prog < <prog source>

NOTE
----
La commande 
    ./prog < <prog source>
donne les détails du parsage et affiche les lexèmes, les symboles et les régions avec l'arbre correspondant.


LISTING FICHIER 
---------------
.
+--- defound
+--- Makefile
+--- INC
|   +--- regions_table.h
|   +--- symbol_table.h
|   +--- list.h
|   +--- mystring.h
|   +--- regions_stack.h
|   +--- private_tree.h
|   +--- error.h
|   +--- kernel.h
|   +--- y.tab.h
|   +--- syntax_tree.h
|   +--- dimensions_buffer.h
|   +--- lexeme_table.h
|   +--- variables_buffer.h
|   +--- hashtable.h
|   +--- tree.h
|   +--- ptypes.h
|   +--- private_list.h
|   +--- description_table.h
+--- README.md
+--- BIN
+--- TODO
+--- SRC
|   +--- list.c
|   +--- hashtable.c
|   +--- dimensions_buffer.c
|   +--- main.c
|   +--- variables_buffer.c
|   +--- symbol_table.c
|   +--- syntax_tree.c
|   +--- y.tab.y
|   +--- regions_table.c
|   +--- tree.c
|   +--- regions_stack.c
|   +--- lex.yy.c
|   +--- lex.yy.l
|   +--- error.c
|   +--- lexeme_table.c
|   +--- y.tab.c
|   +--- mystring.c
|   +--- description_table.c
