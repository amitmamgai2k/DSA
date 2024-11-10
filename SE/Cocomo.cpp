#include <iostream>
#include <cmath>
using namespace std;

void calculateCOCOMO(double KLOC, string projectType) {
    double a, b, c, d;
    if (projectType == "organic") {
        a = 2.4; b = 1.05; c = 2.5; d = 0.38;
    } else if (projectType == "semi-detached") {
        a = 3.0; b = 1.12; c = 2.5; d = 0.35;
    } else if (projectType == "embedded") {
        a = 3.6; b = 1.20; c = 2.5; d = 0.32;
    } else {
        cout << "Invalid project type!" << endl;
        return;
    }
    // Calculate Effort (E) and Development Time (D)
    double E = a * pow(KLOC, b); // Effort in person-months
    double D = c * pow(E,d); // Development time in months
    double SS = E/D;// staff size
    double P = KLOC/E; //productivity

    cout << "Estimated Effort (E): " << E<< " person-months" << endl;
    cout << "Estimated Development Time (D): " << D << " months" << endl;
     cout << "Average Staff Size (SS): " << SS << " Persons" << endl;
      cout << "Productivity (P): " << P << " KLOC/PM" << endl;
}
int main() {
    double KLOC = 31.779; // Calculated earlier
    string projectType;
    cout << "Enter the project type (organic, semi-detached, embedded): ";
    cin >> projectType;
    calculateCOCOMO(KLOC, projectType);
    return 0;
}
