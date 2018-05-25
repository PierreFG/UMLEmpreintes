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

//------------------------------------------------------ Include Personnel
#include "model/Print.h"
#include "analysis/Mat.h"
#include "analysis/Vect.h"
using namespace std; 

class StrToMath
{
public:
	//---------------------------------------------------- Fonctions publiquess
    map<int,vector<string>> listVals(vector<Print> datas);
    Mat generateMat(vector<Print> datas, map<int,vector<string>> valpossibles);
    
	//-------------------------------------------- Constructeurs - destructeur
	StrToMath();
    virtual ~StrToMath();
    //------------------------------------------- Surcharge d'opérateurs
    
   
protected:
	//----------------------------------------------------- Attributs privés
    
};

#endif // STRTOMATH_H
