// This is one important implementation of merge sort Logic...
// Inversion Count: How far the array is from being sorted ?
//  Basically checks for this 2 condition: For all i < j, Arr[i]  > Arr[j], if so inversion_count++...
#include <bits/stdc++.h>
using namespace std;

// merge logic to sort and merge the array..
int merge(int arr[], int start, int end)
{

    int inversion_count = 0;

    // find the mid...
    int mid = start + (end - start) / 2;

    // create 2 new array...
    int *leftArr = new int[mid - start + 1];
    int *rightArr = new int[end - mid];

    // copy elements from many arr to left and Right array..
    int leftLen = 0, rightLen = 0;
    for (int i = start; i <= mid; i++)
        leftArr[leftLen++] = arr[i];
    for (int i = mid + 1; i <= end; i++)
        rightArr[rightLen++] = arr[i];

    // Now from 2 sorted array creating one sorted array..
    int i = 0, j = 0, k = start;
    while (i < leftLen && j < rightLen)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
        {
            // here our inversion condition staisfyies... i.e leftArr[i] > rightArr[j]
            arr[k++] = rightArr[j++];
            inversion_count += (leftLen - i);
        }
    }

    // handling left-over
    while (i < leftLen)
        arr[k++] = leftArr[i++];
    while (j < rightLen)
        arr[k++] = rightArr[j++];

    // handling pointers
    delete[] leftArr;
    delete[] rightArr;

    return inversion_count;
}

// same logic as merge-sort, we will break the array...
int findInversion(int arr[], int start, int end)
{

    int inversion_count = 0;

    // base_condition
    if (start < end)
    { // If one ele then return.
        // find the mid...
        int mid = start + (end - start) / 2;

        // array in left half...
        inversion_count += findInversion(arr, start, mid);
        // array in right half...
        inversion_count += findInversion(arr, mid + 1, end);

        // now perform merge of the 2 halfs for sorting...
        inversion_count += merge(arr, start, end);
    }
    return inversion_count;
}

int main()
{

    int arr[] = {2, 5, 1, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << "No of Inversions: " << findInversion(arr, 0, n - 1) << endl;
    cout << "Inversion_Count" << endl;
    return 0;
}