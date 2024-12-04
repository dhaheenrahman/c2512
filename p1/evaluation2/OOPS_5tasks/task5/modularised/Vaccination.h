#pragma once
#include <string>

using std::string;

class Vaccination{
    private:
        string VaccinationID;
        int DosesAdministered;
    
    public:
        Vaccination(string VaccinationID, int DosesAdministered);
        bool Equals(const Vaccination& other);
		bool NotEquals(const Vaccination& other);
		bool GreaterThan(const Vaccination& other);
		bool GreaterThanEquals(const Vaccination& other);
		bool LessThan(const Vaccination& other);
		bool LessThanEquals(const Vaccination& other);

        string getVaccinationID();
        int getDosesAdministered();

};