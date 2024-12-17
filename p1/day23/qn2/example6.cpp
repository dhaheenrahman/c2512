/* single inheritance using static binding:
=============================================================
Create two static objects for Both Base and Derived class
and call all behaviours
and 
two dynamic objects for Base and Derived class 
and call all behaviours     

Define constructors and destructors for all the classes */

#include <iostream>

using namespace std;

class Account{
    private:
        string accountNumber;

    public:
        void deposit(){
            cout << "Account's deposit behaviour called" << endl;
        }
        Account(){
            cout << "Account constructor called" << endl;
        }
        virtual ~Account(){       //set as virtual to call derived class destructor
            cout << "Account destructor called" << endl;
        }
};

class SavingsAccount : public Account{
    private:
        int interestRate;

    public:
        void calculateInterest(){
            cout << "SavingsAccount's calculateInterests behaviour called" << endl;
        }
        SavingsAccount(){
            cout << "SavingsAccount constructor called" << endl;
        }
        ~SavingsAccount(){
            cout << "SavingsAccount destructor called" << endl;
        }
};

int main(){
    Account object1;                        //static object object1 for Base Class
    object1.deposit();                      //object1 behaviour called
    cout << endl;

    SavingsAccount object2;                 //static object object2 for Derived Class
    object2.deposit();                      //object2 behaviours called
    object2.calculateInterest();            //object2 behaviours called
    cout << endl;

    Account* object3 = new Account;         //dynamic object object3 for Base class
    object3 -> deposit();                   //object3 behaviour called
    cout << endl;

    SavingsAccount* object4 = new SavingsAccount;  //dynamic object object4 for Derived Class
    object4 -> deposit();                   //object4 behaviours called
    object4 -> calculateInterest();
    cout << endl;

    delete object3;                         //dynamic object object3 deleted
    object3 = nullptr;
    cout << endl;

    delete object4;                         //dynamic object object4 deleted
    object4 = nullptr;
    cout << endl;
    
}