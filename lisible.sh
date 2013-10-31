#!/bin/bash
# REYNAUD NICOLAS 
# mercredi 30 octobre 2013, 21:09:59 (UTC+0100)

# utilisation : ./lisible.sh [Nom fichier]

if test -z "$1"; then
     echo "Erreur : Il faut 2 arguments au minimum."
     echo -e "$0 [fichier]"
     exit 1
else
     #cat $1 > $2;
     i=0
     for j in $(grep -o "0x[^,) ]*" $1); do
	echo "$j -> $i";
	sed -i "s/$j/$i/g" $1
	i=$(( i + 1 ));
     done	
fi	
