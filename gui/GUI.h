/**
* UI.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

#ifndef UI_H
#define UI_H

#include <iostream>
#include <set>
#include "../modele/doctor.h"

class UI {
	public:
		void intro();
		void connectionMenu();
		void mainMenu();
		int inputInt();
		string inputString();
		char inputChar(set<char> expected);
		
	private:
		Doctor saisirInformation();
		
};

#endif // UI_H