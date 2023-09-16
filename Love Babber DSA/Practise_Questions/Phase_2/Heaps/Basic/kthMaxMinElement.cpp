// Link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

/*
Basically, You given an Array, You need to Find out without using any sorting algo
    1) Who is the smallest kth element.
    2) Who is the largest kth element.
*/
#include <bits/stdc++.h>
using namespace std;

// Approach: First k element's maxHeap and then remaining if min found, pop and push
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> max_heap;

    int index;

    // push the first k elements into the maxHeap...
    for (index = 0; index < k; index++)
        max_heap.push(arr[index]);

    // Now iterate remaining elements...
    while (index <= r)
    {
        // If any small element found, pop the heap and push this element.
        if (arr[index] < max_heap.top())
        {
            max_heap.pop();
            max_heap.push(arr[index]);
        }
        index++;
    }

    return max_heap.top(); // top will hold the kth min element.
}

// Appraoch: Using Min Heap to Find the kth Largest Element. TC: O(N) SC: O(N)
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Push the first k elements in the min_heap...
    int index = 0;
    while (index < k)
    {
        min_heap.push(nums[index]);
        index++;
    }

    // Now iterate the remaning elements in the arr..
    while (index < nums.size())
    {
        // If any element is greater, pop and push it in the queue...
        if (nums[index] > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(nums[index]);
        }
        index++;
    }
    return min_heap.top();
}

/*

Idea:
   -> P_Queue will mainting the top max/min Element in the queue.
   -> In case of kth Largest, You just pushing the Kth max inside the queue to top, by poping from queue and pushing max elements.
   -> In case of kth samllest, You just pushing the Kth min inside the queue to top, by poping from queue and pushing min elements.

Approach: Using Heap,
1) Kth Smallest Element: TC: O(N) SC:O(N)
    -- Use a max priority_queue. [Always stores the max Element on top]
    -- First k Element push in the queue. [Now you now who is max in the first k Elements]
    -- Iterate the remaining elements, If any element is smaller than the top
        -- Pop the top, push the element.
        -- P_Queue will rearrange and find the max element in it.
    -- Once all Elements we cover,
        The P_queue top will have the kth smallest element.

2) Kth largest Element: TC: O(N) SC: O(N)
    -- use a min Priority_queue. [Always Store the min value at the top]
    -- Fisrt k Elements lets push in the queue. [Top of the Queue holds the min most Element]
    -- Iteerate the remaining elements, If any element is greater then top
        -- pop the the top and push the element.
    -- Once all eLEmeents are pushed,
        The top will give the kth largest element.

*/