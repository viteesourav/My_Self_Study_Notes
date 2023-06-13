/*
Handling Loops in LinkedList
   1) Detect if there is a cycle present in the given LinkedList or not ? [using Map Loopkup or Floyd's Loop detection Algo]
   2) Find the Node where the Loop is starting ? [using Floyd's Loop Detection Algo]
   3) Remove the Loop From the Looped Linked List. [Find the start of the Loop, Then REmove the loop]
*/

#include <bits/stdc++.h>
using namespace std;

// class def...
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Insertion in Linked List...
void insert(Node *head, int data)
{

    // creating a new Node...
    Node *newNode = new Node(data);

    // Going to the end of the Linked List...
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // insert the new Node...
    temp->next = newNode;
}

// LinkedList Travese...
void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 1) Check if loop present in Linked List ?
// Aproach1: using Map as lookup Table... TC: O(n), SC: O(n)
bool isLoopedList1(Node *head)
{

    map<Node *, bool> lookupMap;

    Node *temp = head;

    // Iterate through all Nodes in the List...
    while (temp != NULL)
    {

        // check if the node is already Vistied ?
        if (lookupMap[temp])
            return true;
        lookupMap[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Approach2: Using Floyd's Loop Detection Algorith...[Fast and slow Pointer approach] TC: O(n) SC: O(1)
bool isLoopedList2(Node *head)
{

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// 2) Finding the starting Node of Loop...
Node *findLoopStart(Node *head)
{

    // using Floyd's detection algo we can find the Intersection of slow and fast..
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }
    // Thus we have a node where slow and fast both are pointing...

    slow = head; // update slow to head, and fast remain at the intersetion NOde..
    while (slow != fast)
    {
        slow = slow->next; // updating slow and fast 1 node at a time...
        fast = fast->next;
    }
    return slow; // Point of intersction of slow and fast will give Loop start Node.
}

// 3) Removal Loops from the linked List...
void removeLoop(Node *head)
{

    // find the start of the Loop...
    Node *startLoopNode = findLoopStart(head);

    // Iterate over the Loop Nodes....
    Node *temp = startLoopNode;
    while (temp->next != startLoopNode)
        temp = temp->next;

    // Remove the Node connection That is causing the Loop...
    temp->next = NULL;
}

int main()
{

    // Need to craete a LinkedList that has loop
    Node *head = new Node(8);

    insert(head, 7);
    insert(head, 2);
    insert(head, 1);
    insert(head, 5);
    insert(head, 6);

    // This will make the List looped...
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head->next->next; // Tail is pointing back to 3rd Node, Thus Looped.

    // traverse(head);  //This will fail, as temp traverse pointer will stuck in Infinity Loop...

    // NOw we can perform all Algorithms on Looped LinkedList....

    // 1) Verify if the LinkedList as Loops or not ?
    cout << "is the LinkedList Looped: " << isLoopedList2(head) << endl;

    // 2) Find the starting node of loop in Linked List..
    Node *loopStartNode = findLoopStart(head);
    cout << "The Loop starts at Node: " << loopStartNode->data << endl;

    removeLoop(head); // Remove the Loop from the LinkedList...

    traverse(head); // Traverse the LinkedList..

    cout << "Loops in Linked Lists !" << endl;
    return 0;
}