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

        bool Equals(const Vaccination& other);
		bool NotEquals(const Vaccination& other);
		bool GreaterThan(const Vaccination& other);
		bool GreaterThanEquals(const Vaccination& other);
		bool LessThan(const Vaccination& other);
		bool LessThanEquals(const Vaccination& other);
};

Vaccination::Vaccination(string VaccinationID, int DosesAdministered):VaccinationID {VaccinationID}, DosesAdministered {DosesAdministered} {}

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

int main(){
    Vaccination vaccinations[] = { Vaccination("HS001", 5), Vaccination("HS002", 7) };

    cout << boolalpha;
    cout << "Equals: " << vaccinations[0].Equals(vaccinations[1]) << endl;
    cout << "Not Equals: " <<  vaccinations[0].NotEquals(vaccinations[1]) << endl;
    cout << "GreaterThan: " << vaccinations[0].GreaterThan(vaccinations[1]) << endl;
    cout << "LessThanEquals: " << vaccinations[0].LessThanEquals(vaccinations[1]) << endl;

    return 0;
}