/*
Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // using freqTable Logic O(n) O(n)
        //  unordered_map<int, int> freqT;
        //  for(int i=0;i<nums.size();i++) freqT[nums[i]]++;
        //  vector<int> ans;
        //  for(auto it:freqT) {
        //      if(it.second == 2) ans.push_back(it.first);
        //  }
        //  return ans;

        // using flip-switch tech O(n) O(1) {It works because all elements in the array will be in the range of 1 to n}
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                ans.push_back(abs(nums[i])); // some other number has flip has flipped it.
            else
                nums[index] = -nums[index]; // fresh condition.
        }
        return ans;
    }
};

/*
Logic:
condition: This tech can be used only if all eles are between 1 to n
Flip Switch tech Approach:
    -- loop throung the array with index.
    -- go to the position at arr[index]-1 and check,
       If it is nagative: means someone else flipped it already, thus duplicated. [Found your duplicates elements]
       If ot is Positive: flip it. i.e make it nagative.
*/