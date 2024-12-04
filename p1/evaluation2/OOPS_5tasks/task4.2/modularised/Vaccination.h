#pragma once
#include <string>

using std::string;

class Vaccination{
    friend class VaccinationComparison;
    
    private:
        string VaccinationID;
        int DosesAdministered;
    
    public:
        Vaccination(string VaccinationID, int DosesAdministered);
};
class VaccinationComparison{
    public:
        bool Equals(const Vaccination& first, const Vaccination& second); 
        bool NotEquals(const Vaccination& first, const Vaccination& second); 
        bool GreaterThan(const Vaccination& first, const Vaccination& second); 
        bool GreaterThanEquals(const Vaccination& first, const Vaccination& second); 
        bool LessThan(const Vaccination& first, const Vaccination& second); 
        bool LessThanEquals(const Vaccination& first, const Vaccination& second); 
};