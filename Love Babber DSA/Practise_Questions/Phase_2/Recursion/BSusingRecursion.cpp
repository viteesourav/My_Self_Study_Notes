// Implementation of Binary Search using Recursion concept
#include <bits/stdc++.h>
using namespace std;

// check if the array is sorted or not ?
bool isSorted(int a[], int n)
{

    // base condition:
    if (n == 1)
        return true; // if the size of array is 1
    if (n == 0)
        return true; // if the size of array is 0 i.e empty.

    // if at address a and a+1 the ele is sorted.
    if (*a <= *(a + 1))
        return isSorted(a + 1, n - 1);
    else
        return false;
}

// get the sum of the array
int findSumArr(int arr[], int n)
{

    // base case:
    if (n == 1)
        return *arr; // if array has only 1 element, return that val.
    if (n == 0)
        return 0; // if there is nothing in the array.

    // we will go till the end and while coming back we will add everything..
    return *arr + findSumArr(arr + 1, n - 1);
}

// Liner Search
bool searchLinear(int arr[], int n, int target)
{

    // base condition
    if (n == 0)
        return false; // if the array is empty

    // check if the current ele is target ?
    if (*arr == target)
        return true;
    else
    {
        return searchLinear(arr + 1, n - 1, target); // move down the arr to see if target exist ?
    }
}

// Binary Search
bool searchBinary(int arr[], int start, int end, int target)
{

    // baseCondition
    if (start > end)
        return false; // exit constion of Binary SEarch

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return true; // found the element
    // the mid ele > target, move the end towards start
    else if (arr[mid] > target)
        return searchBinary(arr, start, mid - 1, target);
    // the mid ele < target, move the start towards end
    else if (arr[mid] < target)
        return searchBinary(arr, mid + 1, end, target);

    return false; // just if nothing works this will throw false.
}
/*
Logic:

Dry Run:

 0 1 2 3 4 5
 4 5 6 7 8 9
 s   m s m e

target - 8

 fn(arr,0,5,8) -> fn(arr, 3,5,8) -> true.
 fn(arr, 3,5,8) -> true;


*/

int main()
{

    int arr[] = {4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    cout << isSorted(arr, size) << endl;
    cout << findSumArr(arr, size) << endl;
    cout << searchLinear(arr, size, 5) << endl;
    cout << searchBinary(arr, 0, size - 1, 6) << endl;
    return 0;
}