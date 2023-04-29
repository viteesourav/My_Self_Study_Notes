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