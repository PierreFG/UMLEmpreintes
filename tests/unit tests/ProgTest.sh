#!/bin/sh

#Le but de ce script est de faire dérouler un à un les tests unitaires.
#Il suffit seulement de démarrer cet utilitaire à l'aide de la commande :
#bash ProgTest.sh
#Cet utilitaire renverra ensuite un framework bien formé (normalement)
#avec le résultat de l'ensemble des tests


#Dans un premier temps, compiler le fichier test unitaire
echo "Compilation du fichier Unitaire.cpp"

g++ Unitaire.cpp -o tester -std=c++11

if [ ! -e tester ]
then
	echo -e "\033[31mLa compilation du testeur a échoué, veuiller corriger les fautes.\033[0m"
	exit
fi

#Le fichier a été compilé, on peut donc commencer à générer le framework

#clean de ce qu'il y avait avant
rm -rf Test*

#Combien de tests ?
echo -n "Combien y a-t-il de test ? "
reponse=0
read reponse

#On parse le fichier d'input pour que tout soit plus facile
i=0
k=1
while [ "$i" -le "$reponse" ]
do
	a=$(sed "$k!d" inputFile)
	if [[ "$a" != "%"Test* && "$a" != "" ]]
	then
		echo "$a" >> "input"$i
	else
		[ "$i" -ne "0" ] && echo "" >> "input"$i
		i=$(($i+1))
		[ "$i" -le "$reponse" ] && echo "$i" >> "input"$i
	fi
	k=$(($k+1))
done

#Maintenant, il suffit de faire tourner le programme pour générer les tests
i=1
err=0
out=0
while [ "$i" -le "$reponse" ]
do
	echo "Test "$i
	mkdir "Test"$i
	./tester 1>"Test"$i"/std.out" 2>"Test"$i"/std.err" <"input"$i
	rm "input"$i
	cd "Test"$i
	for fichier in $(ls)
	do
		vide=$(du $fichier | cut -f1)
		[ "$vide" -eq "0" ] && rm $fichier
	done
	[ -e "std.err" ] && err=$(($err+1))
	[ -e "std.out" ] && out=$(($out+1))
	cd ..
	echo -e "\n\n"
	i=$(($i+1))
done 

#Génération du compte-rendu sur les tests
echo "Tests ayant un affichage cerr : "$err
