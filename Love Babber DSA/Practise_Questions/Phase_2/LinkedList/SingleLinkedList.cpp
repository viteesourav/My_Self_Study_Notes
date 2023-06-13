// This shows all the utility methods and node creation for Single Linked List.
/*

1) How to create a node and its dynamic initialization.
2) head and tail concepts in Linked List
3) Traverse the Linekd List.
4) Insertat any place and delete at any place.

*/

#include <bits/stdc++.h>
using namespace std;

// This is a node class..
class Node
{
public:
    int data;
    Node *next;

    // constructor for Node intialization...
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
    head = temp;
    // cout<<head<<endl;
};

// traversing Linked List...
void printNodes(Node *head)
{

    Node *temp = head; // declaring a temp node.
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

// Insertion at the mid...
void insertionAtEnd(Node *&tail, int data)
{

    Node *temp = new Node(data);
    tail->next = temp;
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
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next; // store the address where temp was pointing..
    temp->next = newNode;
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
    }
    else
    { // If the node is not at the end
        temp->next = nodeToDelete->next;
        nodeToDelete->next = NULL;
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

    printNodes(head);

    deleteNodePos(head, tail, 12); // delete at any node in Linked List.

    printNodes(head);

    cout << "Linked Lists" << endl;
    return 0;
}
