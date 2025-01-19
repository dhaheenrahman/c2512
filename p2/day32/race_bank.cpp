#include <iostream>
#include <thread>

using namespace std;

class BankAccount{
    private:
        int balance;
    
    public:
        void deposit(int amount){
            balance += amount;
        }

        int getBalance(){
            return balance;
        }
};

void makeDeposit(BankAccount& account){
    for (int i = 0; i < 1000; i++){
        account.deposit(1);
    }

}

int main(){
    BankAccount account;
    thread thrOne(makeDeposit, ref(account));
    thread thrTwo(makeDeposit, ref(account));
    thrOne.join();
    thrTwo.join();
    cout << "Final balance: " << account.getBalance() << endl;
    return 0;
}