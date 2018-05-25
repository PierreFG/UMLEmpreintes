#include "fs/FileServices.h"

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

vector<Print> fs::getPrint(string filename){
	//First of all, load all metadatas and analyse them
	ifstream isMeta("meta_"+filename);
	string buffer;
	
	//Since we know every data is in order and that there's exactly n different types,
	//we only need to store a number between 0 and n-1 to indicate the type of the i-th
	//data.
	
	vector<int> types;
	while (!(isMeta.eof() || isMeta.fail() || isMeta.bad()){
		getline(isMeta, buffer);
		string type = buffer.substr(buffer.find(";"));
		if (type=="ID"){
			types.push_back(0);
		} else if (type=="double"){
			types.push_back(1);
		} else if (type=="string"){
			types.push_back(2);
		}
	}
	
	//Then parse all files and get the prints
	vector<Print> vec;
	
	ifstream is(filename.c_str());
	
	while (!(is.eof() || is.fail() || is.bad()){
		getline(is, buffer);
		stringstream data(buffer);
		Print print;
		for(int i=0; i<types.size(); i++){
			string value;
			getline(buffer, value, ";");
			switch(types[i]){
				case 0:
				{
					
					break;
				}
				case 1:
				{
					break;
				}
				case 2:
				{
					break;
				}
			}
		}
		string type = buffer.substr(buffer.find(";"));
		
	}
}