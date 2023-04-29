// Merge Logic: is faster compare to any other Sorting tech. TC: O(nlogn)

#include <bits/stdc++.h>
using namespace std;

// print the array..
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// merge logic -> break the array into 2 halfs and merge them sorted.
void merge(int arr[], int start, int end)
{

    int mid = start + (end - start) / 2;

    // let create 2-new array, break arr into 2 array from mid.
    int *leftArr = new int[mid - start + 1];
    int *rightArr = new int[end - mid];

    // copy the data from main arr to this new sub-arrays..
    int lenLeft = 0, lenRight = 0;
    for (int i = start; i <= mid; i++)
        leftArr[lenLeft++] = arr[i];
    for (int i = mid + 1; i <= end; i++)
        rightArr[lenRight++] = arr[i];

    // logic for merging 2-sorted array into one sorted array...
    int i = 0, j = 0, k = start;
    while (i < lenLeft && j < lenRight)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    // If the size of left Array and right array Differs then handling the left over array elements
    while (i < lenLeft)
        arr[k++] = leftArr[i++];
    while (j < lenRight)
        arr[k++] = rightArr[j++];

    // Removing the heap memory
    delete[] leftArr;
    delete[] rightArr;
}

// merge-sort algo: Approach using create new array and Sort
void mergeSort(int arr[], int start, int end)
{

    // baseCase:
    if (start >= end)
        return; // when start and end points to same ele, only 1 ele so sorted.

    int mid = start + (end - start) / 2;

    // break the left part of the array...
    mergeSort(arr, start, mid);
    // break the right part of the array...
    mergeSort(arr, mid + 1, end);

    // now use the merge logic.. -> sort the array
    merge(arr, start, end);
}

int main()
{
    // int arr[] = {7,2,8,5,9,1,6};
    int brr[] = {3, 4, 1, 6, 2, 5, 7};
    // int n = sizeof(arr)/sizeof(int);
    int n2 = sizeof(brr) / sizeof(int);
    // mergeSort(arr, 0, n-1);
    // printArr(arr, n);
    mergeSort(brr, 0, n2 - 1);
    printArr(brr, n2);
    cout << "Merge Sort" << endl;
    return 0;
}