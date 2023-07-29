// Link: https://www.codingninjas.com/studio/problems/reverse-first-k-elements-of-queue_982771?leftPanelTab=0
/*
Given a Queue, and k, Reverse first k elements and keep the rest of the order intact.
*/

#include <bits/stdc++.h>
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    // Approach 1: use Stack with size k SC: O(K) TC: O(N)
    stack<int> st;
    queue<int> ans;

    // travers the queue till k, pop and store in stack...
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // while stack is empty pop and store it in the ans..
    while (!st.empty())
    {
        ans.push(st.top());
        st.pop();
    }

    // While the queue is not empty, push in the queue..
    while (!q.empty())
    {
        ans.push(q.front());
        q.pop();
    }
    return ans;
}

/*
Appraoch: Use Stack TC: O(n) SC: O(k)

    -- First K elements pop it from the queue and store it in stack.
    -- pop from stack, store it in ans Queue.
    -- pop rest of the ele from Queue, store it in ans queue.


*/