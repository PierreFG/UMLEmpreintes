#include "print.h"
#include <iostream>
long Print::getID(){
    return ID;
}

vector<string> Print::getDiseases(){
    return diseases;
}

vector<double> Print::getAttr(){
    return attr;
}

vector<string> Print::getAttrStr(){
    return attrStr;
}

void Print::addDisease(string disease){
    cout << "J'ajoute : "<<disease << endl;
    diseases.push_back(disease);
    cout << diseases.back()<<endl;
    cout<<"Mes maladies sont :"<<endl;
    for (auto it=diseases.cbegin(); it!=diseases.cend(); it++){
        cout << *it << " | ";
    }
}

Print::Print(long pid, string pdiseases, vector<double> pattr, vector<string> pattrStr)
{
    ID = pid;
    diseases.push_back(pdiseases);
    cout << diseases.back()<<endl;
    for(auto it=pattrStr.cbegin(); it!=pattrStr.cend(); it++){
        attrStr.push_back(*it);
        
        cout << *it << " |";
    }
    cout<<endl;
    for(auto it=pattr.cbegin(); it!=pattr.cend(); it++){
        attr.push_back(*it);
        cout << *it << " |";
    }
    cout<<endl;
}

Print::~Print(){}