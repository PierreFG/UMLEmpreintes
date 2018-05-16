#include <iostream>
#include "UI.h"

using namespace std;
using namespace UI;

void test1(){
	//Vérification de la saisie correcte d'un entier
	int a=0;
	while (cin.good()){
		a = inputInt();
		cout << a << endl;
	}
}

void test2(){

}

void test3(){

}

int main(){
	test1();
	return 0;
}
