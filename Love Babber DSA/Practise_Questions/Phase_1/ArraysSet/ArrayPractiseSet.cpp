#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// adjacent Elements should be swapped...
void swapAlternate(int arr[], int n)
{
    for (int i = 0; i < n - 1; i = i + 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}

// find the unique element in the given array. --> XOR logic
// consition: Array has only 1 unique element.
int findUnique(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = res ^ arr[i];
    }
    return res;
}

// NOte: here arr[] contains ele from 1 to n-1 and one element is repeated.[**IMP**]
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
/*
Logic:
consition: If Array has n elements form [1, n-1] and one is repeated.
logic: XOR all elements of the array with all the indexes form 1 to n-1.
eg: (5^1^2^3^4^5) ^  (1^2^3^4^5) ->  5 [this is the duplicate element]
      given arr     index 1 to n-1
*/

// Note Same, here also the arr n has all elements from n to n-1 with one duplicate.
// Logic: using n(n+1)/2-sum of n elements from array logic
int findDuplicatesMethod2(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int diff = (n * (n + 1)) / 2 - sum;
    return n - diff;
}

// using 2-pointer approach -> Provide all the common elements form arr and brr
// NOTE: arr and brr have sorted elements.
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

    // Printing the common elements from arr and brr...
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

// Task: To find all the pair elements in arr, whose sum is checkSum
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
/*
Logic:
    -- First sort the given array.
    -- i at first and j at last.
    -- check the sum, if matched -> found,
       if > targetSum -> j--
       if < targetSun -> i++
*/

// use 2-pointer tech to i for zeros and j for ones [Imp]
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
/*
Approach:
    -- i at starting and j at the end. [2-pointers]
    -- till i < j, if at ith we have 1, then swap with jth place and j--.
                   if at ith we have 0, then just i++
*/

// using the 3-pointer tech to sort zeros, ones and twos.[imp]
void sortZeroOneTwo(int arr[], int n)
{
    // here i tracks 0, j tracks 2 and k tracks 1.
    int i = 0, k = n - 2, j = n - 1;
    while (i <= k)
    {
        if (arr[i] == 2)
        {
            swap(arr[i], arr[j]);
            if (k == j - 1) // if j and k are adjacent, both will shift left.
            {
                k--;
                j--;
            }
            else
                j--; // If not adjacent then only j can shift left
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
/*
Approach:
    -- 3 pointers, i, j and k. i at begining tracks 0, j at end tracks 2 and k tracks 1.
    -- till i < k,
       if ith place -> 2, swap with j, move k and j to right(If adjacent) else only move j to right. [IMP]
       if ith palce -> 1, swap with k, move k to left.
       if ith place -> 0, just do i++.
*/

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
