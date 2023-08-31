// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
/*
    You given a preOrder Node Vals, Prepare a BST from this.
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Creation...
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
private:
    // Recursion to construct Tree based on Nodes...
    TreeNode *constructBST(vector<int> &preorder, int &index, int min, int max)
    {
        // baseCase: //If we traversed all the Nodes come back OR
        // check if it falls in the range min < Node < max...
        if (index >= preorder.size() || preorder[index] < min || preorder[index] > max)
            return NULL;

        // Take out the currNode..
        TreeNode *currNode = new TreeNode(preorder[index++]);

        // Call recursion for left and right sub-tree...
        // For left Node, min to currNodeVal..
        currNode->left = constructBST(preorder, index, min, currNode->val);
        // For right Node, currNode to max...
        currNode->right = constructBST(preorder, index, currNode->val, max);

        return currNode;
    }

public:
    // Approach: Range Limit For Nodes + Recrusion to Construct Tree... TC: O(N) SC:O(N)
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int start = 0;
        return constructBST(preorder, start, INT_MIN, INT_MAX);
    }
};

/*
Appraoch: Recursion Appraoch with Node ranges
    -- Use Recursion,
    -- Check edge case if the NOde is inBound the range or not ? OR if we visited all Nodes in preOrder List ?
    -- If not in range or we visited all Nodes, return NULL

    -- If we inboud the range, create a new Node,
    -- Left and right tree, Recursion will fetch. [NOTE: Update the index first and then use in Recursion call]

    -- return the currNode..

*/