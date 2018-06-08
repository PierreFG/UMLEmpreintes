#include <iostream>
#include <unistd.h>

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

void usage() {
	cerr << "usage : ./app [-i \"setfile.txt\"]" << endl;
	cerr << "There must be the the set file itself (xxx.txt) but also the meta file named meta_xxx.txt." << endl;
	exit(1);
	return;
}

int main(int argc, char* argv[]) {
	//****TRAITEMENT ARGUMENTS
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

	//****MAJ DE LA BASE DE DONNE (si -i)
	if(i) {
		vector<Print_ptr> v;
		v = getPrints(path);
		/*for(auto it=v.begin(); it!=v.end(); it++){
			cout << *(*it) << endl;
		}*/
		if(v.begin()==v.end()){
			cerr << "Something wrong happened, we could'nt find your files." << endl;
			usage();
		}
		PrintRuleMaker *prm = new PrintRuleMaker();

		cout.setstate(std::ios_base::failbit);
		Rule r = prm->generateRule(v);
		cout.clear();

		Rule_ptr r1 = make_shared<Rule>(r);
		cout<<*r1;
		saveRule(r1);
		return 0;
	}

	Rule_ptr rule = getRule();
	if(rule == nullptr) {
		cerr << "Error : No print set was loaded !" << endl;
		usage();
        return -1;
	}
	analyser.SetRule(rule);

	//****MAIN APP
	intro();
	for(;;) {
		Doctor_ptr d = connectionMenu();
		if(d == nullptr) {
			return 0;
		}
		mainMenu(d);
	}

	return 0;
}

/*#include "model/analysisResult.h"
#include <map>
#include "fs/FileServices.h"
using namespace fs;
int main(){
	map<string, double> proba;
	proba["Hepatite"]=39.0; proba["Rhume"]=69.2;
	AnalysisResult_ptr ar = make_shared<AnalysisResult>(proba, "./empreinte01.csv");
	cout << *ar;
	addResultToLog(ar);
	return 0;
}*/
