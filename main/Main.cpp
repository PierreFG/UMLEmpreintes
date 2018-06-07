#include <iostream>
#include <unistd.h>

#include "model/doctor.h"
#include "model/rule.h"
#include "fs/FileServices.h"
#include "analysis/PrintAnalyser.h"
#include "ui/UI.h"

using namespace std;
using namespace ui;

void usage() {
	cerr << "usage : ./app [-i]" << endl;
	//exit(1);
	return;
}

int main(int argc, char* argv[]) {
	//****TRAITEMENT ARGUMENTS
	char optstring[]="i";
	int c;
	bool i = false;
	while( (c=getopt (argc, argv, optstring)) != -1 )
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

	//****MAJ DE LA BASE DE DONNE (si -i)
	if(i){
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

/*#include<map>
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
}*/


/*#include "model/rule.h"
#include "fs/FileServices.h"
using namespace fs;
int main(){
	Rule_ptr r = fs::getRule();
	cout << *r;
	return 0;
}*/

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
