#include <bits/stdc++.h>
using namespace std;

int findTotalPages(int arr[], int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// if we set a page limit, is it possible to distribute the books
bool isPossibleToDistribute(int arr[], int n, int m, int mid)
{

    int studCount = 1;
    int pageCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return 0; // edge case when the pagesize if more than mid itself.
        pageCount += arr[i];
        if (pageCount > mid)
        {
            studCount++;
            pageCount = arr[i];
        }
    }
    if (studCount > m) // if the distribution of all the books need more students
        return 0;
    else
        return 1;
}

// Book Allocation Problems
int bookAllocation(int arr[], int n, int m)
{

    // first thing, Create a sample solution space...
    int l = 0; // can be optimised if this starts from the max page available.
    int h = findTotalPages(arr, n);
    int ans = -1;

    // next find a min page limit for a student...
    while (l <= h)
    {

        int mid = l + (h - l) / 2; // this gives you a possible page limit.

        // this checkes if mid is page limit per stud then can we distribute all the books to all stud ?
        if (isPossibleToDistribute(arr, n, m, mid))
        {
            // if yes, then all values greater than that we will, so search leftside for min page limit.
            ans = mid; // possible min value.
            h = mid - 1;
        }
        else
        {
            // if no, then all vlaues lower then that will also fail, so search right side
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int pages[] = {10, 20, 30, 40}; // pages in the book
    int n = 4;                      // no of books
    int m = 2;                      // no of students.

    cout << "solution of book Allocation: " << bookAllocation(pages, n, m) << endl;

    cout << "Binary Search Very Very Important Questions" << endl;

    return 0;
}
