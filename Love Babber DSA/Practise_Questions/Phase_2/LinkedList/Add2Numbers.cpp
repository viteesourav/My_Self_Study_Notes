// Link: https://leetcode.com/problems/add-two-numbers/description/
//  Baiscally,
//  Assume you have given two numbers, digit as LinkedList Nodes, Add the Numbers and Return a new List.
//  NOTE: Here in this question the input numbers Nodes are already reversed, and Answer Nodes are also Reversed.
//       -- If required, additional ReverseList algo can handle to reverse the input List and result Result..[Below Code, reverse is not needed as per the question]

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
    void insertIntoNode(ListNode *&tail, int data)
    {

        ListNode *newNode = new ListNode(data);
        tail->next = newNode;
        tail = newNode;
    }

    // Approach1: Addition using the Carray. TC: O(n) SC: O(1)
    ListNode *solve(ListNode *&l1, ListNode *&l2)
    {

        // we will start recording the result in a resNode..
        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyTail = dummyHead;

        int carry = 0; // starting carry with 0.

        // We will put traverse pointers for both the List...
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;

        // adding values..
        while (temp1 != NULL && temp2 != NULL)
        {
            int res = temp1->val + temp2->val + carry;
            carry = res / 10;
            res = res % 10;
            insertIntoNode(dummyTail, res);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // If l1 has left over Nodes...
        while (temp1 != NULL)
        {
            int res = temp1->val + carry;
            carry = res / 10;
            res = res % 10;
            insertIntoNode(dummyTail, res);
            temp1 = temp1->next;
        }

        // If l2 has left over Nodes...
        while (temp2 != NULL)
        {
            int res = temp2->val + carry;
            carry = res / 10;
            res = res % 10;
            insertIntoNode(dummyTail, res);
            temp2 = temp2->next;
        }

        // handle if the carry is not empty...
        if (carry != 0)
        {
            insertIntoNode(dummyTail, carry);
        }

        // Now By this, we already have formed the new List with the added val...
        if (dummyHead == dummyTail)
            return NULL; // Just check if the new List is empty or not..

        // upating the head of the new list and removing the dummyHead..
        ListNode *head = dummyHead->next;
        delete dummyHead;

        return head;
    };

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // edgeCase..
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        return solve(l1, l2);
    }
};

/*

Appraoch/Logic:  Addition using LinkedList...

C

2   ->  4  ->  3  ->  X
t1

5   ->  6  ->  4  ->  X
t2

7   ->  0  ->  8  -> X


342 + 465 = 807


Approach1:

1. Start a resNode with haed as val -1 [dummy head]
2.
Till either t1 or t2 becomes NULL

  -- Sum carry i.e C, t1 Node and t2 Node
  -- Get the Sum, update the Carry,
  -- Push the unit digit in a new resNode...
3.
Check if t1 has left over Node or t2 has left Over Node..
  -- iterate over them and add carray and push the result in resNode.

5. Check if the carry is zero or not, If not, add it to the resNode.

6. Check if the resNode has only one Node [dummy], return NULL
   else update the head as head->next and delete the dummy head Node.

*/