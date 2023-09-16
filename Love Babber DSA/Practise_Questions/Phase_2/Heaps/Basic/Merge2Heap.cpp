// Link: https://www.codingninjas.com/studio/problems/merge-two-binary-max-heaps_1170049
/*
Baically you given 2 heaps: heap1 and heap2, Merge both the heaps
*/

#include <bits/stdc++.h>
using namespace std;

// Heafiy Algo: Build a heap...[Recursion]
void heapify(vector<int> &arr, int size, int currIndex)
{

    int largest = currIndex;
    // For zero-based index...
    int leftChild = 2 * currIndex + 1;  // for left Child
    int rightChild = 2 * currIndex + 2; // for right Child

    // Check for the heap Condition..
    if (leftChild < size && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild < size && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    // If the largest is updated then swap and call heapify...
    if (largest != currIndex)
    {
        swap(arr[largest], arr[currIndex]);
        heapify(arr, size, largest);
    }
}

// Approach: combine vectors + heapify
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2)
{

    vector<int> arr3;

    // combine arr1 and arr2 in arr3...
    for (auto i : arr1)
        arr3.push_back(i);
    for (auto i : arr2)
        arr3.push_back(i);

    // Now we have an new List of elements, lets build a Heap..
    int size = arr3.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr3, size, i);
    }

    // Return the new heap..
    return arr3;
}

/*
Appraoch: Combine the vectors + heapify them.
    -- Combine vecotrs for heap1 and heap 2 into a single vector.
    -- Use that vector to Build a new heap [use Heapify algo]
*/