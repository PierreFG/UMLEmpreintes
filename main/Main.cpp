#include <iostream>
#include <unistd.h>
//#include "./ui/UI.h"
//optarg
using namespace std;
//using namespace UI;

void error(){
	cerr << "bad arguments" << endl;
}

int main(int argc, char* argv[]) {
	//****TRAITEMENT ARGUMENTS
	bool i = false;
	if(argc > 2){
		error();
		return 1;
	}else if(argv[1]){
		cout << argv[1];
	}


	/**intro();
	connectionMenu();**/
	return 0;
}
