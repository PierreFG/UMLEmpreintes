/**
* IHM.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

#include <iostream>

void IHM::intro(){
	cout << "\033[031m"<<endl;
	cout << "Analyseur d'empreintes" << endl;
	cout << "Application développée dans un contexte de TP \"Génie logiciel\" à l'INSA de Lyon"<<endl
	cout << "Copyrights : Pierre Faure--Giovagnoli, Romain Fournier, Alexis Le Conte, Louis Ohl"<<endl<<endl;
	cout <<"\033[0m";
}

void IHM::connectionMenu(){
	cout << "Bienvenue sur l'analyseur d'empreintes !"<<endl<<endl;
	cout<< "Possédez-vous un compte (o) ou voulez-vous vous inscrire (i) ?"<<endl;
	char res=inputChar();
	while (
	
}

void IHM::mainMenu(){
	
}

int IHM::inputInt(){
	
}

string IHM::inputString(){
	
}

char IHM::inputChar(){
	string resultat=getline(cin);
	char charac=resultat.at(0);
	return charac;
}