#include "rule.h"

map<string,vector<double>> Rule::getAsso(){
    return asso;
}

Rule::Rule (map<string,vector<double>> passo):asso(passo)
{}

Rule::~Rule(){}