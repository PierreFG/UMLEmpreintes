#include <iostream>
using namespace std;
#include "doctor.h"

int main(){
    Doctor * d = new Doctor("Louis", "Ohl", "louis.ohl@ina-lyon.fr", "a");
    cout << *d;
    return 0;
}

