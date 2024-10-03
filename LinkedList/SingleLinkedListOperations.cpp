#include <iostream>
using namespace std;

// Structure of our Node
struct Node {
    int data;
    Node *next;
};
Node*head;

// create LinkedList
Node *CreateLinkedList(int n) {
    Node*head = (Node*)malloc(sizeof(Node));
    cout<<"Enter element 1: ";
    cin>>head->data;
    Node*mover = head;
    for(int i = 1;i<n;i++){
        Node*temp = (Node*)malloc(sizeof(Node));
        cout<<"Enter element "<<i+1<<": ";
        cin>>temp->data;
        temp->next = nullptr;
        mover->next = temp;
        mover= temp;
    }
  return head;
}

// delete head of the Single Linked List
Node *deleteHeadOfSingleLL() {
    if (head == NULL) {
     cout<<"List is empty"<<endl;
     return NULL;
    }
    if(head->next==nullptr){
       free(head);
       cout << "Head deleted.\n";
       return NULL;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
    cout << "Head deleted.\n";
    return head;
}

Node *deleteTailOfSingleLL() {
    if (head == NULL){
          cout<<"List is empty"<<endl;
     return NULL;
         
    } 
    else if (head->next == NULL) {
       
        free(head);
         cout<<"Tail deleted";
        return head;
    }
    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    cout<<"Tail deleted";
    temp->next = nullptr;
    return head;
}

// delete after given Node
Node* deleteAfterLocation(int value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return nullptr;
    }

    Node* temp = head;

    // Find the node with the specified value
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }


    if (temp->data != value) {
        cout << "Node with value " << value << " not found." << endl;
        return head;
    }
    if (temp->next == nullptr) {
        cout << "No node exists after the node with value " << value << endl;
        return head;
    }

    // Node to be deleted
    Node* temp2 = temp->next;

    // Remove the node
    temp->next = temp2->next;

    // Free the memory
    free(temp2);

    return head;
}

// Insertion

Node*insertAtBeginning(int value){
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = head;
    return temp;

    

}
Node* insertAtEnd(int value){
    Node*temp = head;
    if(head==NULL){
       Node*temp1 = (Node*)malloc(sizeof(Node));
       temp1->data = value;
       temp1->next = nullptr;
       return temp1;
        
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node*NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = value;
    NewNode->next = nullptr;
    temp->next = NewNode;
    return head;
    

}


Node*InsertAfterPosition(int value,int pos){
    if(head==NULL){
        cout<<"List is empty.\n";
        return head;
    }
    Node*temp = head;
     while (temp != nullptr && temp->data != pos) {
        temp = temp->next;
    }
     if (temp == nullptr || temp->data!=pos) {
        cout << "Node with value " << pos << " not found or there is no node after it." << endl;
        return head;
    }
    Node*temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = value;
    temp1->next=  temp->next;
    temp->next = temp1;
    return head;



}

Node*CountNumberOfNodes(){
    Node*temp = head;
    int counter  = 0;
    while(temp!=NULL){
        temp= temp->next;
        counter++;
    }
    cout<<"No of Nodes is Given Linked List is "<<counter<<endl;
    return head;
}

Node*ReverseLinkedList(){
    if(head ==NULL){
        return NULL;

    }
    if(head->next==nullptr){
        return head;

    }
     Node*current= head;
     Node*prev = nullptr;
     Node*save;
     while(current!=NULL){
        save = current->next;
        current->next = prev;
        prev = current;
        current = save;

     }
     head = prev;
     return head;

}


void display(Node*head) {
    if (head == NULL) {
        return ;
    }
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int choice, subchoice, k, n, value,pos;

    cout << "Enter the number of elements in the Linked List: ";
    cin >> n;
    if(n>=30 || n<=0){
        cout<<"Linked List Size should be less than 30 and greater than or equal to one";
        return 1;
    }
   
 head = CreateLinkedList(n);

     do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Count Number of Nodes\n";
        cout << "5. Reverse Linked List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Insert Menu
                cout << "\nInsert Menu:\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert at Position\n";
                cout << "Enter your choice: ";
                cin >> subchoice;

                cout << "Enter the value to insert: ";
                cin >> value;

                switch (subchoice) {
                    case 1:
                        head = insertAtBeginning(value);
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
                        
            
                        head = InsertAfterPosition( value,pos);
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
                         head = deleteHeadOfSingleLL();
                         display(head);
                       
                         break;
                    case 2:
                            head = deleteTailOfSingleLL();
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
                head = CountNumberOfNodes();
                break;
            case 5:
               head  = ReverseLinkedList();
               display(head);
               break;

                

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
