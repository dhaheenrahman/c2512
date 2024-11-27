#include<iostream>
#include<string>

#include "Vaccination.h"

using std::string;

bool Vaccination::Equals(const Vaccination& other){
	return DosesAdministered == other.DosesAdministered;
}
bool Vaccination::NotEquals(const Vaccination& other){
	return DosesAdministered != other.DosesAdministered;
}
bool Vaccination::GreaterThan(const Vaccination& other){
	return DosesAdministered > other.DosesAdministered;
}
bool Vaccination::GreaterThanEquals(const Vaccination& other){
	return DosesAdministered >= other.DosesAdministered;
}
bool Vaccination::LessThan(const Vaccination& other){
	return DosesAdministered < other.DosesAdministered;
}
bool Vaccination::LessThanEquals(const Vaccination& other){
	return DosesAdministered <= other.DosesAdministered;
}
//constructor
Vaccination::Vaccination(string p_VaccinationID, int p_DosesAdministered){
	VaccinationID = p_VaccinationID;
	DosesAdministered = p_DosesAdministered;
}
