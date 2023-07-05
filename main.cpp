#include <iostream>

using namespace std;

struct Rectangle {
    double length;
    double width;
    double x;
    double y;
};

void moveRectangle(Rectangle& rectangle, double dx, double dy) {
    rectangle.x += dx;
    rectangle.y += dy;
}

void resizeRectangle(Rectangle& rectangle, double newLength, double newWidth) {
    rectangle.length = newLength;
    rectangle.width = newWidth;
}

void printRectangle(const Rectangle& rectangle) {
    cout << "Length: " << rectangle.length << endl;
    cout << "Width: " << rectangle.width << endl;
    cout << "Position (x, y): (" << rectangle.x << ", " << rectangle.y << ")" << endl;
}

int main() {

    Rectangle rectangle;
    rectangle.length = 5.0;
    rectangle.width = 3.0;
    rectangle.x = 0.0;
    rectangle.y = 0.0;

    cout << "Initial Rectangle:" << endl;
    printRectangle(rectangle);
    cout << endl;

    moveRectangle(rectangle, 2.0, 3.0);
    cout << "Rectangle after moving:" << endl;
    printRectangle(rectangle);
    cout << endl;

    resizeRectangle(rectangle, 8.0, 4.0);
    cout << "Rectangle after resizing:" << endl;
    printRectangle(rectangle);
    cout << endl;

    return 0;
}
