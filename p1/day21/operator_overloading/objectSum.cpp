#include <iostream>

using namespace std;

class Test{
    // friend int main();
    private:
        int num;
    
    public:
        Test operator+(Test);
        Test(int);
        int get_num();
};

int main(){
    Test obj1(5);
    Test obj2(10);
    Test sum = obj1 + obj2; 
    cout << sum.get_num();
}

Test::Test(int num) : num (num) {}

Test Test::operator+(Test other){
    return num + other.num;
}

int Test::get_num(){
    return num;
}
