// Link: https://leetcode.com/problems/balance-a-binary-search-tree/
/*
    A BST is given, Return a balanced BST.
    Balanced BST:
        -- For every Node, the diff between the left Tree and right tree must be at max 1.
        -- i.e abs[leftTreeHeight - rightTreeHeight] <= 1
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
    // Function to Fetch the sorted Inorder List of the Node's data. [using Recusrion]
    void inorderTraversal(TreeNode *root, vector<int> &list)
    {
        // baseCase:
        if (root == NULL)
            return;

        inorderTraversal(root->left, list);
        list.push_back(root->val);
        inorderTraversal(root->right, list);
    }

    // This creates a Balanced BST from the List...[Recusrion]
    TreeNode *constructBalancedBST(int start, int end, vector<int> list)
    {
        // baseCase: If the start moves ahead of end...
        if (start > end)
            return NULL;

        // Find the mid, and create a new node with that...
        int mid = start + (end - start) / 2;
        TreeNode *newNode = new TreeNode(list[mid]);

        // Now Recursion, fetch me the tree for the left side...
        newNode->left = constructBalancedBST(start, mid - 1, list);
        // Now Recursion, fetch me the tree for the right side...
        newNode->right = constructBalancedBST(mid + 1, end, list);

        return newNode;
    }

public:
    // Appraoch: Inorder Traversal + BST TreeCreation using Recursion..
    TreeNode *balanceBST(TreeNode *root)
    {
        // Have the sorted Lsit of the Nodes from the BST
        vector<int> list;
        inorderTraversal(root, list);

        // Now we have the list,use Recursion to Construct a Balanced BST...
        int s = 0, e = list.size() - 1;
        root = constructBalancedBST(s, e, list);

        return root;
    }
};

/*
    Appraoch:
        -- Get the inOrder Traversal For the BST. [Sorted Node List]
        -- Now use Recursion.
           -- Take the List, find the mid Node, make that as root,
           -- left all elements of mid will form the left Tree [Recursion will provide this]
           -- right all elements of mid will form the right Tree [Recursion will provide this]
    -- BST is balanced.

    Additional Queustion: How we know if a BST is balanced or not ?
        -- Use Recursion + pair<height, isBalanced>
        -- Traverse the Tree, using Recursion.
        -- For each Node, From left you will get the height and if it's balance ?
        -- For each Node, From right you will get the height and if it's balance ?
        -- Consider both of them and return for the currNode if it's balanced or not !
*/