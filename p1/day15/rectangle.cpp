#include<iostream>
using namespace std;

class Rectangle{
	public:
	// members
		int length;
		int breadth;
	//functions
		int findArea();
		void print();
	//constructor
		Rectangle(int length, int breadth);
};

int main(){
	Rectangle rectangle1(300,400);
	Rectangle rectangle2(200,700);
	rectangle1.print();
	cout << "Area = " << rectangle1.findArea() << "\n";
	rectangle2.print();
	cout << "Area = " << rectangle2.findArea() << "\n";
}

int Rectangle::findArea(){
	return length * breadth;
}

Rectangle::Rectangle(int p_length, int p_breadth){
	length = p_length;
	breadth = p_breadth;
}

void Rectangle::print(){
	cout << "[length = " << length << ", breadth = " << breadth << "]\n";
}
