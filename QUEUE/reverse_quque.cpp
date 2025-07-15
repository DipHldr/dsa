#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int>q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}