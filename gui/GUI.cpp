/**
* GUI.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

//todo : créer manipulateur de couleur et formattage de texte paramétrable pour meilleure esthétique (classe)

#include <iostream>

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
	while (res!='i' && res !='c' && res!='q'){
		cout << "Cela n'était pas demandé ! Recommencez. " << endl;
		cout << "Possédez-vous un compte (c) ou voulez-vous vous inscrire (i) ?"<<endl;
		res=inputChar();
	}
	if (res=='i'){
		
	}
	if (res=='c'){
		
	}
	if (res=='q'){
		notConnected=false;
	}
}

void GUI::mainMenu(){
	
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

string GUI::inputPassword(){
	
}

char GUI::inputChar(){
	string resultat;
	getline(cin, resultat);
	if (resultat==""){
		return '\0';
	} else {
		return resultat[0];
	}
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
		cout <<"Veuillez saisir votre mot de passe :" << endl;
	
	} while(!ok);
}