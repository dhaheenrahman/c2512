// swap two numbers

#include <iostream>
using namespace std;

void swapNums(int &number1,int &number2){
    int temp = number1;
    number1 = number2;
    number2 = temp;
}

void swapNumsTest(){
    int number1,number2;
    cout<<"Enter number 1: ";
    cin>>number1;
    cout<<"Enter number 2: ";
    cin>>number2;
    swapNums(number1,number2);
    cout<<"New Num1: "<<number1;
    cout<<"\nNew Num2: "<<number2;
    
}

int main()
{
    
    swapNumsTest();
    return 0;
}