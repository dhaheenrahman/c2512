#include<iostream>
#include<string>

#include "Vaccination.h"
#include "Aggregator.h"

using namespace std;

int main(){
    Vaccination vaccinations[] = { Vaccination("V001", 2), Vaccination("V001", 4), Vaccination("V002", 5), Vaccination("V003", 1), Vaccination("V004", 3) };

    cout << boolalpha;
    cout << "Equals: " << vaccinations[0].Equals(vaccinations[1]) << endl;
    cout << "Not Equals: " <<  vaccinations[0].NotEquals(vaccinations[1]) << endl;
    cout << "GreaterThan: " << vaccinations[0].GreaterThan(vaccinations[1]) << endl;
    cout << "LessThanEquals: " << vaccinations[0].LessThanEquals(vaccinations[1]) << endl;

    int size = sizeof(vaccinations) / sizeof(vaccinations[0]);
    int minDose = vaccinations[findMinDoseIndex(vaccinations, size)].getDosesAdministered();
    int maxDose = vaccinations[findMaxDoseIndex(vaccinations, size)].getDosesAdministered();
    int secondMinDose = vaccinations[findSecondMinDoseIndex(vaccinations, size)].getDosesAdministered();
    int secondMaxDose = vaccinations[findSecondMaxDoseIndex(vaccinations, size)].getDosesAdministered();



    cout << "\nMinimum Dose Administered: " << minDose;
    cout << "\nMaximum Dose Administered: " << maxDose;
    cout << "\nSecond Minimum Dose Administered: " << secondMinDose;
    cout << "\nSecond Maximum Dose Administered: " << secondMaxDose << endl;


    return 0;
}

