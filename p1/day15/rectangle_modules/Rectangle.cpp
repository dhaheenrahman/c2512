#include <iostream>
#include "Rectangle.h"

using std::cout;

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
