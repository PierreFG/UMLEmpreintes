#include <ctime>
#include "analysisResult.h"
#include "fs/FileServices.h"

AnalysisResult::AnalysisResult(map<string, double> pproba, string pfile) : proba(pproba), file(pfile) {
    printID = 0;
    date = fs::getCurrentTime();
    doctor = make_shared<Doctor>("Faure", "Pierre", "monMail", "a");
}

AnalysisResult::AnalysisResult() {
    printID = 0;
}

AnalysisResult::~AnalysisResult(){}

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
