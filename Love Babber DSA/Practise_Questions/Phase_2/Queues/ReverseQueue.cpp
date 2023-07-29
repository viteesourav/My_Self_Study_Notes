// Link: https://www.codingninjas.com/studio/problems/reversing-queue_1170046?leftPanelTab=0
/*
    Basically, You have a queue, Reverse the Elements.
*/
#include <bits/stdc++.h>
using namespace std;

// Appraoch: Using Recursive Pop and hold tech...
void solve(queue<int> &q)
{

    // Basecase: Till the Queue is empty...
    if (q.empty())
    {
        return;
    }

    // Take out the element from the front and store it.
    int val = q.front();
    q.pop();

    // calling Recursion..
    solve(q);

    // While coming back, push the data that we hold back to queue...
    q.push(val);
}

void reverse(queue<int> &q)
{
    // using Recursion...
    solve(q);
}

/*
Approach1: Use Recursion [TC: O(n) SC: O(1) [No extra dataStructure is used]]
    -- use the Recursion way to hold the data, and then while coming back, push it. [Tail Recursion]
    -- solve one case, Rest assume Recursion already solved it. [Basic approach to Recusion Problems]
*/