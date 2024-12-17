#include <iostream>

using namespace std;

class Test{
    private:
        int a,b;
    public:
        Test(int, int);
        int get_a();
        int get_b();
};

Test::Test(int a, int b) : a(a), b(b) {}

int Test::get_a(){
    return a;
}

int Test::get_b(){
    return b;
}

ostream& operator<<(ostream& out, Test obj){
    out << "obj(" << obj.get_a() << "," << obj.get_b() << ")";
    return out;
}

int main(){
    Test obj1(1, 4);
    Test obj2(2, 8);
    cout << obj1 << endl << obj2;
    return 0;
}