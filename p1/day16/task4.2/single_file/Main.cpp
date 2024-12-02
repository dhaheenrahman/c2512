#include<iostream>
#include<string>

using namespace std;

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