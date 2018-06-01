//---------- Interface du module <PrintAnalyser> (fichier PrintAnalyser.h) --------
#if ! defined ( PRINTANALYSER_H )
#define PRINTANALYSER_H

//------------------------------------------------------------------------
// R�le du module <PrintAnalyser>

//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include Système


//------------------------------------------------------ Include Personnel
#include "model/rule.h"
#include "model/doctor.h"
#include "model/analysisResult.h"
#include "model/print.h"

using namespace std; 

class PrintAnalyser{
    //---------------------------------------------------- Fonctions publiques
public:
    AnalysisResult analysePrint(string file);
    void SetRule(Rule * r);
    void SetDoctor(Doctor* d);
//-------------------------------------------- Constructeurs - destructeur

    PrintAnalyser();
    virtual ~PrintAnalyser();
//---------------------------------------------------- Attributs privés
private:
    Rule* usedRule;
    Doctor* doctor;

};
#endif // PRINTANALYSER_H