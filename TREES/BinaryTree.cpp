#include <iostream>
using namespace std;

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

  
};

// Function to insert a new value into the Binary Search Tree (BST)
Node* insert(Node* root, int value) {
    // If the tree is empty, create a new node and return it as the root
    if (root == nullptr) {
        Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for new node
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    // If the value is smaller than the root's data, insert it into the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If the value is greater than the root's data, insert it into the right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the root pointer after insertion
    return root;
}


bool search(Node*root,int value){
    Node*temp = root;
    while(temp!=NULL){
    if(temp->data ==value){
        return true;
    }
    if(temp->data >value){
        temp = temp->left;
    }
    else{
        temp = temp->right;
    }
    }
return false;
}

Node*Delete(Node*root,int value){
    if(root==NULL){
        return root;
    }
    if(root->data ==value){
        // when leaf node
        if(root->left==nullptr && root->right==nullptr){
            free(root);
            return NULL;
        }
        //when right child is null
        else if( root->left!=NULL && root->right==nullptr){
            Node*temp = root->left;
            free(root);
            return temp;

        }
        //when left child is null
        else if(root->left==nullptr && root->right!=NULL){
            Node*temp = root->right;
            free(root);
            return temp;
        }
        else if(root->left!=NULL && root->right!=NULL){
            //first find max from left or min value from right
            Node*temp = root->right;
            while(temp->left!=nullptr){
                temp = temp->left;
            }
           int temp1 = temp->data;
           root->data  = temp1;
           root->right = Delete(root->right,temp1);
           return root;

        }

    }
    else if(root->data >value){
        root->left = Delete(root->left,value);
        return root;
    }
    else{
        root->right = Delete(root->right,value);
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

// Function for Preorder traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function for Postorder traversal (Left, Right, Root)
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
        // Display the menu
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
                cout << "Inserted " << value << " into the BST.\n";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = Delete(root, value);
                cout << "Deleted " << value << " from the BST.\n";
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
