#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
};

Node* NewNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insertNode() {
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;
    if (data == -1) {
        return nullptr;
    }
    
    Node* node = NewNode(data);
    cout << "Enter left child of " << data << endl;
    node->left = insertNode();
    cout << "Enter right child of " << data << endl;
    node->right = insertNode();

    return node;
}

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    stack<Node*> Stack;
    Stack.push(root);

    while (!Stack.empty()) {
        Node* temp = Stack.top();
        cout << temp->data << " ";
        Stack.pop();
        if (temp->right) {
            Stack.push(temp->right);
        }
        if (temp->left) {
            Stack.push(temp->left);
        }
    }
    cout << endl;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    stack<Node*> Stack;
    Node* current = root;

    while (current != nullptr || !Stack.empty()) {
        while (current != nullptr) {
            Stack.push(current);
            current = current->left;
        }

        current = Stack.top();
        Stack.pop();
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    stack<Node*> Stack;
    Node*ptr = root;
    while(ptr!=nullptr || !Stack.empty()){
        while(ptr!=nullptr){
            Stack.push(ptr);
            // if the node has right child
            //if child child push with a negative sign
            if(ptr->right!=nullptr){
                 Stack.push((Node*)(-1 * (intptr_t)ptr->right));
            }
            ptr = ptr->left;

        }
        ptr = Stack.top();
        Stack.pop();
        if((intptr_t) ptr< 0){
            ptr = (Node*)(-1*(intptr_t)ptr);

        }else{
            cout<<ptr->data<<" ";
            ptr = nullptr;
        }


    }



  
}

int main() {
    cout << "Build the binary tree:\n";
    Node* root = insertNode();

    int choice;
    do {
        cout << "\nBinary Tree Traversal Menu:\n";
        cout << "1. Preorder Traversal\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
