// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/*
    given a BST, and 2 nodes, p and q, Find the LCA of p and q.
*/
#include <bits/stdc++.h>
using namespace std;

// Tree Creation...
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Approach: Iterative Approach TC:O(N) SC: O(1)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // take a currNode to traverse...
    TreeNode *currNode = root;

    while (currNode != NULL)
    {
        // 1) check if both p and q less than currNode ?
        if (p->val < currNode->val && q->val < currNode->val)
            currNode = currNode->left;
        else if (p->val > currNode->val && q->val > currNode->val) // 2) check if both p and q mote than currNode ?
            currNode = currNode->right;
        else
            break; // 1) if p and q are not on same side of the currNode ?
    }
    return currNode;
}

/*
Approach: [Iterative Appraoch: TC:O(N), SC:O(1)]
    -- Start from the root Node, till it becomes NULL...
    -- Take the currNode,
        1) if p and q both are less than currNode, Go to the left Tree.
        2) if p and q both are more than currNode, Go to right Tree.
        3) If p and q falls under 2 sides of a node, either left or right, Then this is the ancestor.
*/