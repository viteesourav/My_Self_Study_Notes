// maximum possible minimum distance...
#include <bits/stdc++.h>
using namespace std;

bool isPossibleToPlace(vector<int> &stalls, int k, int safeDist)
{

    int totCows = 1, lastCowPost = 0;
    for (int i = 0; i < stalls.size(); i++)
    {

        if (stalls[i] - stalls[lastCowPost] >= safeDist)
        {
            totCows++;
            if (totCows == k)
                return 1;
            lastCowPost = i;
        }
    }
    return 0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    // First of all we will sort the postions of the stalls
    sort(stalls.begin(), stalls.end());

    // now lets take the solution space region for the search of largest min distance.
    int l = 0, h = stalls[stalls.size() - 1], ans = -1;

    while (l <= h)
    {

        int mid = l + (h - l) / 2; // this gives a possible safe distance between the cows.

        // check if we are able to place all cows with that safe dist.
        if (isPossibleToPlace(stalls, k, mid))
        {
            // if yes, then all dist less than that we will can place them.
            // lets looks towards the right.
            ans = mid; // a possible safe dist.
            l = mid + 1;
        }
        else
        {
            // If no, then all dist more than it, cows we cannot accomodate.
            // LEts looks towards the left.
            h = mid - 1;
        }
    }
    return ans;
}

// WorkOut of the aggressive cow problem with dry run...
/*
Aggressive cows


0 3 4 7 10 9


no Of Aggressive cows = 4


0 3 4 7 9 10       ans: 3

    m	m	m -->ignore all to right
0 1 2 3 4 	5 6 7 8 9 10
l    	  h
      l
mid = 5 (not possible) move left
mid = 2 (possible) move right
mid = 3 (possible) move right
mid = 4 (not possible) move left but(l>h) so break,

last mid is ans ---> 3 (largest min safe distance between the cows)

//if this is the safe distance
dist = 4;

c1: 0

c2: 4

c3: 9

c4: -

*/