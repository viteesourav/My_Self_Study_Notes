// Link: Link: https://leetcode.com/problems/combination-sum/
/*
Basically, A set of numbers are given i.e [1, 2, 5] and a target is given say tar = 5.
    You Need to find the possible Combiantion of numbers to reach target using the given numbers in array.

NOTE:
    1) [Use Vector + backtracking to keep track of the path, Logic is same]
    2) say you found 2 combinations [2, 2, 3] and [3, 2, 3] -> Both of this should be considered as one. [You should take only 1 out of this pair]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Approach1: using Recursion Tech [TC: Exponential]
    // NOTE: To get unique result, under each recursion call, we will not consider the all elements in candidate keys.
    void solve1(vector<int> &candidates, int keyIndex, int target, vector<int> &trackKeys, vector<vector<int>> &ans)
    {
        // baseCase: If you reached target 0, -> Store the trackKeys in ans and return..
        if (target == 0)
        {
            ans.push_back(trackKeys);
            return;
        }

        // Now For a target, iterate the candidates key from keyIndex to end [to avoid duplicates in ans]
        for (int i = keyIndex; i < candidates.size(); i++)
        {
            if (target - candidates[i] >= 0)
            {                                                                  // check if the tar-candidate exists
                trackKeys.push_back(candidates[i]);                            // keep track of the keys used..
                solve1(candidates, i, target - candidates[i], trackKeys, ans); // call Recursive with updated target values..[**IMP** NOTE we are passing i as the new start index for candidate key]
                trackKeys.pop_back();                                          // pop the keys added while returing back i.e [back-tracking]
            }
        }
    }

public:
    // Approach: will solve using choice of each candidate key for making target [Combination Sum IV appraoch]
    // and a vector to keep track of the choosed candidate key. [Involves backtracking]
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        // Lets have 2 vectors, one to keep track of the ans and other one to keep track of the choosed candidate key..
        vector<vector<int>> ans;
        vector<int> trackKeys;

        int keyIndex = 0; // this to track from where we are considering the items in candidate key array..

        solve1(candidates, keyIndex, target, trackKeys, ans);

        return ans;
    }
};

/*
Logic: Each target will have all nums as choices...

-- Draw a Recursive Tree to get for info on the Appraoch.
Recursive Logic:
    -- You start with target.
    -- Now for target you have k choices. k is the number of elements given in the array.
    NOTE: To avoid duplicate here, we will not consider all elements form the candidate array for every target.
        NOTE: Before making recursie call, make sure, the target > 0. As we cannot make negative target.
    -- for each Choices, update the trackKey Array.
    -- baseCase:
        - If tar becomes 0, push trackKey in the ans and return.
    -- Now while coming back,
        -> Pop the element that is pushed in the trackKey i.e Backtracking Method [we are tracking all the path in the Recursive call]

NOTE: To Avoid Duplicates of the Nums in the List.
    -- For each iteration, we will not consider all the elements in the candiate key list.
    -- as [2, 3, 5] -> For first key as 2, all possiblility of 2 has already been accounted for.
    -- for next call stack, we choose, [3, 5] -> Now we will check all possiblity with 3.
    -- in the next one just 5.
    -- Thus,
        -> It helps avoid duplicates in the ans vector.
        -> Also reduce the spread of the Recursive tree.

*/