#include<bits/stdc++.h>
using namespace std;

class doublyEndedQueue{
    int* arr;
    int front;
    int rear;
    int size;

    public:
    doublyEndedQueue(int n){
        size=n;
        arr=new int [size];
        front=rear=-1;
    }

    bool pushFront(int data){
        if(isFull()){
            cout<<"Quque is full "<<endl;
            return false;
        }
        else if(isEmpty()){
            front=rear=0;
        }
        else if(front==0&&rear!=size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=data;
        return true;
    }

    bool pushRear(int data){
        if(isFull()){
            cout<<"Quque is full "<<endl;
            return false;
        }
        else if(isEmpty()){
            front=rear=0;
        }
        else if(front!=0&& rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=data;
        return true;
    }

    int popFront(){
        if(isEmpty()){
            cout<<"Queue is empty "<<endl;
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }

    int popRear(){
        if(isEmpty()){
            cout<<"Queue is empty "<<endl;
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return ans;
    }
    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if((front==0&&rear==size-1)||(rear==(front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    doublyEndedQueue q(5);
    q.pushFront(15);
    q.pushFront(12);
    q.pushRear(17);
    q.pushRear(13);
    q.pushRear(37);
    cout<<"before popping "<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.getFront()<<endl<<endl;
    q.popFront();
    q.popRear();
    cout<<"after popping "<<endl;
     cout<<q.getRear()<<endl;
    cout<<q.getFront()<<endl<<endl;
    q.pushFront(99);
    q.pushFront(45);
    //queue is full cant push any more as size is only 5
    q.pushFront(45);
}