#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    // node(int d){
    //     this->data=d;
    //     this->next=NULL;
    // }
};
void deleteBeginning(node** head){
    node* temp=new node();
    temp=*head;
    *head=(*head)->next;
    free(temp);
   
}
void deleteEnd(node** head){
    node* prev;
    node* end=(*head);
    while(end->next!=NULL){
        prev=end;
        end=end->next;
    }
    prev->next=NULL;
    free(end);
}
int getCount(node* head){
    int count =0;
    node* current=head;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}
void deleteAnyPoint(node** head,int position){   
    node* prev=(*head);
     node* curr=(*head)->next;
    int count=1;
    while(count<position-1){
        prev=prev->next;
        curr=curr->next;
        count++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    // free(curr);
}
int push(node** head_ref,int d){
    node* newNode=new node();
    if(*head_ref==NULL){
        *head_ref=newNode;
        newNode->data=d;
        newNode->next=NULL;
        return 0;
    }
    newNode->data=d;
    newNode->next=*(head_ref);
    *(head_ref)=newNode;
}
// how to insert at any position of linked list
    // Firstly, check if the given previous node is NULL or not.
    // Then, allocate a new node and
    // Assign the data to the new node
    // And then make the next of new node as the next of previous node. 
    // Finally, move the next of the previous node as a new node.
    void insertAfter(node* &head,int d,int position){
        // if(prev_node==NULL){
        //     cout<<"The give previous node cannot be null";
        //     return;
        // }
        if(position==1){
        push(&head,d);
        return;
        }
        node* temp=head;
        int pos=1;
        while(pos<position-1){
            temp=temp->next;
            pos++;
        }
        node* nodeToInsert=new node();
        nodeToInsert->data=d;
        nodeToInsert->next=temp->next;
        temp->next=nodeToInsert;
    }
    void append(node** head,int d){
        node* newNode=new node();
        node* last=*(head);
        newNode->data=d;
        newNode->next=NULL;
        if(*(head)==NULL){
            *(head)=newNode;
            return;
        } 
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=newNode;
        newNode=last;
    }
void display(node* head){
    if(head==NULL)
    cout<<"The list is empty ";
    node* temp=head;
  while(temp!=NULL){
    cout<<"-->"<<temp->data;
    temp=temp->next;
}
cout<<endl;
}
int main(){
    // node* node1=new node();
    node* head=NULL;
    int n;
    for(int i=0;i<5;i++){
        cin>>n;
    push(&head,n);
    display(head);
    }
    insertAfter(head,222,3);
    display(head);
    append(&head,333);
    display(head);
    deleteBeginning(&head);
    display(head);
    deleteEnd(&head);
    display(head);
    deleteAnyPoint(&head,4);
     display(head);    
     cout<< getCount(head);
    
}