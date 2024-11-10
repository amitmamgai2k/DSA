#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
   

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

bool search(Node* root, int value) {
    Node* temp = root;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        if (temp->data > value) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

Node* Delete(Node* root, int value) {
    if (root == nullptr) {
        cout << "No Element Present\n";
        return nullptr;
    }
    if (root->data == value) {
        // when leaf node
        if (root->left == nullptr && root->right == nullptr) {
            free(root);
            cout << value << " Successfully deleted\n";
            return nullptr;
        }
        // when right child is null
        else if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root->left;
            free(root);
            cout << value << " Successfully deleted\n";
            return temp;
        }
        // when left child is null
        else if (root->left == nullptr && root->right != nullptr) {
            Node* temp = root->right;
            free(root);
            cout << value << " Successfully deleted\n";
            return temp;
        }
        else if (root->left != nullptr && root->right != nullptr) {
            // find min value from the right subtree
            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            int temp1 = temp->data;
            root->data = temp1;
            root->right = Delete(root->right, temp1);
            cout << value << " Successfully deleted\n";
            return root;
        }
    } else if (root->data > value) {
        root->left = Delete(root->left, value);
    } else {
        root->right = Delete(root->right, value);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int choice, value;
    
   

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = Delete(root, value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Value " << value << " found in the BST.\n";
                } else {
                    cout << "Value " << value << " not found in the BST.\n";
                }
                break;

            case 4:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
