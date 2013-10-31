#!/bin/bash
# REYNAUD NICOLAS 
# jeudi 31 octobre 2013, 01:06:03 (UTC+0100)


function changepointer() {
     i=0
     #echo -e "\t\tFile : $1\n";
     for j in $(grep -o "0x[^,) ]*" $1); do
  	#echo "$j -> $i";
	sed -i "s/$j/$i/g" $1
	i=$(( i + 1 ));   
     done
}

function sub() {
     ./BIN/prog -a -c "$1" > out;
     changepointer out
     ./BIN/prog -a -s myout > out2
     changepointer out2
     echo -e  "Différence(s) pour $1: \n\n"
     diff out out2 | grep ">" | sed "s/> //g"
}

if test -z "$1"; then
     echo "Erreur : Il faut 1 argument au minimum."
     echo -e "$0 [ARG 1]"
     exit 1
else
	for i in $(find "$1" -type f ! -name "marche_pas"); do
		sub "$i"
		#rm out
		#rm out2
		sleep 2

	done	
fi
