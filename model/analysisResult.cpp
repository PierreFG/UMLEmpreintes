#include <ctime>
#include "analysisResult.h"
#include "fs/FileServices.h"

AnalysisResult::AnalysisResult(map<string, double> pproba, string pfile):proba(pproba),file(pfile) {
    printID = 0;
<<<<<<< HEAD
    date = fs::getCurrentTime();
=======
    //date = fs::cTimeToString();
>>>>>>> f012e093c848221a3c829941b499a2d71a4a4382
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

