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
    vector<AnalysisResult_ptr> analysePrints(string file);
    void SetRule(Rule_ptr r);
    void SetDoctor(Doctor_ptr d);
//-------------------------------------------- Constructeurs - destructeur

    PrintAnalyser();
    virtual ~PrintAnalyser();
//---------------------------------------------------- Attributs privés
private:
    Rule_ptr usedRule;
    Doctor_ptr doctor;

};

// Instance de PrintAnalyser accessible dans toute l'application
extern PrintAnalyser analyser;

#endif // PRINTANALYSER_H
