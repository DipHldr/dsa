/*Deletion in Linked list*/

#include<iostream>
using namespace std;

//Linked list node
struct node{
    int data;
    struct node* next;
};

//delete first node in the linked list
node* deleteFirstNode(struct node* head){
    if(head==NULL)
    return NULL;
    
    //move the head pointer to the next node
    node* tempNode=head;
    head=head->next;
    delete tempNode;
    return head;
}

//delete last node from the linked list
node* removeLastNode(struct node* head){
    if(head==NULL)
    return NULL;

    if(head->next==NULL){
    delete head;
    return NULL;
    }

    //first find second last node
    node* second_last=head;
    while(second_last->next->next!=NULL)
        second_last=second_last->next;

        //delete the last node
    delete (second_last->next);

    //set next of second last to NULL
    second_last->next=NULL;

    return head;
}

//create linked list by adding nodes at head
void push(struct node** head,int new_data){
    struct node* newNode=new node;
    newNode->data=new_data;
    newNode->next= (*head);
    (*head) =newNode;
}

//main function
int main(){

    //start with the empty list
    node* head=NULL;

    //create linked list
    push(&head,2);
    push(&head,4);
    push(&head,6);
    push(&head,8);
    push(&head,10);

    node* temp;

    cout<<"linked list created "<<endl;
    for(temp=head;temp!=NULL;temp=temp->next)
    cout<<temp->data<<"-->";
    if(temp==NULL)
    cout<<"null"<<endl;
    
    //delete first node
    head=deleteFirstNode(head);
    cout<<"linked list after deleting head node "<<endl;
    for(temp=head;temp!=NULL;temp=temp->next)
    cout<<temp->data<<"-->";
    if(temp==NULL)
    cout<<"null"<<endl;

    //delete last node
    head=removeLastNode(head);
     cout<<"linked list after deleting last node "<<endl;
    for(temp=head;temp!=NULL;temp=temp->next)
    cout<<temp->data<<"-->";
    if(temp==NULL)
    cout<<"null"<<endl;

    return 0;
    
}