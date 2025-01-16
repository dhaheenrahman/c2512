#include <iostream>
#include <vector>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <cstring>
#include <string>
#include <unistd.h>

using namespace std;

class VaccinationRecord {
private:
    string vaccinationId;
    int DoseAdministered;
public:
    VaccinationRecord(string id, int dose) : vaccinationId(id), DoseAdministered(dose) {}

    int getDoseAdministered() const { return DoseAdministered; }
};

struct Message {
    long msg_type;
    int data[100];
};

void client(int msgid) {
    vector<VaccinationRecord> vaccinations = {
        VaccinationRecord("V001", 2), 
        VaccinationRecord("V002", 1), 
        VaccinationRecord("V003", 5), 
        VaccinationRecord("V004", 4), 
        VaccinationRecord("V005", 3)
    };

    int size = vaccinations.size();
    Message msg;
    msg.msg_type = 1;

    for (int i = 0; i < size; ++i) {
        msg.data[i] = vaccinations[i].getDoseAdministered();
    }

    cout << "Client sending doses: ";
    for (int i = 0; i < size; ++i) {
        cout << msg.data[i] << " ";
    }
    cout << endl;

    msgsnd(msgid, &msg, sizeof(msg.data), 0);

    int sum;
    msgrcv(msgid, &msg, sizeof(msg.data), 2, 0);
    sum = msg.data[0];
    cout << "Client received sum from server: " << sum << endl;
}

void server(int msgid) {
    Message msg;
    int sum = 0;

    msgrcv(msgid, &msg, sizeof(msg.data), 1, 0);

    cout << "Server received doses: ";
    for (int i = 0; i < 5; ++i) {
        cout << msg.data[i] << " ";
        sum += msg.data[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    msg.msg_type = 2;
    msg.data[0] = sum;
    msgsnd(msgid, &msg, sizeof(msg.data), 0);
}

int main() {
    int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Message queue creation failed");
        return 1;
    }
    {
        int pid = fork();
        if (pid == 0) {
            client(msgid);
            return 0;
        }
    }
    
    {
        int pid = fork();
        if (pid == 0) {
            server(msgid);
            return 0;
        }
    }
    wait(nullptr);
    wait(nullptr);

    msgctl(msgid, IPC_RMID, nullptr);
    return 0;
}
