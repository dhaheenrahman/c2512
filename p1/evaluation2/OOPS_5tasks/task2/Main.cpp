#include<iostream>
#include<iomanip>

#include "Vaccination.h"

using std::cout;
using std::boolalpha;
using std::endl;

int main() {
    Vaccination v1("V001", 2);
    Vaccination v2("V002", 3);
    Vaccination v3("V003", 1);
    Vaccination v4("V004", 3);

    cout << boolalpha;
    cout << "Equals: " << Equals(v1,v2) << endl;
    cout << "Not Equals: " <<  NotEquals(v1,v2) << endl;
    cout << "GreaterThan: " << GreaterThan(v1,v3) << endl;
    cout << "LessThanEquals: " << LessThanEquals(v4,v1) << endl;
    cout << "Equals: " << LessThanEquals(v4,v2) << endl;

    return 0;
}

