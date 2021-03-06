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
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------ Include Personnel
using namespace std;

class Vect
{

    friend class Mat;
public:
	//---------------------------------------------------- Fonctions publiquess
    Vect operator+(const Vect& B);//addition de vector
    Vect operator*(double c); //multiplication par un scalaire /!\ v*c et pas c*v sinon cast du vecteur en double
    double operator*(const Vect& B) ; //produit scalaire
    void operator=(const Vect& B);
    int size() const ; //taille du vecteur
    operator double(); //conversion en scalaire si taille 1
    void resize(int l); //modifier taille du vecteur
    void afficher();
    void set(int j, double k);
    int addvalue(double x);
    void clear();
    vector<double> getData();

	//-------------------------------------------- Constructeurs - destructeur
    Vect();
    Vect(int np);
    ~Vect();
    Vect(const Vect&);
    Vect(vector<double>);



private:
	//----------------------------------------------------- Attributs privés
    vector<double> data;
	int n;
};

#endif // VECT_H
