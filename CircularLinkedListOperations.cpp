#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

// Structure of our Node
struct Node {
    int data;
    Node *next;
};

// create CircularLink
Node*createCircularLinkedList(vector<int> arr) {
    if (arr.size() == 0) return NULL;
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = nullptr;
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = nullptr;
        mover->next = temp;
        mover = temp;
    }
    mover->next = head;
    return head;
}


// delete head of the Circular Linked List
Node *deleteHeadOfCircularLL(Node *head) {
    if (head == NULL) return NULL;
      if (head->next == head) {
        delete head; 
        return nullptr; 
    }
    Node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    Node*newHead = head->next;
    temp->next = newHead;
    delete head;
   return newHead;


    
}
// deleteTail

Node *deleteTailOfCircularLL(Node *head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    Node*tail = temp->next;
    temp->next = head;
    delete tail;
    return head;
}

Node* deleteAfterLocation(Node* head, int value) {
    if (head == NULL) {
        // Print error message if the list is empty
        cout << "List is empty!" << endl;
        return NULL;
    }

    Node* temp = head;

    // Find the node with the specified value
    do {
        if (temp->data == value) {
            break;
        }
        temp = temp->next;
    } while (temp != head);

    // If no node with the specified value was found
    if (temp->data != value) {
        cout << "Node with value " << value << " not found." << endl;
        return head;
    }

    // Check if there is a node to delete after the found node
    if (temp->next == head) {
        cout << "No node to delete after the node with value " << value << "." << endl;
        return head;
    }

    // Node to be deleted
    Node* nodeToDelete = temp->next;

    // Remove the node
    temp->next = nodeToDelete->next;

    // Free the memory
    delete nodeToDelete;

    return head;
}


// Insert at start

Node*InsertAtBeggining(Node*head,int value){
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = nullptr;
    if(head==NULL){
        head= temp;
        temp->next = head;
        return head;
    }
    Node*tail = head;
    while(tail->next!=head){
        tail  =  tail->next;

    }
    tail->next = temp;
    temp->next = head;
    head = temp;
    return head;

}

//Insert at end
Node*insertAtEnd(Node*head,int value){
    
     Node*NewNode = (Node*)malloc(sizeof(Node));
     NewNode->data = value;
     if(head ==NULL){
        
        NewNode->next = NewNode;
       return NewNode;
        
     }
    Node*temp = head;
     while(temp->next !=head){
        temp =temp->next;

     }
     
     temp->next = NewNode;
     NewNode->next= head;
     return head;

}

// Insert after position
Node*InsertAfterPosition(Node*head,int value,int pos){
    if(head==NULL){
        cout<<"List is empty.\n";
        return head;
    }
    Node*temp = head;
     while (temp != head && temp->data != pos) {
        temp = temp->next;
    }
     if (temp == head || temp->data!=pos) {
        cout << "Node with value " << pos << " not found or there is no node after it." << endl;
        return head;
    }
    Node*temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = value;
    temp1->next=  temp->next;
    temp->next = temp1;
    return head;



}



void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp= head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int choice, subchoice, k, n, value,pos;

    cout << "Enter the number of elements in the Linked List: ";
    cin >> n;
    if(n>=30 || n<0){
        cout<<"Linked List Size should be less than 30 and greater than or equal to one";
        return 1;
    }
    // Declare the vector with size n
    vector<int> arr(n);

    // Directly assign values to the vector
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    Node*head=  createCircularLinkedList(arr);

     do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Insert Menu
                cout << "\nInsert Menu:\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert after Position\n";
                cout << "Enter your choice: ";
                cin >> subchoice;

                cout << "Enter the value to insert: ";
                cin >> value;

                switch (subchoice) {
                    case 1:
                        head = InsertAtBeggining(head,value);
                        display(head);
                        cout<<"Element successfully insert at beggining.\n";

                        break;
                    case 2:
                        head = insertAtEnd(head, value);
                        display(head);
                        cout<<"Element successfully insert at the end.\n";
                        break;
                    case 3:
                        cout << "Enter the value after which new Node insert: ";
                        cin >> pos;
                        
            
                        head = InsertAfterPosition(head, value,pos);
                        display(head);
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                }
                break;

             case 2:  // Delete Menu
                cout << "\nDelete Menu:\n";
                cout << "1. Delete Head\n";
                cout << "2. Delete Tail\n";
                cout << "3. Delete After  Position\n";
               
                cout << "Enter your choice: ";
                cin >> subchoice;

                switch (subchoice) {
                    case 1:
                         head =deleteHeadOfCircularLL(head);
                         display(head);
                         cout << "Head deleted.\n";
                         break;
                    case 2:
                            head =deleteTailOfCircularLL(head);
                            display(head);
                            cout << "Tail deleted.\n";
                            break;
                    case 3:
                       cout << "Enter the value of the node after which you want to delete the next node: ";
                        cin >> value;
                        head = deleteAfterLocation(head, value);
                        display(head);
                        break;
                   


                    default:
                        cout << "Invalid choice! Please try again.\n";
              }
                break;

            case 3:
                display(head);
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
