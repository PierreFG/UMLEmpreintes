#include "fs/FileServices.h"

ostream& operator<<(ostream& out, const Doctor& d) {
    // Ecriture dans le flux de sortie au format CSV
    out << d.ID << ";" << d.firstName << ";" << d.name << ";" << d.mail << ";" << d.mdp;
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

Doctor_ptr fs::signInDoctor(string username, string password) {
    // TODO
    return nullptr;
}

Doctor_ptr fs::signUpDoctor(string username, string password) {
    ofstream os(fs::DOCTORS_PATH.c_str(), ios::out | ios::app);
    if(os.is_open()) {
        // TODO
    }
    return nullptr;
}
