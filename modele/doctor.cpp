#include <iostream>

#include "doctor.h"


ostream& operator << (ostream &out, Doctor &d){
    out << "Doctor " + d.firstName + " " + d.name << endl;
    out << "Mail : " + d.mail  << endl;
    return out;
}

Doctor::Doctor (string pname, string pfN, string pmail, string pmdp):name(pname),firstName(pfN), mail(pmail), mdp(pmdp)
{
    ID = 0;
}

Doctor::~Doctor(){

}