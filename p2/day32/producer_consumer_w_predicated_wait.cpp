#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>
#include <chrono>
#define MAX_SIZE 5

using namespace std;

mutex mt;
condition_variable cv;
queue<int> products;
int product_id;

void producer(){
    while(true){
        unique_lock lock(mt);
        cv.wait(lock, []() -> bool { return !(products.size() == MAX_SIZE);});
        product_id ++;
        products.push(product_id);
        cout << "produced product: " << product_id << endl;
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    
}

void consumer(){
    int product = 0;
    while(true){
        unique_lock lock(mt);
        cv.wait(lock, []() -> bool { return !(products.empty());});
        product = products.front();
        products.pop();
        cout << "consumed product: " << product << endl;
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(50));

    }
    
}

int main(){
    thread thrProducer(producer);
    thread thrConsumer(consumer);

    thrProducer.join();
    thrConsumer.join();
    return 0;
}