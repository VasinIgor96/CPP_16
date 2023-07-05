#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

double calculateDistance(const Point& point1, const Point& point2) {
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point point1, point2;

    cout << "Enter coordinates for Point 1:" << endl;
    cout << "x: ";
    cin >> point1.x;
    cout << "y: ";
    cin >> point1.y;

    cout << "Enter coordinates for Point 2:" << endl;
    cout << "x: ";
    cin >> point2.x;
    cout << "y: ";
    cin >> point2.y;

    double distance = calculateDistance(point1, point2);
    cout << "Distance between the two points: " << distance << endl;

    return 0;
}
