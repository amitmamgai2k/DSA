#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countLines(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Unable to open file!" << endl;
        return -1;
    }

    int lineCount = 0;
    string line;
    bool inMultiLineComment = false;

    while (getline(file, line)) {
        bool hasCode = false;

        for (size_t i = 0; i < line.size(); i++) {
            if (inMultiLineComment) {
                if (line[i] == '*' && i + 1 < line.size() && line[i + 1] == '/') {
                    inMultiLineComment = false;
                    i++; // Skip '/'
                }
                continue;
            }

            if (line[i] == '/' && i + 1 < line.size()) {
                if (line[i + 1] == '/') break; // Ignore single-line comment
                if (line[i + 1] == '*') {
                    inMultiLineComment = true;
                    i++; // Skip '*'
                    continue;
                }
            }

            if (!isspace(line[i])) {
                hasCode = true; // Found actual code
            }
        }

        if (hasCode) lineCount++; // Count only if there's actual code
    }

    file.close();
    return lineCount;
}

int main() {
    string filename;
    cout << "Enter the name of the C++ file: ";
    cin >> filename;

    int lines = countLines(filename);
    if (lines != -1) {
        cout << "The file '" << filename << "' has " << lines << " lines of actual code." << endl;
    }

    return 0;
}
