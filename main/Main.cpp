#include <iostream>
#include <unistd.h>
using namespace std;

#include "ui/UI.h"
using namespace UI;

void usage(){
	cerr << "bad arguments" << endl;
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
   
	intro();
	connectionMenu();
	return 0;
}
