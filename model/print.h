//---------- Interface de la classe <Print> (fichier print.h) ----------------
#if ! defined ( PRINT_H )
#define PRINT_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

typedef int64_t printid_t;

class Print
{

public:
    friend ostream& operator << (ostream& out, const Print& p);
    Print& operator =(const Print& p);
    Print (printid_t id, vector<string>, vector<double>, vector<string>);
    Print(Print &p);
    Print();
    virtual ~Print();

    void addDisease(string d);

    long getID() const;
    vector<string> getDiseases() const;
    vector<double> getAttr() const;
    vector<string> getAttrStr() const;


private:
    printid_t ID;
    vector<string> diseases;
    vector<double> attr;
    vector<string> attrStr;

};

typedef shared_ptr<Print> Print_ptr;

#endif // Print_H
