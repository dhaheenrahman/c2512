#include<iostream>

#include "Rectangle.h"

using std::cout;

int main(){
	Rectangle rectangle1(300,400);
	Rectangle rectangle2(200,700);
	rectangle1.print();
	cout << "Area = " << rectangle1.findArea() << "\n";
	rectangle2.print();
	cout << "Area = " << rectangle2.findArea() << "\n";
}
