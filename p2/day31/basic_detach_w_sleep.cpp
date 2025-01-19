#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void first(){

    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;

}

void second(){
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "4" << endl;
    cout << "5" << endl;
    cout << "6" << endl;

}

void third(){
    cout << "7" << endl;
    cout << "8" << endl;
    cout << "9" << endl;
}

int main(){
    thread threadOne(first);
    thread threadTwo(second);
    threadOne.detach();
    threadTwo.detach();
    this_thread::sleep_for(chrono::milliseconds(2000));
    third();
}