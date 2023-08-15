// Link: https://www.codingninjas.com/studio/problems/check-if-binary-tree-is-sum-tree-or-not_1164404
/*
Basically, For each and every Node, If sum of all Nodes on left and right is equal to the current Node,
        then its balanced.
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Approach1: Recusrion + pair [pair<isSumTree, SumAllChildNodes>]
pair<bool, int> appraoch1(TreeNode *root)
{
    // baseCase:
    if (root == NULL)
        return make_pair(true, 0); // If the Node is null, isSumTree -> T and sumAllNode -> 0
    // if the Node is a leaf Node...
    if (root->left == NULL && root->right == NULL)
        return make_pair(true, root->val); // IF leaf Node, issumTree -> T and sumAllNode -> val at leaf node.

    // Recusrion, fetch me data for left and right child for current Node..
    pair<bool, int> leftNode = appraoch1(root->left);
    pair<bool, int> rightNode = appraoch1(root->right);

    // Now For the current Node, check of sum of left and right Node sum is same as current Node.
    bool currentNode = leftNode.second + rightNode.second == root->val;

    // Make a newPair and update the currentNode and sumOfALLchildNOde..
    pair<bool, int> newPair;
    newPair.first = leftNode.first && rightNode.first && currentNode; // if all this are true then okay, else false.
    // Store the new Sum of all Nodes including the rootNode
    newPair.second = leftNode.second + rightNode.second + root->val;

    return newPair;
};

bool isSumTree(TreeNode *root)
{
    return appraoch1(root).first; // First part holds if it isSumTree or not ?
};

/*
TC: O(N)
Appraoch: Recursion + Pair [pair<isSumTree, totalChildNodeSume>]
    -- Base Case:
        1) Current Node is null, isSumTree -> true and totalChildNodeSum -> 0
        2) Current Node is leaf Node, isSumTree -> true and totalChildNodeSum -> currentNode Val

    -- Recursion, fetch me the data for the left and right child of the current Node..
    -- For current Node to be a isSumTree ture, Conditions:
        1) leftNode should be isSumTree true.
        2) rightNode should be isSumTree true.
        3) currentNode = sum of all child for left + sum of all child for right == current node.
    -- make a new Pair,
        isSumTree will be true, if all above condition are true.
        sum of all child is leftSumChildcount + rightSumChildCount + currentNodeVal.
    retun newPair.
[**DONE**]
*/