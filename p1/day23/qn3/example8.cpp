/* single inheritance with dynamic binding
=============================================================
one dynamic/static objects of the Derived class 
pointed by base class pointer
and call all behaviours using Base class pointer 

Override Base Class behaviors to derived class.
Define constructors and destructors for all the classes 
Define all the fields as dynamic fields in each class */

#include <iostream>

using namespace std;

class Plant{
    private:
        int* height = new int {};
        char* type = new char[50] {};
    
    public:
        virtual void photosynthesize() = 0;     //pure virtual function
        virtual void grow() = 0;                //pure virtual function

        Plant(){
            cout << "Plant constructor called" << endl;
        }
        virtual ~Plant(){
            cout << "Plant destructor called" << endl;  //set as virtual to call derived class destructor
            delete height;
            height = nullptr;
            delete type;
            type = nullptr;
        }
};

class FloweringPlant : public Plant{
    private:
        char* flowerColor = new char[50] {};
        char* bloomSeason = new char[50] {};
    
    public:
        void photosynthesize() override{
            cout << "FlowringPlant photosynthesize" << endl;
        }
        void grow() override{
            cout << "FloweringPlant grows" << endl;
        }

        FloweringPlant(){
            cout << "FloweringPlant constructor called" << endl;
        }
        ~FloweringPlant(){
            cout << "FloweringPlant destructor called" << endl;
            delete flowerColor;
            flowerColor = nullptr;
            delete bloomSeason;
            bloomSeason = nullptr;
        }
};

int main(){
    FloweringPlant derivedObj;              //static object derivedObj of Derived Class
    Plant* parentPtr1 = &derivedObj;        //Base class pointer parentPtr1 to derivedObj
    parentPtr1 ->photosynthesize();         //derivedObj behaviours called using parentPtr1
    parentPtr1 -> grow();                   
    cout << endl;
    
    Plant* parentPtr2 = new FloweringPlant; //Base class pointer parentPtr2 to dynamic object of Derived Class
    parentPtr2 ->photosynthesize();         //Derived class behaviours called using parentPtr2
    parentPtr2 -> grow();
    cout << endl;

    delete parentPtr2;                      //deleted dynamic object
    parentPtr2 = nullptr;
    cout << endl;

    return 0;
}

