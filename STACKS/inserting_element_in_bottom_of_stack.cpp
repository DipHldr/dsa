#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&st,int n){
    
    if(st.empty()){
        st.push(n);
        return;
    }

    int temp=st.top();
    st.pop();
    solve(st,n);
    st.push(temp);
}

stack<int> pushAtBottom(stack<int>&myStack,int n){
    solve(myStack,n);
    return myStack;
}

int main(){
    stack<int> myStack;
    myStack.push(12);
    myStack.push(43);
    myStack.push(32);
    myStack.push(14);
    myStack.push(13);
    myStack.push(72);
    myStack.push(42);
    pushAtBottom(myStack,333);

    while(!myStack.empty()){
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
}