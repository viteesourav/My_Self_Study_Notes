#include <bits/stdc++.h>
using namespace std;

int maxPossibleTime(vector<int> &arr)
{
    int totTime = 0;
    for (int i = 0; i < arr.size(); i++)
        totTime += arr[i];
    return totTime;
}

bool isJobFinished(vector<int> &arr, int k, int maxTimePerPainter)
{

    int totaltime = 0;
    int totalPainter = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxTimePerPainter)
            return 0;
        totaltime += arr[i];
        if (totaltime > maxTimePerPainter)
        {
            totalPainter++;
            totaltime = arr[i];
        }
    }
    if (totalPainter > k)
        return 0;
    else
        return 1;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    // This problem is similar to Books allocation Problem.
    // we will work with our solution space...

    int l = 0, h = maxPossibleTime(boards), ans = -1;
    // now we have the sample space lets, analysis the region with mid
    while (l <= h)
    {

        int mid = l + (h - l) / 2; // mid gives a possible min time limit

        if (isJobFinished(boards, k, mid))
        {
            // if yes, then all time more that mid also will work...
            // lets look in left half
            ans = mid; // a possible solution
            h = mid - 1;
        }
        else
        {
            // if no, then all time less mid also wont staisfy for sure.
            // lets look in right side
            l = mid + 1;
        }
    }
    return ans;
}

// This containes just the driver function with the logic...