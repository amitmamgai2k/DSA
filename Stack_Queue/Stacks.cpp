#include <iostream>
using namespace std;


int stack[20];
int top = -1;
void push(int data,int size) {
        if (top <  size- 1) {
            top++;
            stack[top] = data;
            cout<<data<<" pushed successfully"<<endl;
        } else {
            cout << "Stack overflow" << endl;
        }
        
    }

    void pop() {
        if (top >= 0) {
             cout<<stack[top]<<" pop successfully"<<endl;
            top--;
           
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0) {
            return stack[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; 
        }
    }

int main() {
  int size,choice,data ;
  cout<<"Enter Stack Size( Stack size should be greater than 0 and less than 20)"<<endl;
  cin>>size;
   if (size > 20 || size<= 0)
    {
        cout << "Invalid size. Please set an appropriate Stack size between 1 and 20." << endl;
        return-1;

    }


  do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. See Top Element\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            cout << "Enter the element to push: ";
                cin >> data;
                push(data,size);
                break;
            case 2:
                pop();
                break;
            case 3:{
                int topelement = peek();
                  if (topelement != -1)   cout << "Top element is: " << topelement << endl;
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

   return 0;
}
