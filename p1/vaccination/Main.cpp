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
    cout << "Equals: " << v1.Equals(v2) << endl;
    cout << "Not Equals: " <<  v1.NotEquals(v2) << endl;
    cout << "GreaterThan: " << v1.GreaterThan(v3) << endl;
    cout << "LessThanEquals: " << v4.LessThanEquals(v1) << endl; 
    cout << "Equals: " << v4.LessThanEquals(v2) << endl; 
   

    return 0;
}
