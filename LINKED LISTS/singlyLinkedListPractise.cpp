#include<iostream>
using namespace std;
class node{
    
    public:
    int data;
    node* next;
    //constructor
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void insertAtHead(node* &head,int d){
    node* temp = new node(d);
    temp -> next = head;
    head=temp;   
}
void insertAtTail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}

void insertAtAnyPosition(node* &head,node* &tail,int position,int d){
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    node* temp = head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    node* newNode= new node(d);
    newNode->next=temp->next;
    temp->next=newNode;
}
void print(node* &head){
    if(head==NULL){
        cout<<"List is empty "<<endl;
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        cout<<"-->"<<temp->data;
        temp=temp->next;
    }
}

int main(){
    node* node1= new node(23);
    node* head=node1;
    node* tail=node1;
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,7);
    insertAtHead(head,8);
    insertAtHead(head,9);
    insertAtHead(head,58);
    insertAtTail(tail,7);
    insertAtTail(tail,22);
    insertAtAnyPosition(head,tail,3,55);
    insertAtAnyPosition(head,tail,4,45);
    print(head);
}
