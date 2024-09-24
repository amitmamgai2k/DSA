#include <iostream>
using namespace std;

// Define the structure for a node in the binary search tree
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

// Function to insert a new value into the Binary Search Tree (BST)
Node* insert(Node* root, int value) {
    // If the tree is empty, create a new node
    if (root == nullptr) {
        return new Node(value);
    }

    // If the value is smaller than the root's data, insert it into the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If the value is greater than the root's data, insert it into the right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;  // Return the root pointer after insertion
}

// Function for Inorder traversal (Left, Root, Right)
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
    Node* root = nullptr;  // Initialize the root of the BST as null
    int n, value;

    cout << "Enter the number of nodes you want to insert: ";
    cin >> n;

    // Insert values into the Binary Search Tree
    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    // Display the tree using different traversal techniques
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
