#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {

        // First i need to create a freq table using hashMap.
        unordered_map<int, int> freqTable;

        for (int i = 0; i < arr.size(); i++)
        {
            freqTable[arr[i]]++;
        }

        // now we will use a set to see if all this values are exactly once or repeated.
        unordered_set<int> unique;
        for (auto it : freqTable)
        {
            unique.insert(it.second);
        }

        // If the map size and set size differ, means duplicates, if not then all eleme are unique.
        return unique.size() == freqTable.size();
    }
};