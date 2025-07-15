/*INSERTION IN LINKED LIST*/

#include <iostream>
using namespace std;

// a linked list node
struct node
{
    int data;
    struct node *next;
};

// insert a new node infront of the list
void push(struct node **head, int node_data)
{

    // 1. create and allocate node
    struct node *newNode = new node;
    // 2.assign data to node;
    newNode->data = node_data;
    // 3. set next of new node as head
    newNode->next = (*head);
    // 4. move the head to point to the new node
    (*head) = newNode;
}

// insert new node after a given node
void insertAfter(struct node *prev_node, int node_data)
{
    // 1. check if the given previous node is null
    if (prev_node == NULL)
    {
        cout << "The given previous node is NULL";
        return;
    }
    // 2. create and allocate new node
    struct node *newNode = new node;
    // 3. Assign data to the node
    newNode->data = node_data;
    // 4. make next of new node as next of prev_node
    newNode->next = prev_node->next;
    // 5. move the next of prev_node as newNode
    prev_node->next = newNode;
}

// insert new node at the end of the linked list
void append(struct node **head, int node_data)
{
    // 1.create and allocate node
    struct node *newNode = new node;

    struct node *last = *head; // used in  step 5

    // 2.assign data to the node
    newNode->data = node_data;
    // 3.set next pointer of newNode to NULL as its the last node
    newNode->next = NULL;
    // 4. if list is empty new node becomes first node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    // 5.else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next;
    }
    // 6.change the next of the last node
    last->next = newNode;
    return;
}

// display linked list contents
void displayList(struct node *Node)
{

    // traverse the list to display each node
    while (Node != NULL)
    {
        cout << Node->data << "-->";
        Node = Node->next;
    }

    if (Node == NULL)
        cout << "null";
}

/*main function for linked list*/
int main()
{
    // empty list
    struct node *head = NULL;

    // Insert 10
    append(&head, 10);

    // Insert 20 at the beginning
    push(&head, 20);
    // Insert 30 at the beginning
    push(&head, 30);
    // insert 40 at the end
    append(&head, 40);
    // Insert 50 after 20
    insertAfter(head->next, 50); 
    cout << "final linked list" << endl;
    displayList(head);
    return 0;
}
