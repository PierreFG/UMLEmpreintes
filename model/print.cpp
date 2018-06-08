#include "print.h"
#include <iostream>

Print& Print::operator =(const Print& p){
	ID=p.ID;
	attrStr.clear();
	diseases.clear();
	attr.clear();
	for (string s : p.attrStr){
		attrStr.push_back(s);
	}
	for (string s : p.diseases){
		cout <<"Copie de : " << s << endl;
		diseases.push_back(s);
	}
	for(double d: p.attr){
		attr.push_back(d);
	}
	return *(this);
}

long Print::getID() const {
    return ID;
}

vector<string> Print::getDiseases() const {
    return diseases;
}

vector<double> Print::getAttr() const {
    return attr;
}

vector<string> Print::getAttrStr() const {
    return attrStr;
}

void Print::addDisease(string d) {
    diseases.push_back(d);
}

void Print::afficherMaladies() const {
	for (string s: diseases){
		cout << s << "; "<<endl;
	}

}
Print::Print(printid_t pid, vector<string> pdiseases, vector<double> pattr, vector<string> pattrStr):ID(pid), diseases(pdiseases), attr(pattr), attrStr(pattrStr) {
}

Print::Print() {
    ID = 0;
}

Print::Print(Print &p){
	ID=p.ID;
	attrStr.clear();
	diseases.clear();
	attr.clear();
	for (string s : p.attrStr){
		attrStr.push_back(s);
	}
	for (string s : p.diseases){
		cout <<"Copie de : " << s << endl;
		diseases.push_back(s);
	}
	for(double d: p.attr){
		attr.push_back(d);
	}
}

Print::~Print(){}
