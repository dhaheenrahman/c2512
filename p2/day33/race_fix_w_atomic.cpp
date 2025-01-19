#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> count = 0;

void counter(){
    
    for(int i = 0; i < 100000; i++){ 
        count.fetch_add(1);
        // count ++;    // this will also works
        //count.store(count.load() + 1)  // this will not work since it performs two instructions which may lead to race when other thread perform it simultaneously 
    }
    
 
}

int main(){
    std::thread thr1(counter);
    std::thread thr2(counter);
    thr1.join();
    thr2.join();
    
    std::cout << count << std::endl; 
    return 0;
}
