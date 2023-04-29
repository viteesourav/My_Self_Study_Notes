#include <bits/stdc++.h>
using namespace std;

// Find the pivot point in a rotated array
void ShowPivotElement(int arr[], int n)
{

    int l = 0, h = n - 1;
    int ans = -1;

    while (l < h)
    {

        int mid = l + (h - l) / 2;

        if (arr[mid] >= arr[0])
            l = mid + 1;
        else
            h = mid;
    }
    ans = l; // the position of l will return the pivort point.
    if (ans != -1)
        cout << "The Pivot Index is: " << ans << endl;
    else
        cout << "Something went wrong" << endl;
}

int binarySearch(int arr[], int l, int h, int k)
{

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == k)
            return mid;
        else if (k > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

// search  a key in Sorted and Roated array.
void searchKey(int arr[], int n, int k)
{

    // first find pivot element..
    int l = 0, h = n - 1;

    while (l < h)
    {

        int mid = l + (h - l) / 2;

        if (arr[mid] >= arr[0])
            l = mid + 1;
        else
            h = mid;
    }
    int pivot = l;
    cout << "pivot index: " << pivot << endl;
    // Now implement BS based on where the key would have lied.
    if (arr[pivot] <= k && k <= arr[n - 1])
    {
        cout << "Post of key is: " << binarySearch(arr, pivot, n - 1, k) << endl;
    }
    else
    {
        cout << "Post of key is: " << binarySearch(arr, 0, pivot, k) << endl;
    }
}

// finding sqrt using BS
int findSqrtBS(int num)
{

    int l = 0, h = num;
    int ans = -1;

    while (l <= h)
    {

        long long int mid = l + (h - l) / 2;

        long long int power = mid * mid;

        if (power == num)
            return mid;
        else if (power > num)
            h = mid - 1;
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

// Finding sqrt upto 2digit precision.
double findPrecisionSqrt(int x, int precision)
{

    int closestsqrt = findSqrtBS(x);
    double factor = 1;
    double ans = closestsqrt;
    for (int i = 0; i < precision; i++)
    {

        factor = factor / 10; // 0.1 then 0.01 then 0.001 i.e upto 3 precision layer

        double j = ans;
        while (j * j < x)
        {
            ans = j;
            j += factor;
        }
    }
    return ans;
}

int main()
{

    int arr[] = {3, 8, 10, 17, 1};                // array is sorted and then rotated.
    int brr[] = {15, 34, 45, 67, 4, 5, 7, 9, 10}; // sorted and rotated.
    int n = sizeof(brr) / sizeof(int);
    // ShowPivotElement(brr, n);
    int k = 8;
    // searchKey(brr, n, k);
    int num = 38;
    // cout<<"closest Sqrt of "<<num<<" is: "<<findSqrtBS(num)<<endl;
    cout << "Precision sqrt of " << num << " is: " << findPrecisionSqrt(num, 3) << endl;
    cout << "Binary Search Questions" << endl;

    return 0;
}
