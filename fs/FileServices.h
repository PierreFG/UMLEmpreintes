#ifndef FILESERVICES_H_INCLUDED
#define FILESERVICES_H_INCLUDED

#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>

#include "model/doctor.h"
#include "model/print.h"
#include "model/analysisResult.h"
#include "model/rule.h"

using namespace std;

// Operator overloading for model classes
ostream& operator<<(ostream& out, const Doctor& d);
istream& operator>>(istream& in, Doctor& d);

ostream& operator<<(ostream& out, const Print& p);
istream& operator>>(istream& in, Print& p);

ostream& operator<<(ostream& out, const AnalysisResult& r);
istream& operator>>(istream& in, AnalysisResult& r);

ostream& operator<<(ostream& out, const Rule& r);
istream& operator>>(istream& in, Rule& r);

namespace fs {

    const string FORMAT_PATH = "data/format.cfg";
    const string RULES_PATH = "data/rules.csv";
	const string ONE_HOT_RULE_PATH= "data/ohrule.csv";
    const string LOGS_PATH = "data/logs/";
    const string DOCTORS_PATH = "data/doctors.csv";

    Doctor_ptr signInDoctor(string username, string password);

    bool signUpDoctor(Doctor_ptr doctor);

<<<<<<< HEAD
    vector<Print> getPrints(string filename);
=======
    vector<Print> getPrint(string filename);
<<<<<<< HEAD

    bool saveRule(Rule_ptr r);

=======
>>>>>>> 8fa95ffead5f0fecae9e7c595a423bd90297d2d8
	//Get the prints associated with the file
	//It also looks at the metadatas in order to
	//have a correct form

	void saveOneHotString(map<string, int> oneHot);
	/* This saves the one hot coding associated with a string
	* the integer specifies the number of the string column
	* of the matrix which should be set to 1.
	*/
	
	map<string, int> loadOneHotString();
	/* Loads in memory from a file the one hot coding transposition
	* of every possible string in a print. See method saveOneHotString above.
	*/
	
<<<<<<< HEAD

    bool saveRule(Rule_ptr r);
=======
>>>>>>> d6e15725e18882c2bd467b6ed25cf3792a51d7c4
>>>>>>> 8fa95ffead5f0fecae9e7c595a423bd90297d2d8
}

#endif // FILESERVICES_H_INCLUDED
