// Link: https://www.codingninjas.com/studio/problems/maximum-frequency-number_920319?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
/*
Basically, You have an array of elements, Need to give the element who has the highest Frequency.
    NOTE: If 2 elements have the highest freq, Print the one that comes first.
*/
#include <bits/stdc++.h>
using namespace std;

// Approach: use hashMap For Freq Tracking...
int maximumFrequency(vector<int> &arr, int n)
{

    unordered_map<int, int> freqMap;

    // This will iterate the List, And for each Element it will increment the value...
    for (auto i : arr)
    {
        freqMap[i]++;
    }

    int maxFreq = INT_MIN; // A track for the maxfreq...
    int ans = -1;

    // loop through the vector...
    for (auto i : arr)
    {
        if (freqMap[i] > maxFreq) // For each element check if it's freq > maxFreq so far
        {
            ans = i; // If yes, update the ans, and store the maxFreq.
            maxFreq = freqMap[i];
        }
    }

    return ans;
}

/*
Appraoch: use HashMap TC: O(N) SC: O(N)
    -- We will use unordered map to store the freq of each of the element.
    -- Next we will run a loop again and see if the element has the max Freq or not.
*/