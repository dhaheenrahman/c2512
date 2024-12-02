#include<iostream>
#include<string>

#include "Vaccination.h"

using std::cout;
using std::endl;
using std::boolalpha;

int main(){
    Vaccination vaccinations[] = { Vaccination("HS001", 5), Vaccination("HS002", 7) };

    cout << boolalpha;
    cout << "Equals: " << vaccinations[0].Equals(vaccinations[1]) << endl;
    cout << "Not Equals: " <<  vaccinations[0].NotEquals(vaccinations[1]) << endl;
    cout << "GreaterThan: " << vaccinations[0].GreaterThan(vaccinations[1]) << endl;
    cout << "LessThanEquals: " << vaccinations[0].LessThanEquals(vaccinations[1]) << endl;

    return 0;
}