#include<string>

#include "Vaccination.h"

Vaccination::Vaccination(string VaccinationID, int DosesAdministered){
    this -> VaccinationID = VaccinationID;
    this -> DosesAdministered = DosesAdministered;
}


bool VaccinationComparison::Equals(const Vaccination& first, const Vaccination& second){
    return (first.DosesAdministered == second.DosesAdministered);
}
bool VaccinationComparison::NotEquals(const Vaccination& first, const Vaccination& second){
    return (first.DosesAdministered != second.DosesAdministered);
}
bool VaccinationComparison::GreaterThan(const Vaccination& first, const Vaccination& second){
    return (first.DosesAdministered > second.DosesAdministered);
}
bool VaccinationComparison::GreaterThanEquals(const Vaccination& first, const Vaccination& second){
    return (first.DosesAdministered >= second.DosesAdministered);
}
bool VaccinationComparison::LessThan(const Vaccination& first, const Vaccination& second){
    return (first.DosesAdministered < second.DosesAdministered);
}
bool VaccinationComparison::LessThanEquals(const Vaccination& first, const Vaccination& second){
    return (first.DosesAdministered <= second.DosesAdministered);
}