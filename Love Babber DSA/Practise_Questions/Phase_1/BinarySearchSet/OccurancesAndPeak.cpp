#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int start, int end, int key)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

// First and last Occurance of a key, in sorted arr.
int findFirstOccurance(int arr[], int n, int k)
{

    int l = 0, h = n - 1;
    int startPost = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == k)
        { // this is important, since we need to find the left most occurance, keep on searching on the left.
            startPost = mid;
            h = mid - 1;
        }
        else if (k > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return startPost;
}

int findLastOccurance(int arr[], int n, int k)
{

    int l = 0, h = n - 1;
    int endPost = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == k)
        { // this is important, since we need to find the left most occurance, keep on searching on the left.
            endPost = mid;
            l = mid + 1;
        }
        else if (k > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return endPost;
}

// peak Index in Mountain
int peakMountainArr(int arr[], int n)
{

    int l = 0, h = n - 1;
    if (n < 3)
        return -1;
    while (l < h)
    {

        int mid = l + (h - l) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1] && mid > 0 && mid < n)
            return arr[mid]; // return the element at the peak.
        else if (arr[mid] < arr[mid + 1])
            l = mid + 1; // mid on the up going slope
        else if (arr[mid] > arr[mid + 1])
            h = mid; // mid on the down going slope. **NOTE: Here never do h= mid-1, then the below meantion arr it will fail.
        else
            break; // if none of the above condition satisfy break the infinite loop.
    }
    return -1; // not a mountain arr.
}

/*

arr[] = {3 5 3 2 0}, This array make sure you are able to find the peak. **NOTE**

*/

int main()
{

    int arr[] = {0, 0, 1, 1, 1, 2, 2, 2, 2, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6}; // sorted array
    int n = sizeof(arr) / sizeof(int);
    int k = 4;
    pair<int, int> ans;
    // ans.first = findFirstOccurance(arr, n, k);
    // ans.second = findLastOccurance(arr, n, k);
    // if(ans.first == -1) cout<< "Element not present"<<endl;
    // else {
    //     cout<<"Element start Post: "<<ans.first<<endl;
    //     cout<<"Element end Post: "<<ans.second<<endl;
    // }
    // cout<<"Total occurance: "<<ans.second-ans.first+1 <<endl;
    int krr[] = {0, 2, 3, 4, 5, 2, 1, 0};
    int n2 = sizeof(krr) / sizeof(int);
    cout << "Peak is: " << peakMountainArr(krr, n2) << endl;

    cout << "Binary Search Program end" << endl;
    return 0;
}
