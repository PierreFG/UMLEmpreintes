#!/bin/sh

#Avec ce test, on vérifie la bonne màj des règles

here=$(pwd)
cd ..
main=$(pwd)
cd ../..
./app -i "$here/ref1" 1>"$main/$0/out1" 2>"$main/$0/err1"
[ -e "datas/rules.csv" ] && cp -T "datas/rules.csv" "$main/$0/rules1.csv"
./app -i "$here/ref2" 1>"$main/$0/out2" 2>"$main/$0/err2"
[ -e "datas/rules.csv" ] && cp -T "datas/rules.csv" "$main/$0/rules2.csv"

