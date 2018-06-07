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

void usage(){
	cerr << "usage : ./app [-i]" << endl;
	//exit(1);
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
	if(i){
		vector<Print> v;
		v = getPrint(path);
		cout << "coucou2" << endl;
		PrintRuleMaker *prm = new PrintRuleMaker();
		Rule r = prm->generateRule(v);
		cout << "coucou2" << endl;
		Rule_ptr r1 = make_shared<Rule>(r);
		cout<<*r1;
		return 0;
	}

	Rule_ptr rule = fs::getRule();
	if(rule == nullptr) {
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
