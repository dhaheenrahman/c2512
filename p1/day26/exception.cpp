#include <iostream>
using namespace std;


int main(){
    int num1, num2;
    cout << "Enter 2 numbers: " << endl; cin >> num1; cin >> num2;
    try{
        cout << "Quotient: " << num1 / num2 << endl;
    }
    catch(exception e){
        cout << e.what() << endl; 
    }
    cout << "Reached end" << endl;
    return 0;
}

