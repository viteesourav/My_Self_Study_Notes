// Code to Find the max possible Size of the blade to get atleast k wood

#include <bits/stdc++.h>
using namespace std;

int findMaxHeight(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, arr[i]);
    return maxi;
}

// checks the the blade cuts enough wood or not ?
bool isValidBladeHgt(int arr[], int n, int woodRequired, int bladeHgt)
{

    int woodCollect = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > bladeHgt)
        {
            woodCollect += (arr[i] - bladeHgt);
        }
    }
    if (woodCollect >= woodRequired)
        return 1;
    else
        return 0;
}

int findBladeSize(int arr[], int n, int woodRequired)
{

    // first need a range for the solution...
    int l = 0, h = findMaxHeight(arr, n), ans = -1;

    // now the BS algo..
    while (l <= h)
    {

        int mid = l + (h - l) / 2; // this is a possible Blade hight

        if (isValidBladeHgt(arr, n, woodRequired, mid))
        {
            // if yes, then all the left side will be valid only
            // look in right side.
            ans = mid; // might be a possible solution
            l = mid + 1;
        }
        else
        {
            // if no, then all in the right are also not valid.
            // look in the left half.
            h = mid - 1;
        }
    }
    return ans;
}

/*
Workout and dry run of the given.............

EKO Problem

height of tree

Before:

20 15 10 17


blade hight:
15 --> cuts everything above it


After:
5        2  -> total wood collect: 5+2= 7
15 15 10 15

To Find: max Height of the Blade to get at least M meets of wood.


4 42 40 26 46    k=20

Range: 0 t0 46(max height of the tree)

m
36 37
l   h

possible Height: 36

wood coolect:
6+4+10 = 20


Possible blade height:

mid = 23 (Possible)  Need to look right.(l=mid+1)
mid = 35 (possible)  Need to look right
mid = 41 (not possible) Need to look left. (h=mid-1)
mid = 38 (not possible) Need to look left.
mid = 36 (possible) Need to look right.
mid = 37 (not possible) also l>h so exit the loop.

Last possible was mid = 36 (ans)

*/