// Link: https://leetcode.com/problems/sort-list/description/
/*Biscally, You given an unsorted List, And you need to Sort it....
NOTE:
Mostly in Linked List Case we use merge Sort to sort the list.
    Reason: Random Access of Node takes O(n) in Linked List and Arrays it is O(1). Insertion is faster in Linked List.
    BY logic, merge sort involves, breaking the List, sort both halves and merge it, Thus, mergeSort is faster...
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
private:
    // Function to find the mid of the List...
    ListNode *findMidNode(ListNode *&head)
    {

        // using fast and slow pointer approach to find the mid...
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow will be at the mid ListNode...
        return slow;
    }

    // Function to merge 2 sorted List...
    ListNode *sortList(ListNode *&leftHead, ListNode *&rightHead)
    {

        // edge condition: See if either left or right half is NULL ?
        if (leftHead == NULL)
            return rightHead;
        if (rightHead == NULL)
            return leftHead;

        // Now we will create a new Sorted List...
        ListNode *dummyHead = new ListNode(-1);
        ListNode *newTail = dummyHead;

        ListNode *temp1 = leftHead;
        ListNode *temp2 = rightHead;

        // traverse both the List and compare and add Nodes in sorted List...
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val <= temp2->val)
            {
                // inserting temp1 Node...
                newTail->next = temp1;
                newTail = newTail->next;
                temp1 = temp1->next;
                newTail->next = NULL;
            }
            else
            {
                // inserting temp2 Node...
                newTail->next = temp2;
                newTail = newTail->next;
                temp2 = temp2->next;
                newTail->next = NULL;
            }
        }

        // check if we completly traversed both the List or not ?
        if (temp1 != NULL)
        {
            // Fews Nodes Left in LeftList to traverse....
            newTail->next = temp1;
        }
        if (temp2 != NULL)
        {
            // Fews Nodes Left in rightList to traverse....
            newTail->next = temp2;
        }

        // Now we have merged our List, let's update our head...
        ListNode *newHead = dummyHead->next;
        delete dummyHead;

        return newHead;
    };

    // Approach2: Recursive way to merge 2 sorted List.[Works faster than approach 1]
    ListNode *sortList2(ListNode *&leftHead, ListNode *&rightHead)
    {

        // edgeCase...
        if (leftHead == NULL)
            return rightHead;
        if (rightHead == NULL)
            return leftHead;

        // Let's solve the comparison of just first Node of both Lists, Rest Recursion will do
        ListNode *newList = NULL;
        if (leftHead->val <= rightHead->val)
        {
            // leftHead NOde is smaller...
            newList = leftHead;
            newList->next = sortList2(leftHead->next, rightHead); // Fetch the next Node[Recursion]
        }
        else
        {
            // rightHead Node is smaller...
            newList = rightHead;
            newList->next = sortList2(leftHead, rightHead->next); // Fetch the next Node[Recursion]
        }

        // Now returing the sortedList...
        return newList;
    };

    // Appraoch1: MergeSort, Break the Lsit from mid, Sort Left and Right halves, merge them
    ListNode *mergeSort(ListNode *&head)
    {
        // This is a recursive function, That breaks, sort and merges the List...
        // Base Case:
        if (head == NULL || head->next == NULL)
            return head;

        // Now let's Find the mid of the List...
        ListNode *midNode = findMidNode(head);

        // break the List into 2 halves...
        ListNode *leftHead = head;
        ListNode *rightHead = midNode->next;
        midNode->next = NULL; // This makes sure, Left and Right Nodes are not Linked..

        // Now call Recursion and Assume your left and Right is sorted...
        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);

        // Now we have 2 sorted List, so we will try to merge it into One...
        head = sortList2(leftHead, rightHead);

        return head;
    };

public:
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};

/*
Approach/Logic:

Merge Sort with Linked List

H
4 -> 2 -> 1 -> 3 -> X

Approach1: Same Logic as Array, Break it from mid and then merge it [TC: O(nlogn) SC: O(logn)]

-- First Find the Mid of the List.[Use Fast and Slow Pointer]

-- Then Make 2 Lists, LeftList and RightList from Mid

-- Call sort Recursively, This will sort both the halves...

-- Then Merge the 2 Sorted List into one List. [!! List Sorted !!]


H    M
4 -> 2 -> 1 -> 3 -> X
     s         f

LH             RH
4 -> 2 -> X     1 -> 3 -> X


Recursion will sort Left and Right Halves...[we assume this]

LH              RH
2 -> 4 -> X      1 -> 3 -> X
t1               t2

Now merge this 2 sorted List into one sorted List....
[Merge 2 sorted List Approach]

1 -> 2 -> 3 -> 4 -> X


*/