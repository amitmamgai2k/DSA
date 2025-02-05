#include <iostream>  // This is a comment (should NOT be counted)

using namespace std;

int main() {  // This line has code (should be counted)

    int a = 10;  // Code + comment (should be counted)

    // This is a full-line comment (should NOT be counted)

    int b = 20; /* Inline multi-line comment starts but
                   should still count this line */ int c = 30;

    /* This is a
       multi-line comment
       spanning multiple lines (should NOT be counted) */

    int d = 40; /* This is a multi-line comment */ int e = 50;

    /*
       Multi-line comment starts here (should NOT be counted)
       int f = 60;
    */


    cout << "Hello, world!";  // Print statement (should be counted)

    return 0;  // This line has code + comment (should be counted)
}
