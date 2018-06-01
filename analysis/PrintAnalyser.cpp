//---------- R?alisation du module <PrintAnalyser> (fichier PrintAnalyser.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include personnel
#include "analysis/Vect.h"
#include "analysis/Mat.h"
#include "fs/FileServices.h"
#include "analysis/PrintAnalyser.h"
#include "StrToMath.h"

//-------------------------------------------------------- Include syst?me
#include <iostream>
#include <cassert>
#include <cmath>

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
AnalysisResult PrintAnalyser :: analysePrint(string file){

    Print p = fs::getPrint(file)[0];
    StrToMath Tools;
    vector<double> printNum = Tools.transformPrint(p, usedRule->getOneHotRule());
    Vect X(printNum);
    map<string,vector<double>> asso = usedRule->getAsso();
    map<string, double> Y;
    double val=0;
    for(auto it=asso.begin();it!=asso.end();++it){
        Vect R(it->second);
        val=X*R;
        Y.insert(pair<string,double>(it->first,val));
    }
    AnalysisResult result(Y,file);
    return result;
    
}
void PrintAnalyser :: SetRule(Rule * r){
    usedRule = r;
}
void PrintAnalyser ::SetDoctor(Doctor* d){
    doctor = d;
}
//-------------------------------------------- Constructeurs - destructeur
PrintAnalyser :: PrintAnalyser(){};
PrintAnalyser :: ~PrintAnalyser(){};