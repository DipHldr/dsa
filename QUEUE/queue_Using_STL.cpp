#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>l;
    l.push(56);
    l.push(45);
    l.push(23);
    l.push(24);
    l.push(23);
    l.push(43);
    l.push(13);
    l.push(21);
    cout<<"before pop"<<endl;
    cout<<l.front()<<" "<<l.back()<<endl;
     cout<<l.size()<<endl;
    l.pop();
    cout<<"after pop"<<endl;
    cout<<l.front()<<" "<<l.back()<<endl;
    cout<<"queue size: "<<l.size()<<endl;
}