
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vaccination{
    friend class VaccinationManager;

    private:
        string VaccinationID;
        int DosesAdministered;
};

class VaccinationManager{
    private:
        vector<Vaccination> vaccinations;

    public:
        void create();
        void displayAll();
        void editByID();
        void deleteByID();

        int findIndexById(string id);
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
                break;
            default:
                cout << "Invalid input";
            
        }

    } while (choice != 5);

    
}

void VaccinationManager::create(){
    string id;

    cout << "Enter Vaccination ID: ";
    cin >> id;
    
    if(findIndexById(id) != -1){
        cout << "ID already exists!";
        return;
    }

    Vaccination tempRecord;
    tempRecord.VaccinationID = id;

    cout << "Doses Administered: ";
    cin >> tempRecord.DosesAdministered;

    vaccinations.push_back(tempRecord);

    cout << "New record created!\n";

}

void VaccinationManager::displayAll(){
    if(vaccinations.empty()){
        cout << "No records to display";
        return;
    }

    cout << "\nVaccination_ID\tDoses Administered\n";

    for (int i = 0; i < vaccinations.size(); i++){
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

    cout << "Current Doses Admininstered: " << vaccinations[index].DosesAdministered;
    cout << "\nEnter new Doses Administered: ";
    cin >> vaccinations[index].DosesAdministered;
    cout << "Record updated!\n";

}

void VaccinationManager::deleteByID(){
    if(vaccinations.empty()){
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

    vaccinations.erase(vaccinations.begin() + index);
    
    cout << "Record deleted!\n";
}

int VaccinationManager::findIndexById(string id) {
    for (int i = 0; i < vaccinations.size(); i++) {
        if (vaccinations[i].VaccinationID == id) {
            return i;
        }
    }
    return -1;
}