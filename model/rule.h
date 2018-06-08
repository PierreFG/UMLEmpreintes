//---------- Interface de la classe <Rule> (fichier Rule.h) ----------------
#if ! defined ( RULE_H )
#define RULE_H

#include <string>
#include <map>
#include <vector>
#include <memory>
using namespace std;

class Rule
{

public:
    Rule (map<string,vector<double>> ,map<int,vector<string>>);
    virtual ~Rule ();

    map<string,vector<double>> getAsso();
    map<int,vector<string>> getOneHotRule();

    friend ostream& operator<<(ostream& out, const Rule& r);

private:
    map<string,vector<double>> asso;
    map<int,vector<string>> oneHotRule;
};

typedef shared_ptr<Rule> Rule_ptr;

#endif // RULE_H
