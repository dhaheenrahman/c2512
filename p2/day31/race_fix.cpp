#include <iostream>
#include <thread>

int count1 = 0;
int count2 = 0;

void counter1(){
    for(int i = 0; i < 100000; i++){ 
        count1++;
    }
}

void counter2(){
    for(int i = 0; i < 100000; i++){ 
        count2++;
    }
}

int main(){
    std::thread thr1(counter1);
    std::thread thr2(counter2);
    thr1.join();
    thr2.join();
    
    std::cout << (count1 + count2) << std::endl; 
    return 0;
}
