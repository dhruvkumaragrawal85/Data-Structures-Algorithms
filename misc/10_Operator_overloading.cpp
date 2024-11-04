#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    // Constructor to initialize complex number
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator + (const Complex &obj) {
        Complex result;
        result.real = real + obj.real;
        result.imag = imag + obj.imag;
        return result;
    }

    // Function to display complex number
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex c3 = c1 + c2;  // Using overloaded + operator

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "c1 + c2 = "; c3.display();

    return 0;
}
