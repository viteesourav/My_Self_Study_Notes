// Link: https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271
/* Given:
    A size of Array S, and number of Stacks N, we need to implement N stacks inside it.
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
class NStack
{
    int *arr;
    int *topIndex;
    int *nextFreeSpace;
    int size, stackCnt, freeSpotIndex;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        size = S;
        stackCnt = N;

        // This are the 3 addiitonal space we will use...
        arr = new int[size];           // array to store the data
        topIndex = new int[stackCnt];  // topIndex to keep track of the index of the top for stacks
        nextFreeSpace = new int[size]; // This keeps track of the next availble space or Previous top index for the values stored in arr

        // Initializing the topIndex with all index as -1 as stack is empty
        for (int i = 0; i < stackCnt; i++)
            topIndex[i] = -1;

        // Intializing the nextFreeSpace array with the immediate right index.[for LAst index its -1]
        for (int i = 0; i < size; i++)
            nextFreeSpace[i] = i + 1;
        nextFreeSpace[size - 1] = -1;

        // Initialize the freeSpotIndex with first index..
        freeSpotIndex = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // First check if the stack is overflowed or not ? [See if freeSpot is available or not]
        if (freeSpotIndex == -1)
            return false;

        // 1. First fetch the index for the available free space, and update it to the next Index.
        int index = freeSpotIndex;
        freeSpotIndex = nextFreeSpace[index]; // nextFreeSpace stores the next available free space index.

        // 2. Pushing the data at the index...
        arr[index] = x;

        // 3. Now the data is pushed, we will update the nextFreeSpace for index to Prev top Index val i.e the val in topIndex at mth-1.
        nextFreeSpace[index] = topIndex[m - 1];

        // 4. Now we will update the topIndex with the index value..
        topIndex[m - 1] = index; // This keeps track, What is the top index for mth Stack

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // The Logic for pop is same Step, But in Reverse..

        // Check if the mth stack is empty [check the topIndex is -1 ?]
        if (topIndex[m - 1] == -1)
            return -1;

        // 1. Take the index value from the topIndex for the mth Stack
        int index = topIndex[m - 1];

        // 2. Update the nextFreeSpace for index, based on the topIndex's index value for mth stack
        topIndex[m - 1] = nextFreeSpace[index]; // Here, nextFreeSpace has the prev top Index, that we will update in top Index.

        // 3. update the nextfreeSpot at index, same as the current freeSpotIndex
        nextFreeSpace[index] = freeSpotIndex;

        // 3. Now update the freeSpotIndex, as the current index should be free...
        freeSpotIndex = index;

        return arr[index]; // The element at index is popped.
    }
};

/* Approach/Logic:

Approach 1: [Space Division Method]

-- Divide the whole Array in S/N parts, then each stack takes each S/N parts.

Problem: Not Space efficient at all.
  -- If space of one stack is fulled, It cannot push further even if there is space.

[Not prefered]

Approach 2: [Using Helping Arrays for tops, nextFreeSpot Appraoch]

TC: O(1) SC: O(N+S) where, N is no of Stacks and S is size of arr.

-- For This appraoch, Intialize logic with
   1) take topIndex array[size is same as number of stack], initialize all by -1. [stack is empty in begining]
   2) take nextFreeSpace[size same as given array], Put the next Free space availble for the current Index. NOTE: For last index, store -1.
   3) freeSpotIndex, initialize with 0.

** Steps to insert into Stack, -> push(val, stackIndex)

   1) Get an index, that takes the freeSpotIndex, Update the freeSpotIndex with the val stored in the nextFreeSpace for the current index.
   2) Store the value in the array, at the index.
   3) Now we pushed the data, we need to update the NextFreeSpace for index to the previous top index. [Take it from topIndex[stackIndex]]
   4) Now since we pushed the Data, we will update top[stackIndex] with index Value.

[DONE]


** For poping out of the Array...
 -- Reverse the logic of pushing in the Array.
 -- Same steps just follow from down to top. It will remove the element from stack.

[DONE]

*/