#include <algorithm>
#include <ctime>

#include "fs/FileServices.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// FONCTIONS UTILITAIRES
///////////////////////////////////////////////////////////////////////////////

string fs::getCurrentTime(){
    time_t t = time(0);
    tm* now = localtime(&t);
    stringstream buffer;
    buffer << now->tm_year + 1900 << "-";
    buffer << now->tm_mon + 1 << "-";
    buffer << now->tm_mday << " ";
    buffer << now->tm_hour << ":";
    buffer << now->tm_min << ":";
    buffer << now->tm_sec;
    return buffer.str();
}

string fs::itos(int i) {
    stringstream buffer;
    buffer << i;
    return buffer.str();
}

int fs::stoi(string s) {
    int result;
    stringstream buffer(s);
    if(!(buffer >> result)){
        result=-1;
    }
    return result;
}

double fs::stod(string s){
    double result;
    stringstream buffer(s);
    if(!(buffer >> result)){
        result=-1;
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// LECTURE / ECRITURE DES OBJETS METIERS DANS DES FICHIERS
///////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& out, const Doctor& d) {
    // Ecriture dans le flux de sortie au format CSV
    out << d.ID << ";" << d.firstName << ";" << d.name << ";" << d.mail << ";" << d.mdp << ";" << endl;
    return out;
}

ostream& operator<<(ostream& out, const Rule& r) {

    for(auto it = r.asso.begin(); it!=r.asso.end(); ++it){
        out << it->first << ";";
        vector<double> v = it->second;
        for(auto it2 = v.begin(); it2!=v.end(); ++it2){
            out << *it2 << ";";
        }
        out << endl;
    }
    out << "?"<< endl;
    for (auto it =r.oneHotRule.begin(); it!=r.oneHotRule.end(); it++){
        out << it->first << ";";
        vector<string> v = it->second;
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
    out << r.doctor->getID() << ";" << r.date << ";" << r.file << ";" << r.printID << ";" << endl;
    return out;
}

istream& operator>>(istream& in, AnalysisResult& r) {
    // Lecture d'une ligne de donnï¿½es sous forme de texte
    string buffer;
    if(!getline(in, buffer) || buffer.empty()) {
        // Indique une erreur si la ligne de donnï¿½es n'est pas conforme
        in.setstate(ios::failbit);
        return in;
    }

    // Copie les donnï¿½es dans un flux et parse ce flux de donnï¿½es
    stringstream data(buffer);
    long doctorID;
    bool success = (data >> doctorID)
        && getline(data, buffer, ';') // ignore le ';'
        && getline(data, r.date, ';')
        && getline(data, r.file, ';')
        && (data >> r.printID);

        cout << doctorID << endl;

    r.doctor = fs::findDoctorByID(doctorID);

    // Indique une erreur si les donnï¿½es parsï¿½es sont non conformes
    if(!success) {
        in.setstate(ios::failbit);
    }
    return in;
}

ostream& operator << (ostream& out, const Print& p){
    cout << "Voici une empreinte : " << endl;
    for(vector<double>::const_iterator it=p.attr.cbegin(); it!=p.attr.cend(); it++){
        cout << *it << "; ";
    }
    cout << endl;
    for (vector<string>::const_iterator it=p.attrStr.cbegin(); it!=p.attrStr.cend(); it++){
        cout << *it << "; ";
    }
    cout << endl;
    cout << "Les maladies associées sont : "<<endl;
    for (vector<string>::const_iterator it=p.diseases.cbegin(); it!=p.diseases.cend(); it++){
        cout << *it << "; ";
    }
    cout << endl;
    return out;
}
///////////////////////////////////////////////////////////////////////////////
/// SERVICES DE HAUT NIVEAU D'ACCES AUX FICHIERS DE STOCKAGE
///////////////////////////////////////////////////////////////////////////////

Doctor_ptr fs::findDoctorByID(long id) {
    ifstream is(fs::DOCTORS_PATH.c_str(), ios::in);
    if(is.is_open()) {
        Doctor tmp;
        // Parcours de tous les docteurs inscrits
        while(is >> tmp) {
            if(tmp.getID() == id) {
                is.close();
                return make_shared<Doctor>(tmp);
            }
        }
        is.close();
    }
    return nullptr;
}

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
    || doctor->getID() != 0
    || fs::signInDoctor(doctor->getMail(), doctor->getPassword()) != nullptr) {
        return false;
    }

    // donner un ID
    if((doctor->ID = generateDoctorID()) == 0) {
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

long fs::generateDoctorID() {
    ifstream is(fs::DOCTORS_PATH.c_str(), ios::in);
    if(is.is_open()) {
        vector<unsigned long> idList{};
        Doctor tmp;
        while(is >> tmp) {
            idList.push_back(tmp.getID());
        }
        sort(idList.begin(), idList.end());
        long nextID = idList.size()+1;
        for(unsigned int i=0; i<idList.size(); i++) {
            if(idList[i] > i+1) {
                nextID = i+1;
                break;
            }
        }
        is.close();
        return nextID;
    }
    return 0;
}

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

vector<Print_ptr> fs::getPrints(string filename){
	//First of all, load all metadatas and analyse them
	ifstream isMeta("meta_"+filename);
	string buffer;

	//Since we know every data is in order and that there's exactly n different types,
	//we only need to store a number between 0 and n-1 to indicate the type of the i-th
	//data.

	vector<int> types;
	while(getline(isMeta, buffer)) {
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
	vector<Print_ptr> vec;

	ifstream is(filename.c_str());

    //count the lines
    int total=0;
    while (getline(is, buffer) && !is.eof()) { total++;}
    is.close();

    is.open(filename.c_str());

	int id = -1;
	int ligne=0;
	vector<string> vecStr;
	vector<double> vecDou;
	vector<string> vecDis;
	if (is.is_open()){
        string useless;
        getline(is, useless);
        ligne++;
        while (getline(is, buffer)){
            stringstream data(buffer);
            string value;
            for(unsigned int i=0; i<types.size(); i++){
                getline(data, value, ';');
                if(types.at(i)==0){
                    int a = fs::stoi(value);
                    if (a==id){
                        for(unsigned int index=i; index<types.size(); index++){
                            getline(data, value, ';'); //emptyiung buffer til we reach end of line containing disease
                        }
                        break;
                    }
                    //Save print
                    if(id != -1) {
                        vec.push_back(make_shared<Print>(id, vecDis, vecDou, vecStr));
                    }
                    id=a;
                    vecDis.clear();
                    vecDou.clear();
                    vecStr.clear();
                } else if (types.at(i)==1){
                    vecDou.push_back(fs::stod(value));
                } else if (types.at(i)==2){
                    vecStr.push_back(value);
                }
            }
            getline(data, value);
            if (value!=""){
                vecDis.push_back(value);
            }
            ligne++;
            cout << ligne << endl;
            if(ligne==total){
                vec.push_back(make_shared<Print>(id, vecDis, vecDou, vecStr));
            }
        }
	}


	return vec;
}

bool fs::saveResult(AnalysisResult_ptr r) {
    bool success = false;
    ofstream os(fs::OUTPUT_PATH.c_str() + r->getFileName + ".xml", ios::out | ios::app);
    if(os.is_open()) {
        os << "<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>" << endl;
        os << "<!DOCTYPE analysis [" << endl;
        os << "<!ENTITY analysis (time, doctorid, fileid, printid, result*)>" << endl;
        os << "<!ENTITY time (#PCDATA)>" << endl;
        os << "<!ENTITY doctorid (#PCDATA)>" << endl;
        os << "<!ENTITY fileid (#PCDATA)>" << endl;
        os << "<!ENTITY printid (#PCDATA)>" << endl;
        os << "<!ENTITY result (name, proba)>" << endl;
        os << "<!ENTITY name (#PCDATA)>" << endl;
        os << "<!ENTITY proba (#PCDATA)>" << endl;
        os << "]>" << endl;
        os << "<analysis>" << endl;
        os << "  <time>" << endl;
        os << "    " << r->getDate() << endl;
        os << "  </time>" << endl;
        os << "  <doctorid>" << endl;
        os << "    " << r->getDoctor()->getID() << endl;
        os << "  </doctorid>" << endl;
        os << "  <fileid>" << endl;
        os << "    " << r->getFileName() << endl;
        os << "  </fileid>" << endl;
        os << "  <printid>" << endl;
        os << "    " << r->getPrintID() << endl;
        os << "  </printid>" << endl;
        for(auto& prb : r->getProbas()) {
            os << "    <name>" << endl;
            os << "      " << prb.first << endl;
            os << "    </name>" << endl;
            os << "    <proba>" << endl;
            os << "      " << prb.second << endl;
            os << "    </proba>" << endl;
        }
        os << "</analysis>" << endl;
        success = os.good();
        os.close();
    }
    return success;
}

Rule_ptr fs::getRule(){
    ifstream is(fs::RULES_PATH.c_str(), ios::in);
    if(!is.is_open()) return nullptr;

    map<string,vector<double>> m;
    map<int, vector<string>> one;
    string line; //1 ligne du csv
    bool oneHot=false;
    while (getline(is, line)){
        if (line=="?"){
            oneHot=true;
            continue;
        }
        if (oneHot){
            vector<string> v;
            stringstream data(line);

            string d; //maladie
            getline(data, d, ';');
            string buffer = d;
            getline(data, buffer, ';');
            while(buffer.compare("") != 0){
                //cout << fs::stoi(buffer) << " | ";
                v.push_back(buffer);
                getline(data, buffer, ';');
            }
            one[fs::stoi(d)] = v;
        } else {
            vector<double> v;
            stringstream data(line);

            string d; //maladie
            getline(data, d, ';');
            string buffer = d;
            getline(data, buffer, ';');
            while(buffer.compare("") != 0){
                //cout << fs::stoi(buffer) << " | ";
                v.push_back(fs::stoi(buffer));
                getline(data, buffer, ';');
            }
            m[d] = v;
        }
    }
    Rule_ptr r = make_shared<Rule>(m, one);
    return r;
}


bool fs::addResultToLog(AnalysisResult_ptr r) {
    // Vérification de la conformité de l'analyse à enregistrer
    if(r == nullptr) {
        return false;
    }

    // Ajout de l'analyse dans le fichier de logs
    bool success = false;
    ofstream os(fs::LOGS_PATH.c_str(), ios::out | ios::app);
    if(os.is_open()) {
        os << *r;
		success = false;
    }
    return success;
}

vector<AnalysisResult_ptr> fs::readLogs(long doctorID) {
    vector<AnalysisResult_ptr> results;
    ifstream is(fs::LOGS_PATH.c_str(), ios::in);
    if(is.is_open()) {
        AnalysisResult tmp;
        // Parcours de tous les docteurs inscrits
        while(is >> tmp) {
            if(tmp.getDoctor()->getID() == doctorID) {
                results.push_back(make_shared<AnalysisResult>(tmp));
            }
        }
        is.close();
    }
    return results;
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
	map<string, int> oneHot;
	if(is.is_open()){
		while(is.good()){
			string buffer;
			getline(is, buffer);
			string str1,str2;
			str1=buffer.substr(0,buffer.find(";"));
			str2=buffer.substr(buffer.find(";")+1);
			oneHot.insert(pair<string, int>(str1, fs::stoi(str2)));
		}
	}
	return oneHot;
}

