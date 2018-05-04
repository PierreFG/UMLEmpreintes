//---------- Interface du module <Mat> (fichier Mat.h) --------
#if ! defined ( MAT_H )
#define MAT_H

//------------------------------------------------------------------------
// R�le du module <Mat>
// Contient une matrice et les opérations de base
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include Système


//------------------------------------------------------ Include Personnel
#include "Vect.h"
using namespace std; 
using num = double; 

class Mat
{
public:
	//---------------------------------------------------- Fonctions publiquess


	//-------------------------------------------- Constructeurs - destructeur
	Mat();
	virtual ~Mat();

    Vect& operator[](int i);//indexation
    Mat operator+(const Mat& B);//addition de matrices
    Mat operator*(num c); //multiplication scalaire
    Mat operator*(const Mat& B) ; //multiplication de matrices
    Mat transpose(); //transposée de la matrice
    num get(int i, int j) const ;
    int nbRows() const ;
    int nbColumn() const ;



protected:
	//----------------------------------------------------- Attributs privés
    vector<Vect> data; 
	int m;
};

#endif // MAT_H
