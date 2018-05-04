#ifndef FILESERVICES_H_INCLUDED
#define FILESERVICES_H_INCLUDED

#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "modele/doctor.h"
#include "modele/print.h"
#include "modele/analysisResult.h"
#include "modele/rule.h"

using namespace std;

namespace fs {

    const string PATH_RULES = "data/rules.csv";
    const string PATH_LOGS = "data/logs/";
    const string PATH_DOCTORS = "data/doctors.csv";

    ostream& operator<<(ostream& out, const Doctor& d);

    istream& operator>>(istream& in, Doctor& d);

    Doctor_ptr signInDoctor(string username, string password);

    bool signUpDoctor(Doctor_ptr doctor);

    vector<Print> getPrint(string filename);

}

#endif // FILESERVICES_H_INCLUDED
