#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};
int getheight(Node*root){
    if (root==NULL){
        return 0;
    }
    return root->height;

}


int getBalanceFactor(Node*root){
    if(root==NULL){
        return 0 ;
    }
    return getheight(root->left) - getheight(root->right);

}
//Right Rotation
Node*rightRotation(Node*root){
    Node*child = root->left;
    Node*childRight = child->right;
    child->right = root;
    root->left = childRight;

    // update height;
    root->height = 1+max(getheight(root->left),getheight(root->right));
    child->height = 1+max(getheight(child->left),getheight(child->right));
    return child;


}
//Left Rotation
Node*leftRotation(Node*root){
    Node*child = root->right;
    Node*childleft = child->left;
    child->left = root;
    root->right = childleft;
     root->height = 1+max(getheight(root->left),getheight(root->right));
    child->height = 1+max(getheight(child->left),getheight(child->right));
    return child;

}
Node*insert (Node*root,int value){
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left  = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    if(root==nullptr){
        return newNode;
    }
    if(value <root->data){
       root->left=  insert(root->left,value);

    }
    else if (value>root->data){
        root->right = insert(root->right,value);
    }
    else{
        return root; // Duplicate element not allowed
    }
    // update height
    root->height = 1+max(getheight(root->left),getheight(root->right));
    //Balancing check
    int balance = getBalanceFactor(root);
     
    // Left Left case 
    if(balance>1 && value <root->left->data){
         return rightRotation(root);

    }
    // Right Right case
   else if(balance<1 && root->right->data<value){
        return leftRotation(root);

   }
    // Left Right case
   else if(balance >1 && value >root->left->data){
       root->left =  leftRotation(root->left);
       return rightRotation(root);
   }
    // Right left case
   else if(balance <1 && root->right->data>value){
    root->right =   rightRotation(root->right);
     return leftRotation(root);

   }
    // No unblancing
    else{
         return;
    }

}
 

