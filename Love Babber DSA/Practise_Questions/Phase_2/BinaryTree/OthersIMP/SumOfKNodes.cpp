// Link: https://leetcode.com/problems/path-sum-iii/
/*
You have BTree, You have a targetSum, Find me total Number of possible paths [Not necessary go through the root]
    where the sum of nodes is targetSum.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
private:
    // Approach: Recursive + vector to track the Node Path
    // TC: O(n^2)[As Recursion we visit each Node, for each Node we see if targetSum exist]
    void solve(TreeNode *node, int target, int &count, vector<int> &trackNodes)
    {
        // baseCase:
        if (node == NULL)
            return;

        // For the currentNode, we will track the currentNode..
        trackNodes.push_back(node->val);

        // After the node is inserted, we see if the targetSum exist ?
        long sum = 0;
        for (int i = trackNodes.size() - 1; i >= 0; i--)
        {
            sum += trackNodes[i];
            if (sum == target)
                count++;
        }

        // Now go to the left and right Child...
        solve(node->left, target, count, trackNodes);
        solve(node->right, target, count, trackNodes);

        // while returning back from the currentNode, we should remove the currentNode from track..
        trackNodes.pop_back();
    };

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int count = 0;
        vector<int> trackNodes; // Vector to keep track of the path..
        solve(root, targetSum, count, trackNodes);
        return count;
    }
};

/*
Logic:
    Do the treeTravesal, look for all the paths, and check if the nodes in that path has targetSum ?
        -- Maintain a vector, that stores the Nodes val, and check for targetSum.
        -- Use Recursion.

Appraoch: Recursion + vector to Store NodePath Values
    EdgeCase:
        -- If you reach the end of the Node, Just come back..
    -- Add the current Node to the path, and check if the target sum exist ?
        -- Run a loop in vector from back, and see if target sum is there, If yes, increment count.
    -- REcursion go to the left and go to Right Nodes...
    -- While Returning,
        The current Node should be removed. [**IMP**] [AS we are going back in the path]
    Count should give the answer...
[**DONE**]

*/