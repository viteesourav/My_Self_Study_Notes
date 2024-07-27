//Link: https://leetcode.com/problems/merge-intervals/
/*
Problem: Given a list of intervals.. eg: [1, 3] [2, 6] [8, 10],[9, 12] [15, 18]
    Merge them...
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //function: Is prossible to merge 2 intervals ? 
    bool isMergePossible(vector<int> p1, vector<int> p2) {
        if(p1[1] >= p2[0])
            return true;
        else 
            return false;
    }

    //function: Returns a new merged Interval.. [a,b] [c,d]
    vector<int> getMergedInterval(vector<int> p1, vector<int> p2) {
        vector<int> merged(2, 0);
            merged[0] = min(p1[0], p2[0]);  // which ever is samll between a and c.
            merged[1] = max(p1[1], p2[1]);  //which ever is bigger between b and d.
        return merged;
    }

    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //First lets sort the intervals...
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans; //stores the merged intervvals..

        //lets push the first interval inside the ans...
        ans.push_back(intervals[0]);

        //Now Loop the intervals starting from i=1..
        int i = 1;
        while(i<intervals.size()) {
            int k = ans.size()-1;
            //checks, if it's possible to merge the intervals... NOTE: Order is imp, ans[k] then intervals[i]
            if(isMergePossible(ans[k], intervals[i])) {
                ans[k] = getMergedInterval(ans[k], intervals[i]);  
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;    
    }
};

/*
TC: O(Nlogn), SC: O(1) [Except the output vector]
Logic: 
    1. Sort the intevals. --> sort the given intervals based on starting point.
    2. 2 Methods: [a, b] [c, d]
        1. IsMergePossible ?  --> check is b >= c
        2. getMergedInterval --> min(a, c) and max(b, d)
    3. In Main Method:
        - Push the first element inside ans.
        - Iterate the intervals from index 1 till n-1...
        - For each interval check isMergePossible ? [NOTE: the order matters, first ans then intervals] 
            - If yes,  replace the last element of ans with mergedInterval.
            - If No, simply insert that interval into ans.
*/