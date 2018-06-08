//---------- R?alisation du module <Mat> (fichier Mat.cpp) ---------

/////////////////////////////////////////////////////////////////  INCLUDE
//------------------------------------------------------ Include personnel
#include "analysis/Vect.h"
#include "analysis/Mat.h"

//-------------------------------------------------------- Include syst?me
#include <iostream>
#include <cassert>
#include <cmath>

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

double Mat::get(int i, int j) const{
	assert(i<m && j<data[0].n);
	return data[i].data[j];
}

Mat Mat::transpose(){
    int n = data[0].n;
	Mat Xt(n , m);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			Xt.data[j].data[i]=data[i].data[j];
		}
	}
	return Xt;
}

Mat Mat::inv(){
    //pivot de Gauss
    assert(m==data[0].n);
    Mat G(*this);
    Mat I(m);
    int r = -1;
    int k=0;
    Vect bufferG;
    Vect bufferI;
    double pivot = 0;
    double val=0;

    for(int j =0;j<m;j++){
        //k=find max sur la colonne
        k=r+1;
        for(int ip=r+1;ip<m;ip++){
            if(abs(G.data[ip].data[j])>abs(G.data[k].data[j])){
                k=ip;
            }
        }
        pivot = G.data[k].data[j];
        if(pivot!=0){
            r++;

             //divise ligne k par A[k,j]
            for(int jp=0;jp<m;jp++){
                I.data[k].data[jp]=((I.data[k].data[jp])/pivot);
                G.data[k].data[jp]=((G.data[k].data[jp])/pivot);
            }
            //swipe line k and r
            bufferG = G.data[r];
            bufferI = I.data[r];
            for(int jp=0;jp<m;jp++){
                G.data[r].data[jp]=G.data[k].data[jp];
                G.data[k].data[jp]=bufferG.data[jp];
                I.data[r].data[jp]=I.data[k].data[jp];
                I.data[k].data[jp]=bufferI.data[jp];
            }
            for(int i=0;i<m;i++){

                if(i!=r){
                    val=(double)(G.data[i].data[j]);
                    I.data[i] =(I.data[i]+((I.data[r])*(((double)(-1))*val)));
                    G.data[i] =(G.data[i]+((G.data[r])*(((double)(-1))*val)));
                }
            }

        }

    }
    G.afficher();
    return I;
}

int Mat::addline(Vect v){
    m=m+1;
    data.push_back(v);
    return m;
}
void Mat::set(int i, int j, double x){
    assert(i<m&&j<data[0].n);
    data[i].data[j]=x;
}

void Mat::afficher(){
    cout<<"matrix "<<m<<" x "<<data[0].n<<endl;
    for(int i=0;i<m;i++){
        data[i].afficher();
    }
    cout<<endl;
}
//---------------------------------------------------- Surcharge d'op�rateur

Mat Mat::operator*(double c){
    int n =data[0].n;
    Mat B = Mat(m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            B.data[i].data[j]= data[i].data[j] * c;
        }
    }
    return B;
}
Mat Mat::operator*(const Mat& B){
    assert(data[0].n==B.m && m ==B.data[0].n);
    int n =data[0].n;
    Mat R = Mat(m,B.data[0].n);
    for(int i=0;i<m;i++){
        for(int j=0;j<B.data[0].n;j++){
            R.data[i].data[j]=0;
            for(int k=0;k<n;k++){
                R.data[i].data[j]+=data[i].data[k]*B.data[k].data[j];
            }
        }
    }
    return R;
}

Mat Mat::operator+(const Mat& B){
    assert(m==B.m && data[0].n==B.data[0].n);
    int n= data[0].n;
    Mat R(m,n);
    for(int i =0; i<m; i++){
        for(int j=0; j<n; j++){
            R.data[i].data[j]=data[i].data[j] + B.data[i].data[j];
        }
    }
    return R;
}

Vect Mat::operator*(const Vect& V){
    assert(data[0].n==V.n);
    Vect R(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<V.n;j++){
            R.data[i]=R.data[i]+data[i].data[j]*V.data[j];
        }
    }
    return R;
}

//-------------------------------------------- Constructeurs - destructeur

Mat::Mat(){
    m=0;
    data.resize(0);
}
Mat::Mat(int pm, int pn){
    m=pm;
	data.resize(pm);
	for(int i=0;i<m;i++){
		data[i].resize(pn);
	}
}

Mat::Mat(const Mat& M){
    m=M.m;
    data.resize(m);
    for(int i=0;i<m;i++){
        data[i].resize(M.data[i].n);
        for(int j=0;j<data[i].n;j++){
            data[i].data[j]=M.data[i].data[j];
        }
    }
}

Mat::Mat(int n){
    m=n;
    data.resize(n);
    for(int i=0;i<n;i++){
        data[i].resize(n);
        data[i].data[i]=1;
    }
}

Mat::~Mat(){

}
//-------------------------------------------- Getter

int Mat::nbColumns() const{
	return data[0].n;
}

int Mat::nbRows() const {
	return m;
}
