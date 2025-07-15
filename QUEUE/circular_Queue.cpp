#include<bits/stdc++.h>
using namespace std;
class circularQueue{
    int* arr;
    int front;
    int rear;
    int size;

    public:
    circularQueue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }

    bool enqueue(int data){
        //to check whether queue is full
        if((front==0&&rear==size-1)||(rear==(front-1)%(size-1))){
            cout<<"Queue is full "<<endl;
            return false;
        }
        else if(front==-1){//first element to push
            front=rear=0;
        }
        else if(rear==size-1&&front!=0){// to maintain cyclic nature
            rear=0;
        }
        else{//normal flow
            rear++;
        }
        arr[rear]=data;//push inside queue;
        return true;
    }
    int dequeue(){
        if(front==-1){//to check queue is empty
        cout<<"Queue is empty "<<endl;
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;        
         if(front==rear){//single element is present
            front=rear=-1;
        }
        else if(front==size-1){//to maintaain cyclic nature;
            front=0;
        }
        else{//normal flow
            front++;
        }
        return ans;
    }
    int qfront(){
        return arr[front];
    }
    int back(){
        return arr[rear];
    }
};
int main(){
    circularQueue q(5);
    q.enqueue(15);
    q.enqueue(45);
    q.enqueue(14);
    q.enqueue(13);
    q.enqueue(35);
    cout<<q.qfront()<<endl;
    cout<<q.back()<<endl;

}