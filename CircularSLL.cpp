#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node*next;


};


Node*head;

Node*CreateSingleLinkedList(vector<int>arr){
    if (arr.size() == 0) return NULL;
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = nullptr;
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = nullptr;
        mover->next = head;
        mover = temp;
    }
    return head;
}

Node*InsertAtBeggining(Node*head,int value){
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = nullptr;
    if(head==NULL){
        head= temp;
        temp->next = head;
        return;
    }
    Node*tail = head;
    while(tail->next!=head){
        tail  =  tail->next;

    }
    tail->next = temp;
    temp->next = head;
    head = temp;
    return head;

}
Node*InsertAtEnd(Node*head,int &value){
     Node*temp = head;
     while(head ==NULL){
        Node*temp1 = (Node*)malloc(sizeof(Node));
        temp->data = value;
        temp->next = temp;
        head  = temp;
        return;
     }
     while(temp->next !=head){
        temp =temp->next;

     }
     Node*EndNode = (Node*)malloc(sizeof(Node));
     EndNode->data= value;
     temp->next = EndNode;
     EndNode->next= head;
     return head;

}
Node*InsertAtLocation(Node*head,int &value){
    
}
Node*DeleteHead(Node*head){
    if(head==NULL || head->next == head ){

        return NULL;
    }
    
    Node*temp = head;
    head->next = head;
    Node*tail = head;
    free(temp);
    while(tail->next!=head){
        tail = tail->next;

    }
    tail->next = head;


  
    return head;

}

Node*DeleteTail(Node*head){
    if (head == NULL) return NULL;
    else if (head->next == head) {
        free(head);
        return NULL;
    }
    Node*tail = head;
    while(tail->next->next != head){
        tail = tail->next;
    }
    free(tail->next);
    tail->next= head;
    return head;

}
Node*DeleteAtLocation(Node*head,int &position){
    if(head==NULL)return NULL;
    if(position==1){
        Node*temp = head;
        head->next = head;
        free(temp);
        return head;

    }
    Node*next = head;
    Node*prev = ;
    int counter  =  1;
    

return head;

}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp= head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main(){


    return 0;

}


