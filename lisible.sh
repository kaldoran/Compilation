#!/bin/bash
# REYNAUD NICOLAS 
# mercredi 30 octobre 2013, 21:09:59 (UTC+0100)

# utilisation : ./lisible.sh [Nom fichier]

if test -z "$1"; then
     echo "Erreur : Il faut 1 argument au minimum."
     echo -e "$0 [fichier]"
     exit 1
else
     ./BIN/prog < $1 > out;
     i=0
     for j in $(grep -o "0x[^,) ]*" out); do
	echo "$j -> $i";
	sed -i "s/$j/$i/g" out
	i=$(( i + 1 ));
     done	
fi	
