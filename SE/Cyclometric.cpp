#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// Function to count the decision points in the given code
int countDecisionPoints(const string& code) {
    int decisionPoints = 0;
    stringstream ss(code);
    string line;
    // Count the decision points like 'if', 'for', 'while', 'switch', 'case'
    while (getline(ss, line)) {
        if (line.find("if") != string::npos) {
            decisionPoints++; // Found an 'if' statement
        }
        if (line.find("for") != string::npos) {
            decisionPoints++; // Found a 'for' loop
        }
        if (line.find("while") != string::npos) {
            decisionPoints++; // Found a 'while' loop
        }
        if (line.find("switch") != string::npos) {
            decisionPoints++; // Found a 'switch' statement
        }
        if (line.find("case") != string::npos) {
            decisionPoints++; // Found a 'case' statement
        }
    }
    return decisionPoints;
}
// Function to calculate Cyclomatic Complexity
int calculateCyclomaticComplexity(const string& code) {
    int decisionPoints = countDecisionPoints(code);
    // Cyclomatic Complexity Formula: V(G) = D + 1
    // Where D is the number of decision points
    int V = decisionPoints + 1; // For a single program, P = 1
    return V;
}
int main() {
    // Example Paigaam Project Code snippet (simplified version)
    string code = R"(
        #include <iostream>
        using namespace std;
        int main() {
            int a = 5, b = 10;
            // Decision point 1: if statement
            if (a > b) {
                cout << "a is greater than b";
            } else {
                cout << "a is not greater than b";
            }
            // Decision point 2: for loop
            for (int i = 0; i < 5; i++) {
                cout << i;
            }
            // Decision point 3: while loop
            while (a < b) {
                a++;
            }
            // Decision point 4: switch case
            switch (a) {
                case 1:
                    cout << "One";
                    break;
                case 2:
                    cout << "Two";
                    break;
                default:
                    cout << "Default case";
            }
            return 0;
        }
    )";
    // Calculate Cyclomatic Complexity for the code
    int cyclomaticComplexity = calculateCyclomaticComplexity(code);
    // Output the result
    cout << "Cyclomatic Complexity of the program: " << cyclomaticComplexity << endl;
    return 0;
}
