#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&stacks,int count,int size){
    if(count==(size+1)/2 -1){
        stacks.pop();
        return;
    }

    int temp=stacks.top();
    stacks.pop();

    solve(stacks,count+1,size);
    stacks.push(temp);
}

void deleteMiddle(stack<int>&stacks,int n){
    int count=0;
    solve(stacks,count,n);
}

int main(){

    stack<int> inputStacks;
    inputStacks.push(23);
    inputStacks.push(61);
    inputStacks.push(13);
    inputStacks.push(26);
    inputStacks.push(21);
    // inputStacks.push(63);
    deleteMiddle(inputStacks,5);
    while(!inputStacks.empty()){
        cout<<inputStacks.top()<<" ";
        inputStacks.pop();
    }
}