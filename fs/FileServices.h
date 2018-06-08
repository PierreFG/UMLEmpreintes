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
ostream& operator<<(ostream& ostring, const Doctor& d);
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
    const string LOGS_PATH = "data/logs.csv";
    const string DOCTORS_PATH = "data/doctors.csv";
    const string OUTPUT_PATH = "out/";

    ///*****UTILITY FUNCTIONS
    string getCurrentTime();
    /*  Returns the Date and Time in String Format
    *   Date parsing : jj-mm-yyyy hh:mm:ss
    */

    string itos(int i);
    /* Returns the int parameter parsed to string*/

    int stoi(string s);
    /* Returns the string parameter parsed to int*/

    double stod(string s);
    /* Returns the string parameter parsed to double*/

    ///*****IN&OUT FUNCTIONS
    Doctor_ptr signInDoctor(string username, string password);
    /* Returns a shared pointer to a Doctor if 
    * the parameters match a doctor in the database.
    * Returns nullptr if no doctor was found */

    Doctor_ptr findDoctorByID(doctorid_t id);
    /* Returns a shared pointer to a Doctor if 
    *  the id in parameter matches the one in the database.
    *  Returns nullptr if no doctor was found */
    
    doctorid_t generateDoctorID();
    /* Returns an unique ID for a doctor */

    bool signUpDoctor(Doctor_ptr doctor);
    /* Save a doctor in the database
    *  Returns false if anything wrong happened.
    */

    vector<Print_ptr> getPrints(string filename);
    /* Returns a vector of the prints (shared_pointer) found
    *  at the filde pointed in the path in parameter. 
    */

    bool saveRule(Rule_ptr r);
    /* Save a rule in the database
    *  Returns false if anything wrong happened.
    */

    Rule_ptr getRule();
    /* Returns the current rule in the database
    *  Return nullptr if anything wrong happened.
    */

    bool saveResult(AnalysisResult_ptr r);
    /* Save the AnalysisResult parameter in the out folder
    *  Returns false if anything wrong happened.
    */

    bool addResultToLog(AnalysisResult_ptr r);
    /* Save the AnalysisResult parameter at the end of the logfile
    *  Returns false if anything wrong happened.
    */

    vector<AnalysisResult_ptr> readLogs(doctorid_t doctorID);
    /* Returns the content of a doctor history.
    * (found in the log file)
    */
}

#endif // FILESERVICES_H_INCLUDED
