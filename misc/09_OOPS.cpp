#include <iostream>
using namespace std;

class Base {
public:
    // Overloaded method (same method name, different parameter types)
    void show() {
        cout << "Base class show() with no arguments" << endl;
    }

    void show(int x) {
        cout << "Base class show() with integer argument: " << x << endl;
    }

    // Virtual function to demonstrate method overriding
    virtual void display() {
        cout << "Base class display()" << endl;
    }
};

class Derived : public Base {
public:
    // Overriding the base class display method
    void display() override {
        cout << "Derived class display()" << endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    // Demonstrating method overloading
    baseObj.show();
    baseObj.show(10);

    // Demonstrating method overriding
    baseObj.display();        // Calls Base class display()
    derivedObj.display();     // Calls Derived class display()

    // Using a base class pointer to demonstrate polymorphism with overriding
    Base* ptr = &derivedObj;
    ptr->display();           // Calls Derived class display() due to virtual function

    return 0;
}
