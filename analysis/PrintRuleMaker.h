//---------- Interface du module <PrintRuleMaker> (fichier PrintRuleMaker.h) --------
#if ! defined ( PRINTRULEMAKER_H )
#define PRINTRULEMAKER_H

//------------------------------------------------------------------------
// R�le du module <StrToMath>
// Détermine la règle de transformation des attributs string en valeur mathématique
//(One hot coding)
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include Système


//------------------------------------------------------ Include Personnel
#include "analysis/StrToMath.h"
#include "model/rule.h"

using namespace std; 

class PrintRuleMaker{

public:


//---------------------------------------------------- Fonctions publiquess
    Rule generateRule(vector<Print> datas);
	//-------------------------------------------- Constructeurs - destructeur
	PrintRuleMaker();
    virtual ~PrintRuleMaker();
    //------------------------------------------- Surcharge d'opérateurs   

};
#endif //PRINTRULEMAKER_H