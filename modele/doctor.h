//---------- Interface de la classe <Doctor> (fichier Doctor.h) ----------------
#if ! defined ( DOCTOR_H )
#define DOCTOR_H

#include <string>
#include <iostream>
using namespace std;

class Doctor
{

public:
    Doctor (string pname, string pfirstName, string pemail, string pmdp);
    virtual ~Doctor ();

    friend ostream& operator << (ostream &out, Doctor &d);
	

protected:
    long ID;
    string name;
    string firstName;
    string mail;
    string mdp;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // DOCTOR_H
