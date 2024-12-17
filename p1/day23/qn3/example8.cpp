/* single inheritance with dynamic binding
=============================================================
one dynamic/static objects of the Derived class 
pointed by base class pointer
and call all behaviours using Base class pointer 

Override Base Class behaviors to derived class.
Define constructors and destructors for all the classes 
Define all the fields as dynamic fields in each class */

#include <iostream>
#include <cstring>
// #include <string>
using namespace std;

class Plant{
    protected:
        int* height;
        char* type;
    
    public:
        virtual void photosynthesize() = 0;     //pure virtual function
        virtual void grow() = 0;                //pure virtual function

        Plant(int height,const char* type){
            this -> height = new int{height};
            this -> type = new char[strlen(type) + 1];
            strcpy(this -> type, type);
            cout << "Plant constructor called for " << type << endl;
        }
        virtual ~Plant(){
            cout << "Plant destructor called for " << type << endl;  //set as virtual to call derived class destructor
            delete height;
            height = nullptr;
            delete[] type;
            type = nullptr;
        }
};

class FloweringPlant : public Plant{
    private:
        char* flowerColor;
        char* bloomSeason;
    
    public:
        void photosynthesize() override{
            cout << "FlowringPlant photosynthesize for " << type << endl;
        }
        void grow() override{
            cout << "FloweringPlant grows for " << type << endl;
        }

        FloweringPlant(int height,const char* type, const char* flowerColor, const char* bloomSeason) : Plant(height, type) {
            this -> flowerColor = new char[strlen(flowerColor) + 1];
            strcpy(this -> flowerColor, flowerColor);
            this -> bloomSeason = new char[strlen(bloomSeason) + 1];
            strcpy(this -> bloomSeason, bloomSeason);
            cout << "FloweringPlant constructor called for " << type << endl;
        }
        ~FloweringPlant(){
            cout << "FloweringPlant destructor called for " << type << endl;
            delete[] flowerColor;
            flowerColor = nullptr;
            delete[] bloomSeason;
            bloomSeason = nullptr;
        }
};

int main(){
    FloweringPlant derivedObj(5, "Rose", "Red", "Spring");              //static object derivedObj of Derived Class
    Plant* parentPtr1 = &derivedObj;        //Base class pointer parentPtr1 to derivedObj
    parentPtr1 ->photosynthesize();         //derivedObj behaviours called using parentPtr1
    parentPtr1 -> grow();                   
    cout << endl;
    
    Plant* parentPtr2 = new FloweringPlant(7, "Sun Flower", "Yellow", "Monsoon"); //Base class pointer parentPtr2 to dynamic object of Derived Class
    parentPtr2 ->photosynthesize();         //Derived class behaviours called using parentPtr2
    parentPtr2 -> grow();
    cout << endl;

    delete parentPtr2;                      //deleted dynamic object
    parentPtr2 = nullptr;
    cout << endl;

    return 0;
}

