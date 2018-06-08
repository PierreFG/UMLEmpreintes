#!/bin/sh

#Compiling time--------------------------------

if [ "$1" == "compile" ]; then
	here=$(pwd)
	cd ../..
	appFolder=$(pwd)
	g++ ui/*.cpp main/*.cpp fs/*.cpp model/*.cpp analysis/*.cpp -I "." -o app -std=c++11
	[ -e app ] || echo "Il y a eu une erreur"
	[ -e app ] || exit
	cd "$here"
fi
#Now, we need to run every subtest. Easy.
cd list
for script in $(ls -1)
do
	[ -e "$script" ] || continue # skip if not file
	[[ $script =~ .*sh.* ]] || continue
	[ -d "../$script" ] || mkdir "../$script"
	
	bash "$script"
done
cd "$here"
