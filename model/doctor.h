//---------- Interface de la classe <Doctor> (fichier Doctor.h) ----------------
#if ! defined ( DOCTOR_H )
#define DOCTOR_H

#include <string>
#include <iostream>
#include <memory>
using namespace std;

class AnalysisResult;
class Doctor;


typedef uint16_t doctorid_t;
typedef shared_ptr<Doctor> Doctor_ptr;
namespace fs {
    bool signUpDoctor(Doctor_ptr);
}

/*
* Class instantiating a doctor using our application
*/

class Doctor
{
public:
    Doctor ( );
    /*Default constructor*/
    Doctor (string pname, string pfirstName, string pemail, string pmdp);
    /*Constructor*/
    virtual ~Doctor ();
    /*Default destructor*/

    friend ostream& operator<<(ostream &out, const Doctor &d);
    /*helps the extern overload of the doctor output stream*/
    friend istream& operator>>(istream &in, Doctor &d);
    /*Extern overload of the input stream operator*/
    friend istream& operator>>(istream& in, AnalysisResult& r);
    /*Extern overload of the output stream operator*/
    friend bool fs::signUpDoctor(Doctor_ptr);

    doctorid_t getID();
    /*Returns the doctor's id*/
    string getName();
    /*Returns the doctor's name*/
    string getFirstName();
    /*Returns the doctor's first name*/
    string getMail();
    /*Returns the doctor's mail*/
    string getPassword();
    /*Returns the doctor's password*/

protected:
    doctorid_t ID;
    string name;
    string firstName;
    string mail;
    string mdp;
};



#endif // DOCTOR_H
