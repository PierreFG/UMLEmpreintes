/**
* UI.h
* Auteur : Louis Ohl
* Projet : analyseur d'empreintes (TP GLUML)
* Date : 4 Mai 2018
*/

#ifndef UI_H
#define UI_H

#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include "model/doctor.h"

namespace ui {

    std::shared_ptr<Doctor> connectionMenu();
    //Displays the connection Menu

    void mainMenu(Doctor d);
    //Displays the main menu of the application
    //(once you're connected)

    int inputInt();
    //Seizes the integer the user has typed.
    //If anything's wrong, this method forces
    //the user to type again

    string inputString();
    //Seizes the string the user has typed

    char inputChar(set<char> expected);
    //Forces the user to seize a character
    //that is contained in the set expected.
    void intro();
    //Default constructor of the interface.
    //Shows a small introduction message about
    //the software and its rights.

    Doctor seizeInformation();
    //Invites the user to complete fields
    //about his datas in order to create a proper
    //Doctor instance

    class Colorize {
    public:
        enum {DEFAULT = 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
        explicit Colorize(int c = DEFAULT) : color(c) {}
        inline friend ostream& operator<<(ostream& out, const Colorize& colorizer) {
            std::stringstream ss;
            switch(colorizer.color) {
            case DEFAULT:
                ss <<"\033[0m";
                break;
            case RED:
            case GREEN:
            case YELLOW:
            case BLUE:
            case MAGENTA:
            case CYAN:
            case WHITE:
            	out << colorizer.color<<endl;
            	ss << "\033[3"<<colorizer.color<<"m";
            	break;
            default:
                break;
            }
            return out << ss.str() << flush;
        }
    private:
        int color;
    };

}

#endif // UI_H
