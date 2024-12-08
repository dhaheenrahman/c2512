#include <iostream>

using namespace std;

class Plant{
    private:
        int* height = new int {};
        char* type = new char[50];
    
    public:
        virtual void photosynthesize() = 0;
        virtual void grow() = 0;

        Plant(){
            cout << "Plant constructor called" << endl;
        }
        virtual ~Plant(){
            cout << "Plant destructor called" << endl;
            delete height;
            height = nullptr;
            delete type;
            type = nullptr;
        }
};

class FloweringPlant : public Plant{
    private:
        char* flowerColor = new char[50];
        char* bloomSeason = new char[50];
    
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
    FloweringPlant derivedObj;
    Plant* parentPtr1 = &derivedObj;
    parentPtr1 -> photosynthesize();
    parentPtr1 -> grow();
    cout << endl;
    
    Plant* parentPtr2 = new FloweringPlant;
    parentPtr2 ->photosynthesize();
    parentPtr2 -> grow();
    delete parentPtr2;
    cout << endl;


    return 0;
}

