// Link: https://leetcode.com/problems/same-tree/description/
/*
    Baisaclly given 2 Tree, Need to findout if they are identical or not ?
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
    // Appraoch1: using REcursion [TC: O(n)]
    bool checkIdentical(TreeNode *root1, TreeNode *root2)
    {
        // baseCase:
        if (root1 == NULL && root2 == NULL)
            return true; // If both roots are NULL
        else if (root1 == NULL || root2 == NULL)
            return false; // If either of them is NULL

        bool isLeftIdentical = checkIdentical(root1->left, root2->left);    // Check the left identical or not ?
        bool isRightIdentical = checkIdentical(root1->right, root2->right); // Check the right identical or not ?

        // based on left and right Node, we will deciide if the current node is identical or not ?
        // checks, if left and right are identical and if the current Node is identical or not ?
        return isLeftIdentical && isRightIdentical && (root1->val == root2->val);
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return checkIdentical(p, q);
    }
};

/*
Appraoch1: USe Recursion. [TC: O(n), visiting all Node atleast once.]
    -- It takes root1 and root2, belongs to both of the tree...
    -- base Case:
        1) if root1 and root2 both are NULL together then return true.
        2) if either root1 is NULL or root2 is NULL then return false. [Tree is not identical]

    -- Recusrion will fetch if the left and right child are identical or not.
    -- current child is identical if the root1 and root2 have the same value.
    -- If the above 2 conditions are true, return true, else false.
[**DONE**]
*/