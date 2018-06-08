//---------- R?alisation du module <PrintAnalyser> (fichier PrintAnalyser.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include personnel
#include "analysis/Vect.h"
#include "analysis/Mat.h"
#include "fs/FileServices.h"
#include "analysis/PrintAnalyser.h"
#include "StrToMath.h"

//-------------------------------------------------------- Include syst?me
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

PrintAnalyser analyser;

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
vector<AnalysisResult_ptr> PrintAnalyser::analysePrints(string file, Doctor_ptr d) {
    vector<AnalysisResult_ptr> results;
    vector<Print_ptr> prints = fs::getPrints(file);
    for(Print_ptr& p : prints) {
        
        vector<double> printNum = StrToMath::transformPrint(p, usedRule->getOneHotRule());
        Vect X(printNum);
        map<string,vector<double>> asso = usedRule->getAsso();
        map<string, double> Y;
        double val=0;
        for(auto it=asso.begin();it!=asso.end();++it){
            
            vector<double> coefs= it->second;
            double termeConstant = coefs[0];
            coefs.erase(coefs.begin());
            Vect R(coefs);            
            cout << "X.size :" << X.size() << " R.size : " << R.size() << endl;
            val=X*R;
            Y.insert(pair<string,double>(it->first,val));
        }
        results.push_back(make_shared<AnalysisResult>(Y, file, d, p->getID()));
    }
    return results;

}
void PrintAnalyser :: SetRule(Rule_ptr r){
    usedRule = r;
}
void PrintAnalyser ::SetDoctor(Doctor_ptr d){
    doctor = d;
}
//-------------------------------------------- Constructeurs - destructeur
PrintAnalyser :: PrintAnalyser(){}
PrintAnalyser :: ~PrintAnalyser(){}
