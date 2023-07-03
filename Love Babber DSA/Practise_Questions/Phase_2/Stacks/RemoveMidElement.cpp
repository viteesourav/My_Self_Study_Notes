// Link: https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0
// Basically, You given a stack of size N, You need to remove the middle element.

#include <bits/stdc++.h>
using namespace std;

// Appraoch1: we will use Recursion to Hold and traverse till the mid element, remove it..
void solve(stack<int> &s, int size, int count)
{

    // base Case: When we reached till the mid element..
    if (count == size / 2)
    {
        s.pop();
        return;
    }

    // One Case, we will solve, other, Recursion will handle...
    int curr = s.top(); // store the peek element..
    s.pop();            // Removes the element..

    // calling Recursion...
    solve(s, size, count + 1);

    // after removing, lets put tback the elements...
    s.push(curr);
};

void deleteMiddle(stack<int> &inputStack, int N)
{

    // Write your code here
    // Approach: will Try to solve this using Recursion Approach..
    solve(inputStack, N, 0);
}

/*
Approach/Logic: Use Recursion...
    -- Till It reaches the mid element,
       At mid element, pop the mid element and start coming back from recursion.
    -- Take the top element, store it in a variable.
    -- Remove the top, then then call Recursion calls...
    -- While coming back from the calls, Make sure you push the element back to the stack.
*/