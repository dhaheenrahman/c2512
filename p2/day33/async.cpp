#include <iostream>
#include <thread>
#include <future>

using namespace std;

double findSum(){
    double sum = 0;

    for (double i = 1; i <= 100000000; i++){
        sum += i;
    }

    return sum;
}

int main(){
    future result = async(launch::async, findSum);  // launch::deferred will not create a seperate thread.
    cout << result.get();
    return 0;
}

// here async will return a future object whose value will be the return value of the thread
// by default the first argument of async() is (launch::async | launch::deferred)