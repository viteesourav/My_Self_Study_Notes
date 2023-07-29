// This Class shows the implementation of DoubleEnded Cyclic Queue using Array.
/*
Operations shown:
    1) Pushfront
        -- check if the Queue is Full ?
    For Updating the front, check these conditions....
        -- Check if you inserting the first element.
        -- Check if you reached the cyclic condition..
        -- push Front Operation [take Front 1 step back]
    Push the element at front

    2) Pushback
        -- check if the Queue is Full ?
    For Updating the rear, check these conditions....
        -- Check if you inserting the first element.
        -- Check if you reached the cyclic condition..
        -- Normal Push Operation [take Rear 1 Steap ahead]
    Push the element at rear

    3) PopFront
        -- check if the Queu is empty ?
        -- Take the front element to return.
    For updating the fornt, check the conditions
        -- If single element, pop, then reset front and rear to intial value.
        -- Check if the cyclic pattern is reached.
        -- Noraml Pop Operation [take Front 1 step ahead]
    retunr the front element.

    4) PopBack
        -- check if the Queu is empty ?
        -- Take the rear element to return.
    For updating the rear, check the conditions
        -- If single element, pop, then reset front and rear to intial value.
        -- Check if the cyclic pattern is reached.
        -- Pop Rear Operation [take rear 1 step back]
    retunr the rear element.

    5) Front
    6) back
    7) isEmpty
    8) isFull
*/

#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int size;
    int front, rear;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Check if the Queue is Full ?
        if ((rear + 1) % size == front)
            return false;

        // Inserting the First element in the Array.
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        { // Maintain the cyclic order...
            front = size - 1;
        }
        else
        {
            front--; // Moveing front 1 step back to push new element.
        }

        // pushing the value...
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Check if the Queue is Full ?
        if ((rear + 1) % size == front)
            return false;

        // Inserting the First element in the Array.
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        { // Maintain the cyclic order...
            rear = 0;
        }
        else
        {
            rear++; // Moving rear 1 step ahead to push new element.[Noraml insertion at back]
        }

        // pushing the value...
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Check if the Queue is empty ?
        if (front == -1)
            return -1;

        int ans = arr[front]; // store the ele at front to return.

        // check if only 1 element is preset
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        { // To maintain the cyclic order...
            front = 0;
        }
        else
        {
            front++; // Moving front 1 step ahead [Noraml pop at front]
        }

        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Check if the Queue is empty ?
        if (front == -1)
            return -1;

        int ans = arr[rear]; // store the ele at rear to return.

        // check if only 1 element is preset
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        { // To maintain the cyclic order...
            rear = size - 1;
        }
        else
        {
            rear--; // Moving rear 1 step back.
        }

        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (front == -1)
            return -1;
        else
            return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (rear == -1)
            return -1;
        else
            return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((rear + 1) % size == front)
            return true;
        else
            return false;
    }
};