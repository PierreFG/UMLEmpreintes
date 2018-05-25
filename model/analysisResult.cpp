#include "analysisResult.h"

AnalysisResult::AnalysisResult(map<string, double> pproba, string pfile):proba(pproba),file(pfile) {
    printID = 0;
}

AnalysisResult::AnalysisResult() {
    printID = 0;
}

AnalysisResult::~AnalysisResult(){}

Doctor_ptr AnalysisResult::getDoctor() const {
    return doctor;
}
