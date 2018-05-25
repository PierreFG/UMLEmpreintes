//-------------------------------------------------------- Include syst�me
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Mat.h"

using namespace std;

// TEST VECTEURS
void test1(){
    //test de la construction de vecteur
    int n;
    cout<<"taille du vecteur?";
    cin>>n;
    Vect v(n);
    v.afficher();
}

void test2(){
    //test de la modif d'un vecteur
    Vect v(3);
    v.afficher();
    v.set(2,(double) 1);
    v.afficher();
}

void test3(){
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
void test4(){
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

void test5(){
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

void test6(){
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

void test7(){
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

void test8(){
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
void test9(){
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

Mat createX(Mat M){
    int m=M.nbRows();
    int p=M.nbColumns();
    Mat X(m, p+1);
    for(int i=0;i<m;i++){
        X.set(i,0,1);
        for(int j=0;j<p;j++){
            X.set(i,j+1,M.get(i,j));
        }
    }
    return X;
}
void test10(){
    //calcul de l'estimateur :
    int p = 3;
    int n = 10;
    Vect Y(n);
    Y.set(1,1);
    Y.set(3,1);
    Y.set(4,1);
    Y.set(8,1);
    Mat M(n,p);
    M.set(0,0,5);
    M.set(0,1,4);
    M.set(0,2,3);
    M.set(1,0,2);
    M.set(1,1,2);
    M.set(1,2,2);
    M.set(2,0,3);
    M.set(2,1,3);
    M.set(2,2,12);
    M.set(3,0,4);
    M.set(3,1,12);
    M.set(3,2,13);
    M.set(4,0,2);
    M.set(4,1,23);
    M.set(5,1,21);
    M.set(5,2,3);
    M.set(6,0,5);
    M.set(6,1,14);
    M.set(6,2,5);
    M.set(7,0,3);
    M.set(7,1,5);
    M.set(7,2,4);
    M.set(8,0,1);
    M.set(8,1,11);
    M.set(8,2,1);
    M.set(9,0,4);
    M.set(9,1,8);
    M.set(9,2,11);
    M.afficher();
    Mat X = createX(M); //works
    X.afficher();

    Mat G=(X.transpose()*X);
    cout<<"pop"<<endl;
    G=G.inv();
    cout<<"pip"<<endl;
    Vect D = (X.transpose())*Y;;
    cout<<"pup"<<endl;
    Vect R=G*D;
    cout<<"pap"<<endl;

    Vect verif = X*R;

    R.afficher();

    verif.afficher();
    Y.afficher();
    


}
int main(){
    test10();
}

