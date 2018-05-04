//---------- Interface de la classe <Doctor> (fichier Doctor.h) ----------------
#if ! defined ( DOCTOR_H )
#define DOCTOR_H

#include <string>
using namespace std;

class Doctor
{

public:
    Doctor (string pname, string pfirstName, string pemail, string pmdp);
    virtual ~Doctor ();

    string to_string(){
        string r = "Doctor " + firstName + " " + name + "\n";
        r += "Mail : " + mail  + "\n";
        return r;
    }

protected:
    long ID;
    string name;
    string firstName;
    string mail;
    string mdp;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // DOCTOR_H
