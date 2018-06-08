#include "print.h"

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

Print::Print(printid_t pid, vector<string> pdiseases, vector<double> pattr, vector<string> pattrStr):ID(pid),diseases(pdiseases), attr(pattr), attrStr(pattrStr) {}

Print::Print() {
    ID = 0;
}

Print::~Print(){}
