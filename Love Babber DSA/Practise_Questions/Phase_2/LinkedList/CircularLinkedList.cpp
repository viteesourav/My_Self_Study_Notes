// THis shows the implementation of Circular Linked List...
/*
NOTE: We need just tail pointer here..
1) Insertion in circular linedList.
2) traversal in circular Linkedlist.
3) Deletion of node in CircularLinkedList. -> Based Value we will delete.
*/

#include <bits/stdc++.h>
using namespace std;

// Circular Linked List Node Structure..
class Node
{
public:
    int data;
    Node *next;

    // Constructor For handling node Creation.
    Node(int data)
    {
        this->data = data;
        this->next = this;
    }

    // destructor called for Node Deletion..
    ~Node()
    {
        cout << "Node is deleted with value: " << this->data << endl;
    }
};

// insertion based on the matching vlaue..
void insertIntoList(Node *&tail, int data)
{

    // creating a new node...
    Node *newNode = new Node(data);

    // check if a tail is present or not ?
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail; // Single node pointing to itself..
        return;            // Skip the below code execution...
    }

    // If tail is present...
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode; // update the tail..
};

// traversing the Circular linked List...
void traverseList(Node *&tail)
{

    // handles if all elements are removed...
    if (tail == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    Node *temp = tail->next; // temp points where the tail is pointing..

    // traverse untill temp again becomes tail..
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl; // For priting the node where temp and tail same.
};

// deletion in case of circular Linked List..[based on Node Value]
void deleteNode(Node *&tail, int value)
{

    bool delFlag = false;

    Node *temp = tail->next;
    Node *prev = tail;

    // If only one element is present to delete...
    if (temp == prev)
    {
        if (temp->data == value)
        {
            Node *nodeTodelete = tail;
            nodeTodelete->next = NULL;
            tail = NULL;
            delete nodeTodelete;
        }
        else
        {
            cout << "Element not present" << endl;
        }
        return;
    }

    // traverse and try to find a match..
    while (temp != tail)
    {
        if (temp->data == value)
        {

            // perform Node deletion.
            Node *nodeTodelete = temp;
            prev->next = nodeTodelete->next;
            nodeTodelete->next = NULL;
            delete nodeTodelete;
            delFlag = true;
            break;
        }
        prev = temp;
        temp = temp->next; // traverse the list...
    }

    // Deletion at the tail Node...
    if (temp->data == value)
    {
        delFlag = true;
        prev->next = temp->next;
        temp->next = NULL;
        tail = prev;
        delete temp;
    }

    // If the element don't match...
    if (!delFlag)
    {
        cout << "No Matching elements Found that can be deleted !" << endl;
    }
};

int main()
{
    // Incase of Circular Linked List, only tail is needed.
    Node *tail = new Node(8);

    // Node* tail = NULL; //InCase, tail sets to NULL, Insertiong code can handle it.

    insertIntoList(tail, 11);
    // insertIntoList(tail, 12);
    // insertIntoList(tail, 13);

    // traverse the list..
    traverseList(tail);

    cout << "After Deletion" << endl;

    deleteNode(tail, 8); // Deletion works for any value...
    traverseList(tail);

    cout << "Circular Linked List" << endl;
    return 0;
}
