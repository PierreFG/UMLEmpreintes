//---------- Interface de la classe <analysisResult> (fichier Doctor.h) ----------------
#if ! defined ( ANALYSISRESULT_H )
#define ANALYSISRESULT_H

#include <string>
#include <memory>
#include <map>

#include "print.h"
#include "model/doctor.h"

using namespace std;

/*
* Used as a container for the result of an analysis
*/

class AnalysisResult
{
public:
    AnalysisResult (map<string, double> pproba, string pfile, Doctor_ptr pDoctor, printid_t id);
    /*Constructor*/
    AnalysisResult();
    /*Default constructor*/
    virtual ~AnalysisResult ();
    /*Default destructor*/

    friend ostream& operator<<(ostream& out, const AnalysisResult& r);
    /*Extern overload of the output stream operator*/
    friend istream& operator>>(istream& in, AnalysisResult& r);
    /*Extern overload of the input stream operator*/

    Doctor_ptr getDoctor() const;
    /*Returns the Doctor associated with de Result*/
    string getDate() const;
    /*Returns the date of the Result*/
    long getPrintID() const;
    /*Returns the the id of the associated print*/
    string getFileName() const;
    /*Returns the file path to the print*/
    map<string, double> getProbas() const;
    /*Returns the probas*/

private:
    map<string, double> proba;
    string file;
    string date;
    Doctor_ptr doctor;
    printid_t printID;
};

typedef shared_ptr<AnalysisResult> AnalysisResult_ptr;

#endif // ANALYSISRESULT_H
