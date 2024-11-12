#include <iostream>
#include <string>
using namespace std;
int main() {
  double side1, side2, side3;
  cout << "\nEnter sides of the triangle: ";
  cin >> side1 >> side2 >> side3;
  if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
    cout << "Invalid: All sides must be greater than zero." << endl;
  }
  else if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2) {
    cout << "Invalid: The sum of any two sides must be greater than the third side." << endl;
  }
  else if (side1 == side2 && side2 == side3) {
    cout << "Triangle type is: Equilateral" << endl;
  }
  else if (side1 == side2 || side2 == side3 || side1 == side3) {
    cout << "Triangle type is: Isosceles" << endl;
  }
  else {
    cout << "Triangle type is: Scalene" << endl;
  }
  return 0;
}

