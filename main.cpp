#include <iostream>
#include <windows.h>
using namespace std;

struct Complex {
    double real;
    double imaginary;
};

Complex addComplex(const Complex& num1, const Complex& num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

Complex subtractComplex(const Complex& num1, const Complex& num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}

Complex multiplyComplex(const Complex& num1, const Complex& num2) {
    Complex result;
    result.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    result.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return result;
}

Complex divideComplex(const Complex& num1, const Complex& num2) {
    Complex result;
    double denominator = num2.real * num2.real + num2.imaginary * num2.imaginary;
    result.real = (num1.real * num2.real + num1.imaginary * num2.imaginary) / denominator;
    result.imaginary = (num2.real * num1.imaginary - num1.real * num2.imaginary) / denominator;
    return result;
}

void displayComplex(const Complex& num) {
    std::cout << num.real << " + " << num.imaginary << "i" << std::endl;
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Complex num1, num2;

    cout << "Enter the first complex number:" << endl;
    cout << "The real part: ";
    cin >> num1.real;
    cout << "The imaginary part: ";
    cin >> num1.imaginary;

    cout << "\nEnter the second complex number:" << endl;
    cout << "The real part: ";
    cin >> num2.real;
    cout << "The imaginary part: ";
    cin >> num2.imaginary;

    Complex sum = addComplex(num1, num2);
    cout << "\nSum: ";
    displayComplex(sum);

    Complex difference = subtractComplex(num1, num2);
    cout << "Difference: ";
    displayComplex(difference);

    Complex product = multiplyComplex(num1, num2);
    cout << "Product: ";
    displayComplex(product);

    Complex quotient = divideComplex(num1, num2);
    cout << "Quotient: ";
    displayComplex(quotient);

    return 0;
}
