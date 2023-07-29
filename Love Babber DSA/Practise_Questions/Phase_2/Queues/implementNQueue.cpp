// Link: https://www.codingninjas.com/studio/problems/n-queue-using-array_1170053
/*
    You are given an Array of size N, Implement k queues inside the array. [Make it space efficient]
*/

#include <bits/stdc++.h>
using namespace std;

class NQueue
{
    int *arr;
    int size;
    int *front, *rear, *nextFreespot;
    int freespotIndex;

public:
    NQueue(int n, int s)
    {
        // initializing all the required DS...
        size = s;
        arr = new int[size];
        nextFreespot = new int[size];
        front = new int[n];
        rear = new int[n];
        freespotIndex = 0;

        // putting the elements in front, rear and nextFreespot arr...
        for (int i = 0; i < n; i++)
            front[i] = rear[i] = -1;
        for (int i = 0; i < size; i++)
            nextFreespot[i] = i + 1;
        nextFreespot[size - 1] = -1; // the last element of nextFreespot should have -1 [Array is full condition]
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {

        // first check if the Array is full or not ?
        if (freespotIndex == -1)
            return false;

        // let take the freespot in a index...
        int index = freespotIndex;
        freespotIndex = nextFreespot[index]; // update the freespotIndex;

        // now check is this the first entry for the queue...
        if (front[m - 1] == -1)
        {
            // yes, this is the first entry...
            front[m - 1] = index; // updating the index in front[Q]
        }
        else
        {
            // No, we alrady have entries...
            // Now we need to form a link between the rear for Q and this new index...
            nextFreespot[rear[m - 1]] = index;
        }

        // Now we push val at index and update rear and nextFreespot arr...
        arr[index] = x;
        rear[m - 1] = index;      // updating index in rear[Q]
        nextFreespot[index] = -1; // since, at index, Now the location is occupied.

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {

        // Underflow Condition check...
        if (front[m - 1] == -1)
            return -1; // If front is empty ? Queue is empty...

        // Let hold the front index in a variable...
        int index = front[m - 1];
        int ans = arr[index];

        // lets update front to the next location...
        front[m - 1] = nextFreespot[index];

        // Now we moved the front from index, index become a freespot...
        nextFreespot[index] = freespotIndex;
        freespotIndex = index; // udpate freespot to index.

        return ans;
    }
};

/*
[VVIMP -> Understand steps using dry-run]
Appraoch: [Using the Next freespot concept]
    -- Things we need...
       -- front array of size K [keep track of the front]
       -- back array of size K [keep track of the back]
       -- NextFreespot array of size N [keep track of the location of the next freespot]
       -- FreespotIndex, [Keep track current freespot available]

Push Operation: [at kth Queue]
    -- First check if the Array is Full or not ? [check if FreespotIndex is -1 ? If yes Array is full]
    -- take index from FreespotIndex,
       update the FreespotIndex from nextFreespot[index].
    -- Check if front[k] == -1, [Frist element we are pushing]
        update front[k] = index
    -- If front != -1 [Not the first index]
        -- update the location of the new index, nextFreeSpot[rear[k]] = index;
    -- Push at arr[index].
       -- update rear[k] = index.
       -- update nextFreeSpot[index] = -1 [since at index we pushed the data]   [***Push Operation Done***]

Pop Operration: [at kth Queue]
    -- First check if the Queue is empty ? [front[k] is -1 ? If yes, Array is empty]
    -- get the index from front[k].
    -- Move front[k] to the nextFreespot[index],
    Now, Index became a free space...
    -- nextFreespot[index] should hold the current freespot.
    -- update freespot to index.                                [***Pop Operation DONe***]

*/