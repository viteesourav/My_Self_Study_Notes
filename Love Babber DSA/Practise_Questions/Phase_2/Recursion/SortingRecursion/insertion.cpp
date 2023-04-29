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
void insertionSort1(int arr[], int n)
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

// using Recursion
void insertionSort2(int arr[], int index, int n)
{

    // baseCase:
    if (index == n)
        return; // If we reached the second last element we are done.

    // solving for 1 case:
    // we will take a j behind the  current position and compare all elments behind
    int temp = arr[index]; // storing current element
    int j = index - 1;
    while (arr[j] > temp && j >= 0)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp;

    // Recursion will handle the rest...
    index++;
    return insertionSort2(arr, index, n); // updating the params for the recursion.
}

int main()
{
    int arr[] = {4, 5, 2, 7, 1, 3, 6};
    int brr[] = {7, 2, 8, 5, 9, 1, 6};
    int n1 = sizeof(arr) / sizeof(int);
    int n2 = sizeof(brr) / sizeof(int);
    insertionSort1(arr, n1);
    insertionSort2(brr, 0, n2);
    printArr(brr, n2);
    cout << "insertion Sort" << endl;
    return 0;
}
