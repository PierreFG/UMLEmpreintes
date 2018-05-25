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
    const string LOGS_PATH = "data/logs/";
    const string DOCTORS_PATH = "data/doctors.csv";

    Doctor_ptr signInDoctor(string username, string password);

    bool signUpDoctor(Doctor_ptr doctor);

    vector<Print> getPrint(string filename);
	//Get the prints associated with the file
	//It also looks at the metadatas in order to
	//have a correct form

}

#endif // FILESERVICES_H_INCLUDED
