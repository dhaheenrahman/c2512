#include <iostream>
using namespace std;

class Fraction{
        private:
                int numerator;
                int denominator;
        
        public:
                Fraction();
                Fraction(int a, int b);
                
                void add(Fraction &other);
                void display();
                void reduceFraction();
}

int main() {
// Create two fraction objects
Fraction f1(1, 2); // Represents 1/2
Fraction f2(2, 3); // Represents 2/3

// Add two fractions
Fraction result = f1.Add(f2);
cout << "Sum of two fractions: ";
result.display(); // Expected output: 7/6 (in reduced form)

// Create a third fraction
Fraction f3(3, 4); // Represents 3/4

// Add three fractions
Fraction result2 = f1.Add(f2.Add(f3));
cout << "Sum of three fractions: ";
result2.display(); // Expected output: 23/12 (in reduced form)

return 0;
}

Fraction::Fraction(int a, int b){
        if(b == 0){
                cout << "Invalid fraction!\nProgram Terminated!";
                return;                        // verify
        }

        numerator = a;
        denominator = b;
}
Fraction::Fraction(){
        numerator = 0;
        denominator = 1;
}

void Fraction::add(Fraction &other){
        int numerator = ((a * other.b) + (b * other.a));
        int denominator = (b * other.b);
        Fraction sum(numerator, denominator);
        return sum;
}

void Fraction::reduceFraction(){
        int smaller = (numerator < denominator) ? numerator : denominator;
        
        for(int i = smaller; i >= 1; i--){
                if(numerator % i ==0 && denominator % i == 0){
                        numerator /= i;
                        denominator /= i;
                }
        }
}

void Fraction::display(){
        reduceFraction();
        cout << numerator << "/" << denominator;
}