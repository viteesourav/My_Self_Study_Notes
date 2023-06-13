// Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
//  This Problem needs to Merge 2 given sorted List into a single List....

#include <bits/stdc++.h>
using namespace std;

// NOde Defination...
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // Approach1: Using 2 Node Pointers and Based on comparison Creating a new Sorted List...
    ListNode *solveApproach1(ListNode *&list1, ListNode *&list2)
    { // TC: O(m+n), SC: O(1)

        // Creating a newHead and tail to store the sorted List...[starts with a dummy head]
        ListNode *tempHead = new ListNode(-1); // starting both are pointing to dummy head -1.
        ListNode *tempTail = tempHead;

        // Travesing both the list till one of them becomes NULL...
        while (list1 != NULL && list2 != NULL)
        {
            // comparing the val of Nodes...
            if (list1->val <= list2->val)
            {
                // insert the Node from List1 to sorted List...
                ListNode *nodeToInsert = list1;
                list1 = list1->next; // updating the head of list1
                nodeToInsert->next = NULL;
                tempTail->next = nodeToInsert; // Creating the newLink...
                tempTail = nodeToInsert;       // updating the tail.
            }
            else
            {
                // insert the Node from List2 to sorted List...
                ListNode *nodeToInsert = list2;
                list2 = list2->next; // updating the head of list1
                nodeToInsert->next = NULL;
                tempTail->next = nodeToInsert; // Creating the newLink...
                tempTail = nodeToInsert;       // updating the tail.
            }
        }

        // Check which of the List is leftOver...
        // Pointing the tail of sorted List to the leftover Nodes of List1
        if (list1 != NULL)
        {
            tempTail->next = list1;
        }
        if (list2 != NULL)
        {
            tempTail->next = list2;
        }

        // update the newHead and removing the starting dummy Node for sorted List..
        ListNode *newHead = tempHead->next;
        delete tempHead;

        return newHead;
    };

    // Approach2: Insertion Of Node, based on comparison... TC: O(n) SC: O(1)
    ListNode *solveApproach2(ListNode *&list1, ListNode *&list2)
    {

        // declaring the Node pointers We need For this Approach...
        // prev and curr are on list1...
        ListNode *prev = list1;
        ListNode *curr = list1->next;

        ListNode *index = list2; // index is on list2..

        // Now we will try to insert Nodes from list2 in list1 at its right position...
        // Traverse till either curr becomes NUll or index becomes NUll.
        while (curr != NULL && index != NULL)
        {

            // Condition to check if we can insert index Node from list2 in list1, b/w Prev and curr
            if ((prev->val <= index->val) && (index->val <= curr->val))
            {
                // we can insert index Node...
                ListNode *nodeToInsert = index;
                // Link update between the Nodes...
                index = index->next;
                prev->next = nodeToInsert;
                nodeToInsert->next = curr;
                // Update prev Node...
                prev = prev->next;
            }
            else
            {
                // Naah !! Not possible...
                prev = curr;
                curr = curr->next;
            }
        }

        // case1: If Curr becomes NULL and index is not NULL,
        // then we can link the prev of list1 to leftOver of list2..
        if (curr == NULL && index != NULL)
            prev->next = index;
        // case2: If index becomes NULL, Then we successfully inserted all List2 Nodes in list1..

        return list1; // Returning the head of list1.
    };

    // Approach3: Recursive Approach [wayy Faster than rest 2 Appraoch...]
    ListNode *solveApproach3(ListNode *&list1, ListNode *&list2)
    {

        // edge Case...
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        // Solving one case, Rest Recursion will handle...
        // Out of list1 first node and list2 first Node, which one we will take ?
        ListNode *ans = NULL; // This is the new ans List.
        if (list1->val <= list2->val)
        {
            // list1 node val is smaller...
            ans = list1;
            ans->next = solveApproach3(list1->next, list2); // Recursion
        }
        else
        {
            // list2 node val is smaller...
            ans = list2;
            ans->next = solveApproach3(list1, list2->next);
        }

        // returning the new List ans..
        return ans;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        // Handle the edge case...
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        // Solving by Approach 2:
        // Deciding which List starts with a less Node val...
        // if (list1->val <= list2->val)
        // {
        //     return solveApproach2(list1, list2);
        // }
        // else
        // {
        //     return solveApproach2(list2, list1);
        // }

        return solveApproach3(list1, list2);
    }
};

/* Logic/ Appraoches:

Appraochs1: Based On Comparison between the Nodes and creation of new Node LinkedList...[Simple appraoch]

h1
1 -> 4 -> 5


h2
2 -> 3 -> 5

tt
-1 -> 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
tH

-- Use 2 Node Pointers and traverse both the List and return the new List based on comparison of the elements.

Approach2: Insertion of Nodes from List2 at correct place between Nodes of list1 [Little complicated appraoch because handling the links between the Nodes]
TC: O(n) SC: O(1)
-- We will try to Insert Nodes [if possible] from the Second List into First List.

Assuming -> First Node Value of list 1 is less than first Node value of list2.
-- If not swap the lists, List 1 will become list2, and list2 as list1.
-- in the Function, the first param, list1 starting node should be less than first Node of list2.

Steps:

1  ->  3  -> 5 -> X
p      c

2  ->  4  -> 5  -> X
i

    p: prev, c: curr and i: index
    -- Handle edge case: If List1 or List2 are null...
    -- First and second List we will decide, [IMP]
    -- Whichever Head Node data is less will be First Node, Other one the other one will be second List.
    -- Condition:  p->data <= i->data <= c->data ->
    -- Store i in temp,
    -- Update the head of second List,Update i to the next Pointer.
    --Insert the Node between p and c.
    -- Update p and c.
    -- If not, then move p and c.
    -- If the c becomes Null, pull the p and points to i Node.
    -- If i becomes NULL, then We are done.

Return the First List...

Appraoch3: Recusive appraoch...[Preffered for Merging 2 sorted List]

-- We will create a new List.
-- Since Recusion, we need an edge case...[When one of the  Nodes becomes Null, return the other one.. ]
-- One case we will solve, for selecting the correct Node based on comaprison of Nodes of list1 and list2.
-- Rest we assume Recursion will do for us, and fetch the correct Node in order based on comparison...

*/