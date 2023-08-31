// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
/*
    A BST is given and a nodeVal is given, Search the NodeVal in BST
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
private:
    // Approach1: We will use Recursion... TC: O(N)[In case of skew BST] or O(logn) [Noraml BST], SC: O(N) [Recursion]
    TreeNode *findNode(TreeNode *node, int target)
    {
        // baseCondition:
        if (node == NULL)
            return NULL;

        // check if the currentNode Matches the target ?
        if (node->val == target)
            return node;

        TreeNode *targetNode = NULL; // stores the targetNode

        // Decide to go to left or right child based on target and Node Val..
        if (target < node->val)
            targetNode = findNode(node->left, target);
        else if (target > node->val)
            targetNode = findNode(node->right, target);

        return targetNode;
    }

    // Approach2: Same Logic, USe Iterative way.. SC: O(1), TC: O(N)
    TreeNode *findNode2(TreeNode *root, int target)
    {
        TreeNode *ans = NULL;      // stores the targetNode
        TreeNode *currNode = root; // A temp Node to iterate

        // loop till you reach the Null Node...
        while (currNode != NULL)
        {
            if (currNode->val == target) // If currNode is the ans
            {
                ans = currNode;
                break;
            }
            else if (target < currNode->val) // If target < currNode, Move to left...
            {
                currNode = currNode->left;
            }
            else if (target > currNode->val) // If target > currNode, Move to right...
            {
                currNode = currNode->right;
            }
        }
        return ans; // return the target Node...
    }

public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // check if the targetval is in the root Node ?
        if (root->val == val)
            return root;

        // return findNode(root, val);
        return findNode2(root, val);
    }
};