// Link: https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_893103
/*
    you given a Binary Tree, You need to tell what is the max possible size of BST exist inside the given Tree.

*/
#include <bits/stdc++.h>
using namespace std;

// Tree Creation...
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// declaring a class that holds info for each Nodes...
class Info
{
public:
    int mini;
    int maxi;
    bool isBST;
    int totNodes;
};

// Implementing the Recursive method of traverse the Tree...
Info traverseTree(TreeNode *root, int &ans)
{
    // baseCase: If the node is NULL, return {min, max, isValidBST, totNodes}
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN, true, 0};
    }

    // Now at any Node, First fetch the Info from the left and right Trees.. [Recursion will do it]
    Info leftTree = traverseTree(root->left, ans);
    Info rightTree = traverseTree(root->right, ans);

    // Now we need to decide what to send back for the currNode ?
    Info currNodeInfo;

    // The min node val will be between currNode and miniNode from left Tree..
    currNodeInfo.mini = min(root->data, leftTree.mini);
    // The max node val will be between currNode and maxiNode from right Tree..
    currNodeInfo.maxi = max(root->data, rightTree.maxi);
    // The currNode will be a BST if 1) Left is bst, 2) right is BST and 3) IT satisfy BST conditon.
    currNodeInfo.isBST = (leftTree.isBST && rightTree.isBST && (root->data > leftTree.maxi && root->data < rightTree.mini)) ? true : false;
    // Total No of Nodes: leftTreeNodes + rightTreeNodes + currNode
    currNodeInfo.totNodes = leftTree.totNodes + rightTree.totNodes + 1;

    // If the currNode is a BST, store the max totNodes in ans...
    if (currNodeInfo.isBST)
    {
        ans = max(ans, currNodeInfo.totNodes);
    }

    return currNodeInfo;
}

// Appraoch: Recursive way..
int largestBST(TreeNode *root)
{
    int ans = 0;
    Info resp = traverseTree(root, ans);
    return ans;
}

/*
    Appraoch: Recusrive Appraoch
        -- At each Node, I need 4 info to decide if it's a valid BST or not ?
            1) If the left side is a BST or not ?
            2) If the right side is a BST or not ?
            3) If both are BST, then check if the currNodeVal > maxFrom the left Tree and currNodeVal < min From the right Tree.
            4) If all 3 satisfy, I need to find the max Size for the current Tree.
        -- Start with a class that holds 4 data:
            1) mini [Holds the minimum Node val]
            2) maxi [Holds the maximum Node val]
            3) isBST [Holds boolean if its a BST]
            4) totNodes [Holds total Number of visited Nodes]
        -- The Recusrion takes the rootNode and ans [holds the max totNodes for any found BST]
*/