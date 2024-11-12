#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, c;
    cout << "Enter coefficients a, b, and c for quadratic equation ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;
    if (a == 0) {
        cout << "Coefficient of X^2 not zero" << endl;
    } 
    else {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots are real and distinct: " << root1 << ", " << root2 << endl;
        } 
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "Roots are real and equal: " << root << endl;
        } 
        else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            cout << "Roots are complex: " << realPart << " ± " << imaginaryPart << "i" << endl;
        }
    }
    return 0;
}

