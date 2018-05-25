//---------- Interface de la classe <Rule> (fichier Rule.h) ----------------
#if ! defined ( RULE_H )
#define RULE_H

#include <string>
#include <map>
#include <vector>
using namespace std;

class Rule
{

public:
    Rule (map<string,vector<double>>);
    virtual ~Rule ();

    map<string,vector<double>> getAsso();

protected:
    map<string,vector<double>> asso;
};

#endif // RULE_H
