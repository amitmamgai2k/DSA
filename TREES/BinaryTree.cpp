#include <iostream>
using namespace std;

// Define the structure for a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build the binary tree recursively
Node* buildTree() {
    int value;
    cout << "Enter data (-1 for no node): ";
    cin >> value;

    // Base case: return NULL if the input is -1 (no node)
    if (value == -1) {
        return nullptr;
    }

    // Create a new node with the given value
    Node* root = new Node(value);

    // Recursively build the left and right subtrees
    cout << "Enter data for inserting in left of " << value << endl;
    root->left = buildTree();

    cout << "Enter data for inserting in right of " << value << endl;
    root->right = buildTree();

    return root;  // Return the built tree
}
void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}
void preorder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<< " ";
    preorder(root->left);
   
    preorder(root->right);
}
void postorder(Node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<< " ";
}


int main() {
    // Build the tree starting from the root
    Node* root = buildTree();
   cout <<" Inorder traversal is:";
   inorder(root);
    // The tree has been built successfully
    return 0;
}
//ssss