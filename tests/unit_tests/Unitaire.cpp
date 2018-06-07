#include <iostream>

#include <set>
#include <map>
#include <vector>

#include "fs/FileServices.h"
#include "ui/UI.h"
#include "model/doctor.h"
#include "analysis/Vect.h"
#include "analysis/Mat.h"
#include "model/print.h"
#include "model/rule.h"

using namespace std;
using namespace ui;
using namespace fs;

namespace test {
    //TEST des fonctions du fs
    //getPrints
    void UT_1_1() {
        vector<Print_ptr> vp = fs::getPrints("prints.csv");
        for(auto it = vp.begin(); it != vp.end(); it++){
            cout << **it << endl;
        }
    }

    //Generation d'un ID pour le docteur
    void UT_1_2() {
        long long int n;
        cin >> n;
        cin.ignore();
        for(long long int i=0; i<n; i++) {
            cout << generateDoctorID() << endl;
        }
    }

	void UT_1_3(){
		map<string,vector<double>> map1;
        vector<double> v1; v1.push_back(5.0); v1.push_back(4.0);
        map1["rhume"] = v1;
        vector<double> v2; v2.push_back(5.0); v2.push_back(2.0);
        map1["cancer"] = v2;
        vector<double> v3;
        map1["varicelle"] = v3;
        map<int, vector<string>> chaud;
        vector<string> v4; v4.push_back("yo"); v4.push_back("lol");
        chaud[1]=v4;
        vector<string> v5; v5.push_back("kikou");
        chaud[2]=v5;
        Rule_ptr ru = make_shared<Rule>(map1, chaud);
        fs::saveRule(ru);
        Rule_ptr r = fs::getRule();
        cout << "Expected : " << *ru << endl;
        cout << "Obtained : " << *r << endl;
	}
	
	void UT_1_4(){
        Doctor_ptr d = seizeInformation();
        cout << signUpDoctor(d)<<endl;
	}
	
	void UT_1_5(){
		string mail = inputString();
		string mdp = inputString();
        Doctor_ptr d = signInDoctor(mail,mdp);
        cout << *d << endl;
	}
	
	void UT_1_6(){
		Doctor_ptr d = make_shared<Doctor>("Jean", "Michel", "jm@chaudcourriel", "azerty");
		map<string,double> map1;
        map1["rhume"] = 0.9;
        map1["cancer"] = 0.7;
        map1["varicelle"] = 0.3;
        AnalysisResult_ptr a = make_shared<AnalysisResult>(map1,"empreintes", d);
        saveResult(a);
        cout << "Résultat attendu : dtd + xml" << endl;
	}
	
	void UT_1_7(){
		Doctor_ptr d = make_shared<Doctor>("Jean", "Michel", "jm@chaudcourriel", "azerty");
		map<string,double> asso;
		asso["rhume"] = 0.9;
		asso["cancer"] = 0.7;
		asso["varicelle"] = 0.3;
		AnalysisResult_ptr ar = make_shared<AnalysisResult>(asso,"empreintes.csv", d);
		addResultToLog(ar);
		cout << "Résultat attendu (ligne ajoutée à ./data/logs.csv) : 0;aaaa-mm-jj hh:mm:ss;empreintes.csv;0;" << endl;
	}
	
	void UT_1_8(){
		
	}
	
	//TESTS DE UI
	
	void UT_2_1(){
		string s=inputString();
		cout << s << endl;
	}
    
	void UT_2_2(){
		int a = inputInt();
		cout << a << endl;
	}
	
	void UT_2_3(){
		char c = inputChar({'a','b','c'});
		cout << c << endl;
	}
    

    // TEST VECTEURS
    void UT_3_1(){
        //test de la construction de vecteur
        int n;
        cout<<"taille du vecteur?";
        cin>>n;
        Vect v(n);
        v.afficher();
    }

    void UT_3_2(){
        //test de la modif d'un vecteur
        Vect v(3);
        v.afficher();
        v.set(2,(double) 1);
        v.afficher();
    }

    void UT_3_3(){
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
    void UT_3_4(){
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

    void UT_3_5(){
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

    void UT_3_6(){
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

    void UT_3_7(){
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

    void UT_3_8(){
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
    void UT_3_9(){
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

    void UT_3_10(){
        //Test de la génération d'une matrice à partir du set d'empreintes
        vector<Print> V;
        vector<string> S1={"AT","OUI"};
        vector<string> S2={"AA","OUI"};
        vector<int> I1={1,1,4};
        vector<int> I2={1,4,1};
     }

}

using namespace test;


int main() {
    int test=-1;
    cin >> test;
    cin.ignore();
    switch(test){
        case 1:
            UT_1_1();
            break;
        case 2:
            UT_1_2();
            break;
        case 3:
            UT_1_3();
            break;
        case 4:
            UT_1_4();
            break;
        case 5:
            UT_1_5();
            break;
        case 6:
            UT_1_6();
            break;
        case 7:
            UT_1_7();
            break;
        case 8:
            UT_1_8();
            break;
        case 9:
            UT_2_1();
            break;
        case 10:
            UT_2_2();
            break;
        case 11:
            UT_2_3();
            break;
        case 12:
            UT_3_1();
            break;
        case 13:
            UT_3_2();
            break;
        case 14:
            UT_3_3();
            break;
        case 15:
            UT_3_4();
            break;
        case 16:
            UT_3_5();
            break;
       case 17:
            UT_3_6();
            break;
       case 18:
            UT_3_7();
            break;
       case 19:
            UT_3_8();
            break;
       case 20:
            UT_3_9();
            break;
       case 21:
            UT_3_10();
            break;
    }

    return 0;
}
