#include <iostream>

#include "doctor.h"
#include "fs/FileServices.h"

/* !!!! On utilisera ces op�rateurs pour les �critures / lectures dans les fichiers. Pour l'affichage � l'�cran, c'est le module UI qui d�finit comment �a s'affiche. Ce sera plus coh�rent !
ostream& operator << (ostream &out, Doctor &d){
    out << "Doctor " + d.firstName + " " + d.name << endl;
    out << "Mail : " + d.mail  << endl;
    return out;
}*/

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

Doctor::Doctor() : ID(fs::generateDoctorID()) {}

Doctor::Doctor (string pname, string pfN, string pmail, string pmdp):name(pname),firstName(pfN), mail(pmail), mdp(pmdp)
{
    ID = fs::generateDoctorID();
}

Doctor::~Doctor(){

}
