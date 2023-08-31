/*
Basically, You given a binary Search Tree and a Node X. Find Predecessor and succssor of the given Node..
    If you do a inorder Traversal,
        Predecessor -> Immediate previous Node of Node X.
        Successor -> Immediate next Node of Node X.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// Appraoch: Iterative, Find KeyNode + Inorder predecessor and sucessor Logic
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1, sucessor = -1;

    // First lets find the key Node in the BST...
    TreeNode *currNode = root;

    while (currNode->data != key)
    {

        // check the key and move to either left or right tree...
        if (key < currNode->data)
        {
            sucessor = currNode->data; // Since key is smaller, so current Node may be the successor..
            currNode = currNode->left;
        }
        else if (key > currNode->data)
        {
            pred = currNode->data; // Since key is bigger, so current Node may be the predecessor..
            currNode = currNode->right;
        }
    }

    // Now you have the currNode at key..

    // pred: Find the max possible node val from the left Tree..
    if (currNode->left)
    {
        TreeNode *temp = currNode->left;
        while (temp->right != NULL)
            temp = temp->right; // max value always lie on the right in BST...
        pred = temp->data;
    }

    // sucessor: Find the min possible node val from the right-most Tree..
    if (currNode->right)
    {
        TreeNode *temp = currNode->right;
        while (temp->left != NULL)
            temp = temp->left; // min value always lie on the left-most in BST...
        sucessor = temp->data;
    }

    return make_pair(pred, sucessor);
}

/*
    Approach1: [Perform Inorder Traversal]
        -- Two Appraoch Of Inroder Traversal: Recursion [TC: O(N), SC:O(N)] OR Morris Traversal [TC:O(N) SC: O(1)]
        -- Once you get the inorder list,
            find predecessor and successor of Node X
    [**DONE**]

    Logic: If at a Node X, in a BST
        -- Predecessor of Node X -> maxNode val from the left tree of the currNode.
        -- Successor of Node X -> minNode val from the right tree of the currNode.

    Approach2: [use the above Logic: ]
        -- have pred = succ as -1.
        -- First Find the NOde X in the given tree.
            -- If you go to left tree, then currNode is > X then it a possible successor.
            -- If you go to right tree, then currNode is < X then it a possible predecessor.
        -- Once the node X Found,
            -- predecessor: find the maxNode from the left Tree.[Go to left Tree and move right till yoou hit NULL]
            -- Successor: find the miniNode from the right Tree.[Go to left Tree and move left till you hit NULL]
        -- return predcessor and successor.
    [**DONE**]

*/