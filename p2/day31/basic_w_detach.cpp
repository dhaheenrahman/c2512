#include <iostream>
#include <thread>

void printHi(){
    std::cout << "Hi" << std::endl;
}

void printHello(){
    std::cout << "Hello" << std::endl;
}

int main(){
    std::thread thr1(printHi);
    std::thread thr2(printHello);
    thr1.detach();
    thr2.detach();
    std::cout << "Hello world!" << std::endl;
    return 0;
}