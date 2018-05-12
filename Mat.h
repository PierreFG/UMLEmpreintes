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

class Mat
{
public:
	//---------------------------------------------------- Fonctions publiquess

    Mat transpose(); //transposée de la matrice
    double get(int i, int j) const ;
    int nbRows() const ;
    int nbColumns() const ;
    Mat inv(); // inverse de la matrice par la méthode de Gauss-Jordan
    void set(int i, int j, double x);
    void afficher();
	//-------------------------------------------- Constructeurs - destructeur
	Mat();
    Mat(int i, int j);
    Mat(int n);// matrice identité dim n;
	virtual ~Mat();
    Mat(const Mat& M);
    //------------------------------------------- Surcharge d'opérateurs
    Mat operator+(const Mat& B);//addition de matrices
    Mat operator*(double c); //multiplication scalaire
    Mat operator*(const Mat& B) ; //multiplication de matrices
   
protected:
	//----------------------------------------------------- Attributs privés
    vector<Vect> data; 
	int m;
};

#endif // MAT_H
