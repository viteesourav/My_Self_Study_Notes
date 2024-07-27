// Link: https://leetcode.com/problems/product-of-array-except-self/description/
/*
Problem:
    Given an arr: [1,2,3,4], Return a new arr --> [24,12,8,6], At any pos i, it should hold the prod of all element except itself.
    eg: at i=0, ans[0] -> 2*3*4 ->24
        at i=1, ans[1] -> 1*3*4 ->12 ans so on...
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // prefix ans sufix Product solution...
    vector<int> productExceptSelf(vector<int> &nums)
    {

        // lets define 2 array of the same size in heap..
        int *prefixProd = new int[nums.size()];
        int *sufixProd = new int[nums.size()];

        for (int i = 0; i < nums.size(); i++)
        {
            prefixProd[i] = 1;
            sufixProd[i] = 1;
        }

        // lets first handle the prefix product.. [formula: prefix[i] = prefix[i-1]*nums[i-1]]
        int i = 1;
        while (i < nums.size())
        {
            prefixProd[i] = prefixProd[i - 1] * nums[i - 1];
            i++;
        }
        i = nums.size() - 2;
        while (i >= 0)
        {
            sufixProd[i] = sufixProd[i + 1] * nums[i + 1];
            i--;
        }

        // Lets now respective values from prefix and sufix arr..
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = prefixProd[i] * sufixProd[i];
        }

        // free the arr from the heap..
        delete[] prefixProd;
        delete[] sufixProd;

        return ans;
    }
};

/*
Logic: PrefixProduct and SuffixProduct Concept...
    1. Create 2 arrays one for prefixArr ans sufixArr with size same as nums. --> Make the arrs in heap.
        -- it saves stack memory. eg: int* prefixArr = new int[nums.size()];
        -- NOTE: at the end, remember delete[] prefixArr.
    2. initialise both the arrays with 1.
    3. prepare the prefixArr
        -- iterate from i=1 to i=n-1
        -- Formula: prefixArr[i] = prefix[i-1]*nums[i-1];
        -- Keep tracks of the previous productArr...
    4. prepare the sufixArr
        -- iterate from i=n-1 to i=0
        -- Formula: sufixArr[i] = sufix[i+1]*nums[i+1];
        -- Keep tracks of the next productArr...
    5. prefixArr -> [p1, p2, p3, p4]
       sufixArr  -> [s1, s2, s3, s4]
       ans -> [p1s1, p2s2, p3s3, p4s4] --> Returns the product of all nums excepts itself
*/