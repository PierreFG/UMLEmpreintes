#include <iostream>

#include "doctor.h"



Doctor::Doctor (string pname, string pfN, string pmail, string pmdp):name(pname),firstName(pfN), mail(pmail), mdp(pmdp)
{
    ID = 0;
}

Doctor::~Doctor(){

}