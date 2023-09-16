// Link: https://leetcode.com/problems/merge-k-sorted-lists/
/*
Given are K sorted List, We need to merge them into a single sorted List.
*/
// A custom Comparator Class theat helps me sort the Heads based on it's Respective Values...
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

// A custom Comparator Class theat helps me sort the Heads based on it's Respective Values...
class compare
{
public:
    bool operator()(ListNode *head1, ListNode *head2)
    {
        return head1->val > head2->val;
    }
};

class Solution
{
public:
    // Approach: A MinHeap that takes Node by Node and gradually Sort it...
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *mergedListHead = NULL; // Something to store my newMergedListHead...
        ListNode *mergedListTail = NULL;

        // A MinHeap who stores the Nodes Form the LinkedList a Node will be stored...
        priority_queue<ListNode *, vector<ListNode *>, compare> min_heap;

        // Now lets put the head of all the K Lists into the heap...
        // NOTE: Here lists[0] i.e head of first list, lists[1] i.e head of second List and so on...
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
            { // Push in heap only if the lists[i] has some Nodes...
                min_heap.push(lists[i]);
            }
        }

        // Lets process the minHead, pop the queue, insert the next Node...
        while (!min_heap.empty())
        {
            // 1. Take out the top min Node Info From heap and pop the heap..
            ListNode *minNode = min_heap.top();
            min_heap.pop();

            // 2. Add the new min Node to the mergedList...
            if (mergedListHead == NULL && mergedListTail == NULL)
            {
                // First Node we are about to insert...
                mergedListHead = minNode;
                mergedListTail = minNode;
            }
            else
            {
                // we are adding a new Node at the end...
                mergedListTail->next = minNode;
                mergedListTail = minNode;
            }

            // 3. Now put the next node of the minNode inside the heap..
            if (minNode->next != NULL)
            {                                      // Check if the nextNode exist for the minNode..
                ListNode *newHead = minNode->next; // updating the head of the List...
                min_heap.push(newHead);            // pushing the newHead into the queue..
            }
        }

        return mergedListHead;
    }
};

/*
Approach1: Nive Appraoch TC: O(knlogkn) SC: O(kn) [since using a additional vector to Store Nodes Val]
    -- Iterate all the k Linked List and store there respective values into a vector.
    -- Sort the vector. [use Sorting Algorting]
    -- From the sorted Data create a new Linked List.

[**DONE**]

Appraoch2: use the minHeap. TC: O(klogk) SC: O(nk)
    -- Lets first push the first head of all K LinkedList into the minHeap.
    -- Start a loop till heap is empty:
        -- Take out the top head from the heap and store in create a new Linked List with this head as newMergedHead
        -- Now, For whichever List you taking the top element from, take the next Node in that List and push in the heap.
        NOTE: push only if the nextNode exist.
    -- The newHead will have the sorted List.

NOTE: For the Queue where we will pop, we need to push the next Node from the same List.
    -- No Need for maintaing any pair, since we know the postion of the nextNode based on the currNode using next pointer..

*/