// This is very important, Kadene's Algo... i.e maximum Contigious Sum
/*
Link: https://leetcode.com/problems/maximum-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int arr[], int n)
{

    int maxSum = arr[0]; // let the first value be max
    int sum = 0;
    // we will go through all the elements...
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];             // see the sum
        maxSum = max(maxSum, sum); // store the sum
        if (sum < 0)               // if sum is getting < 0, make Sum = 0
            sum = 0;
    }
    return maxSum;
}

int main()
{
    int arr[] = {5, 4, -1, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    cout << "The Maximum Possible sum is: " << maxSubArray(arr, n) << endl;
}