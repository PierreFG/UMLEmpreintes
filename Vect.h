//---------- Interface du module <Mat> (fichier Mat.h) --------
#if ! defined ( VECT_H )
#define VECT_H

//------------------------------------------------------------------------
// Rôle du module <Vect>
// Contient une vecteur et les opérations de base
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include Système
#include<vector>
//------------------------------------------------------ Include Personnel
using namespace std; 
using num = double; 

class Vect
{
public:
	//---------------------------------------------------- Fonctions publiquess
    Vect operator+(const Vect& B);//addition de vector
    Vect operator*(num c); //multiplication par un scalaire
    Vect operator*(const Vect& B) ; //produit scalaire
    int size() const ; //taille du vecteur
    operator num(); //conversion en scalaire si taille 1

	//-------------------------------------------- Constructeurs - destructeur
    Vect();
    Vect(int np);
    ~Vect();




protected:
	//----------------------------------------------------- Attributs privés
    vector<num> data; 
	int n;
};

#endif // VECT_H