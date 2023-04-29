#include <bits/stdc++.h>
using namespace std;

// just print the array...
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// using forLoop...
void bubbleSort1(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    printArr(arr, n);
}

// using Recursion
void bubbleSort2(int arr[], int n)
{

    // baseCase:
    if (n == 1)
        return; // If there is just 1 element in the arr.

    // solving for 1 case:
    // swap all adjacent ele based on comparison
    for (int i = 0; i < n - 1; i++)
    {
        if (*(arr + i) > *(arr + i + 1))
            swap(*(arr + i), *(arr + i + 1));
    }

    // Recursion will handle the rest...
    return bubbleSort2(arr, n - 1); // updating the params for the recursion.
}

int main()
{
    int arr[] = {4, 5, 2, 7, 1, 3, 6};
    int brr[] = {7, 2, 8, 5, 9, 1, 6};
    int n1 = sizeof(arr) / sizeof(int);
    int n2 = sizeof(brr) / sizeof(int);
    bubbleSort1(arr, n1);
    bubbleSort2(brr, n2);
    printArr(brr, n2);
    cout << "Bubble Sort" << endl;
    return 0;
}
