/**
* GUI.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

#ifndef GUI_H
#define GUI_H

#include <iostream>
#include "Doctor.h"

class GUI{
	public:
		void intro();
		void connectionMenu();
		void mainMenu();
		int inputInt();
		string inputString();
		string inputPassword();
		char inputChar();
		
	private:
		Doctor saisirInformation();
		
}

#endif // GUI_H