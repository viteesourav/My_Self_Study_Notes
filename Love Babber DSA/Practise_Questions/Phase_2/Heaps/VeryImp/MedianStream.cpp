// Link: https://www.codingninjas.com/studio/problems/median-in-a-stream_975268
/*
Basically, You receiving a stream of inputs... You need to Find the median Of the stream each time a new Character added.
*/
#include <bits/stdc++.h>
using namespace std;

// Signum Function...
int signumFun(int num1, int num2)
{
    if (num1 == num2)
        return 0;
    else if (num1 > num2)
        return 1;
    else if (num1 < num2)
        return -1;
}

// Function To Find the Median of the Stream when currElement is added...
int findMedian(int element, priority_queue<int> &maxHeap,
               priority_queue<int, vector<int>, greater<int>> &minHeap, int median)
{

    // First lets pass size of both queues through a signum function...
    int size1 = maxHeap.size();
    int size2 = minHeap.size();

    // switch the Result from the signum Function...
    switch (signumFun(size1, size2))
    {

    case 0: // case when both maxHeap and minHeap are same in size...
        if (element > median)
        { // Element goes to the right part of median i.e minHeap
            minHeap.push(element);
            median = minHeap.top(); // Top will hold the median For the stream...
        }
        else
        {
            maxHeap.push(element);  // Element is < Median, Goes to left part i.e madHeap
            median = maxHeap.top(); // Top will hold the median for the stream...
        }
        break;
    case 1: // Case When the maxHeap size is more then MinHeap...
        if (element > median)
        {
            minHeap.push(element); // This makes both max and min Heap Size equal..
        }
        else
        {
            // Here we cannot push directly in maxHeap, as the size diff will exceed 1.
            // we can shift 1 element from maxHeap to minHeap To make it balance on insertion...
            int carry = maxHeap.top();
            maxHeap.pop();
            minHeap.push(carry);
            // Now push inside the maxHeap...
            maxHeap.push(element); // This make's the size of maxHeap and minHeap same...
        }
        median = (maxHeap.top() + minHeap.top()) / 2; // Avergae of both the top [since same size]
        break;
    // case when maxHeap size is less than minHeap size...
    case -1:
        if (element > median)
        {
            // Here we cannot push directly in minHeap, as the size diff will exceed 1.
            // we can shift 1 element from minHeap to maxHeap To make it balance on insertion...
            int carry = minHeap.top();
            minHeap.pop();
            maxHeap.push(carry);
            // Now push inside the maxHeap...
            minHeap.push(element); // This make's the size of maxHeap and minHeap same...
        }
        else
        {
            maxHeap.push(element); // This makes the size of maxHEap and minHeap same...
        }
        median = (maxHeap.top() + minHeap.top()) / 2; // Avergae of both the top [since same size]
        break;
    }
    return median;
}

// Appraoch: MaxHeap - M - MinHeap Algo
vector<int> findMedian(vector<int> &arr, int n)
{

    vector<int> ans; // To Store the ans...

    // Defining max and minHeap..
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Staring with median of the stream lets be -1.
    int median = -1;

    // Loop over each Element and get the median...
    for (int i = 0; i < arr.size(); i++)
    {
        median = findMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }

    return ans;
}

/*
Approach 1: Use Insertion Sort. [Higher TC, Not Preferred]
    -- Each time a Character is added, Sort it using Insertion Sort. [TC: O(n2)]
    -- Once the Stream is sorted, Then Find the Median.
        -- If the size is odd, then Median at n/2th Index.
        -- If the size is even, then Median is average of  (n/2 - 1)th and n/2 index.

Appraoch 2: use MaxHeap - M - MinHeap [TC: O(nlogn) [Since for each element you inserting in Heap], SC: O(N) [using heaps]]
    -- Before we check the stream, Lets maintaing 2 heaps, MaxHeap and minHeap.
    -- Now a new Input we received in the stream. say X.
    -- We can represent the existing stream like this...
        ................M-1, M, M+1 ................ [Here M is the median of the Stream]
            maxHeap                      minHeap
    -- Left part of M, Can be represented as MaxHeap as M-1 would for Sure is greater than all Elements before it.
    -- M is the median of the whole stream
    -- right part of M, Can be represented as MinHeap as M+1 would for Sure is samller than all Elements after it.

    -- Now lets consider the size of min and max heap, and pass it through a signum function.
       NOTE: signum Fun takes 2 input a and b, and it returns either -1 [If a < b], 0 [If a==b] or 1 [if a > b]

    //Driving Logic here, We have splited the stream in 2 halves -> left side has maxHeap and rightSide has MinHeap.
      -- Now consider situations:
        1) both MaxHeap and MinHeap has size N, then based on if X > M -> push in minHeap OR X < M -> push in maxHeap.
            -- Now the size, MaxHeap -> N+1 and minHeap N OR MaxHeap -> N and minHeap N+1
            -- Either case, The total size of Stream is Odd.
            -- Thus the median im case of Odee is given by the top of either MaxHeap or MinHeap wherever the size is bigger.

        2) maxHeap Size is N and MinHeap size is N-1 [Whole stream is odd Sized]
           1) If x < M
              -- You need to push in maxHeap, but then diff betwenn Max and Min will be more than 1. [Not allowed]
              -- Thus, we take top element for maxHeap and put in MinHeap,
              -- updated size: maxHeap -> N-1 and minHeap -> N
              -- Now add X in minHeap, updated Size is maxHeap -> N and minHeap ->N-1 [Both have same Number of elements]
              -- The Median is given by the top of maxHeap.

            2) If x > M
                -- We can simply push the element in MinHeap.
                -- updated Size: maxHeap -> N and minHeap -> N
                -- The Median is given by average of top of top of both the heaps.

    -- Thus, Process like this For each element in the Stream, And get the Median of the Stream at the moment that Particualr element is added.

    [**DONE**]
*/