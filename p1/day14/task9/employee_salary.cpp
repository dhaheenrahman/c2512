#include <iostream>
#include <climits>
#define MAX_SIZE 10

using std::cout;
using std::cin;

void inputSalaries(int salaries[], int size){
	for(int i = 0; i < size; i++){
		cout << "Enter salary for employee " << (i + 1) <<": ";
		cin >> salaries[i];
	}
}

int findSecondHighestSalary(int salaries[], int size){
	int firstHighestSalary = INT_MIN;
	int secondHighestSalary = INT_MIN;

	for(int i = 0; i < MAX_SIZE; i++){
		if(salaries[i] > firstHighestSalary){
			secondHighestSalary = firstHighestSalary;
			firstHighestSalary = salaries[i];
		}
		else if((salaries[i] > secondHighestSalary) && (salaries[i] < firstHighestSalary)){
			secondHighestSalary = salaries[i];
		}
	}

	return secondHighestSalary;
}

bool isFiveDigits(int salary){
	if((salary >= 10000) && (salary <= 99999)){
		return true;
	}

	return false;
}

void printSalaries(int salaries[], int size){
	for(int i = 0; i < size; i++){
		cout << "Salary " << (i + 1) << ": " << salaries[i]<<"\n";
	}
}

int main(){
	int salaries[MAX_SIZE];

	inputSalaries(salaries, MAX_SIZE);
	
	int secondHighestSalary = findSecondHighestSalary(salaries, MAX_SIZE);

	cout << "\nSecond Highest Salary: " << secondHighestSalary << "\n\n";

	isFiveDigits(secondHighestSalary) ? cout << "Second highest salary is 5-digits\n\n" : cout << "Second highest salary is not 5-digits\n\n";
	
	printSalaries(salaries, MAX_SIZE);
	
	return 0;	
}
