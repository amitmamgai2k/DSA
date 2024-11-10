#include <iostream>
#include <cmath>
using namespace std;
// Function to calculate EAF by multiplying ratings of all 15 cost drivers
double calculateEAF() {
    double costDriverRatings[15] = {
        1.15, 1.00, 1.00, // Product Attributes
        1.00, 1.00, 1.00, 1.00, // Hardware Attributes
        1.00, 0.91, 0.86,1.00,0.95, // Personal Attributes
        1.00, 0.91, 1.00, // Project Attributes
    
    };
    double EAF = 1.0; // Initialize EAF to 1
    // Multiply all cost driver ratings to calculate EAF
    for (int i = 0; i < 15; i++) {
        EAF *= costDriverRatings[i];
    }
    return EAF;
}
// Function to calculate COCOMO effort, development time, and other parameters
void calculateCOCOMO(double KLOC, string projectType) {
    double a, b, c, d;
    // Assign values for COCOMO constants based on project type
    if (projectType == "organic") {
        a = 3.2; b = 1.05; c = 2.5; d = 0.38;
    } else if (projectType == "semi-detached") {
        a = 3.0; b = 1.12; c = 2.5; d = 0.35;
    } else if (projectType == "embedded") {
        a = 2.8; b = 1.20; c = 2.5; d = 0.32;
    } else {
        cout << "Invalid project type!" << endl;
        return;
    }
    // Calculate Effort Adjustment Factor (EAF) based on cost driver ratings
    double EAF = calculateEAF(); 
    // Calculate Effort (E) and Development Time (D),Staff size, produtivity
    double E = a * pow(KLOC, b) * EAF; // Effort in person-months
    double D = c * pow(E, d); // Development time in months
    double SS = E / D; // Staff size
    double P = KLOC / E; // Productivity
    // Output 
    cout << "Estimated Effort (E): " << E << " person-months" << endl;
    cout << "Estimated Development Time (D): " << D << " months" << endl;
    cout << "Average Staff Size (SS): " << SS << " persons" << endl;
    cout << "Productivity (P): " << P << " KLOC/PM" << endl;
}
int main() {
    double KLOC = 31.779; // Example KLOC for your project
    string projectType;
    cout << "Enter the project type (organic, semi-detached, embedded): ";
    cin >> projectType;
    calculateCOCOMO(KLOC, projectType);
    return 0;
}
