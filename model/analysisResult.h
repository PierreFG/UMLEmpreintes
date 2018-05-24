//---------- Interface de la classe <analysisResult> (fichier Doctor.h) ----------------
#if ! defined ( ANALYSISRESULT_H )
#define ANALYSISRESULT_H

#include <string>
#include <map>
using namespace std;

class AnalysisResult
{

public:
    AnalysisResult (map<string, double> pproba, string pfile);
    virtual ~AnalysisResult ();

protected:
    long ID;
    map<string, double> proba;
    string file;
};

#endif // ANALYSISRESULT_H
