#include <iostream>
#include <unistd.h>
#include <time.h>

#include "model/doctor.h"
#include "model/rule.h"
#include "fs/FileServices.h"
#include "analysis/PrintAnalyser.h"
#include "ui/UI.h"
#include "analysis/PrintRuleMaker.h"
#include "model/rule.h"
#include "fs/FileServices.h"


using namespace std;
using namespace ui;
using namespace fs;

#ifndef TEST

int main(int argc, char* argv[]) {
	//****Arguments processing
	string path;
	char optstring[]="i:";
	int c;
	bool i = false;
	while( (c=getopt (argc, argv, optstring)) != -1 )
   	{
		switch(c){
			case 'i':
				i = true;
				path = (string) optarg;
				break;
			case '?':
				usage();
				break;
		}
   	}

	//****Updating/Creating rules (if -i argument)
	if(i) {
		vector<Print_ptr> v;
		v = getPrints(path);
		/*for(auto it=v.begin(); it!=v.end(); it++){
			cout << *(*it) << endl;
		}*/
		if(v.begin()==v.end()){
			cerr << "Something wrong happened, we could'nt find your file." << endl;
			usage();
		}
		PrintRuleMaker *prm = new PrintRuleMaker();

		cout.setstate(std::ios_base::failbit); //disable the ouputs
		Rule r = prm->generateRule(v);
		cout.clear();

		Rule_ptr r1 = make_shared<Rule>(r);
		cout<<*r1;
		saveRule(r1);

		return 0;
	}

	//****MAIN APP
	//Loading rules
	Rule_ptr rule = getRule();
	if(rule == nullptr) {
		cerr << "Error : No print set was loaded !" << endl;
		usage();
	}
	analyser.SetRule(rule);

	intro();
	for(;;) {
		Doctor_ptr d = connectionMenu();
		if(d == nullptr) return 0; //exit app

		for(unsigned int i = 0; i < 10; i++)
		{
			cout << endl;
		}

		mainMenu(d);
	}

	return 0;
}

#endif // TEST
