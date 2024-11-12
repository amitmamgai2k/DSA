#include <iostream>
using namespace std;
// Structure of our Node
struct Node {
    int data;
    Node *next;
};
Node*head;
// create CircularLink
Node*createCircularLinkedList(int n) {
  Node*head= (Node*)malloc(sizeof(Node));
  head->next = head;
  cout<<"Enter Element 1: ";
  cin>>head->data;
  Node*prev = head;
  for(int i =1;i<n;i++){
    Node*temp = (Node*)malloc(sizeof(Node));
    cout<<"Enter element "<<i+1<<":"<<endl;
    cin>>temp->data;
    temp->next = head;
    prev->next = temp;
    prev = temp;
  }
   return head;
}
// delete head of the Circular Linked Listss
Node *deleteHeadOfCircularLL() {
    if (head == NULL) {
  cout<<"List is empty";
  return NULL;
    }
      if (head->next == head) {
        free(head);
        cout<<"Head Deleted";
        return nullptr;
    }
    Node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    Node*newHead = head->next;
    temp->next = newHead;
    free(head);
    cout<<"Head deleted";
   return newHead;
}
// deleteTail///
Node *deleteTailOfCircularLL() {
      if (head == NULL) {
      cout<<"List is empty";
      return NULL;
    }
      if (head->next == head) {
        free(head);
        cout<<"Tail Deleted";
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    Node*tail = temp->next;
    temp->next = head;
    free (tail);
    cout<<"Tail deleted";
    return head;
}
Node* deleteAfterLocation(int value) {
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
    free (nodeToDelete);
    return head;
}
// Insert at start
Node*InsertAtBeggining(int value){
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
Node*insertAtEnd(int value){
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
Node*InsertAfterPosition(int value,int pos){
    if(head==NULL){
        cout<<"List is empty.\n";
        return head;
    }
    Node*temp = head;
     while (temp->next != head && temp->data != pos) {
        temp = temp->next;
    }
    if(temp->data!=pos){
        cout<<"Node with given value not exist"<<endl;
    }
    Node*temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = value;
    temp1->next=  temp->next;
    temp->next = temp1;
    return head;
}
void display(Node* head) {
    if (head == nullptr) {

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
    head=  createCircularLinkedList(n);
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
                        head = InsertAtBeggining(value);
                        display(head);
                        cout<<"Element successfully insert at beggining.\n";
                        break;
                    case 2:
                        head = insertAtEnd( value);
                        display(head);
                        cout<<"Element successfully insert at the end.\n";
                        break;
                    case 3:
                        cout << "Enter the value after which new Node insert: ";
                        cin >> pos;
                        head = InsertAfterPosition(value,pos);
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
                         head =deleteHeadOfCircularLL();
                         display(head);
                         break;
                    case 2:
                            head =deleteTailOfCircularLL();
                            display(head);
                            break;
                    case 3:
                       cout << "Enter the value of the node after which you want to delete the next node: ";
                        cin >> value;
                        head = deleteAfterLocation( value);
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
