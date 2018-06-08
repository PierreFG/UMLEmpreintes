#include "rule.h"

map<string,vector<double>> Rule::getAsso(){
    return asso;
}
map<int,vector<string>> Rule::getOneHotRule(){
    return oneHotRule;
}

//***********Constructor/Destructor
Rule::Rule (map<string,vector<double>> passo, map<int,vector<string>> pOneHotRule):asso(passo),oneHotRule(pOneHotRule)
{}

Rule::~Rule(){}
