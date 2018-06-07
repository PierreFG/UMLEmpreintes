//---------- Interface de la classe <analysisResult> (fichier Doctor.h) ----------------
#if ! defined ( ANALYSISRESULT_H )
#define ANALYSISRESULT_H

#include <string>
#include <memory>
#include <map>

#include "model/doctor.h"

using namespace std;

class AnalysisResult
{

public:
    AnalysisResult (map<string, double> pproba, string pfile, Doctor_ptr pDoctor);
    AnalysisResult();
    virtual ~AnalysisResult ();

    friend ostream& operator<<(ostream& out, const AnalysisResult& r);
    friend istream& operator>>(istream& in, AnalysisResult& r);

    Doctor_ptr getDoctor() const;
    string getDate() const;
    long getPrintID() const;
    string getFileName() const;
     map<string, double> getProbas() const;

protected:
    map<string, double> proba;
    long printID;
    string file;
    string date;
    Doctor_ptr doctor;
};

typedef shared_ptr<AnalysisResult> AnalysisResult_ptr;

#endif // ANALYSISRESULT_H
