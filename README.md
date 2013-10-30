Projet de Compilation L3 - Info (Jean Monnet)
============================================

INSTALLATION
------------

Décompresser l'archive dans le dossier de votre choix ou cloner le repository.

Puis, dans le dossier créé, lancer la commande suivante pour compiler :

    make

Un exécutable au nom de "prog" sera créé dans le dossier BIN.

En cas de soucis essayer la commande :

    make rebuild

Si le soucis persiste, merci de contacter Reynaud Nicolas au 06 79 00...

DÉSINSTALLATION
---------------
Se déplacer à la racine du dossier (dans le répertoire du Makefile) puis exécuter la commande suivante :

    make mrproper

Cette commande supprimera le contenu du fichier OBJ et l'exécutable "prog".
	
	
UTILISATION
-----------
Utiliser simplement la commande suivante pour exécuter un programme : 
    ./prog < <prog source>

NOTE
----
La commande 
    ./prog < <prog source>
donne les détails du parsage et affiche les lexèmes, les symboles et les régions avec l'arbre correspondant.


LISTING FICHIER 
---------------
Voir le fichier README.
