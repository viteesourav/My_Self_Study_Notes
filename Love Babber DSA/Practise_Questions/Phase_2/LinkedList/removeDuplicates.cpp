// Link: https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331
// THis code Shows how we can remove duplicated from a linkedList....
/* Two Situations:
    1) The Linked List is Sorted..
    2) The Linked List is not Sorted....
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

// Approach to Remove duplicates from Sorted LinkedList....
ListNode *deleteDuplicates(ListNode *head)
{

    // Handling edge case:
    if (head == NULL || head->next == NULL)
        return head;

    // lets have curr pointer pointing to the head ListNode...
    ListNode *curr = head;

    while (curr != NULL)
    {

        // Check if the next ListNode is duplicate or not ?
        if (curr->next != NULL && curr->val == curr->next->val)
        {
            // yes it's duplicate...
            ListNode *nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;
        }
        else
        {
            // Naah !!!
            curr = curr->next;
        }
    }
    return head;
}

// If the Nodes are unsorted...
/* 2 Approachs:
    1) USe MAp to keep track of the Vistied Nodess. Tc: O(n) SC: O(n)
    2) First Sort the Nodes and then implements the above Logic for removing Duplicates. TC: O(nlogn) SC: O(1)
*/

// Using a hash Table to Store the visited Nodes... Since SC: O(n), ALl Tescases might not work...
ListNode *removeDuplicates(ListNode *head)
{
    // Write your code here
    // edge case Handle...
    if (head == NULL || head->next == NULL)
        return head;

    // Here The Linked List is unSorted... -> we will use MAp to solve the Problem..
    map<int, bool> traceNode;

    ListNode *current = head;
    traceNode[current->val] = true;
    // Start a while loop till current reaches the LAst ListNode..
    while (current->next != NULL)
    {
        // If the ListNode is already Visitied
        if (traceNode[current->next->val])
        {
            // already vistied..
            ListNode *nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
        }
        else
        {
            // If the ListNode is not vistied...
            traceNode[current->next->val] = true;
            current = current->next;
        }
    }
    return head;
}

// Approach2: WE need to sort the Linked List using merge Sort, Then Apply Duplicate Removal as per sorted List...
//  TO DO: After learning merge sort in LinkedList...