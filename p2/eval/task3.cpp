#include <iostream>
#include <vector>
#include <climits>
#include <unistd.h>
#include <cstring>

using namespace std;

class VaccinationRecord{
	private:
		string vaccinationId;
		int dosesAdministered;
	
	public:
		VaccinationRecord(string vaccinationId, int dosesAdministered){
			this -> vaccinationId = vaccinationId;
			this -> dosesAdministered = dosesAdministered;
		}	

		int getDose(){ return this -> dosesAdministered;}
};

int findSum(int array[], int& size){
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum += array[i];
	}
    
    return sum;
}

void client(vector<VaccinationRecord>& vaccinations, int &pipe_one_write_fd, int &pipe_two_read_fd){
    int numOfElements = vaccinations.size();
    write(pipe_one_write_fd, &numOfElements, sizeof(int));
    cout << "data 1 sent to server: " << numOfElements << endl;
    int doses[numOfElements];

    for(int i = 0; i < numOfElements; i++){
        doses[i] = vaccinations[i].getDose();
    }

    write(pipe_one_write_fd, doses, sizeof(doses));
    
    cout << "data 2 sent to server: \t" ;
    for (int dose : doses){
        cout << dose << "\t";
    }
    cout << endl;

    close(pipe_one_write_fd);

    sleep(2);
    int sum = 0;
    read(pipe_two_read_fd, &sum, sizeof(int));
    cout << "Sum received from server: " << sum << endl;
    close(pipe_two_read_fd);

}

void server(int &pipe_one_read_fd, int &pipe_two_write_fd){
    sleep(1);
    int numOfElements;
    read(pipe_one_read_fd, &numOfElements, sizeof(numOfElements));
    cout << "data 1 received from client: " << numOfElements << endl;

    int buffer[numOfElements];
    read(pipe_one_read_fd, buffer, (sizeof(int) * numOfElements));
    cout << "data 2 received from client: \t" ;
    for (int element : buffer){
        cout << element << "\t";
    }
    cout << endl;
    close(pipe_one_read_fd);

    int sum = findSum(buffer, numOfElements);
    write(pipe_two_write_fd, &sum, sizeof(int));
    close(pipe_two_write_fd);

}

int main(){
	vector<VaccinationRecord> vaccinations;
   
    vaccinations.emplace_back("ID001",3);
	vaccinations.emplace_back("ID002",2);
	vaccinations.emplace_back("ID003",1);
	vaccinations.emplace_back("ID004",5);
	vaccinations.emplace_back("ID005",4);	

    int pipe_one_fd[2], pipe_two_fd[2];
     

    if(pipe(pipe_two_fd) == -1){
        perror("pipe2 creation failure");
        return 1;
    }

    int &pipe_one_read_fd = pipe_one_fd[0];   
    int &pipe_one_write_fd = pipe_one_fd[1];  
    int &pipe_two_read_fd = pipe_two_fd[0];   
    int &pipe_two_write_fd = pipe_two_fd[1];   

    pid_t pid = -1;

    {
        pid = fork();
        if(0 == pid){
            client(vaccinations, pipe_one_write_fd, pipe_two_read_fd);
            return 0;
        }
    }

    {
        pid = fork();
        if(0 == pid){
            server(pipe_one_read_fd, pipe_two_write_fd);
            return 0;
        }
    }

    sleep(3);
	return 0;
}
