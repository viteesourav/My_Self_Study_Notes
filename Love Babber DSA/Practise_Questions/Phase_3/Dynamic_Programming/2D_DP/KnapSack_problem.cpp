// Link:https://www.codingninjas.com/studio/problems/0-1-knapsack_1072980
/*
Basically, You have given a KanpSack i.e Bag that can carray max weight of W. There are N items with Wi Weight and Vi Value.
    Find the max possible Value that the kanpsack can hold ?
[Example of 2D DP]
*/
#include <bits/stdc++.h>
using namespace std;

// Appraoch1: Recursive [Move right to left, either you consider the element or exclude it][TC:O(2^n, exponential) SC: O(n)]
int solve1(vector<int> &values, vector<int> &weights, int n, int capacity, int index)
{
    // baseCase: If we reached the first item..
    if (index == 0)
    {
        // you at first index and you have space in knapsack, return the value, else return 0
        if (weights[index] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }

    // Now For any item, You got 2 choices -> either to include ot exclude it..
    int includeSum = 0, excludeSum = 0;
    // to include, check if you have space in your knapsack..
    if (weights[index] <= capacity)
    {
        includeSum = values[index] + solve1(values, weights, n, capacity - weights[index], index - 1); // Recusion will fetch...
    }
    excludeSum = 0 + solve1(values, weights, n, capacity, index - 1); // since we have not include item at index, capacity of knapsack reamin unchnage..

    return max(includeSum, excludeSum); // which ever gives max result include that..
}

// Appraoch2: Recursion + Memorization.[TC:O(n*w) SC: O(n*w)]
// NOTE: Here 2 things changing so we need a 2-D dp vector...
int solve2(vector<int> &values, vector<int> &weights, int n, int capacity, int index, vector<vector<int>> &dp)
{
    // baseCase: If we reached the first item..
    if (index == 0)
    {
        // you at first index and you have space in knapsack, return the value, else return 0
        if (weights[index] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }

    // check if the dp already holds the value..
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // Now For any item, You got 2 choices -> either to include ot exclude it..
    int includeSum = 0, excludeSum = 0;
    // to include, check if you have space in your knapsack..
    if (weights[index] <= capacity)
    {
        includeSum = values[index] + solve2(values, weights, n, capacity - weights[index], index - 1, dp); // Recusion will fetch...
    }
    excludeSum = 0 + solve2(values, weights, n, capacity, index - 1, dp); // since we have not include item at index, capacity of knapsack reamin unchnage..

    dp[index][capacity] = max(includeSum, excludeSum); // which ever gives max result include that..

    return dp[index][capacity];
}

// Appraoch3: Tabulation. [TC:O(n*w) SC: O(n*w)]
// NOTE: Here dp[index][capacity] [The handling of this is imp]
int solve3(vector<int> &values, vector<int> &weights, int n, int capacity)
{
    // crate the 2D dp vector...
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0)); // with n Rows and capacity+1 cols...

    // Analysing the base Case...
    for (int w = weights[0]; w <= capacity; w++)
    {
        // you at first index and you have space in knapsack, return the value, else return 0
        if (w <= capacity)
        {
            dp[0][w] = values[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    // Now for 1st Row we handled in baseCase, for next n-1 items we will use a loop..
    for (int index = 1; index < n; index++)
    { // Runs Rows wise i.e for each items..
        for (int w = 0; w <= capacity; w++)
        { // Runs in col wise for all the capacity..

            // Now For any item, You got 2 choices -> either to include ot exclude it..
            int includeSum = 0, excludeSum = 0;
            // to include, check if you have space in your knapsack..
            if (weights[index] <= w)
            {
                includeSum = values[index] + dp[index - 1][w - weights[index]];
            }
            excludeSum = 0 + dp[index - 1][w];

            dp[index][w] = max(includeSum, excludeSum); // which ever gives max result include that..
        }
    }

    return dp[n - 1][capacity]; // n-1th item, max Value possible...
}

// Approch4: Space optimization is possible, [TC:O(n*w) SC: O(w) + O(w)]
// for each dp[index] depends upon it's last row, dp[index-1] and some col representing w-weights[index] from the last Row..
int solve4(vector<int> &values, vector<int> &weights, int n, int capacity)
{
    // First lets have 2 vectors prev1 and prev2 having the cols representing capacity-> 0 to capacity+1..
    vector<int> prev1(capacity + 1);
    vector<int> prev2(capacity + 1);

    // Now By Analysing the base case, lets fill the prev1 for item index -> 0
    for (int w = weights[0]; w <= capacity; w++)
    {
        if (w <= capacity)
        {
            prev1[w] = values[0];
        }
        else
        {
            prev1[w] = 0;
        }
    }

    // Now lets run a loop for all the items till n-1 and upadte the values..
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {

            // Now For any item, You got 2 choices -> either to include ot exclude it..
            int includeSum = 0, excludeSum = 0;
            // to include, check if you have space in your knapsack..
            if (weights[index] <= w)
            {
                includeSum = values[index] + prev1[w - weights[index]]; // prev1 is representing dp[index-1]th Row
            }
            excludeSum = 0 + prev1[w];

            // prev2 is represting the index row, which we are filling now...
            prev2[w] = max(includeSum, excludeSum); // which ever gives max result include that..
        }

        // Once we fill all the Cols, Now prev1 will be pointing to prev2.
        prev1 = prev2;
    }

    return prev2[capacity]; // This holds the max Value for the given capacity..
}

// Approach5: furthur Optimization [We used Prev1 and prev2 vector to keep track of previous and current Row] [TC:O(n*w) SC: O(w)]
// Here we can optimize to have work with just prev1 vector.
int solve5(vector<int> &values, vector<int> &weights, int n, int capacity)
{
    // First lets have 1 vectors prev1 having the cols representing capacity-> 0 to capacity+1..
    vector<int> prev1(capacity + 1);

    // Now By Analysing the base case, lets fill the prev1 for item index -> 0
    for (int w = weights[0]; w <= capacity; w++)
    {
        if (w <= capacity)
        {
            prev1[w] = values[0];
        }
        else
        {
            prev1[w] = 0;
        }
    }

    // Now lets run a loop for all the items till n-1 and upadte the values..
    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--)
        { // we will reverse the direction of iterating the cols.

            // Now For any item, You got 2 choices -> either to include ot exclude it..
            int includeSum = 0, excludeSum = 0;
            // to include, check if you have space in your knapsack..
            if (weights[index] <= w)
            {
                includeSum = values[index] + prev1[w - weights[index]]; // prev1 is representing dp[index-1]th Row
            }
            excludeSum = 0 + prev1[w];

            // we will modify the same vector with updated value from right to left one by one...
            prev1[w] = max(includeSum, excludeSum); // which ever gives max result include that..
        }
    }

    return prev1[capacity]; // This holds the max Value for the given capacity..
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // return solve1(values, weights, n, w, n-1); //starting from the right most item.

    // vector<vector<int>> dp(n, vector<int>(w+1, -1)); //here w is the capacity of the bag..[row is index, cols are maxWeight+1]
    // return solve2(values, weights, n, w, n-1, dp);

    // return solve3(values, weights, n, w);

    // return solve4(values, weights, n, w);

    return solve5(values, weights, n, w);
}

