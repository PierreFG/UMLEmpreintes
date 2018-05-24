#include "print.h"

long Print::getID(){
    return ID;
}

vector<string> Print::getDiseases(){
    return diseases;
}

double* Print::getAttr(){
    return attr;
}

Print::Print(vector<string> pdiseases, double* pattr):diseases(pdiseases), attr(pattr)
{
    ID = 0;
}

Print::~Print(){}