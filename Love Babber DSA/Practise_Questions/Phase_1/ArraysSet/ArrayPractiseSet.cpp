#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swapAlternate(int arr[], int n)
{
    for (int i = 0; i < n - 1; i = i + 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}

int findUnique(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = res ^ arr[i];
    }
    return res;
}

// NOte: here arr[] contains ele from 1 to n-1 and one element is repeated.
int findDuplicate(int arr[], int n)
{
    // XOR all elements of the array
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR from 1 to n-1
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

// Note Same, here also the arr n has all elements from n to n-1 with one duplicate.
int findDuplicatesMethod2(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int diff = (n * (n + 1)) / 2 - sum;
    return n - diff;
}

// using 2-pointer approach
void intersectionArr(int arr[], int brr[], int n1, int n2)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr[i] == brr[j])
        {
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        else if (arr[i] < brr[j])
            i++;
        else
            j++;
    }

    if (ans.size() == 0)
        cout << "-1" << endl;
    else
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

void pairSum(int arr[], int n, int checkSum)
{

    sort(arr, arr + n);
    printarr(arr, n); // printing the sorted array.
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == checkSum)
        {
            cout << min(arr[i], arr[j]) << " " << max(arr[i], arr[j]) << endl;
            i++;
            j--;
        }
        if (sum < checkSum)
            i++;
        else
            j--;
    }
}

// use 2-pointer tech to i for zeros and j for ones
void sortZeroOnes(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] == 1)
        {
            swap(arr[i], arr[j]);
            j--;
        }
        else
        {
            i++;
        }
    }

    printarr(arr, n);
}

// using the 3-pointer tech to sort zeros, ones and twos.
void sortZeroOneTwo(int arr[], int n)
{

    int i = 0, k = n - 2, j = n - 1;

    while (i <= k)
    {
        if (arr[i] == 2)
        {
            swap(arr[i], arr[j]);
            if (k == j - 1)
            {
                k--;
                j--;
            }
            else
                j--;
        }
        else if (arr[i] == 1)
        {
            swap(arr[i], arr[k]);
            k--;
        }
        else
        {
            i++;
        }
    }
    printarr(arr, n);
}

int main()
{
    int arr[] = {3, 4, 5, 6, 2, 9};
    int brr[] = {3, 7, 2, 2, 7, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int n1 = sizeof(brr) / sizeof(brr[0]);
    // swapAlternate(arr, n);
    // printarr(brr, n1);
    // cout<<findUnique(brr, n1)<<endl;
    // printarr(brr, n);
    int crr[6] = {5, 1, 2, 3, 4, 5};
    // cout<<findDuplicate(crr, 6)<<endl;
    // cout<<findDuplicatesMethod2(crr, 6)<<endl;
    int arr1[] = {1, 2, 2, 2, 3, 4};
    int arr2[] = {2, 2, 3, 3};
    // intersectionArr(arr1,arr2,6,4);
    int arr3[] = {2, -3, 3, 3, -2};
    int arr4[] = {1, 3, 4, 2, 5};
    int checkSum = 5;
    // pairSum(arr4, 5, checkSum);
    int arr5[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0};
    int arr6[] = {0, 0, 1, 0, 1, 1, 0, 1, 1};
    // sortZeroOnes(arr6, 9);
    // sortZeroOnes(arr5, 11);
    int arr7[] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    int arr8[] = {2, 2, 1, 0, 2, 1, 1, 0, 0, 2, 1, 1};
    sortZeroOneTwo(arr7, 9);
    sortZeroOneTwo(arr8, 12);
    return 0;
}
