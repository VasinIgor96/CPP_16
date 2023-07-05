#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Car {
    double length;
    double groundClearance;
    double engineCapacity;
    double wheelDiameter;
    string color;
    string transmissionType;
};

void setCarValues(Car& car, double length, double groundClearance, double engineCapacity, double wheelDiameter, const string& color, const string& transmissionType) {
    car.length = length;
    car.groundClearance = groundClearance;
    car.engineCapacity = engineCapacity;
    car.wheelDiameter = wheelDiameter;
    car.color = color;
    car.transmissionType = transmissionType;
}

void displayCarValues(const Car& car) {
    cout << "Length: " << car.length << " meters" << endl;
    cout << "Ground Clearance: " << car.groundClearance << " cm" << endl;
    cout << "Engine Capacity: " << car.engineCapacity << " cc" << endl;
    cout << "Wheel Diameter: " << car.wheelDiameter << " inches" << endl;
    cout << "Color: " << car.color << endl;
    cout << "Transmission Type: " << car.transmissionType << endl;
}

void searchCarsByColor(const Car cars[], int numCars, const string& color) {
    cout << "Cars with color " << color << ":" << endl;
    bool found = false;

    for (int i = 0; i < numCars; i++) {
        if (cars[i].color == color) {
            displayCarValues(cars[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "No cars found with color " << color << endl;
    }
}

Car getCarInput() {
    Car car;
    cout << "Enter car details:" << endl;
    cout << "Length: ";
    cin >> car.length;
    cout << "Ground Clearance: ";
    cin >> car.groundClearance;
    cout << "Engine Capacity: ";
    cin >> car.engineCapacity;
    cout << "Wheel Diameter: ";
    cin >> car.wheelDiameter;
    cout << "Color: ";
    cin >> car.color;
    cout << "Transmission Type: ";
    cin >> car.transmissionType;
    return car;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int numCars = 3;
    Car cars[numCars];

    // Задання значень для кожного автомобіля
    for (int i = 0; i < numCars; i++) {
        cout << "Enter details for Car " << (i + 1) << ":" << endl;
        cars[i] = getCarInput();
        cout << endl;
    }

    // Відображення значень кожного автомобіля
    for (int i = 0; i < numCars; i++) {
        cout << "Car " << (i + 1) << ":" << endl;
        displayCarValues(cars[i]);
        cout << endl;
    }

    // Пошук автомобілів за коліром
    string searchColor;
    cout << "Enter color to search: ";
    cin >> searchColor;
    searchCarsByColor(cars, numCars, searchColor);

    return 0;
}

