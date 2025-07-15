#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int>q;
    q.push_front(15);
    q.push_back(22);
    // cout<<q.front()<<endl;
    // cout<<q.back()<<endl;
    // q.pop_back();
    q.push_front(54);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop_back();
    q.pop_front();
    q.pop_front();
    if(q.empty()){
        cout<<"Queue is empty "<<endl;
    }
    
}