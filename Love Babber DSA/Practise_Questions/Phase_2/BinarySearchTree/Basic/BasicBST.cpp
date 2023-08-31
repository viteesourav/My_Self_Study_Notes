/*
    Implementing a BST. [For Each Node, left Child is smaller and right child is greater]
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Creation...
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Approach: Uses Recursion: TC: O(log n)
TreeNode *constructBST(TreeNode *node, int val)
{
    // baseCase:
    if (node == NULL)
    {
        // create a new Node and return..
        TreeNode *newNode = new TreeNode(val);
        return newNode;
    }

    // Check if the val is less or greater ?
    if (val < node->data)
    {
        node->left = constructBST(node->left, val); // travese in left Child
    }
    else if (val > node->data)
    {
        node->right = constructBST(node->right, val); // travese in right Child
    }

    return node;
}

// inorder Traversal,[Recursion] TC: O(N)
void inOrderTraverse(TreeNode *node)
{
    // baseCase:
    if (node == NULL)
        return;

    inOrderTraverse(node->left);
    cout << node->data << " ";
    inOrderTraverse(node->right);
}

int main()
{

    // Getting NodeVals and inserting them in BST..
    TreeNode *root = NULL;
    int val;
    cout << "Enter the NodeVal for BST, till -1" << endl;
    cin >> val;
    while (val != -1)
    {
        root = constructBST(root, val);
        cin >> val;
    }

    // Printing the BST using inorder Traversal..
    cout << endl;
    inOrderTraverse(root);

    return 0;
}