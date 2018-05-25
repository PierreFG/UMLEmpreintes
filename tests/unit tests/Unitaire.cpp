#include <iostream>

#include "fs/FileServices.h"
#include "model/doctor.h"

using namespace std;
/*using namespace UI;

void test1(){
	//Vérification de la saisie correcte d'un entier
	int a=0;
	while (cin.good()){
		a = inputInt();
		cout << a << endl;
	}
}*/

void test1(){
	cout << "yo"<<endl;
}

void test2(){
	cout << "lol"<<endl;
	cerr<<"Une erreur"<<endl;
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

int main(){
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
