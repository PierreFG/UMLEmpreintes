//---------- Interface de la classe <Doctor> (fichier Doctor.h) ----------------
#if ! defined ( DOCTOR_H )
#define DOCTOR_H

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class AnalysisResult;
class Doctor;

typedef shared_ptr<Doctor> Doctor_ptr;
typedef uint16_t id_t;

namespace fs {
    bool signUpDoctor(Doctor_ptr);
}

class Doctor
{

public:
    Doctor ( );
    Doctor (string pname, string pfirstName, string pemail, string pmdp);
    virtual ~Doctor ();

    friend ostream& operator<<(ostream &out, const Doctor &d);
    friend istream& operator>>(istream &in, Doctor &d);
    friend istream& operator>>(istream& in, AnalysisResult& r);

    friend bool fs::signUpDoctor(Doctor_ptr);

    id_t getID();
    string getName();
    string getFirstName();
    string getMail();
    string getPassword();

protected:
    id_t ID;
    string name;
    string firstName;
    string mail;
    string mdp;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // DOCTOR_H