/*
Logic: [Either we pick an item or we dont]

capacity : 10
           0  1  2  3
weights = [6, 1, 5, 3]
values =  [3, 6, 1, 4]

Approach: [Recursive]
    baseCase: If say only 1 item is there [i.e only the first item]
        -- check if the weight of the item, we can include in kapsack.
        -- if yes -> return the value. else return 0

    -- For each item,
        1) check if there weight can be managed in the kapsack. include the value.
        -- If not, ignore that.
        2) exclude the item from the knapsack, i.e add 0 value.
    -- find both the include and exclude sum from Recursion.
    -- Take the max of both and return that.

NOTE: It's a 2D DP problem, as for each Recursion call, the capacity and itemIndex are dependent.

** For Recursion + Memorization:
    -- create a DP that have Rows holding the index of the item.
    -- and columns holding spaces for maxWeight + 1.
    -- and for each Recursion, dp[index][capacity] -> Hold the max Value possible for that item at that capacity.

** For Tebulation:
    -- Convert the Recursion + Memorizzation into a 2D DP + looping logic.
    -- Each Row will signify the item's index.
    -- And Columns will go from 0 to maxCapacity+1.

** space Optimization:
    -> we have 2 level of space Optimization,
        1) one using prev1 and prev2 vector.
        2) Furthur it can reduced to just one vector. [The loop direction will change to Right to left.]
        Why ?
            -- as per the logic dp[index][w] = value[index] + dp[index-1][w-weight[index]].
            -- i.e dp[index] for w depends upon previous row i.e index-1 and some col w-weight[index].
            -- Now In the range, w-weight[index] lies in the left side of [inde-1][w], So in left to right traversal, values might get updated.
            -- to avoid this, we are going from right to left.

*/
