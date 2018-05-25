#include "print.h"

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

Print::Print(long pid, vector<string> pdiseases, vector<double> pattr, vector<string> pattrStr):ID(pid),diseases(pdiseases), attr(pattr), attrStr(pattrStr)
{
    ID = 0;
}

Print::~Print(){}