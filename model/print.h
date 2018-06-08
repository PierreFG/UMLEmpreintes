//---------- Interface de la classe <Print> (fichier print.h) ----------------
#if ! defined ( PRINT_H )
#define PRINT_H

#include <string>
#include <vector>
#include <memory>
using namespace std;

typedef int64_t printid_t;

/*
* Contains the print of a patient.
*/

class Print
{
public:
    Print (printid_t id, vector<string>, vector<double>, vector<string>);
    /*Constructor*/
    Print(Print &p);
    /*Copy constructor*/
    Print();
    /*Default constructor*/
    virtual ~Print();
    /*Default destructor*/

    friend ostream& operator << (ostream& out, const Print& p);
    /*Extern overload of the output stream operator*/
    Print& operator =(const Print& p); 
    /*Overload the input equals operator*/

    void addDisease(string d);

    long getID() const;
    /*Returns the Print's id*/
    vector<string> getDiseases() const;
    /*Returns the diseases attribute*/
    vector<double> getAttr() const;
    /*Returns the attr attribute*/
    vector<string> getAttrStr() const;
    /*Returns the attrStr attribute*/

private:
    printid_t ID;
    vector<string> diseases;
    vector<double> attr;
    vector<string> attrStr;

};

typedef shared_ptr<Print> Print_ptr;

#endif // Print_H
