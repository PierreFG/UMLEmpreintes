#include <iostream>

#include "doctor.h"
#include "fs/FileServices.h"

long Doctor::getID(){
    return ID;
}

string Doctor::getName(){
    return name;
}

string Doctor::getFirstName(){
    return firstName;
}

string Doctor::getMail(){
    return mail;
}

string Doctor::getPassword() {
    return mdp;
}

Doctor::Doctor() : ID(0) {}

Doctor::Doctor (string pname, string pfN, string pmail, string pmdp):name(pname),firstName(pfN), mail(pmail), mdp(pmdp)
{
    ID = 0;
}

Doctor::~Doctor(){

}
