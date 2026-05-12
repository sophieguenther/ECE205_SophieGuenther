//define a class for operating on a complex numbers named Complex. represent a complex number as 2 values of type double. name the member variables re and im to represent the real and imaginary parts of the complex number. include a constructor to initialize the member variables, and member functions to perform addition, subtraction, and division of complex numbers. also include a member function to display the complex number in the form "a + bi" or "a - bi". in the main function, create two complex numbers, perform the operations, and display the results.

#include <iostream>
using namespace std;

class Complex {
private:
    double re;
    double im;

public:
    // Constructor
    Complex(double r = 0, double i = 0) {
        re = r;
        im = i;
    }

    // Addition function
    Complex calculateMagnitude(Complex num) {
        return sqrt(num.re * num.re + num.im * num.im);
    }
    Complex add(Complex other) {
        return Complex(re + other.re, im + other.im);
    }

    // Subtraction function
    Complex subtract(Complex other) {
        return Complex(re - other.re, im - other.im);
    }
    //multiplication function
    Complex multiply(Complex other) {
        double newReal = re * other.re - im * other.im;
        double newImag = re * other.im + im * other.re;
        return Complex(newReal, newImag);
    }
    // Division function
    Complex divide(Complex other) {
        double denominator =
            (other.re * other.re) + (other.im * other.im);

        double newReal =
            (re * other.re + im * other.im) / denominator;

        double newImag =
            (im * other.re - re * other.im) / denominator;

        return Complex(newReal, newImag);
    }

    // Display function
    void display() {
        if (im >= 0)
            cout << re << " + " << im << "i" << endl;
        else
            cout << re << " - " << -im << "i" << endl;
    }
};

int main() {
    Complex num1(3, 4);
    Complex num2(0, 0);

    cout << "First Number: ";
    num1.display();

    cout << "Second Number: ";
    num2.display();

    Complex sum = num1.add(num2);
    cout << "\nAddition: ";
    sum.display();

    Complex difference = num1.subtract(num2);
    cout << "Subtraction: ";
    difference.display();

    Complex quotient = num1.divide(num2);
    cout << "Division: ";
    quotient.display();
    
    Complex product = num1.multiply(num2);
    cout << "Multiplication: ";
    product.display();

    Complex magnitude1 = num1.calculateMagnitude(num1);
    Complex magnitude2 = num2.calculateMagnitude(num2);
    cout << "Magnitude of First Number: " <<endl;
    magnitude1.display();
    cout << "Magnitude of Second Number: " << endl;
    magnitude2.display();
    return 0;
}