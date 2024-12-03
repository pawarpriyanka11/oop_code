//using friend function

#include <iostream>
using namespace std;

class complex {
public:
    int r, i;

    // Default constructor
    complex() {
        r = 0;
        i = 0;
    }

    // Parameterized constructor
    complex(int r1, int i1) {
        r = r1;
        i = i1;
    }

    // Display function
    void display() {
        cout << r;
        if (i >= 0)
            cout << "+" << i << "i";
        else
            cout << i << "i";
    }

    // Friend functions for operator overloading
    friend complex operator+(complex& c1, complex& c2);
    friend complex operator-(complex& c1, complex& c2);
    friend complex operator*(complex& c1, complex& c2);
    friend complex operator/(complex& c1, complex& c2);
};

// Overloading '+' operator using friend function
complex operator+(complex& c1, complex& c2) {
    return complex(c1.r + c2.r, c1.i + c2.i);
}

// Overloading '-' operator using friend function
complex operator-(complex& c1, complex& c2) {
    return complex(c1.r - c2.r, c1.i - c2.i);
}

// Overloading '*' operator using friend function
complex operator*(complex& c1, complex& c2) {
    int real = (c1.r * c2.r) - (c1.i * c2.i);
    int img = (c1.r * c2.i) + (c1.i * c2.r);
    return complex(real, img);
}

// Overloading '/' operator using friend function
complex operator/(complex& c1, complex& c2) {
    int denominator = (c2.r * c2.r) + (c2.i * c2.i);
    if (denominator == 0) {
        throw runtime_error("Division by zero is undefined!");
    }
    int real = (c1.r * c2.r + c1.i * c2.i) / denominator;
    int img = (c1.i * c2.r - c1.r * c2.i) / denominator;
    return complex(real, img);
}

int main() {
    // Input for the first complex number
    int r1, i1;
    cout << "Enter the real part of the first complex number: ";
    cin >> r1;
    cout << "Enter the imaginary part of the first complex number: ";
    cin >> i1;
    complex c1(r1, i1);

    // Input for the second complex number
    cout << "Enter the real part of the second complex number: ";
    cin >> r1;
    cout << "Enter the imaginary part of the second complex number: ";
    cin >> i1;
    complex c2(r1, i1);

    try {
        // Perform arithmetic operations
        complex sum = c1 + c2;
        complex sub = c1 - c2;
        complex mul = c1 * c2;
        complex div = c1 / c2;

        // Display results
        cout << "\nADDITION: ";
        sum.display();
        cout << "\nSUBTRACTION: ";
        sub.display();
        cout << "\nMULTIPLICATION: ";
        mul.display();
        cout << "\nDIVISION: ";
        div.display();
        cout << endl;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}

