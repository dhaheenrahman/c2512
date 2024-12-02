#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class Vaccination{
    friend class VaccinationManager;

    private:
        string VaccinationID;
        int DosesAdministered;
};

class VaccinationManager{
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

void printMenu(){
    cout << "\n\n1. Create new Vaccination record\n2. Delete a record\n3. Edit a record\n4. Display all records\n5. Exit\n\nChoose an option: ";
}

int main(){
    VaccinationManager manager;
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
                cout << "Good Bye!";
            default:
                cout << "Invalid input";
            
        }

    } while (choice != 5);

    
}

VaccinationManager::VaccinationManager(){
    numOfVaccinations = 0;
}

void VaccinationManager::create(){
    if(numOfVaccinations >= MAX_SIZE){
        cout << "Maximum limit reached!";
        return;
    }

    string id;

    cout << "Enter Vaccination ID: ";
    cin >> id;
    
    if(findIndexById(id) != -1){
        cout << "ID already exists!";
        return;
    }

    vaccinations[numOfVaccinations].VaccinationID = id;

    cout << "Doses Administered: ";
    cin >> vaccinations[numOfVaccinations].DosesAdministered;

    numOfVaccinations++;
}

void VaccinationManager::displayAll(){
    if(numOfVaccinations <= 0){
        cout << "No records to display";
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
        cout << "No such records!";
        return;
    }

    cout << "Current ID: " << vaccinations[index].VaccinationID;
    cout << "Current Doses Admininstered: " << vaccinations[index].DosesAdministered;
    cout << "\n\nEnter new ID: ";
    cin >> vaccinations[index].VaccinationID;
    cout << "Enter new Doses Administered: ";
    cin >> vaccinations[index].DosesAdministered;
}

void VaccinationManager::deleteByID(){
    if(numOfVaccinations <= 0){
        cout << "No records to delete";
        return;
    }

    string id;
    
    cout << "Enter Vaccination ID: ";
    cin >> id;
    
    int index = findIndexById(id);

    if(index == -1){
        cout << "No such records!";
        return;
    }

    for (int i = index; i < (numOfVaccinations - 1); i++){
        vaccinations[i] = vaccinations[i + 1];
    }

    numOfVaccinations--;
}

int VaccinationManager::findIndexById(string id) {
    for (int i = 0; i < numOfVaccinations; i++) {
        if (vaccinations[i].VaccinationID == id) {
            return i;
        }
    }
    return -1;
}