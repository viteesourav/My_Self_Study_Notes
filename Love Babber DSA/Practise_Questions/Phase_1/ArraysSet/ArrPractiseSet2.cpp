#include <bits/stdc++.h>
using namespace std;

// print arr..
void printArr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// reverse Arr...
void reverseArr(int arr[], int n)
{

    int s = 0, e = n - 1;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    printArr(arr, n);
}

// merge 2 given Sorted Arr..
void mergeSortedArr(int arr1[], int arr2[], int n1, int n2)
{

    vector<int> v;

    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            v.push_back(arr1[i]);
            i++;
        }
        else
        {
            v.push_back(arr2[j]);
            j++;
        }
    }
    // manage the left over elements from either of the given arrays...
    while (i < n1)
    {
        v.push_back(arr1[i]);
        i++;
    }
    while (j < n2)
    {
        v.push_back(arr2[j]);
        j++;
    }

    // print the New sorted array...
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

// move all zeros to right... **interesting question*** [IMP]
void moveZeroes(int nums[], int n)
{

    // simple know...just traverse put non-zero and then fill rest with zeros..
    int i = 0, k = 0;
    while (i < n)
    {
        if (nums[i] != 0)
        {
            nums[k] = nums[i];
            k++;
        }
        i++;
    }
    // fill rest with zeros..
    while (k < n)
    {
        nums[k] = 0;
        k++;
    }
    printArr(nums, k);
}
/*
Link: https://leetcode.com/problems/rotate-array/description/
*/
// Given an Array and an index, rotate the array about that index.
void rotateArr(int arr[], int n, int k)
{
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }
    int p = 0;
    for (auto i : temp)
    {
        arr[p] = i;
        p++;
    }
    printArr(arr, p);
}
/*
Logic:
   -- Baiscally strat a for loop from 0 to n-1, take a temp array.
   -- now use the logic of index % len -> will always lies between 0 to len.
   -- temp[(i+k)%n] = arr[i] -> temp will be rotated about the kth index.
*/

/*
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
*/
// check if the array is sorted and rotated..
bool check(vector<int> &nums)
{

    // check if there exist any pair where num[i] > num[i+1] for all ele including last one
    int n = nums.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
            count++;
    }
    if (count <= 1)
        return 1;
    else
        return 0;
}

// Give 2 arrays, find the sum of individual elemens and return a new array
vector<int> reverse(vector<int> &v)
{
    int s = 0, e = v.size() - 1;
    while (s <= e)
        swap(v[s++], v[e--]);
    return v;
}

// Find Array Sum...
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    int i = n - 1, j = m - 1;
    vector<int> ans;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        int res = sum % 10;
        ans.push_back(res);
        i--;
        j--;
    }
    // for remaining elements in either arr or brr...
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        int res = sum % 10;
        ans.push_back(res);
        i--;
    }
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        int res = sum % 10;
        ans.push_back(res);
        j--;
    }
    if (carry != 0)
    {
        ans.push_back(carry);
        carry = 0;
    }

    return reverse(ans); // calling the above function to flip the ans array..
}
/*
Approach:
  -- We will mimic how we do noraml addition using carray.
eg:              i
    arr  ->  6 5 6
    brr  ->  2 7 7
                 j
    -- i and j will run from end till first, intialize carry with 0.
    -- sum = arr[i]+arr[j]+carry.
    -- store sum%10 (fetch the unit place digit), update carry -> sum/10.
    -- Do this untill we traverse both the array and either of the remaining array elements.
    -- NOTE: Cehck is carry is 0, if not, add it to the result array.
    -- Now reverse the result array.
*/

int main()
{
    int arr[] = {1, 10, 14, 23, 45};
    int n = sizeof(arr) / sizeof(n);
    // reverseArr(arr, n);

    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6};
    // mergeSortedArr(arr1, arr2, 5, 3);

    int krr[] = {0, 4, 0, 0, 5, 6, 7, 8, 0};
    // moveZeroes(krr, 9);

    int crr[] = {1, 2, 3, 4, 5, 6, 7};
    rotateArr(crr, 7, 3);

    cout << "Just Some Array Questions" << endl;

    return 0;
}
