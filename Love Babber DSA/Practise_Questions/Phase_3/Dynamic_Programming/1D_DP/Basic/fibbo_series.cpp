//Link: https://leetcode.com/problems/fibonacci-number/description/
/*
    Given a integer n, Find the nth Fibbo's Number. Use DP Appraoch:
        1) Without DP: Normal Recursion on F(n) = F(n-1) + F(n-2)
        2) Top Bottom: Use Recusion + Memorization
        3) Bottom Up: Use a 1-D/2-D Data Straucture for Tracking the values.
        4) Space Optimization: Remove the use of additional Data Structure to track the values, use normal Variables. 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Approach1: Normal Recursion...
    int solve1(int n) {
        //baseCase:
        if(n==0 || n==1) return n;
        return solve1(n-1) + solve1(n-2);  //Fibo: f(n) = f(n-1) + f(n-2)
    }

    //Approach2: Memorization...
    int solve2(int n, vector<int>& resMap) {
        //base case:
        if(n==0 || n==1) {  //if n is 1 or 0, store in the respMap and return the value it holds.
            resMap[n] = n;
            return resMap[n];
        }

        //check if the respMap holds the ans for n, if yes, returns value..
        if(resMap[n] != -1)
            return resMap[n];
        
        //If not in resMap, call the recursion, store the res in the respMap..
        resMap[n] = solve2(n-1, resMap) + solve2(n-2, resMap);
        return resMap[n];   //return the value it holds   
    }

    //Approch3: Tabualtion [No Recursion]
    int solve3(int n, vector<int>& resMap) {
        
        //First lets store the base case in the resMap...
        resMap[0] = 0; resMap[1] = 1;

        //use a loop to find the value of n...
        for(int i=2; i<=n; i++) {
            resMap[i] = resMap[i-1] + resMap[i-2];//the value at index n is sum of valueAt(n-1) + valueAt(n-2)
        }

        //return the value at n from the resMap..
        return resMap[n];
    }

    //Approach4: Let's Remove the space occupied by vector...
    int solve4(int n) {
        //let have 2 index pointer...
        int prev = 0, curr = 1;

        //Now for finding the fibbo for n>1 [since for 0 and 1 already handled]
        for(int i=2; i<=n; i++) {
            int val = prev+curr;
            prev = curr;
            curr = val;
        }

        //At the end, return the curr..
        return curr;
    }

    int fib(int n) {
        
        //Appraoch1: Noraml Recursion TC: O(2^n) SC:O(n)
        // return solve1(n);
        
        //Appraoch2: Recursion + Memorization TC: O(n) SC:O(n)*O(n)
        // vector<int> resMap(n+1, -1);
        // return solve2(n, resMap);
        
        //Appraoch3: Tabulation TC: O(n) SC:O(n)
        // if(n==0) return 0;
        // if(n==1) return 1;
        
        // vector<int> resMap(n+1);
        // return solve3(n, resMap);

        //Appraoch4: Space Optimization TC: O(n) SC:O(1)
        if(n==0) return 0;
        if(n==1) return 1;

        return solve4(n);

    }
};