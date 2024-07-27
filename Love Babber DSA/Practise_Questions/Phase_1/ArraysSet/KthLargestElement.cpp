// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
/*
problem:
    You have a arr given [unsorted, may contains duplicates], You need to find the kth max element.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // lets solve using max heap [using priority_queue]...
        priority_queue<int> max_heap;

        // push all elements in the max-heap...
        for (auto it : nums)
        {
            max_heap.push(it);
        }

        // Now to find the kth max elements --> pop from max_heap k times..
        int i = 1;
        while (i < k)
        {
            max_heap.pop();
            i++;
        }

        return max_heap.top(); // The top in the max_heap will hold ans..
    }
};

// TC: O(nlogn) + O(k-1*logn) ==> O(nlogn), SC: O(n)
/*
    Logic: use maxHeap..
        -- Store all the elements in the maxHeap.
        -- pop it k-1 times.. --> this gives the kth maxElement.
*/