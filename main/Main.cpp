#include <iostream>
#include <unistd.h>
using namespace std;

#include "model/doctor.h"
#include "ui/UI.h"
using namespace UI;

void usage(){
	cerr << "usage : ./app [-i]" << endl;
	exit(1);
	return;
}

int main(int argc, char* argv[]) {
	//****TRAITEMENT ARGUMENTS
	char optstring[]="i";
	int c;
	bool i = false;
	while( (c=getopt (argc, argv, optstring)) != EOF ) 
   	{
		switch(c){
			case 'i':
				i = true;
				break;
			case '?':
				usage();
				break;
		}
   	}
	
	//****CHARGEMENT DE LA BASE DE DONNE (si -i)
	if(i){
		return 0;
	}

	//****MAIN APP
	shared_ptr<Doctor> d;
	intro();
	d = connectionMenu();
	if(d=nullptr){
		return 0;
	}
	mainMenu(d);
	
	return 0;
}
