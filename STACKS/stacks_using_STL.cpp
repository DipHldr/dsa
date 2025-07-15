#include<iostream>
#include<stack>
using namespace std;

int main(){
    //creation of stack
    stack<int> s;

    //push operation
    s.push(1);
    s.push(2);

    //pop operation
    s.pop();

    cout<<"printing top element "<<s.top()<<endl;

    if(s.empty()){
        cout<<"stck is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    return 0;
}