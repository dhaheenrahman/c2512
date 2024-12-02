#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class Vaccination{
    friend class VaccinationManager;

    private:
        //members
        string VaccinationID;
        int DosesAdministered;
    public:
        //behaviours
        bool Equals(const Vaccination& other);
		bool NotEquals(const Vaccination& other);
		bool GreaterThan(const Vaccination& other);
		bool GreaterThanEquals(const Vaccination& other);
		bool LessThan(const Vaccination& other);
		bool LessThanEquals(const Vaccination& other);

        //getters
        string getVaccinationID();
        int getDosesAdministered();
};

class VaccinationManager{
    friend class VaccinationAggregator;
    friend int main();

    private:
        Vaccination vaccinations[MAX_SIZE];
        int numOfVaccinations;

    public:
        void create();
        void displayAll();
        void editByID();
        void deleteByID();

        int findIndexById(string id);
        
        VaccinationManager();
};

class VaccinationAggregator{
    public:
        int findMinDoseIndex(VaccinationManager& manager);
        int findMaxDoseIndex(VaccinationManager& manager);
        int findSecondMinDoseIndex(VaccinationManager& manager);
        int findSecondMaxDoseIndex(VaccinationManager& manager);
};

void printMenu();

int main(){
    VaccinationManager manager;
    VaccinationAggregator aggregator;
    int choice;
    
    do{
        printMenu();
    
        cin >> choice;

        switch(choice){
            case 1: 
                manager.create();
                break;
            case 2:
                manager.deleteByID();
                break;
            case 3:
                manager.editByID();
                break;
            case 4:
                manager.displayAll();
                break;
            case 5: 
                {
                    int minIndex = aggregator.findMinDoseIndex(manager);
                    cout << "min dose: " << manager.vaccinations[minIndex].getDosesAdministered() << endl;
                }
                break;
            case 6:
                {
                    int maxIndex = aggregator.findMaxDoseIndex(manager);
                    cout << "max dose: " << manager.vaccinations[maxIndex].getDosesAdministered() << endl;
                }
                break;
            case 7:
                {
                    int secondMinIndex = aggregator.findSecondMinDoseIndex(manager);
                    cout << "Second min dose: " << manager.vaccinations[secondMinIndex].getDosesAdministered() << endl;
                }
                break;
            case 8:
                {
                    int secondMaxIndex = aggregator.findSecondMaxDoseIndex(manager);
                    cout << "Second max dose: " << manager.vaccinations[secondMaxIndex].getDosesAdministered() << endl;
                }
                break;
            case 9:
                cout << "Good Bye!";
                break;
            default:
                cout << "Invalid input\n";
            
        }

    } while (choice != 9);

    
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

VaccinationManager::VaccinationManager(){
    numOfVaccinations = 0;
}

void VaccinationManager::create(){
    if(numOfVaccinations >= MAX_SIZE){
        cout << "Maximum limit reached!\n";
        return;
    }

    string id;

    cout << "Enter Vaccination ID: ";
    cin >> id;
    
    if(findIndexById(id) != -1){
        cout << "ID already exists!\n";
        return;
    }

    vaccinations[numOfVaccinations].VaccinationID = id;

    cout << "Doses Administered: ";
    cin >> vaccinations[numOfVaccinations].DosesAdministered;

    numOfVaccinations++;

    cout << "New record created!\n";
}

void VaccinationManager::displayAll(){
    if(numOfVaccinations <= 0){
        cout << "No records to display\n";
        return;
    }

    cout << "\nVaccination_ID\tDoses Administered\n";

    for (int i = 0; i < numOfVaccinations; i++){
        cout << vaccinations[i].VaccinationID << "\t\t"
        << vaccinations[i].DosesAdministered << "\n";
    }
}

void VaccinationManager::editByID(){
    string id;

    cout << "Enter Vaccination ID: ";
    cin >> id;
    
    int index = findIndexById(id);

    if(index == -1){
        cout << "No such records!\n";
        return;
    }

    // cout << "Current ID: " << vaccinations[index].VaccinationID;
    cout << "Current Doses Admininstered: " << vaccinations[index].DosesAdministered;
    // cout << "\n\nEnter new ID: ";
    // cin >> vaccinations[index].VaccinationID;
    cout << "\nEnter new Doses Administered: ";
    cin >> vaccinations[index].DosesAdministered;
    cout << "Record updated!\n";
}

void VaccinationManager::deleteByID(){
    if(numOfVaccinations <= 0){
        cout << "No records to delete\n";
        return;
    }

    string id;
    
    cout << "Enter Vaccination ID: ";
    cin >> id;
    
    int index = findIndexById(id);

    if(index == -1){
        cout << "No such records!\n";
        return;
    }

    for (int i = index; i < (numOfVaccinations - 1); i++){
        vaccinations[i] = vaccinations[i + 1];
    }

    numOfVaccinations--;

    cout << "Record deleted!\n";
}

int VaccinationManager::findIndexById(string id) {
    for (int i = 0; i < numOfVaccinations; i++) {
        if (vaccinations[i].VaccinationID == id) {
            return i;
        }
    }

    return -1;
}

int VaccinationAggregator::findMinDoseIndex(VaccinationManager& manager){
    int minIndex = 0;

    for(int i = 1; i < manager.numOfVaccinations; i++){
        if(manager.vaccinations[i].LessThan(manager.vaccinations[minIndex])){
            minIndex = i;
        }
    }

    return minIndex;
}

int VaccinationAggregator::findMaxDoseIndex(VaccinationManager& manager){
    int maxIndex = 0;

    for(int i = 1; i < manager.numOfVaccinations; i++){
        if(manager.vaccinations[i].GreaterThan(manager.vaccinations[maxIndex])){
            maxIndex = i;
        }
    }

    return maxIndex;
}

int VaccinationAggregator::findSecondMinDoseIndex(VaccinationManager& manager){
    int minIndex = findMinDoseIndex(manager);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for(int i = 1; i < manager.numOfVaccinations; i++){
        if(i != minIndex){
            if(manager.vaccinations[i].LessThan(manager.vaccinations[secondMinIndex])){
                secondMinIndex = i;
            }
        }
    }

    return secondMinIndex;
}

int VaccinationAggregator::findSecondMaxDoseIndex(VaccinationManager& manager){
    int maxIndex = findMaxDoseIndex(manager);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for(int i = 1; i < manager.numOfVaccinations; i++){
        if(i != maxIndex){
            if(manager.vaccinations[i].GreaterThan(manager.vaccinations[secondMaxIndex])){
                secondMaxIndex = i;
            }
        }
    }

    return secondMaxIndex;
}

void printMenu(){
    cout << "\n1. Create new Vaccination record\n";
    cout << "2. Delete a record\n";
    cout << "3. Edit a record\n";
    cout << "4. Display all records\n";
    cout << "5. find Minimum Dose Administered\n";
    cout << "6. find Maximum Dose Administered\n";
    cout << "7. find Second Minimum Dose Administered\n";
    cout << "8. find Second Maximum Dose Administered\n";
    cout << "9. Exit\n\n";
}