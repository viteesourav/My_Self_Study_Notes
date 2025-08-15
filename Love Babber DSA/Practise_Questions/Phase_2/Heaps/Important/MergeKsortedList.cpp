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
    ListNode(int x) : val(x), next(NULL) {}
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
    // Approach: use MinHeap => stores the node in sorted order. 
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Track my answer list...
        ListNode* headNode = new ListNode(-1);
        ListNode* tailNode = headNode;

        // using c++ lambda funtion to define comparator function ==> min heap, so if l1 val > l2 val => it should return true.
        auto cmp = [](ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        };

        // using minHeap => stores the nodes
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> min_heap;

        //push all heads inside the heap...
        for(ListNode* it : lists) {
            if(it != NULL) {
                min_heap.push(it);
            }
        }

        // till heap is empty => pop the top => add in ans => push the next elememt.
        while (!min_heap.empty())
        {
            // 1. Take out the top min Node Info From heap and pop the heap..
            ListNode *minNode = min_heap.top();
            min_heap.pop();

            // 2. Add the new min Node to the mergedList...
            tailNode->next = minNode;
            tailNode = tailNode->next;

            // 3. if next node after minNode exists, push in heap.
            if (minNode->next != NULL)
            {                                    
                min_heap.push(minNode->next);
            }
        }

        return headNode->next;
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