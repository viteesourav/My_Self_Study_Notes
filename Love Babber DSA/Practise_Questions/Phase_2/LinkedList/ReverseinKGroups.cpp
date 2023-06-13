// This is for Reversing a Linked List in Group of K Nodes.
/*
    If k = 2,
    3 -> 4 -> 5 -> 6 -> 7 -> 8   ------------>   4 -> 3 -> 5 -> 6 -> 8 -> 7 [Output]
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
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // Approaches: Recursive Approach....
        // base case:
        if (head == NULL)
            return head; // If no Node Exists...

        // Check if we have K Nodes to Reverse or not, If not Just return the current head...
        int cnt = 0;
        ListNode *temp = head;
        while (cnt < k)
        {
            if (temp == NULL)
            {
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        // Only One Case we will solve, rest Recursion will take care...
        // case: Reverse the first K-groups Of Nodes using Iterative manner.
        ListNode *prev = NULL;
        ListNode *current = head;
        cnt = 0;

        // Iterate till k Nodes and Reverse the Linkage...
        //[This is same as Reverse of Single Linked List- Iterative method]
        while (current != NULL && cnt < k)
        {
            ListNode *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            cnt++;
        }

        // update the head Node Linkage to the head Node Returned by the Recursive solution...
        if (current != NULL)
        { // Check if the current Node Exists
            head->next = reverseKGroup(current, k);
        }

        // update the head of the Reversed Node to prev and return the head...
        head = prev;
        return head;
    }
};

/* Approach Discussion:
    TC -> O(n) [All Nodes are Vistied Just once] and
    SC -> O(n/k) [If each fun takes some constant Space P to Reverse K noded, then For n Nodes it will take n/k space] i.e O(n)

    -- We will solve this Question using Recursion.[EK Case Solve karenge, Rest part we assume recursion already Solved it !!!]

    Step 1: Base Case
    -- If the head is null i.e no Node is present then return head.
    -- If the Node Count is less than k, Then no need to reverse the nodes i.e return the current head.
       This Condition we need to take care of.

    Step 2: Solve the First case of Reversing first k nodes using Recursion.
        -- using prev, current node pointer reverse the connection of first K nodes.
        -- One this step is Done, prev will be at the new head poistion, current will be pointing to the node of the next k group.
        eg: if k = 2
           head prev current
            3 <- 4  [ 5 -> 6 -> 7 -> 8 ]
                     This part Recursion will solve.

    Step 3:
        -- Check if Current Exists then the head should point to the current i.e head that came as a result of recusrion.
        i.e head->next = fn(current, k);  [recursion will give me the head after the recursion process is done for the remaining part]
        -- Now we need to update the prev as head and return the new head.
      newhead
        4 -> 3 -> [6 -> 5 -> 8 -> 7]
       prev oldhead    This part Recursion solved
*/