// link: https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379
/*
You given K sorted Array. Merge them into a single sorted Array..
*/

#include <bits/stdc++.h>
using namespace std;

// A Compare Class to handle the Comparison based on first element of the pairs...
class compare
{
public:
    // Oveririding the operator method...
    bool operator()(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
    {
        return p1.first > p2.first; // If p1.first is big it will go to end, else it will go to front...
    }
};

// Appraoch: using minHeap and Array pairs.
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{

    vector<int> ans;

    // Lets take a min_heap to store pair<element, <element Position, ArrayIndex>>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> min_heap;

    // Now lets first store the first element of all the k Arrays into heap...
    for (int i = 0; i < k; i++)
    {
        min_heap.push(make_pair(kArrays[i][0], make_pair(0, i))); // It will pick ith Row and push the First element...
    }

    // We start a while loop...
    while (!min_heap.empty())
    {
        // take out the top of the heap[min element], push the value in the ans, pop it and push the next element...
        int minElement = min_heap.top().first;

        pair<int, int> elementInfo = min_heap.top().second;
        int elementIndex = elementInfo.first;
        int arrIndex = elementInfo.second;

        // cout<<minElement<<" "<< elementIndex << " "<< arrIndex<<endl;

        ans.push_back(minElement); // Push the min Element into the ans Array...
        min_heap.pop();            // Pop the top from the heap..

        // check if we have element left in the arr at arrIndex....
        if (elementIndex < kArrays[arrIndex].size() - 1)
        {
            // Push the new Element into the heap, <newElementVal, <newElementpos, arrindex>>
            min_heap.push(make_pair(
                kArrays[arrIndex][elementIndex + 1],
                make_pair(elementIndex + 1, arrIndex)));
        }
    }

    return ans;
}

/*
Approach1: Nive Appraoch [TC: O(kNlogn) SC: O(kn2)]
    -- Iterate all the elements from all the elements and put it in a new Array.
    -- Now simply sort the whole arr.
[**DONE**]

Appraoch2: use the minHeap. TC: O(n*klogk) SC: O(K) + O(nk)
    -- Lets first push the first elements of all K elements into the minHeap.
    -- Start a loop till heap is empty:
        -- Take out the top element from the heap and store in ans.
        -- Now, For which ever array you taking the top element from, take the next Element in that array and push in the heap.
        NOTE: push only if the next Element exist.
    -- The ans will have the sorted List.

NOTE: For the Queue where we will pop, we need to push the next element from the same Array.
    -- We can maintain a pair for element and array index. It help us to identify For which array the next element i need to push.

*/