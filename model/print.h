//---------- Interface de la classe <Print> (fichier print.h) ----------------
#if ! defined ( PRINT_H )
#define PRINT_H

#include <string>
#include <vector>
using namespace std;

class Print
{

public:
    Print (vector<string>, double*);
    virtual ~Print ();

    long getID();
    vector<string> getDiseases();
    double* getAttr();


protected:
    long ID;
    vector<string> diseases;
    double* attr;
    
};

#endif // Print_H
