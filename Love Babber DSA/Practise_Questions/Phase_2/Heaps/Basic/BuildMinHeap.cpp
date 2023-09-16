// Link: https://www.codingninjas.com/studio/problems/build-min-heap_1171167?leftPanelTab=0
/*
    Basically you given an array, build a min heap out of it. [TC: O(N): building heap + heapify]
*/

#include <bits/stdc++.h>
using namespace std;

// Heafiy appraoch: [Take the Node and place it at it's correct post]
void heafiy(vector<int> &arr, int size, int index)
{

    // First take the index and find its children's index...
    int i = index;
    int child1 = 2 * i + 1;
    int child2 = 2 * i + 2;

    // Now lets check if node at index is proper or we need to change ?
    if (child1 < size && arr[i] > arr[child1])
        i = child1;
    if (child2 < size && arr[i] > arr[child2])
        i = child2;

    // Now check if we need to swap or not ?
    if (i != index)
    {
        swap(arr[index], arr[i]);
        heafiy(arr, size, i); // calling heafiy to further check down the tree...
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Appraoch: We will use build heap + heapify...
    // NOTE: For zero-based index...
    // From n/2 to n-1 index elements are at the leaf Node, we will ignore them...
    int n = arr.size();
    for (int index = (n / 2) - 1; index >= 0; index--)
    {
        heafiy(arr, n, index); // This post the node at index at it's correct place..
    }

    return arr;
}

/*
Appraoch:
    -- Since it's a 0-based index...
    -- All Elements from n/2 to n-1 are already heap as they are leaf Nodes...
    -- put a loop to from n/2-1 to 0:
        -- For each Node call headfiy.

** heapify Algo:
    -- Take the current Node's index in i.
    -- find the leftchild index: 2i [For 1-based index] or 2i+1 [for 0-based index]
    -- find the rightchild index: 2i+1 [for 1-based index] or 2i+2 [for 0-based index]

    Now check if we need to swap the leftChild or rightChild ?
        If minHeap: the parent should be less than the children
        If maxHeap: the parent should be greater then the children.

    If needed to swap:
        -- Just swap them and again call heapify to further check for heap down the tree...

[** DONE **]
*/