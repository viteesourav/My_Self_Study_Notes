// This code is used to Revese a Doublly Linked List...
/*  2 Approachs used:
        -- Swapping oh head and prev address.
        -- Breaking the link and creating the Link between the Nodes
*/

#include <bits/stdc++.h>
using namespace std;

// Double Linked List Node Defination..
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    };
};

// Nodes Utility methods....
void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
};

void traverseList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

void traverseReverse(Node *head)
{

    // traverse to the end of the List..
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp->prev != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << temp->data << endl;
}

/*
Approach_1: Swaping of prev and next For head nodes...
Logic:
 -- In a Double node, It stores the prev and next Node Address.
 -- swap the address stored in the next and prev.
 -- It will Reverse the Linked List.
*/
void swapNodeDirections(Node *&element)
{
    Node *temp = element->prev;
    element->prev = element->next;
    element->next = temp;
}

Node *recursiveReverse(Node *&head)
{

    // base Condition: If the last node is reached ?
    if (head == NULL || head->next == NULL)
    {
        swapNodeDirections(head);
        return head;
    }

    // get the last node as newHead Value..
    Node *newHead = recursiveReverse(head->next); // Traverse till the end..

    // Swap the current and prev of the current head node...
    swapNodeDirections(head);

    // the newhead will be passed unchanged from all fun from the call stack.
    return newHead;
}

/*
Approach_2: Breaking the Addresses links and rearranging them, without swapping prev and current Node pointers
Logic:
 -- Use Recursion to Go till the end of the List, Get the updated head pointers
 -- Next rearrange the existing NOde pointers between head and its forward Node.
*/
Node *recursiveReverse2(Node *&head)
{

    // baseCase:
    if (head == NULL || head->next == NULL)
    {
        head->prev = NULL;
        return head;
    }

    // we will call recursion to reach the end of the list..
    Node *newHead = recursiveReverse2(head->next);

    // Now rearranging the connections between the nodes.
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;

    return newHead;
}

int main()
{

    Node *head = new Node(8);
    insert(head, 5);
    insert(head, 3);
    insert(head, 9);

    traverseList(head);

    head = recursiveReverse2(head);

    traverseList(head);

    traverseReverse(head);

    cout << "Recursive REverse of Doublly Linked List" << endl;
    return 0;
}