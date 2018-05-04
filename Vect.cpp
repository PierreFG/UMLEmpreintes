//---------- R�alisation du module <Chainon> (fichier Chainon.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include personnel
#include "Vect.h"

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <cassert>


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

Vect Vect::operator+(const Vect& B) { // Return self+B
	assert(n==B.n); 
    Vect V = Vect(n);
	for(int i=0; i<n; i++){
        V.data[i] = data[i]+B.data[i];
    }
    return V;
}

Vect Vect::operator*(num c){
    Vect V = Vect(n);
    for(int i=0; i<n; i++){
        V.data[i] = data[i]*c;
    }
    return V;
}

Vect::operator num(){
	assert(n==1);
	return data[1]; 
}

//-------------------------------------------- Constructeurs - destructeur

Vect::Vect(){}
Vect::Vect(int pn){
    n=pn;
    data.resize(n);
}
Vect::~Vect(){
}