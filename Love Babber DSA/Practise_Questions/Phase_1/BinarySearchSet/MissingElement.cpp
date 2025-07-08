#include <bits/stdc++.h>
using namespace std;

int findMissing(int arr[], int n)
{

    int l = 0, h = n - 1;
    int start = arr[0];

    while (l <= h)
    {

        int mid = l + (h - l) / 2; // is this the missing ele ?

        // check is the previous val is 2 less or not ?
        if (mid != 0 && arr[mid] - arr[mid - 1] == 2)
            return arr[mid] - 1;

        if (start + mid == arr[mid])
            l = mid + 1;
        else
            h = mid;
    }
    return -1;
}

int main()
{

    int arr2[] = {1, 2, 3, 4, 6, 7, 8};
    int n2 = sizeof(arr2) / sizeof(int);
    cout << "Missing Element: " << findMissing(arr2, n2) << endl;

    int arr3[] = {1, 3, 4, 5, 6, 7, 8};
    int n3 = sizeof(arr3) / sizeof(int);
    cout << "Missing Element: " << findMissing(arr3, n3) << endl;

    int arr1[] = {8, 9, 10, 12, 13, 14, 15};
    int n1 = sizeof(arr1) / sizeof(int);
    cout << "Missing Element: " << findMissing(arr1, n1) << endl;

    cout << "Finding missing ele using Bs" << endl;
    return 0;
}

/*
    Logic:
        1. So you started with low -> 0 and high -> n-1. [n is the size of the arr]
        2. find the mid.
        3. Check if arr[mid] and arr[mid-1] has a diff of 2 --> i.e some number is missed for sure.
        4. If not,
            -> search in left part
            -> search in right part
    HOW ?
        - the arr contains all elements from 1 to n-1 in seq, so lets say what will be the element at pos 5 ?
        - it will be startVal + post => if startval is 1 --> 1+ 5 -> 6.
        -   0   1  2  3  4  [5]  6
           [1]  2  3  4  5   6  7
        - IF it satisify then all elements before mid are proper and something is missing on the right side of the array.
        - If not, then something is missing on the left side of the array.

*/