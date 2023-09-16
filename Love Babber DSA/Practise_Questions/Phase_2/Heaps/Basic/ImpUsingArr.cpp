// This code implements a MaxHeap using Array...
#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:
    int arr[100];
    int size;

public:
    // Constructor to initialize the arr...
    MaxHeap()
    {
        arr[0] = -1; // 1-based index we are considering
        size = 0;    // initial size is 0.
    }

    // 1) Logic For insertion into the maxHeap...
    void insert(int x)
    {

        // 1. We increase the size of arr and push the element at the last...
        size = size + 1;
        int index = size;
        arr[index] = x;

        // 2. Take the last element to it's correct postion in heap...
        while (index > 1)
        {                                // check till my index is inside the array..
            int parentIndex = index / 2; // You know the new child, find the post of it's parent.

            // Check if parent < newNode, If yes, swap them...
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // A function to print the max heap Nodes...
    void printMaxHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 2) Logic for deletion a an Element from the Heap. [When deletion means, deleting the Root Node i.e element at index 1]
    int deleteFromHeap()
    {

        // Check if arr has any element to delete or not...
        if (size == 0)
        {
            cout << "Nothing to delte" << endl;
            return -1;
        }

        int removedEle;

        // lets put last Element at root Element [element at arr index 1] with the last element..
        removedEle = arr[1];
        arr[1] = arr[size];
        size--;

        // Take the root element to it's correct position, by comapring with children.
        int index = 1;

        while (index < size)
        {
            int child1 = 2 * index;
            int child2 = 2 * index + 1;

            if (child1 <= size && child2 <= size && (arr[child1] > arr[index] && arr[child2] > arr[index]))
            {
                // If both the child are greater, swap with the bigger child...
                if (arr[child1] > arr[child2])
                {
                    swap(arr[index], arr[child1]);
                    index = child1;
                }
                else
                {
                    swap(arr[index], arr[child2]);
                    index = child2;
                }
            }
            else if (child1 <= size && arr[child1] > arr[index])
            {
                // If child1 is greater than parent...
                swap(arr[child1], arr[index]);
                index = child1;
            }
            else if (child2 <= size && arr[child2] > arr[index])
            {
                // If child2 is greater than parent...
                swap(arr[child2], arr[index]);
                index = child2;
            }
            else
            {
                break;
            }
        }
        return removedEle;
    }
};

// 3. Convert into maxheap [heafiy algortith: Take the element to its correct place] TC: O(logn)
void heapify(int arr[], int size, int index)
{

    // lets take the index, and find its children..
    int i = index;
    int child1 = 2 * i;
    int child2 = 2 * i + 1;

    if (child1 <= size && arr[i] < arr[child1])
    {
        i = child1;
    }
    if (child2 <= size && arr[i] < arr[child2])
    {
        i = child2;
    }

    // if we updated i, then we we need to swap and call heafiy to further postion the Node..
    if (i != index)
    {
        swap(arr[index], arr[i]);
        heapify(arr, size, i);
    }
}

// Heap Sort Algo: We pass a valid heap into this, and it will sort it.. TC: O(n logn)
void heapSort(int arr[], int n)
{

    int tempSize = n - 1;

    // Do this till, n reaches 1st index...
    while (tempSize > 1)
    {
        // Step1: first swap the first and last element and decrement the size...
        swap(arr[1], arr[tempSize]);
        tempSize--;

        // step2: Now because of swap, the largest element reached at the end...
        //  But since we swap, we need to place the Node at index 1 at it's proper place i.e heapify..
        heapify(arr, tempSize, 1);
    }
}

int main()
{

    // creating a new maxHeap...
    MaxHeap mh;

    // inserting Nodes...
    mh.insert(50);
    mh.insert(55);
    mh.insert(53);
    mh.insert(52);
    mh.insert(54);

    // Printing the Nodes after insertion...
    mh.printMaxHeap(); // 55 54 53 50 52

    // Deleting from Heap...
    cout << "Node deleted: " << mh.deleteFromHeap() << endl; // 55
    cout << "After Deletion: ";
    mh.printMaxHeap(); // 54 52 53 50

    cout << endl;

    cout << "Node deleted: " << mh.deleteFromHeap() << endl; // 54
    cout << "After Deletion: ";
    mh.printMaxHeap(); // 53 52 50

    // Heapify Algorithm...

    // A Heap is given repesented in form of array, convert this into a heap..
    int arr[] = {-1, 54, 55, 53, 50, 52};
    int n = sizeof(arr) / sizeof(int);

    // NOTE: In 1-based index, From n/2 + 1 to n we have leaf nodes, Thus no need to process them...
    // For building a heap: TC: O(n)
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }

    cout << "Printing the heap Nodes after successful heafiy for all the Nodes: " << endl;
    for (int i = 1; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // 4. Sort using heap Sort...[Requrirement: the arr we have for heap must be a valid heap]
    // NOTE: From above we get a valid heap array, lets sort it using heap Sort...
    heapSort(arr, n);

    cout << "Printing the heap Nodes after successful heap Sort: " << endl;
    for (int i = 1; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // 5. using STL implementing heaps...

    cout << "Priority Queue STL example" << endl;

    // implementing maxHeap...
    priority_queue<int> pq_max; // max element always on top..

    // inserting...
    pq_max.push(54);
    pq_max.push(53);
    pq_max.push(55);
    pq_max.push(52);
    pq_max.push(50);

    cout << "TOP element in pq_max: " << pq_max.top() << endl;
    cout << "pop element from pq_max: " << endl;
    pq_max.pop();
    cout << "TOP element in pq_max: " << pq_max.top() << endl;
    cout << "Is pq_max empty ? " << pq_max.empty() << endl;

    cout << endl
         << endl;

    // implementing minHeap...
    priority_queue<int, vector<int>, greater<int>> pq_min; // min element always on top..

    // inserting...
    pq_min.push(54);
    pq_min.push(53);
    pq_min.push(55);
    pq_min.push(52);
    pq_min.push(50);

    cout << "TOP element in pq_min: " << pq_min.top() << endl;
    cout << "pop element from pq_min: " << endl;
    pq_min.pop();
    cout << "TOP element in pq_min: " << pq_min.top() << endl;
    cout << "Is pq_min empty ? " << pq_min.empty() << endl;

    return 0;
}
