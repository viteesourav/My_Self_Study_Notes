// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
/*
    Given a tree, Find the return of the max possible dept of the leaf Node.
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
public:
    // Appraoch: We will use a inOrder traversal, update the count and maxCount.
    void solve(TreeNode *root, int count, int &maxCount)
    {

        // Base Condition: If you reached the end, Just come back...
        if (root == NULL)
            return;

        // Traverse in left Nodes...
        solve(root->left, count + 1, maxCount);
        // If you reached a leaf Node while traversing just update the maxCount...
        if (root->left == NULL && root->right == NULL)
            maxCount = max(maxCount, count);
        // Traverse in right Nodes...
        solve(root->right, count + 1, maxCount);
    };

    // Appraoch 2: Use Noraml Recursion,
    int solve2(TreeNode *root)
    {
        // baseCase:
        if (root == NULL)
            return 0;

        // Assume REcursion to give me the height of left Side tree of the curr Root
        int leftHeight = solve2(root->left);
        // Assume REcursion to give me the height of right Side tree of the curr Root
        int rightHeight = solve2(root->right);

        // Now for the current Node, you have left and right height...
        int maxHeight = max(leftHeight, rightHeight) + 1; //+1 because the current Node is also added in the height.
        return maxHeight;
    }

    int maxDepth(TreeNode *root)
    {
        // edgeCase: If the root is null, return 0;
        if (root == NULL)
            return 0;
        int count = 1;
        int maxCount = 1;
        solve(root, count, maxCount);
        return maxCount;
    }
};

/*
Appraoch1: Do inOrder Traveral, look for leaf Nodes and update maxCount.
    -- Whenever you go left or right, The levelcount must increase.
    -- If you reached a leaf Node, Max sure you check if the current levelCount is max, If so store it.
    [**DONE**]

[This is faster Appraoch...] TC: O(N) SC: O(n)
Approach 2: Recursion concept. [Solve 1 case, Rest cases Recursion will take care]
    -- Get the left side tree height of the current Node using REcursion.
    -- Get the right side tree height of the current Node using Recursion.
    -- current Dept = max(left, right) + 1;
    -- Retunr currentDept. [Rest REcursion will take care...]
    [**DONE**]

*/