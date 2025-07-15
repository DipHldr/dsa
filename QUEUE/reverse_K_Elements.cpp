#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> &q,int k){
    stack<int>s;
    //pop first k elements from q and put it in the stack
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }

    //fetch from stack and push into queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    //fetch first (n-k) elemeents from queue and push back;
    int t=q.size()-k;
    while(t--){
        q.push(q.front());
        q.pop();
    }
    return q;
}

void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
   modifyQueue(q,2);
   display(q);
}