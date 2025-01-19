#include <iostream>

int main(){
    int sum {0};
    int numbers[] = {3,1,2,5,4};

    for(auto num : numbers){
        sum += num;
    }

    std::cout << "Sum: " << sum << std::endl;
}