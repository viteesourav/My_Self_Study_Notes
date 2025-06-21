#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// selection Sort Algo... O(n2) --> i and j = i+1 --> Look right, find the index where ar[j] < ar[i] -> swap i and j.
void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    { // condition till n-1, last ele will alrady be sorted.

        int minEle = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minEle])
                minEle = j; // Find the min val ahead of i.
        }
        swap(arr[i], arr[minEle]);
    }
    printArr(arr, n);
}

// bubble sort Algo...O(n2) -> swap[i and i+1] for n times.
void bubbleSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    printArr(arr, n);
}

// bubble sort Algo...
void OptimizedBubbleSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (isSwapped == false)
            break; // If no swaps happened in one complete Round means the array is sorted.
    }
    printArr(arr, n);
}

// insertionSort...--> i and j= i-1. Hold ar[i], replace -> ar[j+1] with ar[j] till arr[j] > hold --> at end replace ar[j+1] -> hold. 
void insertionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int temp = arr[i], j = i - 1;
        while (arr[j] > temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printArr(arr, n);
}

int main()
{

    int arr[] = {5, 2, 3, 6, 7, 1};
    int n = sizeof(arr) / sizeof(int);

    selectionSort(arr, n);
    bubbleSort(arr, n);

    cout << "Sorting of array !" << endl;

    return 0;
}