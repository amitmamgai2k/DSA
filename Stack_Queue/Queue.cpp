
#include<iostream>
using namespace std;

const int MAX_SIZE = 30;  // Fixed maximum size of the queue
int Queue[MAX_SIZE];      
int front = -1;
int rear = -1;
int MAX;  

void Display() {
    if (front == -1 ) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    for (int i = front; i <= rear; i++) {
        cout << Queue[i] << " ";
    }
    cout << endl;
}

void Enqueue() {
    if (rear >= MAX - 1) {
        cout << "Queue is Overflow" << endl;
        return;
    }

    int value;
    cout << "Enter Your Value to Insert: ";
    cin >> value;

    if (front == -1) {
        front = 0;  // Set front to 0 for the first elements
    }

    rear++;
    Queue[rear] = value;  

    cout << "Element Successfully Enqueued" << endl;
    Display();
}

int Dequeue() {
    if (front == -1 ) {
        cout << "Queue is Underflow" << endl;
        return -1;
    }

    cout << Queue[front] << " Element successfully dequeued from Queue" << endl;
    front++;

    // If the queue becomes empty after dequeue
    if (front > rear) {
        front = -1;
        rear = -1;
    }

    Display();
    return 1;
}

int main() {
    int choice;

    cout << "Enter the size of the Queue (MAX 30): ";
    cin >> MAX;

    if (MAX > MAX_SIZE) {
        cout << "Queue Size should be less than or equal to 30" << endl;
        return -1;
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
