#include <iostream>
using namespace std;
#include <vector>

struct Node{
int data;
    Node*next;
    Node*back;

};
Node*head;

Node*createdoublyCircularLinkedList(vector<int> arr){
Node*head = (Node*)malloc(sizeof(Node));
head->data = arr[0];
Node*prev = head;
for(int i =1; i<arr.size();i++){
    Node*temp  =(Node*)malloc(sizeof(Node));
    temp->data = arr[i];
    temp->next=  head;
    temp->back = prev;
    prev->next = temp;
    prev =temp;
}
return head;
}
//Insertion 
Node*InsertAtBeggining(int value) {
Node*temp = (Node*)malloc(sizeof(Node));
temp->data = value;
if (head==NULL){
temp->next = temp;
temp->back = temp;
    head = temp;
    return head;
}

Node*tail = head;
temp->next = head;
head->back = temp;
while(tail->next!=head){
tail = tail->next;
}
tail->next = temp;
temp->back = tail;
head = temp;
return head;

}
Node*InsertAtEnd(int value){
Node*EndNode = (Node*)malloc(sizeof(Node));
EndNode->data = value;

if(head==NULL){
    head  = EndNode;
    EndNode->next  = head;
    EndNode->back = head;
    return head;
}
Node*tail = head;
while(tail->next!=head){
    tail = tail->next;
}
tail->next = EndNode; 
EndNode->next = head;
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
while(temp->next!=head && temp->data!=pos ){
    temp = temp->next;
}
    if (temp->data != pos) {
    cout << "Node with value " << pos << " not found." << endl;
    free(NewNode);
    return head;
}
if (temp->next == head) {
   temp->next = NewNode;
   NewNode->next = head;
   head->back = NewNode;
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
if(head->next ==head){
    free(head) ;
    return NULL;
}

Node*temp = head;
Node*tail = head;
while(tail->next!=head){
    tail = tail->next;
}

head = head->next;
head->back = tail;
tail->next = head;
free(temp);
return head;

}
Node*DeleteTail(){
if(head==NULL){
    cout<<"List is empty"<<endl;
    return NULL;
}
    else if (head->next == head) {
    free(head);
    return NULL;
}
Node*tail =  head;
while(tail->next->next != head){
    tail = tail->next;
}
free(tail->next);
tail->next = head;
return head;




}
Node*DeleteAfterLocation(int pos){
    if(head==NULL){
    cout<<"List is empty"<<endl;
    return NULL;
}
Node*temp = head;
while(temp->next!=head && temp->data!=pos){
    temp = temp->next;

}
    if (temp->data != pos) {
    cout << "Node with value " << pos << " not found." << endl;
    return head;
}
if (temp->next == head) {
    cout << "No node exists after the node with value " << pos << endl;
    return head;
}

Node*temp1 = temp->next;
    if (temp1->next != head) {
    temp1->next->back = temp;
}
temp->next = temp1->next;
free(temp1);
return head;

}
void display(Node*head) {
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

int main(){
int n,choice,subchoice,value,pos;
cout<<"Enter Number of elements in your doubly Linked List: ";
cin>>n;
    if(n>=30 || n<=0){
    cout<<"Linked List Size should be less than 30 and greater than or equal to one";
    return 1;
}
vector<int>arr(n);

    for (int i = 0; i < n; i++) {
    cout << "Enter element " << i + 1 << ": ";
    cin >> arr[i];
}
head = createdoublyCircularLinkedList(arr);
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
                        cout << "Head deleted.\n";
                        break;
                case 2:
                        head =DeleteTail();
                        display(head);
                        cout << "Tail deleted.\n";
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
