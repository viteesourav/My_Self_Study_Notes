// This Class shows the implementation of Cyclic Queue using Array.
/*
Operations shown:
    1) Enqueue
        -- check if the Queue is Full ?
    For Updating the rear, check these conditions....
        -- Check if you inserting the first element.
        -- Check if you reached the cyclic condition..
        -- Normal Push Operation
    Push the element at rear

    2) Dequeue
        -- check if the Queu is empty ?
        -- Take the front element to return.
    For updating the fornt, check the conditions
        -- If single element, pop, then reset front and rear to intial value.
        -- Check if the cyclic pattern is reached.
        -- Noraml Pop Operation
    retunr the front element.
*/

#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int size;
    int front, rear;

    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1; // intializing my counter...
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        // Check if the Array is Full ?
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
            return false;
        if (front == -1)
        { // check if we are inserting the first element ?
            front = rear = 0;
        }
        else if ((front != 0) && (rear == size - 1))
        { // Cyclic condition...
            rear = 0;
        }
        else
            rear++; // normal insertion...

        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // check if the arr is empty ?
        if (front == -1)
            return -1;

        // Get the element at front.
        int ans = arr[front];

        // check if single element is left...
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1) // Cyclic condition..
            front = 0;
        else
            front++; // Noraml poping...
        return ans;
    }
};