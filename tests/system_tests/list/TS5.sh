#!/bin/sh

#Avec ce test, on vérifie la bonne màj des règles

here=$(pwd)
cd ..
main=$(pwd)
cd ../..
before=$(date +%s)
./app -i "$here/huge" 1>"$main/$0/out" 2>"$main/$0/err"
now=$(date +%s)
echo "L'analyse a pris :"
c= $now-$before
echo $c
