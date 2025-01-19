#include <iostream>
#include <thread>
#include <future>

using namespace std;

void findSum(double a, double b, promise<double> result){
    double sum = 0;
    for (double i = 1; i <= 100000000; i++){
        sum += i;
    }
    result.set_value(sum);
}

int main(){
    promise<double> result;
    future fut = result.get_future();
    thread thrFindSum(findSum, 3, 7, move(result));
    thrFindSum.join();
    // thrFindSum.detach(); // detach also works since the fut.get() will block main thread until promise is fulfilled
    cout << fut.get();
    return 0;
}