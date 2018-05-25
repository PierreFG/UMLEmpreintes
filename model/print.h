//---------- Interface de la classe <Print> (fichier print.h) ----------------
#if ! defined ( PRINT_H )
#define PRINT_H

#include <string>
#include <vector>
using namespace std;

class Print
{

public:
    Print (vector<string>, vector<double>, vector<string>);
    virtual ~Print ();

    long getID();
    vector<string> getDiseases();
    vector<double> getAttr();
    vector<string> getAttrStr();


protected:
    long ID;
    vector<string> diseases;
    vector<double> attr;
    vector<string> attrStr;
    
};

#endif // Print_H
