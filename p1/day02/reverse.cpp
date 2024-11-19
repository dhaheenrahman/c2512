#include <iostream>
using namespace std;

int reverseNumber(int number){
    int reverse = 0;
    while(number > 0){
        int temp = number % 10;
        reverse = reverse * 10 + temp;
        number /= 10;
    }
    return reverse;
}

void reverseNumberTest(){
    int number;
    cout << "Enter your number: ";
    cin >> number;
    cout << "Reverse: " << reverseNumber(number);
}

int main()
{
    reverseNumberTest();

    return 0;
}
