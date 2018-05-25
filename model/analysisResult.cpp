#include "analysisResult.h"

AnalysisResult::AnalysisResult(map<string, double> pproba, string pfile):proba(pproba),file(pfile) {
    printID = 0;
}

AnalysisResult::~AnalysisResult(){}
