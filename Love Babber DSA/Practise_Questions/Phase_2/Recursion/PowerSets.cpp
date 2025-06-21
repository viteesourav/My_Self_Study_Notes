// This Program finds the powerSets of a given Array. Power Set : All possible subsets of given array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void findPowerSet(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
    {

        // base case:
        if (index >= nums.size())
        { // when the index exceeds the len of the array.
            // push the value of output before returning...
            ans.push_back(output);
            return;
        }

        // Case where we will exclude the ele at index.
        findPowerSet(nums, output, index + 1, ans);

        // Case where we will include the ele at index in output array...
        output.push_back(nums[index]);
        findPowerSet(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        // solving it using recursion
        vector<vector<int>> ans;
        vector<int> output;
        // This is a recursive fun to find all possible subsets...
        findPowerSet(nums, output, 0, ans);
        return ans;
    }
};

/* Logic:

  1 2 3
[
  [], 1, 2, 3,
  [1 2],
  [1 3],
  [2 3],
  [1 2 3]
]

Approach:

-- Classic case: where we either exclude or include a element in ouput array. --> Finding all possible subsets or power set.

Solve Recurssively.
fn -> givenArr, outputArr, index ans ansArr
In Each Step:
-- First take the element, first step-> first ele, second Step -> second element and so on...
Base Case: If it moves out of array.
Store the output in ansArr and comeback...
-- For each Step, You will do two things..
   1) include that element from ans.
   2) exclude that element from ans.
For both of them call the function Recursively...

*/