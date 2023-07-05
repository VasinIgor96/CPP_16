#include <iostream>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void simplifyFraction(Fraction& fraction) {
    int commonDivisor = gcd(fraction.numerator, fraction.denominator);
    fraction.numerator /= commonDivisor;
    fraction.denominator /= commonDivisor;
}

void convertToProperFraction(Fraction& fraction) {
    if (fraction.numerator >= fraction.denominator) {
        int wholePart = fraction.numerator / fraction.denominator;
        fraction.numerator %= fraction.denominator;
        fraction.numerator += wholePart * fraction.denominator;
    }
}

Fraction addFractions(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
    result.denominator = fraction1.denominator * fraction2.denominator;
    simplifyFraction(result);
    convertToProperFraction(result);
    return result;
}

Fraction subtractFractions(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
    result.denominator = fraction1.denominator * fraction2.denominator;
    simplifyFraction(result);
    convertToProperFraction(result);
    return result;
}

Fraction multiplyFractions(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.numerator;
    result.denominator = fraction1.denominator * fraction2.denominator;
    simplifyFraction(result);
    convertToProperFraction(result);
    return result;
}

Fraction divideFractions(const Fraction& fraction1, const Fraction& fraction2) {
    Fraction result;
    result.numerator = fraction1.numerator * fraction2.denominator;
    result.denominator = fraction1.denominator * fraction2.numerator;
    simplifyFraction(result);
    convertToProperFraction(result);
    return result;
}


void displayFraction(const Fraction& fraction) {
    cout << fraction.numerator << "/" << fraction.denominator << endl;
}

int main() {
    Fraction fraction1, fraction2;


    cout << "Enter the first fraction:" << endl;
    cout << "Numerator: ";
    cin >> fraction1.numerator;
    cout << "Denominator: ";
    cin >> fraction1.denominator;


    cout << "Enter the second fraction:" << endl;
    cout << "Numerator: ";
    cin >> fraction2.numerator;
    cout << "Denominator: ";
    cin >> fraction2.denominator;

    Fraction sum = addFractions(fraction1, fraction2);
    Fraction difference = subtractFractions(fraction1, fraction2);
    Fraction product = multiplyFractions(fraction1, fraction2);
    Fraction quotient = divideFractions(fraction1, fraction2);

    cout << "Sum: ";
    displayFraction(sum);

    cout << "Difference: ";
    displayFraction(difference);

    cout << "Product: ";
    displayFraction(product);

    cout << "Quotient: ";
    displayFraction(quotient);

    return 0;
}
