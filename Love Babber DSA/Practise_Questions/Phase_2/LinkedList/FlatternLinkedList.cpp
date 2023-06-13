// Link: https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655?leftPanelTab=0
/*
You given a linked List, with next pointers and child pointers... [look at the diagram]
You need to flat the List, All Nodes must be sorted and connected to each other by child pointer..

*/
#include <bits/stdc++.h>
using namespace std;

// Definition for linked list.
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// Function to merge 2 sorted List...[used Recusion Approach]
Node *sortList(Node *&list1, Node *&list2)
{

    // edgecase check
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    // Here also we will use recursion, ans try to merge the List...
    // NOTE: Here the Nodes we are merging are linked with child pointer...
    Node *newHead = NULL;
    if (list1->data <= list2->data)
    {
        // Node of list1 has smaller value..
        newHead = list1;
        newHead->child = sortList(list1->child, list2);
    }
    else
    {
        // Node of list2 has smaller value..
        newHead = list2;
        newHead->child = sortList(list1, list2->child);
    }

    // Now we have the sorted list with head at newHead...
    return newHead;
};

// Approach: Recursive Appraoch
Node *solve(Node *&head)
{

    // Edgecase: If no head or only 1 head Node...
    if (head == NULL || head->next == NULL)
        return head;

    // now lets try to solve just 1 case, Rest we assume Recusion solved for us..
    // Consider the Node with child at head...
    Node *list1 = head;
    head = head->next;         // This is where Recursion will falttern the List.
    list1->next = NULL;        // breaking the next pointer link..
    Node *list2 = solve(head); // Called Recursion, This gives us a flat sorted List..

    // Now we have 2 sorted lists, list1 and list2, we will merge them.
    Node *newHead = sortList(list1, list2);

    return newHead;
};

Node *flattenLinkedList(Node *head)
{
    // Write your code here
    return solve(head);
}

/*

Appraoch/ Logic:

Flatten a List

1 -> 4 -> 7 -> 9 -> 20 -> X
|    |    |    |
2    5    8    12
|    |
3    6


Flat the List ?  Node has child pointer and next pointer..


Appraoch: [Recursive appraoch]

-- Solve 1 case, rest Recursion will handle..

-- The fist Node with it's Child we will consider as List1 with head
-- From the second Node onwards Recursion will Make it sorted and flat and return me a list2 with head2.
-- Now to merge this 2 sorted List into one List, We will use the Merge2sorted List appraoch !!

list1:
1 -> 2 -> 3

list2: [We assume Recusion solved it and returned like this..]
4 -> 5 ->6 -> 7 ->8 -> 9 -> 12 -> 20 -> X

using List1 and list2, we need to make a sorted List..
[Merge 2 sorted List]

- Thus, List is flat now [Done]



*/