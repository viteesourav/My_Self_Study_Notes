// Link: https://leetcode.com/problems/palindrome-linked-list/
//  Check if the Given Linked List is palindrom or not...

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
private:
    // Approach1: We will use array to store the Nodes and then check palindrom.
    // TC:O(n) SC:O(n)
    bool solveApproach1(ListNode *&head)
    {

        // defining an array to store Node Values..
        vector<int> arr;

        // traverse List to copy Node val..
        ListNode *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Now we have the list we can check Palindrom or not ?
        int start = 0, end = arr.size() - 1;
        while (start < end)
        {
            if (arr[start] != arr[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    };

    // Approach2: We will Find mid, Reverse the List ahead of mid and then compare..
    // TC: O(n) SC: O(1)

    // To find the mid of the List using slow and fast pointers...
    ListNode *findMidNode(ListNode *&head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        // Traverse the List to Find th mid element....
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
                fast = fast->next;
            else
                break;
            slow = slow->next;
        }
        // slow pointer will be the mid node..
        return slow;
    };

    // Revesing the List and returning the new head...
    ListNode *reverseNode(ListNode *&head)
    {

        // check for edge cases...
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;

        // Traversing and Reversing the Links between the Nodes...
        while (curr != NULL)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev; // This will point to the new Head..
    }

    bool solveApproach2(ListNode *&head)
    {

        // step1: Find the mid of the List...
        ListNode *mid = findMidNode(head);

        // step2: Reverse the List ahead of mid and attach the reversed List to mid Node
        mid->next = reverseNode(mid->next);

        // step2: Now Traverse in both half and compare value Node by Node...
        ListNode *temp1 = head;
        ListNode *temp2 = mid->next;

        // traversing both the halves checking Node values for palindrom..
        while (temp2 != NULL)
        {
            if (temp1->val != temp2->val)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Step4: [Optional Step], Reverse the List again ahead of mid to bring back the Original List...
        mid->next = reverseNode(mid->next);

        return true;
    };

public:
    bool isPalindrome(ListNode *head)
    {

        // Checking the edge case First...
        if (head == NULL || head->next == NULL)
            return true;
        // return solveApproach1(head);
        return solveApproach2(head);
    }
};

/*

Approach/Logic:

Palindrom Linked List

H
1 -> 2 -> 2 -> 1

Appraoch1: TC: O(n) SC: O(n)

  -- Make a new array, Store all Nodes value in the Array.
  -- In the Array compare and state if palindrom or not ?

Appraoch2: TC: O(n) SC: O(1)

  -- Find the mid Node. [use slow & fast pointer Concept]
  -- Reverse List after the mid Node.
  -- Comapare both the halfs. -> Decide if palindrom or NOT ?
  -- REverse the part in step 2, to get the Original List back.



Use slow and fast pointer to Find Mid....

H         M    T         H2
1 -> 2 -> 3  X <- 3 <- 2 <- 1 -> X
                       P    C    N

LL after Reversal part:
H         M    H2
1 -> 2 -> 3 -> 1 -> 2 -> 3 -> X
t1             t2

Check if palindrom ?

Do the Reverse again for List after mid to get back the Original List.. [Optional]

*/