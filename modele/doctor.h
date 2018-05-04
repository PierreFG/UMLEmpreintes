//---------- Interface de la classe <Doctor> (fichier Doctor.h) ----------------
#if ! defined ( DOCTOR_H )
#define DOCTOR_H

#include <string>
#include <iostream>
#include <memory>

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

typedef shared_ptr<Doctor> Doctor_ptr;

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // DOCTOR_H
