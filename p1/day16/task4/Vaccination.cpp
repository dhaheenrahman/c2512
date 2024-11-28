#include<iostream>
#include<string>

#include "Vaccination.h"

using std::string;

bool VaccinationComparison::Equals(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered == second.DosesAdministered;
}
bool VaccinationComparison::NotEquals(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered != second.DosesAdministered;
}
bool VaccinationComparison::GreaterThan(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered > second.DosesAdministered;
}
bool VaccinationComparison::GreaterThanEquals(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered >= second.DosesAdministered;
}
bool VaccinationComparison::LessThan(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered < second.DosesAdministered;
}
bool VaccinationComparison::LessThanEquals(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered <= second.DosesAdministered;
}
//constructor
Vaccination::Vaccination(string p_VaccinationID, int p_DosesAdministered){
        VaccinationID = p_VaccinationID;
        DosesAdministered = p_DosesAdministered;
}

