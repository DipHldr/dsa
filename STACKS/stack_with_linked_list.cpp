#include<bits/stdc++.h>
using namespace std;

class stackNode{
    public:
    int data;
    stackNode* next;
};
int isEmpty(stackNode* root){
    return !root;
}
stackNode* newNode(int data){
    stackNode* stacks=new stackNode();
    stacks->data=data;
    stacks->next=NULL;
    return stacks;
}

void push(stackNode** root,int data){
    stackNode* stacks=newNode(data);
    stacks->next=*root;
    *root=stacks;
}
int pop(stackNode** root){
    if(isEmpty(*root)){
        return INT_MIN;
    }
    stackNode* temp=*root;
    *root=(*root)->next;
    int popped=temp->data;
    free(temp);
    return popped;
}
int peek(stackNode* root){
    if(isEmpty(root)){
        return INT_MIN;
    }
    return root->data;
}
int main(){
    stackNode* root=NULL;

    push(&root,21);
    push(&root,12);
    push(&root,45);
    push(&root,31);
   cout<< peek(root)<<endl;
   pop(&root);
   cout<<peek(root)<<endl;
    pop(&root);
    pop(&root);
    pop(&root);
    cout<<peek(root)<<endl; //return INT_MIN cuz its empty
}