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

/*int main(int argc, char* argv[]) {
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
}*/

#include<map>
#include<vector>
#include "model/rule.h"
#include "fs/FileServices.h"
using namespace fs;

int main(){
	map<string,vector<double>> map1;
	vector<double> r; r.push_back(5.0); r.push_back(4.0);
	map1["rhume"] = r;
	vector<double> c; c.push_back(5.0); c.push_back(2.0);
	map1["cancer"] = c;
	Rule_ptr ru = make_shared<Rule>(map1);
	
	if(saveRule(ru)){
		cout << "Rule saved !" << endl;
	}else{
		cout << "Something wrong happened..." << endl;
	}

	return 0;
}
