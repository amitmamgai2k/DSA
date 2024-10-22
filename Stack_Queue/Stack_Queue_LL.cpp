#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
Node*front = nullptr;
Node*rear = nullptr;
Node*top = nullptr;

// Push operation 
void Push(){
    int value;
    cout<<"Enter the Value to Push: "<<endl;
    cin>>value;
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = top;
    top = temp;
    cout<<value<< " Successfully Pushed into stack"<<endl;
}
int Pop(){
    if(top==nullptr){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    int value = top->data;
    Node*temp = top;
    top = top->next;
    free(temp);
    cout<<value<<" Successfully popped out"<<endl;
    return value;
}
void peek(){
     if(top==nullptr){
        cout<<"Stack is empty"<<endl;
        return ;
    }
    cout<<"Top Element is: "<<top->data;
   
}
void displayQueue(){
    if(front==nullptr){
      cout<<"Queue is Empty "<<endl;
        return;
    }
    cout<<"Queue elements are: "<<endl;
    Node*temp = front;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}
void enqueue(){
    int value;
    cout<<"Enter the value to Enqueue"<<endl;
    cin>>value;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = nullptr;

    if (rear == nullptr) {
        // First element in the queue
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    cout << value << " Enqueued Successfully into the Queue" << endl;

    displayQueue();
    }

int dequeue(){
    if(front==nullptr){
        cout<<"Queue is empty"<<endl;
        return -1;

    }
    int value = front->data;
    Node*temp = front;
    front  = front->next;
    free(temp);
    cout<<value<<" Successfully dequeue "<<endl;
    return value;
     displayQueue();

}
int main(){

int choice ,dataType;
    cout << "Choose the type of Data structure:\n";
    cout << "1.Stack\n";
    cout << "2.Queue\n";
    cout << "Enter your choice: ";
    cin >>dataType;
     if (dataType==1) {
            do {
                cout << "\nStack Menu: \n";
                cout << "1. Push element onto stack\n";
                cout << "2. Pop element from stack\n";
                cout << "3. Check Top\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                       Push();
                        break;

                    case 2:
                        Pop();
                        break;

                    case 3:
                        peek();
                        break;

                    case 4:
                        cout << "Returning to initial menu.\n";
                        break;

                    default:
                        cout << "Invalid choice, please try again.\n";
                }

            } while (choice != 4);
        } else if (dataType==2) {
            do {
                cout << "\nQueue Menu: \n";
                cout << "1. Enqueue element into queue\n";
                cout << "2. Dequeue element from queue\n";
                cout << "3. Print queue\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        enqueue();
                       
                        break;

                    case 2:
                        dequeue();
                
                        break;

                    case 3:
                        displayQueue();
                        break;

                    case 4:
                        cout << "Returning to initial menu.\n";
                        break;

                    default:
                        cout << "Invalid choice, please try again.\n";
                }

            } while (choice != 4);
        }
        else{
            cout<<"Invalid choice"<<endl;
            return -1;
        }


return 0;
    } 



    
