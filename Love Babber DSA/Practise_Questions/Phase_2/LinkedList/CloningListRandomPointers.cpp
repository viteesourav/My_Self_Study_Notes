// Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
/*
Basically, You Given a List, It has one more pointer called random, That eithers point to Null or ANy other Node from the List.
    Task is to Copy this Original List, Along with mainting all the Random Pointer..
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Fun that handles insertion at the end of the copied List...
void insertInList(Node *&tail, int val)
{
    // creating a new Node...
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

// Appraoch1: Using Map to Store the Address of Original Node and Copied Node address
// TC: O(n) SC: O(n)
Node *solveApproach1(Node *&head)
{

    // edge case...
    // 1. If there is no head...
    if (head == NULL)
        return NULL;
    // If there is 1 Node in head...
    if (head->next == NULL)
    {
        Node *newHead = new Node(head->val); // create a newNode with the same val...
        if (head->random == head)
            newHead->random = newHead;
        return newHead;
    }

    // creating a map and a newDummy head Node for the ans...
    map<Node *, Node *> nodeAddressMap;
    Node *dummyHead = new Node(-1);
    Node *dummyTail = dummyHead;

    // Traversing the Original List and preparing the copied List[using next pointer] and Map the Node Address...
    Node *temp = head;
    while (temp != NULL)
    {
        // Inseting in the copied List...[passing by value]
        insertInList(dummyTail, temp->val);
        nodeAddressMap[temp] = dummyTail; // Adding Node Address in the map
        temp = temp->next;
    }
    // Thus, we copied the Original List to Copied List using next pointer and mapped address..

    // Now for copying the random Node Address, traversing the original List...
    Node *temp1 = head;            // points to the head of original List...
    Node *temp2 = dummyHead->next; // points to the head of copied List...
    while (temp1 != NULL && temp2 != NULL)
    {
        // Find where the random Pointer points in Original List..
        if (temp1->random != NULL)
        { // check if the random points to NULL ?
            Node *randNode = temp1->random;
            temp2->random = nodeAddressMap[randNode];
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // just check if copied List is empty or not ?
    if (dummyHead == dummyTail)
        return NULL;

    Node *newhead = dummyHead->next;
    delete dummyHead;
    return newhead;
}

// Approach2: Forget about the Map, Handle the linkage between the Node...
//  TC: O(n) SC: O(1)
Node *solveApproach2(Node *&head)
{

    // Handle edge case of no Node...
    if (head == NULL)
        return NULL;

    // First let me create a new List copied from Original List...
    Node *temp = head;
    Node *dummyHead = new Node(-1);
    Node *dummyTail = dummyHead;

    // copying the List...
    while (temp != NULL)
    {
        insertInList(dummyTail, temp->val);
        temp = temp->next;
    }

    // update the head of the cloned List...
    Node *newHead = dummyHead->next;
    delete dummyHead;

    // Now we have originalList and cloned List, Lets handle Linkage of Next...
    Node *temp1 = head;
    Node *temp2 = newHead;
    while (temp1 != NULL && temp2 != NULL)
    {
        Node *nextNode1 = temp1->next;
        temp1->next = temp2;
        Node *nextNode2 = temp2->next;
        temp2->next = nextNode1;
        temp1 = nextNode1;
        temp2 = nextNode2;
    }

    // Now we have the combined List... Let's handle the Linkage of Random...
    temp = head;
    while (temp != NULL)
    {
        if (temp->random != NULL && temp->next != NULL)
        {
            Node *randNode = temp->random;       // Random Address of Node from orignal List
            temp->next->random = randNode->next; // Pointing Node of copied List to randElement
        }
        temp = (temp->next != NULL) ? temp->next->next : NULL; // Jumping 2 Nodes at a time...
    }

    // Lets decouple the combined list into seperate List...
    temp1 = head;
    newHead = head->next;
    temp2 = newHead;
    while (temp1 != NULL && temp2 != NULL)
    {
        Node *nextNode1 = (temp1->next != NULL) ? temp1->next->next : NULL;
        temp1->next = nextNode1;
        Node *nextNode2 = (temp2->next != NULL) ? temp2->next->next : NULL;
        temp2->next = nextNode2;
        temp1 = nextNode1;
        temp2 = nextNode2;
    }

    // REturing the head of the cloned List...
    return newHead;
}

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        // return solveApproach1(head);
        return solveApproach2(head);
    }
};

/*

Logic/Approach:

Clone List using Random Pointer..

 H
 1  ->  2 -> 3 -> 4 -> 5 -> X
 |      |    |    |    |
 3      1   NULL   3    2       Random Pointer Nodes



Appraoch1: Use Map to Store Address TC: O(n) SC: O(n)

  -- traverse the Original List and create a new List [use next pointer from Orignal List]
  -- While Traversing,
     Maintain a HashMap, of Original NOde and new Node's Node Addresses.

  Map has: {OrinalListNode: copyListNode}, {..., ...} ...

  -- Now Traverse the Orignal List Again,
     Using the HashMap, Link the Nodes and their random Nodes..



Appraoch2: Forget Map ! Handle the Node Links TC:O(n) SC: O(1)

  -- First Create a copied List from Original List, using next pointer
  -- Then Handle the Link between the Nodes of Original List and Copied List such that,
    a node of Original List points to the node of the Copied List.

             t1
  Original : 1 -> 2 -> 3 -> X
       t2
  Copied : 1` -> 2` -> 3` -> X

                    H    NH
  After Above step: 1 -> 1` -> 2 -> 2` -> 3 -> 3` -> X
                    t1   t2

  -- Now, Traverse the List, 2 Nodes at a time...
          and Create the random MApping for New List node as per the Original Node.

  -- Once the Random Mapping done, undo the Linkage manipulation done as step2.

NOTE:
    For Undersanding and Viszualizing the Linkage updates between the Nodes,
    DRaw Original Nodes and Colned Nodes in 2 seperate Row, then update the Linkage as per the logic
    Do the Random pointer Mapping.
    then decouple them into seperate List i.e Original and ClonedList.

 Done.

*/