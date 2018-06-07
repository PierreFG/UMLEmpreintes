//---------- Interface de la classe <Print> (fichier print.h) ----------------
#if ! defined ( PRINT_H )
#define PRINT_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Print
{

public:
    friend ostream& operator << (ostream& out, const Print& p);
    Print (long id, string, vector<double>, vector<string>);
    virtual ~Print ();

    long getID();
    vector<string> getDiseases();
    vector<double> getAttr();
    vector<string> getAttrStr();
    void addDisease(string disease);


protected:
    long ID;
    vector<string> diseases;
    vector<double> attr;
    vector<string> attrStr;

};

typedef std::shared_ptr<Print> Print_ptr;

#endif // Print_H
