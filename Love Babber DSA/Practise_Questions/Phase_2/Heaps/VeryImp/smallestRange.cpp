// Link: https://www.codingninjas.com/studio/problems/smallest-range-from-k-sorted-list_1069356
/*
Basically, You given K Arrays. You need to Find the smallest Range Possible Which Holds atleast 1 element from each Array.
eg:
    arr1: 4 7 30           Smallest Range possible: [7, 20], Return the min Range as Ans.
    arr2: 1 2 12
    arr3: 20 40 50
*/

#include <bits/stdc++.h>
using namespace std;

// A Class to handle 3 required variables...
class EleInfo
{
public:
    int val;      // Stores the value at a[arrIndex][eleIndex]
    int eleIndex; // Store the respective index for the element.
    int arrIndex; // Store the respective index of the arr out of k given arrays.

    EleInfo(int val, int eleIndex, int arrIndex)
    {
        this->val = val;
        this->eleIndex = eleIndex;
        this->arrIndex = arrIndex;
    }
};

// A custom Compare Class to sort the Objects in ascending order...
class compare
{
public:
    bool operator()(EleInfo *e1, EleInfo *e2)
    {
        return e1->val > e2->val;
    }
};

// Appraoch: using minHeap and track the diff between min and max element...
int kSorted(vector<vector<int>> &a, int k, int n)
{

    int minDiff = INT_MAX;
    int maxi = INT_MIN;

    // Lets define a min_heap to Store the Values...
    priority_queue<EleInfo *, vector<EleInfo *>, compare> min_heap;

    // 1. lets first create EleInfo for all first element for all K arrays and push it...
    for (int i = 0; i < k; i++)
    {
        maxi = max(maxi, a[i][0]);
        EleInfo *info = new EleInfo(a[i][0], 0, i); //(elementValue, elementIndex, arrIndex)
        min_heap.push(info);
    }

    // 2. Now lets loopp till the heap becomes empty..
    while (!min_heap.empty())
    {
        // Take out the top element from the heap and pop it...
        EleInfo *miniElement = min_heap.top();
        min_heap.pop();

        // Now copare the diff between the min and max with minDiff, If less update it...
        //  cout<<minDiff<<" "<<miniElement->val<<" "<<maxi<<endl;
        minDiff = min(minDiff, ((maxi - miniElement->val) + 1)); //+1 because if Range is [2, 5], range including 2: 5-2+1 -> 4

        // Now we push the next element from the same array and update our maxi too..
        // NOTE: Push only if the next element Index is less than arr's size..
        if (miniElement->eleIndex + 1 < n)
        {
            int nextElement = a[miniElement->arrIndex][miniElement->eleIndex + 1];
            maxi = max(maxi, nextElement);
            EleInfo *newElement = new EleInfo(nextElement, miniElement->eleIndex + 1, miniElement->arrIndex);
            min_heap.push(newElement);
        }
        else
        {
            // If the index of any array reached the end, We are done processing..
            break;
        }
    }

    return minDiff;
}

/*
Appraoch:
    -- Lets Store the first Element of each Array in a min_heap. [Smallest Element on the top]
    -- Now till the heap is empty,
        -- Take out the smallest Element and the maxElement among the Elements present in the min_heap.
            [minElement -> top of the P_Queue, maxElement -> While inserting keep Track]
        -- Now comapre the diff between them and already stored max and min, If less store it.
        -- Pop the smallest Elemtn and push the next Element from the Same Array.

    -- At the End when min_heap empty, You left out with the smallest Possible Range. [**DONE**]

NOTE:
    We need to pop the top of P_Queue and push the next Element form the same array. To track the value, Elementindex and ArrIndex,
    we can create a class to hold this 3 required Values, Use is Class's Object as DataType stored in Queue also.

*/