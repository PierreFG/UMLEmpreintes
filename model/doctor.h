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
    Doctor ( );
    Doctor (string pname, string pfirstName, string pemail, string pmdp);
    virtual ~Doctor ();

    friend ostream& operator<<(ostream &out, const Doctor &d);
    friend istream& operator>>(istream &in, Doctor &d);

    long getID();
    string getName();
    string getFirstName();
    string getMail();

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
