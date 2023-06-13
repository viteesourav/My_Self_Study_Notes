/*
This logic we can use to detect if the Linked List is Circular or not ?
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL; // In case of Circular linked List, the new Node's next should point to itself, i.e this->next = this;
    }
};

bool isCircular(Node *head)
{

    if (head == NULL || head->next == NULL)
        return false;
    if (head->next == head)
        return true;

    Node *temp = head->next;

    while (temp != head && temp != NULL)
        temp = temp->next;

    if (temp == head)
        return true;

    return false;
}

/*
    Approach: simple Iterative Apprach:
        -- Just Start a temp ahead of head Node.
        -- start traversing the Linked List, till either temp becomes null or it comes back to head..
        -- If it comes back to head, The Linked List is Circular. Else NOt circular.

    NOTE: [Important Concept of loops in Linked List]
        -- Assuming in this Linked List, There is not Loop present.
    Loops in Linked Lsit,
        A node in the LinkedList points back to any other Node other than head node, It becomes loop.
        -- In this case, the traversing will stuck in an infinity Loop, as it cannot reach head also it won't be able to reach NULL.
*/