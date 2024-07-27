//Link: https://leetcode.com/problems/two-sum/
/*
Problem: Given a arr: [2,7,11,15], target--> 9.
    -- Now Find the "index" of those 2 numbers in arr whose sum can acheive target.
NOTE: You cannot sort the arr --> as position of the numbers will change.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       //lets take an unordered_map --> Our lookup table reminder --> index
       unordered_map<int, int> track;
       vector<int> ans;

        //iterate the arr...
       for(int i=0; i< nums.size(); i++) {
            //check if the map holds the reminder..
            if(!track.count(nums[i])) {
                int rem = target-nums[i];
                track.insert({rem, i});
            } else {
                //if we found a match...
                ans.push_back(track[nums[i]]);
                ans.push_back(i);
                break;
            }
       }
       return ans;
    }
};

//TC: O(N) SC: O(N)
/*
Logic:
    1. We use unordered_map --> keep tracks of reminder and index.
    2. Iterate the arr..
    3. Check if the map holds the ele ?
        --> If yes, Take that value from map, Take the current index --> return.
        --> If No, Find the reminder for the curr ele, Store reminder --> index of curr ele.
*/