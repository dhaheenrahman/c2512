#include<iostream>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<cstring>
#include <string>
#include <vector>
using namespace std;

#define SHM_KEY 1234

class VaccinationRecord {
    private:
        string vaccinationId;
        int dosesAdministered;
    
    public:
        VaccinationRecord(string vaccinationId, int dosesAdministered)
            : vaccinationId(vaccinationId), dosesAdministered(dosesAdministered) {}
        
        int getDose() const { return dosesAdministered; }
};

int findSum(int array[], int& size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

void client(const vector<VaccinationRecord>& vaccinationRecords, int shmid) { // child 1
    int* sharedMemory = (int*)shmat(shmid, nullptr, 0); // attach shared memory

    int size = vaccinationRecords.size();
    sharedMemory[0] = size;  // Store the size of records in shared memory
    for (int i = 1; i <= size; i++) {
        sharedMemory[i] = vaccinationRecords[i - 1].getDose(); // Writing dosesAdministered to shared memory
    }

    // Print the message written
    cout << "Size written to shared memory: " << sharedMemory[0] << endl;
    cout << "doses written to shared memory: " << endl;
    
    for (int i = 1; i <= size; i++) {
        cout << sharedMemory[i] << " ";  // Display doses
    }
    cout << endl;

    sleep(2);
    cout << "Total doses administered retrieved from shared memory: " << sharedMemory[size + 1] << endl;
    shmdt(sharedMemory); // Detach shared memory

}

void server(int shmid) { 
    int* sharedMemory = (int*)shmat(shmid, nullptr, 0);
    int sum = 0;
    int size = sharedMemory[0]; 
    cout << "Size retrieved from shared memory: " << size << endl;

    cout << "doses retrieved from shared memory: " << endl;
    for (int i = 1; i <= size; i++) {
        cout << sharedMemory[i] << " ";  
    }
    cout << endl;

    sum = findSum(sharedMemory + 1, size);  

    sharedMemory[size + 1] = sum;

    cout << "Total doses administered written to shared memory: " << sharedMemory[size + 1] << endl;

    shmdt(sharedMemory); 
}

int main() {

    vector<VaccinationRecord> vaccinations;
    vaccinations.emplace_back("ID001",3);
	vaccinations.emplace_back("ID002",2);
	vaccinations.emplace_back("ID003",1);
	vaccinations.emplace_back("ID004",5);
	vaccinations.emplace_back("ID005",4);	

    int shmid = shmget(SHM_KEY, sizeof(int) * (vaccinations.size() + 1), 0666 | IPC_CREAT); 
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        client(vaccinations, shmid);
        return 0;
    }

    pid = fork();
    if (pid == 0) {
        sleep(1); 
        server(shmid);
        shmctl(shmid, IPC_RMID, nullptr);
        return 0;
    }

    sleep(2);
    return 0;
}
