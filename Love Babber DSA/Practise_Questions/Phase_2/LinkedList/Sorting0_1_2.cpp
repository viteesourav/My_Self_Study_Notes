// Link: https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0
//  Given a Linked List containing 0's, 1's and 2's, Sort them...
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Approach1: If Node data Replacement is allowed.. TC: O(n) SC: O(1)
Node *solveApproach1(Node *&head)
{

    // We will maintain a freq Count for 0,1 and 2...
    int zeroCnt = 0, oneCnt = 0, twoCnt = 0;

    // traverse the List and get the cnt of each Elements..
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zeroCnt++;
        else if (temp->data == 1)
            oneCnt++;
        else if (temp->data == 2)
            twoCnt++;
        temp = temp->next;
    }

    // Now we have the count, we will traverse the List again,
    // we will replace Nodes data value as per the freq count...
    temp = head;
    while (temp != NULL)
    {
        if (zeroCnt != 0)
        {
            temp->data = 0;
            zeroCnt--;
        }
        else if (oneCnt != 0)
        {
            temp->data = 1;
            oneCnt--;
        }
        else if (twoCnt != 0)
        {
            temp->data = 2;
            twoCnt--;
        }
        temp = temp->next;
    }

    // Now the List is sorted, returning the head Node...
    return head;
};

// Function to handle insertion at the End...
void insertIntoList(Node *&tailNode, Node *newNode)
{
    tailNode->next = newNode;
    tailNode = newNode;
}

// Approach2: If Node Replacement is not Allowed, Then we can handle the Links between the Node...
Node *solveApproach2(Node *&head)
{ // TC: O(n) SC: O(1)

    // Will create 3 Dummy Nodes with their own head and tail...
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    // traverse the given List and insert Node in their resp Node List...
    Node *curr = head;
    while (curr != NULL)
    {
        int val = curr->data;
        if (val == 0)
            insertIntoList(zeroTail, curr);
        else if (val == 1)
            insertIntoList(oneTail, curr);
        else if (val == 2)
            insertIntoList(twoTail, curr);
        curr = curr->next;
    }

    // Now we have 3 Linked Lists,
    //  one for all O's, one for all 1's and one for all 2's...

    // Merging of the 3 Dummy Linked Lists...
    //  Fist: Merging of List of 0's and 1's [check if there is any 1's List present or NOT ? ]
    if (oneHead != oneTail)
    {
        // Some Nodes are there is List of 1's...
        zeroTail->next = oneHead->next; // Pointing 0's tail Node to the next of head Node of 1's
        oneTail->next = twoHead->next;  // 1's Tail points to next Node of 2's Head..
    }
    else
    {
        // List of Nodes of 1's is empty...
        zeroTail->next = twoHead->next; // Pointing 1's tail Node to the next of head Node of 2's
    }
    twoTail->next = NULL; // Terminating the List of 2's with NULL..

    // renaming the head and Deleting all head Nodes for the dummy list..
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    // returning head of the newly formed sorted List....
    return head;
};

Node *sortList(Node *head)
{
    // Write your code here.
    // Checking for edge case...
    if (head == NULL || head->next == NULL)
        return head;
    return solveApproach2(head);
}

/* Logic:

    Approach 1: Node Replacement is allowed..
    -- Create a freq table count for 0, 1 and 2...
    -- as per count Taverse the Entire Given LinkedList and replace the Nodes data value...

    Approach 2: Node Replacement Not Allowed...
    -- WE will create 3 Dummy New Linked List, One for zero Nodes, one Nodes and two Nodes..
    -- Then we will merge them to form a single Node in sorted Manner.

    NOTE: We are creating Dummy NOdes starting with -1, We will remove it later, It will make the merge process easy..

*/