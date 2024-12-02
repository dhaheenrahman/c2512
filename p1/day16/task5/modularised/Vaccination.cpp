#include <string>
#include "Vaccination.h"

using std::string;

Vaccination::Vaccination(string VaccinationID, int DosesAdministered){
    this -> VaccinationID = VaccinationID;
    this -> DosesAdministered = DosesAdministered;
}


bool Vaccination::Equals(const Vaccination& other){
    return (DosesAdministered == other.DosesAdministered);
}
bool Vaccination::NotEquals(const Vaccination& other){
    return (DosesAdministered != other.DosesAdministered);
}
bool Vaccination::GreaterThan(const Vaccination& other){
    return (DosesAdministered > other.DosesAdministered);
}
bool Vaccination::GreaterThanEquals(const Vaccination& other){
    return (DosesAdministered >= other.DosesAdministered);
}
bool Vaccination::LessThan(const Vaccination& other){
    return (DosesAdministered < other.DosesAdministered);
}
bool Vaccination::LessThanEquals(const Vaccination& other){
    return (DosesAdministered <= other.DosesAdministered);
}
string Vaccination::getVaccinationID(){
    return VaccinationID;
}
int Vaccination::getDosesAdministered(){
    return DosesAdministered;
}