    //---------- R?alisation du module <StrToMath> (fichier trToMath.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include personnel
#include "analysis/StrToMath.h"


//-------------------------------------------------------- Include syst?me
#include <algorithm>
#include <cassert>


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
map<int,vector<string>> StrToMath::listVals(vector<Print_ptr> datas){
    int nbStrings = datas[0]->getAttrStr().size();
    int nbPrints = datas.size();
    std::vector<string>::iterator it;
    map<int,vector<string>> valpossibles;
    for(int i=0;i<nbStrings;i++){
        valpossibles.insert(pair<int,vector<string> >(i, vector<string>()));
        for(int j=0; j<nbPrints; j++){
            it=find(valpossibles[i].begin(), valpossibles[i].end(), datas[j]->getAttrStr()[i] );
            if(it == valpossibles[i].end()){
                valpossibles[i].push_back(datas[j]->getAttrStr()[i]);
            }
        }
    }
    return valpossibles;
}

vector<string> StrToMath :: listDiseases(vector<Print_ptr> datas){
    unsigned int nbPrints = datas.size();
    vector<string> valpossibles;
    for(unsigned int i=0;i<nbPrints;i++){
        for(unsigned int j=0; j<datas[i]->getDiseases().size(); j++){
            auto it = find(valpossibles.begin(), valpossibles.end(), datas[i]->getDiseases()[j] );
            if(it == valpossibles.end()){
                valpossibles.push_back(datas[i]->getDiseases()[j]);
            }
        }
    }
    return valpossibles;
}

pair<Mat,Vect> StrToMath::generateMat(vector<Print_ptr> datas, string disease, map<int,vector<string>> valpossibles){
    Mat M;
    Vect Y;
    unsigned int nbPrints = datas.size();
    unsigned int nbDoubles = datas[0]->getAttr().size();
    unsigned int nbStrings = datas[0]->getAttrStr().size();
    unsigned int nbVals=0;
    unsigned int ind =0;
    vector<string> vals;
    Vect buffer;
    std::vector<string>::iterator it;
    for(unsigned int i=0; i<nbPrints; i++){
        for(unsigned int d=0;d<datas[i]->getDiseases().size();d++){
            buffer.clear();
            buffer.addvalue(1);
            for(unsigned int j=0;j<nbDoubles;j++){
                buffer.addvalue(datas[i]->getAttr()[j]);
            }
            for(unsigned int j=0;j<nbStrings;j++){
                vals.clear();
                vals = valpossibles[j];
                nbVals=vals.size();
                it = find(vals.begin(),vals.end(),datas[i]->getAttrStr()[j]);
                assert(it!=vals.end());
                ind = vals.end()-it;
                for(unsigned int k=0;k<nbVals;k++){
                    if(k!=ind){
                        buffer.addvalue(0);
                    }else{
                        buffer.addvalue(1);
                    }
                }
            }
            M.addline(buffer);
            if(datas[i]->getDiseases()[d] == disease){
                Y.addvalue(1);
            }else{
                Y.addvalue(0);
            }
        }
    }
    pair<Mat,Vect> Eq(M,Y);
    return Eq;
}

vector<double> StrToMath::transformPrint(Print_ptr p, map<int,vector<string>> valpossibles){
    int nbDoubles = p->getAttr().size();
    int nbStrings = p->getAttrStr().size();
    int ind=0;
    int nbVals;
    vector<double> result;
    vector<string> vals;
    for(int j=0;j<nbDoubles;j++){
        result.push_back(p->getAttr()[j]);
    }
    for(int j=0;j<nbStrings;j++){
        vals = valpossibles[j];
        nbVals=vals.size();
        auto it = find(vals.begin(),vals.end(),p->getAttrStr()[j]);
        assert(it!=vals.end());
        ind = vals.end()-it;
        for(int k=0;k<nbVals;k++){
            if(k!=ind){
                result.push_back(0);
            }else{
                result.push_back(1);
            }
        }
    }
    return result;
}
//int main(){}
//--------------------------------------------- Constructeurs-Destructeurs

StrToMath :: StrToMath(){

}
StrToMath :: ~StrToMath(){

}


