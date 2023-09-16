// Link: https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398
/*
So You have a Array and k value. Need to find the kth largest Sum SubArray.
    Find all the Sum Combinations of the Elements of Array. Then There respective Sum.
    Return the kth largest Sum for those subArrays.
*/

#include <bits/stdc++.h>
using namespace std;

// Use minHeap to find the kth Max element in arr....
int findKthLargest(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> min_heap;
    int index = 0;
    // lets push the first k elements into a minHeap...
    while (index < k)
    {
        min_heap.push(arr[index]);
        index++;
    }

    // Now lets process the remaining elements...
    while (index < arr.size())
    {
        if (arr[index] > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(arr[index]);
        }
        index++;
    }

    // The top will holds the kth largest element...
    return min_heap.top();
}

// Approach: Find All Sums For subArrays and find kth largest Sum..
int getKthLargest(vector<int> &arr, int k)
{

    vector<int> sumList;

    // First we need to iterate the arr, find Sums for all the sub-Arrays...
    // Appraoch: 2-nested Loops and 2 pointers... TC: O(n2)
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            sumList.push_back(sum);
        }
    }

    // Now we have the sumList for all Sub-arrays...
    // Appraoch1: use Sort algo...
    //  sort(sumList.begin(), sumList.end());
    //  return sumList[sumList.size()-k]; //It will bring the Kth index from the last...

    // Approach2: we can use minheap to find kth max Element from the array...
    return findKthLargest(sumList, k);
}

/*
Logic:
    -- So first you use 2 loop- 2-pointer method For making a list of all possible Sums for all subArrays. TC: O(n2)
    -- Store the sums in an array.
    -- Now 2 Options to Find the kth largest Sum

       1) use Sort [TC:O(nlogn) SC: O(n2) [Worst case]]
          -- Sort the whole thing using sorting algo and then pick the kth element from end.

       2) use minHeap [TC: O(n logn) SC: O(K)] [Better approach, It uses Less Space]
          -- First push all elements till k into the minHeap.
          -- iterate the remainign elements, If any element > heap's top
             -- pop the top and insert into the heap.
          -- At the end, Top will give you the kth largest element.
*/