#include <iostream>
using namespace std;
// Node structure for binary tree
struct Node {
    int data;
    Node* right;
    Node* left;
};
struct StackNode {
    Node* data;
    StackNode* next;
};
StackNode* top = nullptr;
void Push(Node* node) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == nullptr) {
        cout << "Memory allocation failed." << endl;
        return;
    }
    temp->data = node;
    temp->next = top;
    top = temp;
}
Node* Pop() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return nullptr;
    }
    Node* value = top->data;
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return value;
}
bool isEmpty() {
    return top == nullptr;
}
Node* insert(Node* root, int value) {
    if (value == -1) {
        return nullptr;
    }
    if (root == nullptr) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        cout << value << " Inserted Successfully\n";
        return newNode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    Push(root);
    while (!isEmpty()) {
        Node* temp = Pop();
        cout << temp->data << " ";
        if (temp->right) {
            Push(temp->right);
        }
        if (temp->left) {
            Push(temp->left);
        }
    }
    cout << endl;
}
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    Node* current = root;
    while (current != nullptr || !isEmpty()) {
        while (current != nullptr) {
            Push(current);
            current = current->left;
        }
        current = Pop();
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    Node* current = root;
    while (current != nullptr || !isEmpty()) {
        while (current != nullptr) {
            Push(current);
            if (current->right) {
                Push((Node*)(-1 * (intptr_t)current->right));
            }
            current = current->left;
        }
        current = Pop();
        if ((intptr_t)current < 0) {
            current = (Node*)(-1 * (intptr_t)current);
        } else {
            cout << current->data << " ";
            current = nullptr;
        }
    }
    cout << endl;
}
int main() {
    Node* root = nullptr;
    int value;
    cout << "Enter values to insert into the tree (-1 to stop):\n";
    while (true) {
        cout << "Enter value: ";
        cin >> value;
        if (value == -1) break;
        root = insert(root, value);
    }
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
