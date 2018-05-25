//---------- R�alisation du module <Chainon> (fichier Chainon.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include personnel
#include "analysis/Vect.h"

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <cassert>


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

int Vect::addvalue(double x){
    n=n+1;
    data.push_back(x);
}
void Vect::resize(int l){
    data.resize(l);
    n=l;
}

void Vect::set(int j, double k){
    assert(j<n);
    data[j]=k;
}

void Vect::afficher(){
    for(int i=0;i<n;i++){
        cout<<data[i]<<' ';
    }
    cout<<endl;
}

void Vect::clear(){
    data.clear();
    n=0;
}
//---------------------------------------------------- Surcharge d'opérateurs
Vect Vect::operator+(const Vect& B) {
	assert(n==B.n); 
    Vect V = Vect(n);
	for(int i=0; i<n; i++){
        V.data[i] = data[i]+B.data[i];
    }
    return V;
}

Vect Vect::operator*(double c){
    Vect V = Vect(n);
    for(int i=0; i<n; i++){
        V.data[i] = data[i]*c;
    }
    return V;
}
void Vect::operator=(const Vect& B){
    data.resize(B.n);
    n=B.n;
    for(int i=0;i<n;i++){
        data[i]=B.data[i];
    }
}

double Vect::operator*(const Vect& B){
	assert(n==B.n); 
	double u = 0;
	for(int i=0; i<n;i++){
		u = u + data[i]*B.data[i];
	}
	return u;
}

Vect::operator double(){
	assert(n==1);
	return data[1]; 
}


//-------------------------------------------- Constructeurs - destructeur

Vect::Vect(){
    n=0;
    data.resize(0);
}
Vect::Vect(int pn){
    n=pn;
    data.resize(n);
}
Vect::~Vect(){
}

Vect::Vect(const Vect& V){
    n=V.n;
    data.resize(n);
    for(int i=0;i<n;i++){
        data[i]=V.data[i];
    }
}
//-------------------------------------------- Getter

int Vect::size() const{
	return n;
}


