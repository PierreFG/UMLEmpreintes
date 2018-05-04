/**
* UI.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

//todo : creer manipulateur de couleur et formattage de texte param�trable pour meilleure esthetique (classe)

#include <iostream>
#include <set>
#include "../modele/doctor.h"
#include "UI.h"


UI::intro(){
	cout << "\033[031m"<<endl;
	cout << "Analyseur d'empreintes" << endl;
	cout << "Application developpee dans un contexte de TP \"Genie logiciel\" a l'INSA de Lyon"<<endl;
	cout << "Copyrights : Pierre Faure--Giovagnoli, Romain Fournier, Alexis Le Conte, Louis Ohl"<<endl<<endl;
	cout <<"\033[0m";
}

void UI::connectionMenu(){
	cout << "Bienvenue sur l'analyseur d'empreintes !"<<endl<<endl;
	
	bool notConnected=true;
	cout<< "Possedez-vous un compte (c) ou voulez-vous vous inscrire (i) ?"<<endl;
	cout<<"Pour quitter l'application, tapez (q)"<<endl;
	char tab[] = {'i','c','q'};
	set<char> expected(tab, tab+3); 
	char res=inputChar(expected);
	if (res=='i'){
		cout << "Inscription"<<endl;
	}
	if (res=='c'){
		cout << "CouCou"<<endl;
	}
	if (res=='q'){
		notConnected=false;
		cout <<"Quitter"<<endl;
	}
}

void UI::mainMenu(Doctor d){
	cout << "Bonjour M." << endl;
}

int UI::inputInt(){
	bool ok=false;
	int res=0;
	while(!ok){
		string line;
		getline(cin, line);
		try{
			res = stoi(line);
			ok=true;
		}catch(exception e){

		}
	}
	return res;
}

string UI::inputString(){
	string line;
	getline(cin, line);
	return line;
}

char UI::inputChar(set<char> expected){
	char charac='\0';
	bool ok=false;
	while (!ok){
		string result;
		getline(cin, result);
		if (result==""){
			charac='\0';
		} else {
			charac=result[0];
		}
		if (expected.find(charac)==expected.end()){
			cout << "Ce caract�re n'est pas demand� !"<<endl;
		} else {
			ok=true;
		}
	}
	
	return charac;
	
}

Doctor UI::seizeInformation(){
	cout <<"Formulaire d'inscription"<<endl<<endl;
	bool ok=false;
	string firstname, lastname, email, password, confirm;
	do{
		cout <<"Veuillez rentrer votre prenom :"<<endl;
		firstname=inputString();
		cout << "Veuillez rentrer votre nom de famille :"<<endl;
		lastname=inputString();
		cout <<"Veuillez saisir votre email (il vous servira d'identifiant) :"<<endl;
		email=inputString();
		bool pwd=false;
		while (!pwd){
			cout <<"Veuillez saisir votre mot de passe :" << endl;
			password=inputString();
			cout << "Veuillez confirmer votre mot de passe :" << endl;
			confirm = inputString();
			if (password==confirm){
				pwd=true;
			} else {
				cout << "Vos mots de passe ne correspondent pas, veuillez les re-saisir !"<<endl;
			}
		}
		cout << "Vous etes : " << firstname << " " << lastname << ". ";
		cout << "Votre mail : " << email<<endl;
		cout << "Ces informations vous correspondent-elles ? (o/n)" <<endl;
		char tab[] = {'o','n'};
		set<char> expected(tab, tab+2);
		char res = inputChar(expected);
		if (res=='o'){
			ok=true;
		}
	} while(!ok);
	Doctor d(firstname, lastname, email, password);
	return d;
}