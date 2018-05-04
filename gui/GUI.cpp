/**
* GUI.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

//todo : créer manipulateur de couleur et formattage de texte paramétrable pour meilleure esthétique (classe)

#include <iostream>
#include <set>

void GUI::intro(){
	cout << "\033[031m"<<endl;
	cout << "Analyseur d'empreintes" << endl;
	cout << "Application développée dans un contexte de TP \"Génie logiciel\" à l'INSA de Lyon"<<endl
	cout << "Copyrights : Pierre Faure--Giovagnoli, Romain Fournier, Alexis Le Conte, Louis Ohl"<<endl<<endl;
	cout <<"\033[0m";
}

void GUI::connectionMenu(){
	cout << "Bienvenue sur l'analyseur d'empreintes !"<<endl<<endl;
	
	bool notConnected=true
	cout<< "Possédez-vous un compte (c) ou voulez-vous vous inscrire (i) ?"<<endl;
	cout<<"Pour quitter l'application, tapez (q)"<<endl;
	char res=inputChar();
	char[] tab = {'i','c','q'}
	set<char> expected(tab); 
	res=inputChar(expected);
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

void GUI::mainMenu(){
	cout << "bouh"<<endl;
}

int GUI::inputInt(){
	ok=false;
	int res=0;
	while(!ok){
		string line;
		getline(cin, line);
		int res = stoi(line);
	}
}

string GUI::inputString(){
	string line;
	getline(cin, line);
	return line;
}

char GUI::inputChar(set<char> expected){
	char charac='\0';
	ok=false;
	while (!ok){
		string result;
		getline(cin, result);
		if (result==""){
			charac='\0';
		} else {
			charac=resultat[0];
		}
		if (expected.find(charac)==expected.end()){
			cout << "Ce caractère n'est pas demandé !"<<endl;
		} else {
			ok=true;
		}
	}
	
	return charac;
	
}

Doctor GUI::saisirInformation(){
	cout <<"Formulaire d'inscription"<<endl<<endl;
	bool ok=false;
	do{
		cout <<"Veuillez rentrer votre prenom :"<<endl;
		string prenom=inputString();
		cout << "Veuillez rentrer votre nom de famille :"<<endl;
		string nom=inputString();
		cout <<"Veuillez saisir votre email (il vous servira d'identifiant) :"<<endl;
		string email=inputString();
		bool pwd=false;
		string password, confirmation;
		while (!pwd){
			cout <<"Veuillez saisir votre mot de passe :" << endl;
			password=inputString();
			cout << "Veuillez confirmer votre mot de passe :" << endl;
			confirmation = inputString();
			if (password==confirmation){
				pwd=true;
			} else {
				cout << "Vos mots de passe ne correspondent pas, veuillez les re-saisir !"<<endl;
			}
		}
		cout << "Vous êtes : " << prenom << " " << nom << ". ";
		cout << "Votre mail : " << email<<endl;
		cout << "Ces informations vous correspondent-elles ? (o/n)" <<endl;
		char res = inputChar();
		while res
	} while(!ok);
}