#include <iostream>

#include <set>

#include "fs/FileServices.h"
#include "ui/UI.h"
#include "model/doctor.h"
#include "analysis/Vect.h"
#include "analysis/Mat.h"
#include "model/print.h"

using namespace std;
using namespace ui;

void test1(){
	//Vérification de la saisie correcte d'un entier
	int a=0;
	while (cin.good()){
		a = inputInt();
		cout << a << endl;
	}
}

void test2(){
	//Vérification du fonctionnement de la saisie d'un char parmi une liste proposée
	char tab[] = {'i','c','q'}, a;
	set<char> expected(tab, tab+3);
	while (cin.good()){
		a = inputChar(expected);
	}
	cout << a << endl;
}

void test3(){
	cerr<<"Juste une erreur"<<endl;
}

void test4(){
	cout <<"division interdite"<<endl;
	int i = 2/0;
}

void TU_05() {
    Doctor doc;
    int i = 0;
    while(cin >> doc) {
        cout << "#" << i++ << ": " << doc;
    }

}

// TEST VECTEURS
void testD1(){
    //test de la construction de vecteur
    int n;
    cout<<"taille du vecteur?";
    cin>>n;
    Vect v(n);
    v.afficher();
}

void testD2(){
    //test de la modif d'un vecteur
    Vect v(3);
    v.afficher();
    v.set(2,(double) 1);
    v.afficher();
}

void testD3(){
    //test des opérations vectorielles
    Vect v(3);
    v.set(2,(double) 1);
    v.set(1,(double) 3);
    Vect u(3);
    u.set(1, (double) 1);
    u.afficher();
    v=v+u;
    v.afficher();

    cout<<v*u<<endl;
    u=u*0.25;
    u.afficher();


}
//TEST MATRICE
void testD4(){
    //construction d'une matrice carrée
    Mat M(2);
    M.afficher();
    //construction d'une matrice quelconque
    Mat Ma(3,2);
    Ma.afficher();
    //modification d'une matrice
    Ma.set(2,1,4);
    Ma.set(0,0,5.2);
    Ma.afficher();
}

void testD5(){
    //test d'une addition
    Mat M(3,2);
    Mat K(3,2);

    M.set(0,0,3);
    K.set(1,0,2);

    M.afficher();
    K.afficher();
    M=M+K;
    M.afficher();
}

void testD6(){
    //test de multiplication
    Mat M(3);
    Mat K(3);
    for(int i=0;i<3;i++){
        for(int j=0; j<3;j++){
           M.set(i,j,i+j) ;
           K.set(i,j,i-j);
        }
    }
    M.afficher();
    K.afficher();
    Mat L=M*K;
    L.afficher();

    Mat O(3,4);
    Mat P(4,3);
    for(int i=0;i<3;i++){
        for(int j=0; j<4;j++){
           O.set(i,j,i+j) ;
           P.set(j,i,i-j);
        }
    }
    O.afficher();
    P.afficher();
    Mat I=O*P;
    I.afficher();
    I=P*O;
    I.afficher();
}

void testD7(){
    //test de la transposée d'une matrice
    Mat M(3);
    for(int i=0;i<3;i++){
        for(int j=0; j<3;j++){
           M.set(i,j,i-j);
        }
    }
    M.afficher();
    Mat K=M.transpose();
    M.afficher();
    K.afficher();

    Mat O(3,4);
    for(int i=0;i<3;i++){
        for(int j=0; j<4;j++){
           O.set(i,j,i+j);
        }
    }
    O.afficher();
    Mat P = O.transpose();
    P.afficher();
    P= P.transpose();
    P.afficher();
}

void testD8(){
    //test de l'inverse d'une matrice
    Mat M(3);
    M.set(0,0,5);
    M.set(0,1,4);
    M.set(0,2,3);
    M.set(1,0,2);
    M.set(1,1,2);
    M.set(1,2,2);
    M.set(2,0,3);
    M.set(2,1,3);
    M.set(2,2,12);
    M.afficher();
    Mat K=M.inv();
    cout<<"Matrice inverse"<<endl;
    K.afficher();
    cout<<"Matrice de base"<<endl;
    M.afficher();
    cout<<"M*M^-1"<<endl;
    Mat U = M*K;
    U.afficher();
    cout<<"M^-1*M"<<endl;
    Mat V = K*M;
    V.afficher();
}
void testD9(){
    //test du changement par ligne
    Mat M(3);
    M.set(0,0,5);
    M.set(0,1,4);
    M.set(0,2,3);
    M.set(1,0,2);
    M.set(1,1,2);
    M.set(1,2,2);
    M.set(2,0,3);
    M.set(2,1,3);
    M.set(2,2,12);
    M.afficher();

}

void testD10{
    //Test de la génération d'une matrice à partir du set d'empreintes
    vector<Print> V;
    vector<string> S1={"AT","OUI"};
    vector<string> S2={"AA","OUI"};
    vector<int> I1={1,1,4}
    vector<int> I2={1,4,1}
    

}

int main() {
	int test;
	cin >> test;
	cin.ignore();
	switch(test){
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
			break;
        case 5:
            TU_05();
            break;
	}
	return 0;
}
