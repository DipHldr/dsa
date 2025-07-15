#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
class stacks{
   int top;

   public:
   int arr[MAX];
   stacks(){top=-1;}
   bool push(int x);
   int pop();
   void peek();
   bool isEmpty();
};

bool stacks::push(int x){
    if(top>=MAX-1){
        cout<<"stack overflow "<<endl;
        return false;
    }
    else{
        arr[++top]=x;
        return true;
    }

}

int stacks::pop(){
    if(top<0){
        cout<<"stack underflow "<<endl;
        return 0;
    }
    else{
        int x=arr[top--];
        return x;
    }
}

void stacks::peek(){
    if(top<0){
        cout<<"stack is empty "<<endl;
    }
    else{
            cout<<arr[top]<<endl;
    }
}

bool stacks::isEmpty(){
    return top<0;
}

int main(){
    stacks st;
    st.push(22);
    st.push(34);
    st.push(59);
    st.push(34);
    st.push(95);
    st.push(54);
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.peek();
    if(st.isEmpty()){
        cout<<"the stack is empty "<<endl;
    }
    else{
        cout<<"the stack is not empty "<<endl;
    }
}
