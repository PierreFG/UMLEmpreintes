#!/bin/sh

#Ce test a pour but de verifier le login/logout

here=$(pwd)
cd ..
main=$(pwd)
cd ../..
./app <"$here/inputTS1" 1>"$main/$0/out" 2>"$main/$0/err"
