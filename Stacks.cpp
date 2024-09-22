#include <iostream>
using namespace std;

class Stack {
    int size;
    int* arr;
    int top;
public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr; // Free allocated memory
    }

    void push(int data) {
        if (top < size - 1) {
            top++;
            arr[top] = data;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // or throw an exception
        }
    }
}
int main() {


    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(50);
    cout << "Top of stack: " << st.peek() << endl; // Output: 50
    st.pop();
    cout << "Top after pop: " << st.peek() << endl; // Output: 43

    return 0;
}
