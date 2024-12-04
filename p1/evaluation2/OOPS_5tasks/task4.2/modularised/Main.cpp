#include<iostream>
#include<string>

#include "Vaccination.h"

using std::cout;
using std::endl;
using std::string;
using std::boolalpha;

int main(){
    Vaccination v1("V001", 2);
    Vaccination v2("V002", 3);
    VaccinationComparison comparisons;

    cout << boolalpha;
    cout << "Equals: " << comparisons.Equals(v1,v2) << endl;
    cout << "Not Equals: " <<  comparisons.NotEquals(v1,v2) << endl;
    cout << "GreaterThan: " << comparisons.GreaterThan(v1,v2) << endl;
    cout << "LessThanEquals: " << comparisons.LessThanEquals(v1,v2) << endl;

    return 0;
}