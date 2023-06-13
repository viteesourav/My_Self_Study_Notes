/*
 This Logic is for finding the middle of a given Linked List.
 Approach:
   Using fast pointer and slow pointer Method.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{

    // Appraoch: Using the Fast pointer and slow Pointer Approach...
    // base case:
    if (head == NULL || head->next == NULL)
        return head;

    // 2 Node Pointers
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL)
    {
        // fast moves 2 node spaces...
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next; // Check before moving the fast for the second time.
        // slow moves 1 node spaces...
        slow = slow->next;
    }

    return slow; // slow will be at the mid.
}

/*  Approach Discussion:

2) find the Middle of a Linked List:
   Brute Force Approach: TC: O(n)
      -- Find the len of the linked list. use a temp pointer iteratre till head.
      -- Again use a temp pointer to iterate till the mid of length.

   Fast pointer and slow Pointer: TC: O(n/2)
      -- Asuming we have 2 pointers:
         fast: Starts from the second Node, moves 2 nodes at a time.
         slow: Starts from the first Node, moves 1 node at a time.
      -- When Fast reaches the end of the Node, slow will be at the mid. [This is the idea]


*/