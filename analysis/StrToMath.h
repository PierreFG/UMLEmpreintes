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

namespace StrToMath
{

	//---------------------------------------------------- Fonctions publiquess
    //listes les valeurs possibles pour chaque attribut de type string des empreintes
    map<int,vector<string>> listVals(vector<Print_ptr> datas);

    //Créer la matrice et le vecteur nécessaire à la régression linéaire
    //M et Y du MX=Y (pour une maladie) :
    pair<Mat,Vect> generateMat(vector<Print_ptr> datas, string disease, map<int,vector<string>> valpossibles);

    //transformer une empreinte en un vecteur de double, cad une ligne de la matrice : en appliquant le one hot coding :
    vector<double> transformPrint(Print_ptr p, map<int,vector<string>> valpossibles);

    //lister les différentes maladies présentes dans le jeu d'empreintes:
    vector<string> listDiseases(vector<Print_ptr> datas);
	//-------------------------------------------- Constructeurs - destructeur

}
#endif // STRTOMATH_H
