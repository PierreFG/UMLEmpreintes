#include <iostream>
using namespace std;
#include "./modele/doctor.h"

int main(){
    Doctor * d = new Doctor("Louis", "Ohl", "louis.ohl@ina-lyon.fr", "a");
    cout << *d;
    return 0;
}

