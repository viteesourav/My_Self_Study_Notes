// Link: https://leetcode.com/problems/validate-binary-search-tree/
/*
    A BTree is given, Have to tell if the given tree is a BST or not ?
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

class Solution
{
public:
    // Appraoch: Use Recursion and check if each node Falls in BST range..
    bool isBST(TreeNode *node, long min, long max)
    {
        // check for base Case:
        if (node == NULL)
            return true;

        // Check if the current Node falls in the range ?
        if (node->val > min && node->val < max)
        {

            // use Recursion to find if the left and right child tree are BST ?
            bool leftChild = isBST(node->left, min, node->val); // For leftTree,max Node val will be < currNode
            // For rightTree, min Node val will be > currNode
            bool rightChild = isBST(node->right, node->val, max);

            // Return true only if left and right tree are BST...
            return leftChild && rightChild;
        }
        else
        {
            return false; // If it wont fall in the range...
        }
    }

    bool isValidBST(TreeNode *root)
    {
        return isBST(root, LONG_MIN, LONG_MAX); // Range for root Node can be anything..
    }
};

/*
Logic:
    1) Do inOrder Traversal, If the Nodes are sorted then its BST.
    2) For each Node, Check the Range.
        -- For left Tree, All Nodes should be less than rootNOde.
        -- For RightTree, All nodes should be greater than rootNode.
    -- If all Node satisy this, then its BST
    NOTE: Take the range as the max possible, use long_min and long_max [Its range is higher than int_min and int_max]
*/