//---------- Interface du module <StrToMath> (fichier StrToMath.h) --------
#if ! defined ( STRTOMATH_H )
#define STRTOMATH_H

//------------------------------------------------------------------------
// R�le du module <StrToMath>
// Détermine la règle de transformation des attributs string en valeur mathématique
//(One hot coding)
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include Système
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>

//------------------------------------------------------ Include Personnel
#include "model/print.h"
#include "analysis/Mat.h"
#include "analysis/Vect.h"

using namespace std; 

class StrToMath
{
public:
	//---------------------------------------------------- Fonctions publiquess
    map<int,vector<string>> listVals(vector<Print> datas);
    pair<Mat,Vect> generateMat(vector<Print> datas, string disease, map<int,vector<string>> valpossibles);
    vector<double> transformPrint(Print p, map<int,vector<string>> valpossibles);
    vector<string> listDiseases(vector<Print> datas);
	//-------------------------------------------- Constructeurs - destructeur
	StrToMath();
    virtual ~StrToMath();
    //------------------------------------------- Surcharge d'opérateurs
    
   
protected:
	//----------------------------------------------------- Attributs privés
    
};
#endif // STRTOMATH_H
