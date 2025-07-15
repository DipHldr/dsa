#include<bits/stdc++.h>
using namespace std;


void sortedInsert(stack<int>&st,int num){
    if(st.empty()||(!st.empty()&&st.top()<num)){
        st.push(num);
        return;
    }
    int temp=st.top();
    st.pop();
    sortedInsert(st,num);
    st.push(temp);
}
void sortStack(stack<int>&stacks){
    if(stacks.empty()){
        return;
    }
    int num=stacks.top();
    stacks.pop();
    sortStack(stacks);
    sortedInsert(stacks,num);
}
int main(){
    stack<int>st;
    st.push(53);
    st.push(93);
    st.push(23);
    st.push(59);
    st.push(25);
    st.push(29);
    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
