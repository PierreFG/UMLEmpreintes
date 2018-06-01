/**
* UI.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

//todo : creer manipulateur de couleur et formattage de texte param�trable pour meilleure esthetique (classe)

#include <iostream>
#include <set>
#include <vector>
#include <memory>

#include "UI.h"
#include "model/doctor.h"
#include "fs/FileServices.h"
#include "model/analysisResult.h"

using namespace std;

void ui::intro(){
	cout << Colorize(Colorize::RED) << endl;
	cout << "Analyseur d'empreintes" << endl;
	cout << "Application developpee dans un contexte de TP \"Genie logiciel\" a l'INSA de Lyon"<<endl;
	cout << "Copyrights : Pierre Faure--Giovagnoli, Romain Fournier, Alexis Le Conte, Louis Ohl"<<endl<<endl;
	cout << Colorize(Colorize::DEFAULT);
	return;
}

shared_ptr<Doctor> ui::connectionMenu(){
	shared_ptr<Doctor> d=nullptr;

	cout << "Bienvenue sur l'analyseur d'empreintes !"<<endl<<endl;

	bool notConnected=true;

	do{
		cout<< "Possedez-vous un compte (c) ou voulez-vous vous inscrire (i) ?"<<endl;
		cout<<"Pour quitter l'application, tapez (q)"<<endl;
		char res=inputChar({'i','c','q'});
		if (res=='i')
		{
			d=make_shared<Doctor>(seizeInformation());
			if(fs::signUpDoctor(d)){
				cout << Colorize(Colorize::GREEN) << endl;
				cout << "Votre inscription a ete realisee avec succes !"<<endl;
				cout << Colorize(Colorize::DEFAULT) << endl;
			} else {
				cout << Colorize(Colorize::RED) << endl;
				cout << "Mmh... Il semblerait que nous n'ayons pas pu realiser l'inscription. Peut-etre cette adresse mail existe deja ?"<<endl;
				cout << Colorize(Colorize::DEFAULT) << endl;
			}
		}
		else if (res=='c')
		{
			bool ok=false;
			string email,password;
			while(!ok){
				cout << "Saisissez votre mail :" << endl;
				email=inputString();
				cout << "Saisissez votre mot de passe :"<<endl;
				password=inputString();
				d = fs::signInDoctor(email, password);
				if (d!=nullptr){
					ok=true;
					notConnected=false;
				} else {
					cout << "Erreur d'authentification, recommencer ? (o/n)"<< endl;
					res=inputChar({'o', 'n'});
					if (res=='n'){
						ok=true;
					}
				}
			}
		}
		else if (res=='q'){
			notConnected=false;
			d=nullptr;
			cout <<"A bientôt"<<endl;
		}
	} while(notConnected);
	return d;
}

void ui::mainMenu(Doctor d){
	char car;

	cout << "Bonjour M. " << d.getName() <<"."<<endl;

	while (car!='d'){
		cout << endl<<endl;
		cout << "Pour analyser un fichier d'empreintes, tapez (a)." << endl;
		cout << "Pour consulter l'historique de votre activite, tapez (h)." << endl;
		cout << "Pour vous deconnecter, tapez (d)."<<endl;
		car=inputChar({'a', 'h', 'd'});
		if (car=='a'){
			cout << "Entrez le chemin d'accès au fichier d'empreinte(s) à analyser :"<<endl;
			string path=inputString();
			//Appeler la méthode d'analyse d'une empreinte

		} else if(car=='h'){
			//Appeler la méthode historique
			vector<AnalysisResult_ptr> res = fs::readLogs(d.getID());
			if (res.size()!=0){
				cout << "Votre historique : " << endl;
				for(vector<AnalysisResult_ptr>::iterator it = res.begin(); it!=res.end(); it++){
					cout << *it<<endl;
				}
				
			} else {
				cout << "Votre historique est vide à l'heure actuelle" << endl<<endl;
			}
						
		}
	}
	cout <<"Au revoir M. " << d.getName() << "." << endl;
}

int ui::inputInt(){
	bool ok=false;
	int res=0;
	while(!ok){
		string line;
		getline(cin, line);
		try{
			res = fs::stoi(line);
			ok=true;
		}catch(exception e){

		}
	}
	return res;
}

string ui::inputString(){
	string line;
	getline(cin, line);
	return line;
}

char ui::inputChar(set<char> expected){
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
			cout << "Ce caractere n'est pas demande !"<<endl;
		} else {
			ok=true;
		}
	}
	return charac;

}

Doctor ui::seizeInformation(){
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
		char res = inputChar({'o','n'});
		if (res=='o'){
			ok=true;
		}
	} while(!ok);
	Doctor d(firstname, lastname, email, password);
	return d;
}
