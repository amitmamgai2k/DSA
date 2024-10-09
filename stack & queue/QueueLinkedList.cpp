#include <iostream>
using namespace std;
struct Node{
     int data;
     Node*next;
};
Node*front  = nullptr;
Node*rear = nullptr;
int QueueSize = 0;

void Enqueue(int value){
    if(QueueSize>=10){
        cout<<"OverFlow"<<endl;
        return;
    }
    Node*temp  = (Node*)malloc(sizeof(Node));

    temp->data = value;
    rear->next = temp;
    temp->next = nullptr;
    cout<<value<<" Enqueue Successfully"<<endl;
    QueueSize++;
}
int Dequeue(){
    if(front==NULL){
        cout<<"UnderFlow"<<endl;
        return -1;
        
    }
    int DequeueElement = front->data;
    Node*temp = front;
    front = front->next;
    free(temp);
    cout<<DequeueElement<<" Dequeue Successfully"<<endl;
    QueueSize--;
}


int main(){
    return 0;
}