#include<bits/stdc++.h>
using namespace std;
class Queue{
    int* arr;
    int size;
    int qfront;
    int rear;

    public:
    Queue(){
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }
    /*public functions of queue*/
    bool isEmpty(){
        if(qfront==rear){
            return true;
        }
        else {return false;}
    }

    void enqueue(int data){
        if(rear==size){
            cout<<"quque is full "<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue(){
        if(qfront==rear){
            cout<<"Queue is empty "<<endl;
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
        if(qfront==rear){
            qfront=0;
            rear=0;
        }
        return ans;
        }
    }

    int front(){
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }    
};
int main(){
    Queue q;
    q.enqueue(51);
    q.enqueue(21);
    q.enqueue(52);
    q.enqueue(31);
    q.enqueue(53);
    cout<<q.front()<<endl;   
    q.dequeue();
     cout<<q.front()<<endl;
}