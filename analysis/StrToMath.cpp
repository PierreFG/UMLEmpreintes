    //---------- R?alisation du module <StrToMath> (fichier trToMath.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include personnel
#include "analysis/StrToMath.h"
#include "analysis/Vect.h"


//-------------------------------------------------------- Include syst?me
#include <algorithm>
#include <cassert>

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
map<int,vector<string>> StrToMath :: listVals(vector<Print> datas){
    int nbStrings = datas[0].getAttrStr().size();
    int nbPrints = datas.size();
    std::vector<string>::iterator it;
    map<int,vector<string>> valpossibles;
    for(int i=0;i<nbStrings;i++){
        valpossibles.insert(pair<int,vector<string> >(i, vector<string>()));
        for(int j=0; j=0; j<nbPrints){
            it=find(valpossibles[i].begin(), valpossibles[i].end(), datas[j].getAttrStr()[i] );
            if(it == valpossibles[i].end()){
                valpossibles[i].push_back(datas[j].getAttrStr()[i]);
            }
        }
    }
    return valpossibles;
}
Mat StrToMath :: generateMat(vector<Print> datas){
    map<int,vector<string>> valpossibles = listVals(datas);
    Mat M;
    int nbPrints = datas.size();
    int nbDoubles = datas[0].getAttr().size();
    int nbStrings = datas[0].getAttrStr().size();
    int nbVals=0;
    int ind =0;
    vector<string> vals;
    Vect buffer;
    std::vector<string>::iterator it;
    for(int i=0; i<nbPrints; i++){
        buffer.clear();
        for(int j=0;j<nbDoubles;j++){
            buffer.addvalue(datas[i].getAttr()[j]);
        }
        for(int j=0;j<nbStrings;j++){
            vals.clear();
            vals = valpossibles[j];
            nbVals=vals.size();
            it=find(vals.begin(),vals.end(),datas[i].getAttrStr()[j]);
            assert(it!=vals.end());
            ind = vals.end()-it;
            for(int k=0;k<nbVals;k++){
                if(i!=ind){
                    buffer.addvalue(0);
                }else{
                    buffer.addvalue(1);
                }
            }
        }
        M.addline(buffer);
    }
    return M;
}

//int main(){}
//--------------------------------------------- Constructeurs-Destructeurs

StrToMath :: StrToMath(){

}
StrToMath :: ~StrToMath(){

}


