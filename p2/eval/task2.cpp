#include <iostream>
#include <vector>
#include <climits>
#include <thread>

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

void findSum(vector<VaccinationRecord>& vaccinations, int &sum){
	for (auto vaccination : vaccinations){
		sum += vaccination.getDose();
	}
}

void findMinInFirstHalf(vector<VaccinationRecord>& vaccinations, int &min){
	int lastIndex = (vaccinations.size() / 2) - 1;
	for (int i = 0; i <= lastIndex; i++){
		int current = vaccinations[i].getDose();
		min = ( current < min) ? current : min;
	}
}

void findMaxInSecondHalf(vector<VaccinationRecord>& vaccinations, int &max){
	int firstIndex = (vaccinations.size() / 2);
	for (int i = firstIndex; i < vaccinations.size(); i++){
		int current = vaccinations[i].getDose();
		max = ( current > max) ? current : max;
	}
}

int main(){
	vector<VaccinationRecord> vaccinations;

	int sum = 0;
	int max = INT_MIN;
	int min = INT_MAX;

    vaccinations.emplace_back("ID001",3);
	vaccinations.emplace_back("ID002",2);
	vaccinations.emplace_back("ID003",1);
	vaccinations.emplace_back("ID004",5);
	vaccinations.emplace_back("ID005",4);

    thread sumThr(findSum, ref(vaccinations), ref(sum));
    thread minThr(findMinInFirstHalf, ref(vaccinations), ref(min));
    thread maxThr(findMaxInSecondHalf, ref(vaccinations), ref(max));

    sumThr.join();
    minThr.join();
    maxThr.join();	

	cout << "Sum: " << sum << endl;
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;

	return 0;
}
