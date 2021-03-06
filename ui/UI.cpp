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
#include <stdio.h>
//#include <termios.h>
#include <unistd.h>

#include "ui/UI.h"
#include "model/doctor.h"
#include "model/analysisResult.h"
#include "analysis/PrintAnalyser.h"
#include "fs/FileServices.h"

using namespace std;

void ui::usage() {
	cerr << "usage : ./app [-i \"setfile.txt\"]" << endl;
	cerr << "There must be the the set file itself (xxx.txt) but also the meta file named xxx_meta.txt." << endl;
	exit(1);
	return;
}

void ui::intro() {
	cout << Colorize(Colorize::RED) << endl;
	cout << "Analyseur d'empreintes" << endl;
	cout << "Application developpee dans un contexte de TP \"Genie logiciel\" a l'INSA de Lyon"<<endl;
	cout << "Copyrights : Pierre Faure--Giovagnoli, Romain Fournier, Alexis Le Conte, Louis Ohl"<<endl<<endl;
	cout << Colorize(Colorize::DEFAULT);
	return;
}

Doctor_ptr ui::connectionMenu() {
	Doctor_ptr d = nullptr;

	cout << "Bienvenue sur l'analyseur d'empreintes !"<<endl<<endl;

	bool notConnected=true;

	do{
		cout<< "Possedez-vous un compte (c) ou voulez-vous vous inscrire (i) ?"<<endl;
		cout<<"Pour quitter l'application, tapez (q)"<<endl;
		char res=inputChar({'i','c','q'});
		if (res=='i')
		{
			d = seizeInformation();
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
				//password=getpass();
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
			cout <<"A bientot"<<endl;
		}
	} while(notConnected);
	return d;
}

void ui::mainMenu(Doctor_ptr d){
	char car;

	cout << "Bonjour Dr. " << d->getName() <<"."<<endl;

	while (car!='d'){
		cout << endl<<endl;
		cout << "Pour analyser un fichier d'empreintes, tapez (a)." << endl;
		cout << "Pour consulter l'historique de votre activite, tapez (h)." << endl;
		cout << "Pour vous deconnecter, tapez (d)."<<endl;
		car=inputChar({'a', 'h', 'd'});
		if (car=='a'){
			cout << "Entrez le chemin d'acces au fichier d'empreinte(s) a analyser :"<<endl;
			string path = inputString();
			PrintAnalyser pa;
			Rule_ptr r = fs::getRule();
			pa.SetRule(r);
			vector<AnalysisResult_ptr> results = pa.analysePrints(path, d);
			cout << "Voici le resultat de chaque empreinte du fichier :"<<endl;
			for(AnalysisResult_ptr& ar : results){
				cout << "Empreinte "<< ar->getPrintID() <<  endl;
				map<string, double> cpy = ar->getProbas();
                for(map<string, double>::iterator it = cpy.begin(); it!=cpy.end(); it++){
                    cout << it->first << " : " << it->second<<endl;
                }
                cout << endl<<endl;
                fs::addResultToLog(ar);
                fs::saveResult(ar);
			}

		} else if(car=='h'){
			//Appeler la methode historique
			vector<AnalysisResult_ptr> res = fs::readLogs(d->getID());
			if (!res.empty()){
				cout << "Votre historique : " << endl;
				for(auto it = res.begin(); it!=res.end(); it++){
					cout << **it <<endl;
				}
			} else {
				cout << "Votre historique est vide a l'heure actuelle" << endl<<endl;
			}

		}
	}
	cout <<"Au revoir M. " << d->getName() << "." << endl;
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

Doctor_ptr ui::seizeInformation(){
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
	return make_shared<Doctor>(firstname, lastname, email, password);
}

/*
int ui::getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

string ui::getpass(bool show_asterisk)
{
  const char BACKSPACE=127;
  const char RETURN=10;

  string password;
  unsigned char ch=0;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}
*/
