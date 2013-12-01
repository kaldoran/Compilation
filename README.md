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

Si le soucis persiste, merci nous contacter.

NETTOYAGE
---------
Se déplacer à la racine du dossier (dans le répertoire du Makefile) puis exécuter la commande suivante :

    make mrproper

Cette commande supprimera le contenu du fichier OBJ et l'exécutable "prog".
	
DÉSINSTALLATION
---------------
Supprimer simplement le dossier que vous aviez décompressé (ou cloné).
	
UTILISATION
-----------

    ./prog -c filename [-oae]
    ./prog -s filename [-a]
    ./prog -h

OPTIONS
-------

    -c <filename> : Compile filename

    -o <output filename> : Renomme la sortie (par défaut : myout)

    -a : Affiche le log de compilation

    -e : Exécute le programme après compilation

    -s <filename> : Exécute un programme compilé

    -h : Affiche l'aide

AUTEURS
-------
ABHAMON Ronan

BIGARD Florian

REYNAUD Nicolas
