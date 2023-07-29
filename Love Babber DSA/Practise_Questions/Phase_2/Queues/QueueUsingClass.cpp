// This Class shows the implementation of Queue using Array.
/*
Operations shown:
    1) isEmpty
    2) Enqueue
        -- check if the Queue is Full ?
        -- Normal Insertion at rear.
    3) Dequeue
        -- check if the Queu is empty ?
        -- Normal Poping at front.
        -- If single element, pop, then reset front and rear  to intial value.
    4) Front
*/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int start, rear;

public:
    Queue()
    {
        arr = new int[10000];
        size = 10000;
        start = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        // check if start and rear points to same location...
        return start == rear ? true : false;
    }

    void enqueue(int data)
    {
        // Check if the queue is overflowing ?
        if (rear == size)
            cout << "Queue is Overflowing" << endl;
        else
        {
            // Put the element at rear, move rear to next Free space...
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        // Check if the Queue is underflowing ?
        if (start == rear)
            return -1;
        else
        {
            // Just move the front to the next element...
            int ans = arr[start];
            start++;
            // Additional condition, when we removed all the elements...
            if (start == rear)
                start = rear = 0;
            return ans;
        }
    }

    int front()
    {
        // Check if the queue is underflowing ?
        if (start == rear)
            return -1;
        else
            return arr[start];
    }
};