#include <iostream>
#include <vector>
#include <climits>

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

int findSum(vector<VaccinationRecord>& vaccinations){
	int sum = 0;
	for (auto vaccination : vaccinations){
		sum += vaccination.getDose();
	}

	return sum;
}

int findMinInFirstHalf(vector<VaccinationRecord>& vaccinations){
	int min = INT_MAX;
	int lastIndex = (vaccinations.size() / 2) - 1;
	for (int i = 0; i <= lastIndex; i++){
		int current = vaccinations[i].getDose();
		min = ( current < min) ? current : min;
	}
	return min;
}

int findMaxInSecondHalf(vector<VaccinationRecord>& vaccinations){
	int max = INT_MIN;
	int firstIndex = (vaccinations.size() / 2);
	for (int i = firstIndex; i < vaccinations.size(); i++){
		int current = vaccinations[i].getDose();
		max = ( current > max) ? current : max;
	}
	return max;
}

int main(){
	vector<VaccinationRecord> vaccinations;
	vaccinations.emplace_back("ID001",3);
	vaccinations.emplace_back("ID002",2);
	vaccinations.emplace_back("ID003",1);
	vaccinations.emplace_back("ID004",5);
	vaccinations.emplace_back("ID005",4);

	cout << "Sum: " << findSum(vaccinations) << endl;
	cout << "Min: " << findMinInFirstHalf(vaccinations) << endl;
	cout << "Max: " << findMaxInSecondHalf(vaccinations) << endl;

	return 0;
}
