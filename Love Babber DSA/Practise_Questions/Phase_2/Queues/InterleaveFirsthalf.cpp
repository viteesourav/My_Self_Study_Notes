// Link: https://www.codingninjas.com/studio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450
/*
Basically, A Queue is given, Now break the queue in 2 equal parts, from left side, Gives the alternate arrangment of elements.
*/

#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    // Appraoch: we will use Queue Appraoch to solve the problem.
    int mid = q.size() / 2;

    // Take a helper Queue..
    queue<int> q1;

    // Pushing the first half inside the new queue...
    for (int i = 0; i < mid; i++)
    {
        q1.push(q.front());
        q.pop();
    }

    // till new Queue is empty, we use loop...
    while (!q1.empty())
    {
        // take front from q1 and push at back of q...
        q.push(q1.front());
        q1.pop();

        // take front from q and push at back of q...
        q.push(q.front());
        q.pop();
    }
}

/*

q -> 10 20 30 40 50 | 60 70 80 90 100

Appraoch1: [Use Queue ][efficient Approach]
    -- Define a new Queue q1.
    -- Push all the elements inside q1 till the mid element.
    i.e q1 -> 10 20 30 40 50
        q -> 60 70 80 90 100
    -- Now till q1 is empty ?
        -> pop q1, push at the back of q.
        -> Then pop q, and push at the back of q.
    [Done]

Appraoch2: [using Stack]

    -- push the first half of the queue in a stack...
        stack -> 10 20 30 40 50.
        q -> 60 70 80 90 100
    -- pop the stack and push at the end of the q.
        q -> 60 70 80 90 100 50 40 30 20 10
    -- Push the second half of the queue inside the stack...
        stack -> 50 40 30 20 10
        q -> 60 70 80 90 100
    -- Now till Stack is empty...
        -> pop from stack, push at q1
        -> pop from q1, push at the back of q1.
    [Done]
*/