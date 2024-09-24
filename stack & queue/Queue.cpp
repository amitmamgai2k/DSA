#include<iostream>
#include<queue>
using namespace std;
class Queue{
    int*arr;
    int front;
    int rear;
    int size;
    public:
    Queue(){
        size = 10;
        arr = new int[size];
        front  = 0;
        rear = 0;
    }

    void enqueue(int data){
          if(rear==size){
            cout<<"Queue is Full";
          }
          else{
            arr[rear] = data;
            rear++;
          }
    }
    void dequeue(int data){
        if(front==rear){
            return-1;
        }
        else{
            arr[front = -1;]
            front++;
            if(front==rear){
                front= 0;
                rear= 0;
            }
        }
    }
}

int main(){
 queue<int>Q;
 Q.push(11);
 Q.push(15);
 Q.push(13);
 cout<<"Size of Queue"<<Q.size();
 cout<<Q.front();
 cout<<Q.back();
 cout<<Q.empty();
 


   return 0;
}