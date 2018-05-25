#include "fs/FileServices.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// LECTURE / ECRITURE DES OBJETS METIERS DANS DES FICHIERS
///////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& out, const Doctor& d) {
    // Ecriture dans le flux de sortie au format CSV
    out << d.ID << ";" << d.firstName << ";" << d.name << ";" << d.mail << ";" << d.mdp << ";" << endl;
    return out;
}

istream& operator>>(istream& in, Doctor& d) {
    // Lecture d'une ligne de données sous forme de texte
    string buffer;
    if(!getline(in, buffer) || buffer.empty()) {
        // Indique une erreur si la ligne de données n'est pas conforme
        in.setstate(ios::failbit);
        return in;
    }

    // Copie les données dans un flux et parse ce flux de données
    stringstream data(buffer);
    bool success = (data >> d.ID)
        && getline(data, buffer, ';') // ignore le premier ';'
        && getline(data, d.firstName, ';')
        && getline(data, d.name, ';')
        && getline(data, d.mail, ';')
        && getline(data, d.mdp, ';');

    // Indique une erreur si les données parsées sont non conformes
    if(!success) {
        in.setstate(ios::failbit);
    }
    return in;
}

///////////////////////////////////////////////////////////////////////////////
/// SERVICES DE HAUT NIVEAU D'ACCES AUX FICHIERS DE STOCKAGE
///////////////////////////////////////////////////////////////////////////////

Doctor_ptr fs::signInDoctor(string username, string password) {
    Doctor_ptr doctor = nullptr;
    ifstream is(fs::DOCTORS_PATH.c_str(), ios::in);
    if(is.is_open()) {
        Doctor tmp;
        // Parcours de tous les docteurs inscrits
        while(is >> tmp) {
            if(tmp.getMail() == username && tmp.getPassword() == password) {
                doctor = make_shared<Doctor>(tmp);
                break;
            }
        }
        is.close();
    }
    return doctor;
}

bool fs::signUpDoctor(Doctor_ptr doctor) {
    // Vérification de la conformité du personnel à inscrire
    if(doctor == nullptr
    || doctor->getMail().empty()
    || doctor->getPassword().empty()
    || doctor->getFirstName().empty()
    || doctor->getName().empty()
    || doctor->getID() == 0
    || fs::signInDoctor(doctor->getMail(), doctor->getPassword()) != nullptr) {
        return false;
    }

    // Ajout du personnel dans le fichier
    bool success = false;
    ofstream os(fs::DOCTORS_PATH.c_str(), ios::out | ios::app);
    if(os.is_open()) {
        os << *doctor;
        success = os.good();
        os.close();
    }
    return success;
}
