// This implements the Doubly Linked List...
/*
Node Structure has, 1 data and 2 pointers [next and prev]
1) Traversal, forward and backward
2) Inseration -> at start, at end, at middle
3) deletion. -> at any poistion.
*/
#include <bits/stdc++.h>
using namespace std;

// This is a node class..[Doublly Linked list]
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor for Node intialization...
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    };

    // destructor calling...
    ~Node()
    {
        cout << "destructor called, Memory is free for element: " << this->data << endl;
    }
};

// Insertion at head...[Remeber to pass Node by Ref, As head will update here.]
void insertionAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    // cout<<head<<endl;
};

// traversing Linked List...
void ForwardTraverse(Node *head)
{

    Node *temp = head; // declaring a temp node.
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

void backwardTraverse(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Insertion at the mid...
void insertionAtEnd(Node *&tail, int data)
{

    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
};

// insertion at any postion..[handles insert at head or tail too]
void insertionAtPostion(Node *&head, Node *&tail, int pos, int data)
{

    Node *temp = head; // Start the temp Node pointer...

    // check if the post is on head ?
    if (pos == 1)
    {
        insertionAtHead(head, data);
        return;
    }

    int cnt = 1;
    // moving the temp till the element before the postion.
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Check if the pos is at the tail node ?
    if (temp->next == NULL)
    {
        insertionAtEnd(tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next; // store the address where temp was pointing..
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
};

// deletion of a node...
void deleteNodePos(Node *&head, Node *&tail, int pos)
{

    Node *temp = head; // temp pointer starting from head.
    int cnt = 1;

    // If deletion is happening from head...
    if (pos == 1)
    {
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp; // Freeing the memory from heap...
        return;
    }

    // traverse to the postion...
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Update the Linkage between the nodes...
    Node *nodeToDelete = temp->next;

    // If delete happens from the end..
    if (nodeToDelete->next == NULL)
    {
        tail = temp;
        temp->next = NULL;
        nodeToDelete->prev = NULL;
    }
    else
    { // If the node is not at the end
        temp->next = nodeToDelete->next;
        nodeToDelete->next->prev = temp;
        nodeToDelete->next = NULL;
        nodeToDelete->prev = NULL;
    }

    delete nodeToDelete;
};

int main()
{
    Node *head = new Node(5); // First element of Linked List is head...
    // cout<<head->data<<"->"<<head->next<<endl;
    // cout<<head<<endl;  Shows the address of head..

    // we have a single node, So it's both head and tail same..
    Node *tail = head;

    insertionAtHead(head, 8);
    // cout<<head<<endl; //Shows the address of head, After insertion.
    insertionAtHead(head, 6);
    insertionAtHead(head, 9);
    insertionAtHead(head, 1);

    insertionAtEnd(tail, 10);
    insertionAtEnd(tail, 11);
    insertionAtEnd(tail, 12);

    insertionAtPostion(head, tail, 3, 101);
    insertionAtPostion(head, tail, 1, 200);  // postion is at begining
    insertionAtPostion(head, tail, 11, 555); // postion at the end.

    cout << "Before Deletion: ";
    ForwardTraverse(head);

    deleteNodePos(head, tail, 11); // delete at any node in Linked List.

    cout << "After Deletion: ";
    ForwardTraverse(head);

    // cout<<"Forward Traversal: ";
    // ForwardTraverse(head);
    // cout<<"Backward Traversal: ";
    // backwardTraverse(tail);

    cout << "Doublly Linked Lists" << endl;
    return 0;
}
