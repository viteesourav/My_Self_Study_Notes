// Link: https://www.codingninjas.com/studio/problems/connect-n-ropes-with-minimum-cost_630476
/*
    You given lengths of Rope. The cost of connecting 2 Ropes is sum of their length.
    Find the min Cost of connecting them ?
*/

#include <bits/stdc++.h>
using namespace std;

// Approach: MinHeap
long long connectRopes(int *arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    long long totCost = 0;

    // Push all lengths of Ropes inside the p_queue...
    for (int i = 0; i < n; i++)
        min_heap.push(arr[i]);

    // Now lets loop till we have heap size 1
    while (min_heap.size() > 1)
    {
        // taking out the first 2 min element...
        long long len1 = min_heap.top();
        min_heap.pop();
        long long len2 = min_heap.top();
        min_heap.pop();

        // Stroing the sum in the totCose...
        totCost += len1 + len2;

        // Pushing the sum in the P_queue...
        min_heap.push(len1 + len2);
    }
    return totCost;
}

/*
Approach: use MinHeap
    -- Store everything in MinHeap.
    -- Now run a loop till only 1 element left in the heap.
        -- Take out the top 2 lengths [min heap so, it would first 2 smallest length]
        -- Add them and push it back to the heap.
        -- Keep a track of the cost also.
    -- When only 1 element left in the heap, add that to cost.

[**DONE**]

*/