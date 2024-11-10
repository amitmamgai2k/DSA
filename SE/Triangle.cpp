#include <iostream>
#include <string>
using namespace std;
// Function to determine the type of triangle
string findTriangleType(double side1, double side2, double side3) {
      if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return "Invalid: All sides must be greater than zero.";
    }
    // Check for triangle inequality validity
    if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2) {
        return "Invalid: The sum of any two sides must be greater than the third side.";
    }
    if (side1 == side2 && side2 == side3) {
        return "Equilateral";
    } else if (side1 == side2 || side2 == side3 || side1 == side3) {
        return "Isosceles";
    } else {
        return "Scalene";
    }
}
int main() {
    double side1, side2, side3;
    cout << "\nEnter sides of the triangle: ";
    cin >> side1 >> side2 >> side3;
    cout << "Triangle type is: " << findTriangleType(side1, side2, side3) << endl;
    return 0;
}
