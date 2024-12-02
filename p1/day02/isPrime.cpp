#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int number){
    if(number < 2)
        return false;  
    for(int divisor = 2; divisor <= (int)sqrt(number); divisor++){
        if(number % divisor == 0)
            return false;
    }
    return true;
}

void isPrimeTest(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int result = isPrime(num);
    if(result)
        cout << num << " is prime";
    else 
        cout << num << " isn't prime"; 
}

int main(){
    isPrimeTest();
    return 0;
}
