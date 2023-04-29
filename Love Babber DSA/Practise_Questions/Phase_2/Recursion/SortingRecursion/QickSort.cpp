// One of the very Important Topic of Sorting... -> Quick Sort
#include <bits/stdc++.h>
using namespace std;

// function to print the array...
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// handle the pivotIndex and Arranging left and right side of the Pivot Index...
int findPivotIndex(int arr[], int start, int end)
{

    // let consider the first element as Pivot element..
    int pivot = arr[start];

    // To Find its correct position, let have a count, to count all ele <= pivot.
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;    // This is our pivotindex.
    swap(arr[start], arr[pivotIndex]); // Putting the pivot ele at it's pivot index..

    // now we need to make sure all elements on left <= then pivot
    // and all element on right > pivot.
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {

        // if the elements are smaller or equal to pivot then move i...
        while (arr[i] <= pivot)
        {
            i++;
        }

        // if element on right greater then pivot, then move j...
        while (arr[j] > pivot)
        {
            j--;
        }

        // If one ele is found in right and left which should be on the other side...
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

// Quick Sort: ALgo Logic...
void QuickSort(int arr[], int start, int end)
{

    // basecase: if 1 ele or no ele then the array is sorted...
    if (start >= end)
        return;

    // Now we need to put pivot ele at pivot index and get the pivotIndex...
    int pivotIndex = findPivotIndex(arr, start, end);

    // We solve one case to find Pivot element and index
    // Rest Recursion will handle it...
    QuickSort(arr, start, pivotIndex - 1); // handle sorting on left side of the pivotIndex
    QuickSort(arr, pivotIndex + 1, end);   // handle sorting on right side of the pivotIndex
}

int main()
{
    int arr[] = {4, 2, 1, 5, 3};
    int n = sizeof(arr) / sizeof(int);

    QuickSort(arr, 0, n - 1);

    printArr(arr, n);

    cout << "Quick Sort Algo";
    return 0;
}
