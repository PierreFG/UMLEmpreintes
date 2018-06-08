#!/bin/sh

here=$(pwd)
cd ..
main=$(pwd)
cd ../..
./app -i "$here/ref1" 1>"$main/$0/out" 2>"$main/$0/err"
[ -e "$main/$0/out" ] && rm "$main/$0/out"
[ -e "$main/$0/err" ] && rm "$main/$0/err"
#Now that is is quite updated, let's get on
chmod 333 "$here/test_ref1"
./app <"$here/inputTS3" 1>"$main/$0/out" 2>"$main/$0/err"
[ -e "$here/test_ref1.xml" ] && cp -T "$here/test_ref1.xml" "$main/$0/CR.xml"
rm "$here/*.xml"
chmod 700 "$here/test_ref1"
