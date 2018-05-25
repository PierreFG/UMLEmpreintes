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

ostream& operator<<(ostream& out, const Rule& r) {
    // Ecriture dans le flux de sortie au format CSV
    string result;
    for(auto it = r.asso.begin(); it!=r.asso.end(); ++it){
        out << it->first << ";";
        vector<double> v = it->second;
        for(auto it2 = v.begin(); it2!=v.end(); ++it2){
            out << *it2 << ";";
        }
        out << endl;
    }
    return out;
}

istream& operator>>(istream& in, Doctor& d) {
    // Lecture d'une ligne de donnï¿½es sous forme de texte
    string buffer;
    if(!getline(in, buffer) || buffer.empty()) {
        // Indique une erreur si la ligne de donnï¿½es n'est pas conforme
        in.setstate(ios::failbit);
        return in;
    }

    // Copie les donnï¿½es dans un flux et parse ce flux de donnï¿½es
    stringstream data(buffer);
    bool success = (data >> d.ID)
        && getline(data, buffer, ';') // ignore le ';'
        && getline(data, d.firstName, ';')
        && getline(data, d.name, ';')
        && getline(data, d.mail, ';')
        && getline(data, d.mdp, ';');

    // Indique une erreur si les donnï¿½es parsï¿½es sont non conformes
    if(!success) {
        in.setstate(ios::failbit);
    }
    return in;
}





ostream& operator<<(ostream& out, const AnalysisResult& r) {
    // Ecriture dans le flux de sortie au format CSV
    out << r.doctor->ID << ";" << r.date << ";" << r.file << ";" << r.printID << ";" << endl;
    return out;
}

istream& operator>>(istream& in, AnalysisResult& r) {
    // Lecture d'une ligne de données sous forme de texte
    string buffer;
    if(!getline(in, buffer) || buffer.empty()) {
        // Indique une erreur si la ligne de données n'est pas conforme
        in.setstate(ios::failbit);
        return in;
    }

    // Copie les données dans un flux et parse ce flux de données
    stringstream data(buffer);
    bool success = (data >> r.doctor->ID)
        && getline(data, buffer, ';') // ignore le ';'
        && getline(data, r.date, ';')
        && getline(data, r.file, ';')
        && (data >> r.printID);

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
    // Vï¿½rification de la conformitï¿½ du personnel ï¿½ inscrire
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

<<<<<<< HEAD
bool fs::saveRule(Rule_ptr r){
    bool success = false;
    ofstream os (fs::RULES_PATH.c_str());
    if(os.is_open()) {
        os << *r;
        success = os.good();
        os.close();
    }
    return success;
}
=======
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
		string type = buffer.substr(buffer.find(";")+1);
		if (type=="ID"){
			types.push_back(0);
		} else if (type=="double"){
			types.push_back(1);
		} else if (type=="string"){
			types.push_back(2);
		}
	}
	
	//Then parse all file and get the prints
	vector<Print> vec;
	
	ifstream is(filename.c_str());
	
	int id=-1;
	vector<string> vecStr;
	vector<double> vecDou;
	vector<string> vecDis;
	while (!(is.eof() || is.fail() || is.bad()){
		getline(is, buffer);
		stringstream data(buffer);
		for(int i=0; i<types.size() && ; i++){
			string value;
			getline(buffer, value, ";");
			if(types.at(i)==0){
				int a =stoi(value);
				if (a==id){
					
					break;
				}
				//Save print
				Print p(id, vecDis, vecDou, vecStr);
				vec.push_bask(p);
				id=a;
				vecDis.clear();
				vecDou.clear();
				vecStr.clear();
			} else if (types.at(i)==1){
				vedDou.push_back(stod(value));
			} else if (types.at(i)==2){
				vecStr.push_back(value);
			}
		}
		getline(buffer, value);
		vecDis.push_back(value);
	}
	
	return vec;
}

void fs::saveOneHotString(map<string, int> oneHot){
	//That'll be a basic csv
	ofstream os(ONE_HOT_RULE_PATH);
	if (os.is_open()){
		for(map<string,int>::iterator it=oneHot.begin(); it!=oneHot.end() && os.good(); it++){
			os<<it->first<<";"<<it->second<<endl;
		}
	}
}

map<string,int> fs::loadOneHotString(){
	ifstream is(ONE_HOT_RULE_PATH);
	map<string, int> ontHot;
	if(is.is_open()){
		while(is.good()){
			string buffer;
			getline(is, buffer);
			string str1,str2;
			str1=buffer.substr(0,buffer.find(";"));
			str2=buffer.substr(buffer.find(";")+1);
			oneHot.insert(pair<string, int>(str1, stoi(str2)));
		}
	}
	return oneHot;
}
>>>>>>> d6e15725e18882c2bd467b6ed25cf3792a51d7c4
