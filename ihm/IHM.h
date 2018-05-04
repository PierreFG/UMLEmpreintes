/**
* IHM.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

#ifndef IHM_H
#define IHM_H

class IHM{
	public:
		void intro();
		void connectionMenu();
		void mainMenu();
		int inputInt();
		string inputString();
		char inputChar();
}

#endif // IHM_H