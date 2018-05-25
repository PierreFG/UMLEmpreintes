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


//------------------------------------------------------ Include Personnel
#include "model/Print.h"
using namespace std; 

class StrToMath
{
public:
	//---------------------------------------------------- Fonctions publiquess
    void count(vector<Print> datas);
    
	//-------------------------------------------- Constructeurs - destructeur
	
    //------------------------------------------- Surcharge d'opérateurs
    
   
protected:
	//----------------------------------------------------- Attributs privés
    
};

#endif // STRTOMATH_H
