/* Here we have 3 approachs to Reverse a Linked List...
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

class Solution
{

    // Recursive Approach 1:
    void reverseLL(ListNode *&head, ListNode *&current, ListNode *&prev)
    {

        // base case: If the current reaches empty
        if (current == NULL)
        {
            head = prev;
            return;
        }

        // Solve one case, Rest Assume Recursion already took care of it...
        ListNode *frwd = current->next;
        reverseLL(head, frwd, current); // frwd will be current and current will be prev
        current->next = prev;           // This breaks the frwd link and connects to prev element
    };

    // Recursive Approach 2:
    // Recursive Solution for Reversing the LL using just head as param.
    ListNode *solveReverse(ListNode *&head)
    {

        // base condition: If there is no head or just one head...
        if (head == NULL || head->next == NULL)
            return head;

        // solve the REcursive part, traverse till the end...
        ListNode *newHead = solveReverse(head->next);

        // Update the Link of the head and the node infront of it..
        head->next->next = head;
        head->next = NULL; // current head Points to NULL

        return newHead; // the newhead will be passed unchanged from all fun from the call stack.
    };

public:
    ListNode *reverseList(ListNode *head)
    {
        /*
        //Iterative Approach 1: Using prev, current and forward Node pointers
            // Edge cases:  If LL is empty or just have 1 element..
            if(head == NULL || head->next == NULL) return head;
            ListNode* prev = NULL;
            ListNode* current = head;

            while(current != NULL) {
                ListNode* forward = current->next;
                current->next = prev;
                prev = current;
                current = forward;
            }
            //update the head to prev
            head = prev;
            return head;
        */
        /*
        //Recursive approach 1...
            ListNode* prev = NULL;
            ListNode* current = head;

            reverseLL(head, current, prev);

            return head;
        }
        */

        // Recursive Approach 2:
        ListNode *newHead = solveReverse(head);
        head = newHead;
        return head;
    };
};

/*  Approach Discussion:

1) Reverse a Linked List:
   Iterative Approach:  TC: O(n)
      -- consider one node prev -> null and current points to the next node lets call it forward node.
      -- Use a loop till current is null
         -- update the forward pointer to the next of current pointer.
         -- current pointer points to prev, update prev to current and curent to forward.
      -- update prev as head of the REversed Linked list.

NOTE: Can be solved using Recursion also and loop too.

   Recursive Approach 1:
      -- same logic just use Recursion, base case , if curr is null -> head is prev and return.
      -- forward stores the current's next node.
      -- call Recursion, [ASsume rest of the part is already reversed.] NOTE: Take care of params you pass here.
      -- Now, break the link between current and forward and point it to prev.

   Recursive Approach 2:
      -- This approach uses just the head pointer.
      -- Use Recursion to go till the end of the List, now get the latest head as the last node of the list.
      -- update the head as head->next->next, that is update the the node infornt of head points to head.
      -- Update the had points to NUll.



*/