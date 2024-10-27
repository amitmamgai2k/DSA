#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

const int MAX_SIZE = 30;  
int Queue[MAX_SIZE];      
int front = -1;
int rear = -1; 
int Size;  
// Front and rear pointers for the linked list queue
Node* frontList = nullptr;
Node* rearList = nullptr;

void displayArrayQueue() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    int i = front;
    while (true) {
        cout << Queue[i] << " ";
        if (i == rear) break; 
        i = (i + 1) % Size;   
    }
    cout << endl;
}

void displayLinkedListQueue() {
    if (frontList == nullptr) {
        cout << "Linked list queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    Node* temp = frontList;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != frontList);
    cout << endl;
}

void EnqueueArray() {
    if ((rear + 1) % Size == front) {
        cout << "Queue is full" << endl;
        return;
    }
    int value;
    cout << "Enter the value to Enqueue: ";
    cin >> value;

    if (front == -1) {
        front = 0;  // Set front to 0 when the first element is added
    }
    rear = (rear + 1) % Size;
    Queue[rear] = value;
    cout << value << " successfully Enqueued in Array Queue" << endl;
    displayArrayQueue();
}


void DequeueArray() {
    if (front == -1) {
        cout << "Queue is empty, nothing to Dequeue" << endl;
        return;
    }
    int value = Queue[front];
    if (front == rear) {  
        front = rear = -1;
    } else {
        front = (front + 1) % Size;
    }
    cout << value << " successfully Dequeued from Array Queue" << endl;
    displayArrayQueue();
}


void EnqueueLinkedList() {
    int value;
    cout << "Enter the value to Enqueue: ";
    cin >> value;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;

    if (frontList == nullptr) {
        frontList = rearList = newNode;
        newNode->next = frontList;  
    } else {
        rearList->next = newNode;
        newNode->next = frontList;
        rearList = newNode;
    }
    cout << value << " successfully Enqueued in Linked List Queue" << endl;
    displayLinkedListQueue();
}

void DequeueLinkedList() {
    if (frontList == nullptr) {
        cout << "Queue is empty, nothing to Dequeue" << endl;
        return;
    }
    int value = frontList->data;
    if (frontList == rearList) { 
        free(frontList);
        frontList = rearList = nullptr;
    } else {
        Node* temp = frontList;
        frontList = frontList->next;
        rearList->next = frontList;
        free(temp);
    }
    cout << value << " successfully Dequeued from Linked List Queue" << endl;
    displayLinkedListQueue();
}

int main() {
    int choice, queueType;

    cout << "Choose the type of Queue:\n";
    cout << "1.Circular Queue using Array\n";
    cout << "2.Circular Queue using Linked List\n";
    cout << "Enter your choice: ";
    cin >> queueType;

    if (queueType == 1) {
        cout << "Enter the size of the Array Queue (MAX 30): ";
        cin >> Size;

        if (Size <= 0 || Size > MAX_SIZE) {
            cout << "Queue Size should be greater than 0 and less than or equal to 30" << endl;
            return -1;
        }
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
                if (queueType == 1) {
                    EnqueueArray();
                } else {
                    EnqueueLinkedList();
                }
                break;
            case 2:
                if (queueType == 1) {
                    DequeueArray();
                } else {
                    DequeueLinkedList();
                }
                break;
            case 3:
                if (queueType == 1) {
                    displayArrayQueue();
                } else {
                    displayLinkedListQueue();
                }
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
