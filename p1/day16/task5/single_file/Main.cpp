#include<iostream>
#include<string>

using namespace std;

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

int findMinDoseIndex(Vaccination vaccinations[], int size);
int findMaxDoseIndex(Vaccination vaccinations[], int size);
int findSecondMinDoseIndex(Vaccination vaccinations[], int size);
int findSecondMaxDoseIndex(Vaccination vaccinations[], int size);

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

int findMinDoseIndex(Vaccination vaccinations[], int size){
    int minIndex = 0;
    for(int i = 1; i < size; i++){
        if(vaccinations[i].LessThan(vaccinations[minIndex])){
            minIndex = i;
        }
    }
    return minIndex;
}
int findMaxDoseIndex(Vaccination vaccinations[], int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (vaccinations[i].GreaterThan(vaccinations[maxIndex]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findSecondMinDoseIndex(Vaccination vaccinations[], int size)
{
    int minIndex = findMinDoseIndex(vaccinations, size);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for (int i = 0; i < size; i++)
    {
        if (i != minIndex)
        {
            if (vaccinations[i].LessThan(vaccinations[secondMinIndex]))
            {
                secondMinIndex = i;
            }
        }
    }

    
    return secondMinIndex;
}

int findSecondMaxDoseIndex(Vaccination vaccinations[], int size)
{
    int maxIndex = findMaxDoseIndex(vaccinations, size);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for (int i = 0; i < size; i++)
    {
        if (i != maxIndex)
        {
            if (vaccinations[i].GreaterThan(vaccinations[secondMaxIndex]))
            {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}
