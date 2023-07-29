// Link: https://www.codingninjas.com/studio/problems/first-negative-in-every-window_759333?leftPanelTab=0
/*
Basically, you given an array and a window length k.
    Need to give the list of first negative number in each window of k size...
*/

#include <bits/stdc++.h>
using namespace std;

// Approach: we will use dequeue to store the index of negative numbers.
vector<int> firstNegative(vector<int> arr, int n, int k)
{

    deque<int> dq;
    vector<int> ans;

    // First we will try to solve for the first k index...
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            dq.push_back(i);
    }

    // Now based on what dequeue stored, we will get the ans for the first k window..
    if (dq.empty())
        ans.push_back(0);
    else
        ans.push_back(arr[dq.front()]); // fetch the index of first neg from dequeue..

    // Now For next windows of K...
    for (int i = k; i < arr.size(); i++)
    {

        // check if the front index in dequeue moved out of the currenet window ? If yes remove it..
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        if (arr[i] < 0)
            dq.push_back(i); // Push index of neg inside the dq.

        // now as we update the dq, we will update the ans...
        if (dq.empty())
            ans.push_back(0);
        else
            ans.push_back(arr[dq.front()]); // fetch the index of first neg from dequeue..
    }

    return ans;
}

/*
NOTE: [Not a very good approach]
Approach1: Use dequeue [store index of neg elements ] TC: O(n) SC: O(k) [at max size of dequeue can be k]
    -- First solve for the first k elements.
    -- Store the index of the negative numbers in the dequeue.
    -- based on dequeue size() store the ans.

    -- Next for each elements in the array... Start a loop.
    -- check if the front index in dequeue is going out of the window ? If so, pop it out.
    -- check if the curr element is neg, store the index in dequeue.
    -- Use the same logic, based on dequeue size, store the ans.
*/