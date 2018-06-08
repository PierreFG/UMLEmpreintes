#include "analysisResult.h"
#include "fs/FileServices.h"

using namespace fs;

Doctor_ptr AnalysisResult::getDoctor() const {
    return doctor;
}

string AnalysisResult::getDate() const{
    return date;
}

long AnalysisResult::getPrintID() const {
 return printID;
}

string AnalysisResult::getFileName() const {
    return file;
}

map<string, double> AnalysisResult::getProbas() const {
    return proba;
}

//***********Constructor/Destructor
AnalysisResult::AnalysisResult(map<string, double> pproba, string pfile, Doctor_ptr pDoctor, printid_t id) :
    proba(pproba), file(pfile), printID(id) {
    date = getCurrentTime();
    doctor = pDoctor;
}

AnalysisResult::AnalysisResult() {
    printID = 0;
}

AnalysisResult::~AnalysisResult(){}
