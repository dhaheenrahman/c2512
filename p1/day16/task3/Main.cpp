#include<iostream>
#include<iomanip>

#include "Vaccination.h"
#include "HospitalStay.h"

using std::cout;
using std::boolalpha;
using std::endl;

int main() {
    Vaccination v1("V001", 2);
    Vaccination v2("V002", 3);
    HospitalStay hs1("HS001",5);
    HospitalStay hs2("HS002",7);

    cout << boolalpha;
    cout << "Equals: " << Equals(v1,v2) << endl;
    cout << "GreaterThan: " << GreaterThan(v1,v2) << endl;
    cout << "LessThanEquals: " << LessThanEquals(v1,v2) << endl;

    cout << "Equals: " << hs1.Equals(hs2) << endl;
    cout << "GreaterThan: " << hs1.GreaterThan(hs2) << endl;
    cout << "LessThanEquals: " << hs1.LessThanEquals(hs2) << endl;

    return 0;
}

