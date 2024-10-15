#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;

};
//Global Variable
Node*top = NULL;

int StackSize = 0;
//Push into Stack
void Push(int value){

    if(StackSize>=10){
        cout<<"Stack OverFlow"<<endl;
        return;
    }
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = top;
    top = temp;
    cout<<value <<" Pushed Successfully into the Stack "<<endl;
    StackSize++;
}
int Pop(){
    if(top==NULL){
        cout<<"Stack UnderFlow"<<endl;
        return -1;
    }
    int PopData = top->data;
    Node*temp = top;
    top = top->next;
    free(temp);
    StackSize--;
    cout<<PopData<<" Popped out Successfully from the Stack "<<endl;
    
}


void display(){
    if (top==NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }
    Node*temp = top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
    cout<<endl;
}
int main(){
    int choice,value;
    do{
         cout << "\nMenu: \n";
        cout << "1. Push element onto stack\n";
        cout << "2. Pop element from stack\n";
        cout << "3. Print stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
         case 1:
            cout<<"Enter the value to push: ";
            cin>>value;
            Push(value);
            display();
            break;
        
        case 2:
        Pop();
        display();
        break;
        case 3:
         display();
         break;
         case 4:
          cout << "Exiting program.\n";
           break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
        


    }while(choice!=4);
    return 0;
}