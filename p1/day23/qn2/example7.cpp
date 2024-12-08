#include <iostream>

using namespace std;

class Animal{
    private:
        string species;

    public:
        void eat(){
            cout << "Animal eats" << endl;
        }
        Animal(){
            cout << "Animal constructor called" << endl;
        }
        virtual ~Animal(){
            cout << "Animal destructor called" << endl;
        }
};

class Bird : public Animal{
    private:
        string wingSpan;

    public:
        void fly(){
            cout << "Bird flys" << endl;
        }
        Bird(){
            cout << "Bird constructor called" << endl;
        }
        ~Bird(){
            cout << "Bird destructor called" << endl;
        }
};

int main(){
    Animal object1;
    object1.eat();
    cout << endl;

    Bird object2;
    object2.eat();
    object2.fly();
    cout << endl;


    Animal* object3 = new Animal;
    object3 -> eat();
    cout << endl;


    Animal* object4 = new Bird;
    object4 -> eat();
    cout << endl;

    delete object3;
    cout << endl;
    delete object4;
    cout << endl;
    
}