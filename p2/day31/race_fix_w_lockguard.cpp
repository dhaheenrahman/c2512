#include <iostream>
#include <thread>
#include <mutex>

int count = 0;
std::mutex mt;

void counter(){
    
    for(int i = 0; i < 100000; i++){ 
        std::lock_guard<std::mutex> lock(mt);
        {
            count++;    
        }
        
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
