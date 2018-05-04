#include "analysisResult.h"

AnalysisResult::AnalysisResult(map<string, double> pproba, string pfile):proba(pproba),file(pfile)
{
    ID = 0;
}

AnalysisResult::~AnalysisResult(){}