#include<iostream>
#include<string>

#include "Vaccination.h"

using std::string;

bool Equals(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered == second.DosesAdministered;
}
bool NotEquals(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered != second.DosesAdministered;
}
bool GreaterThan(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered > second.DosesAdministered;
}
bool GreaterThanEquals(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered >= second.DosesAdministered;
}
bool LessThan(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered < second.DosesAdministered;
}
bool LessThanEquals(const Vaccination& first, const Vaccination& second){
        return first.DosesAdministered <= second.DosesAdministered;
}
//constructor
Vaccination::Vaccination(string p_VaccinationID, int p_DosesAdministered){
        VaccinationID = p_VaccinationID;
        DosesAdministered = p_DosesAdministered;
}

