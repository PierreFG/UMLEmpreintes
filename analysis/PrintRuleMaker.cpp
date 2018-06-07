    //---------- R?alisation du module <PrintRuleMaker> (fichier PrintRuleMaker.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include personnel
#include "analysis/PrintRuleMaker.h"


//-------------------------------------------------------- Include syst?me



//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

Rule PrintRuleMaker::generateRule(vector<Print_ptr> datas){
    vector<string> diseases = StrToMath::listDiseases(datas);
    map<int,vector<string>> valpossibles = StrToMath::listVals(datas);
    map<string,vector<double>> M;
    for(unsigned int i =0; i<diseases.size();i++){
        pair<Mat,Vect> Eq = StrToMath::generateMat(datas, diseases[i], valpossibles);
        Mat G=((Eq.first).transpose()*(Eq.first));
        G=G.inv();
        Vect D = ((Eq.first).transpose())*(Eq.second);
        Vect R=G*D;
        M.insert(pair<string, vector<double>>(diseases[i],R.getData()));
    }
    Rule Rl(M,valpossibles);
    return Rl;
}

//-------------------------------------------- Constructeurs - destructeur
PrintRuleMaker :: PrintRuleMaker(){

}

PrintRuleMaker :: ~PrintRuleMaker(){

}
