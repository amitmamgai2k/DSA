#include <iostream>
using namespace std;


struct Node{
    int data;
     Node*next;
     Node*back;

};
Node*head;
//s
Node*createdoubleLinkedList(int n){
    if(n<=0){
        cout<<"Number of nodes should be greater than 0.\n";
        return nullptr;
    }
    Node*head = (Node*)malloc(sizeof(Node));
    cout << "Enter element 1: ";
    cin >> head->data;
    head->back = nullptr;
    head->next= nullptr;
    Node*prev= head;
    for(int i= 1;i<n;i++){
        Node*temp = (Node*)malloc(sizeof(Node));
        cout << "Enter element " << i+1 << ": ";
        cin>>temp->data;
        temp->next = nullptr;
        temp->back = prev;
        prev->next = temp;
        prev = temp;

    }
    return head;
    
}
//Insertions
Node*InsertAtBeggining(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = head;
    temp->back = nullptr;
    if (head != NULL) {
        head->back = temp;
    }

    head = temp;
    return head;
}
Node*InsertAtEnd(int value){
    Node*EndNode = (Node*)malloc(sizeof(Node));
    EndNode->data = value;
    
    if(head==NULL){
        head  = EndNode;
        head->next  = nullptr;
        head->back = nullptr;
        return head;
    }
    Node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = EndNode;
    EndNode->next = nullptr;
    EndNode->back = tail;
    return head;

}
Node*InsertAfterPosition(int pos, int value){ //pos is the Node value after which we insert new Node 
     if(head==NULL){
        cout<<"List is empty.\n";
        return head;
    }
    Node*NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = value;
    Node*temp = head;
    while(temp!=NULL && temp->data!=pos ){
        temp = temp->next;
    }
      if (temp == NULL || temp->data!=pos) {
        cout << "Node with value " << pos << " not found or there is no node after it." << endl;
        free(NewNode);
        return head;
    }
    NewNode->next = temp->next;
    NewNode->back = temp;
    temp->next = NewNode;
    if(NewNode->next!=NULL){
        NewNode->next->back = NewNode;
    }
    return head;

}
Node*DeleteHead(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }
    
    if(head->next ==NULL ){
        free(head);
         cout<<"Head deleted";
        return NULL;
    }
    Node*temp = head;
    head = head->next;
    head->back = nullptr;
    free(temp);
    cout<<"Head deleted";
   
    return head;
    
}
Node*DeleteTail(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }
    if (head->next == NULL) {

        free(head);
        cout << "Tail deleted.\n";
        return NULL;
    }
    Node*tail =  head;
    while(tail->next->next != NULL){
        tail = tail->next;
    }
    free(tail->next);
     cout << "Tail deleted.\n";
    tail->next = nullptr;
    return head;

//s.


}
Node*DeleteAfterLocation(int pos){
      if(head==NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }
    Node*temp = head;
    while(temp!=NULL && temp->data!=pos){
        temp = temp->next;

    }
      if (temp == NULL || temp->next == NULL) {
        cout << "Node with value " << pos << " not found or there is no node after it." << endl;
        return head;
      }

    Node*temp1 = temp->next;
     if (temp1->next != NULL) {
        temp1->next->back = temp;
    }
   temp->next = temp1->next;
   free(temp1);
   
   return head;
   
}
void display(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;

}
int main(){
    int n,choice,subchoice,value,pos;
    cout<<"Enter Number of elements in your doubly Linked List: ";
    cin>>n;
     if(n>=30 || n<=0){
        cout<<"Linked List Size should be less than 30 and greater than or equal to one";
        return 1;
    }
   
    head = createdoubleLinkedList(n);
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
                        head = InsertAtEnd( value);
                        display(head);
                        cout<<"Element successfully insert at the end.\n";
                        break;
                    case 3:
                        cout << "Enter the value after which new Node insert: ";
                        cin >> pos;
                        
            
                        head = InsertAfterPosition(pos,value);
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
                         head =DeleteHead();

                         display(head);
                      


                       

                    
                         break;
                    case 2:
                            head =DeleteTail();
                            display(head);
                           
                            break;
                    case 3:
                       cout << "Enter the value of the node after which you want to delete the next node: ";
                        cin >> pos;
                        head = DeleteAfterLocation( pos);
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

//sss