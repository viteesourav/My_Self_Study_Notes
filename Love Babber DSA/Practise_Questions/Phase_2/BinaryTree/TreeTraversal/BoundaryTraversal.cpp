// Link: https://www.codingninjas.com/studio/problems/boundary-traversal_790725
/*
    Traverse the Tree only by using the Nodes at boundary in anti-clock dir.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// Traverse the left part of Root except leaf Nodes...[Recusrion]
void leftTraverse(TreeNode *node, vector<int> &ans)
{
    // edgeCase: If node is null OR we reached a leaf Node...
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return;

    ans.push_back(node->data); // stores the value of current Node

    // Recursion, Go to left side if it exist
    if (node->left)
        leftTraverse(node->left, ans);
    else
        leftTraverse(node->right, ans); // go to right node is left doesnot exist..
}

// For leaf Nodes...
void leafNodes(TreeNode *node, vector<int> &ans)
{
    // edgeCase:
    if (node == NULL || (node->left == NULL && node->right == NULL))
    {
        if (node != NULL)
            ans.push_back(node->data); // stores the value of current Node
        return;
    }

    // InOrder Traversal..
    leafNodes(node->left, ans);
    leafNodes(node->right, ans);
}

// Traverse the right part of Root except leaf Nodes...[Recusrion]
void rightTraverse(TreeNode *node, vector<int> &ans)
{
    // edgeCase: If node is null OR we reached a leaf Node...
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return;

    // Recursion, Go to right side if it exist
    if (node->right)
        rightTraverse(node->right, ans);
    else
        leftTraverse(node->left, ans); // go to left node is left doesnot exist..

    // while returning, store the Node val
    ans.push_back(node->data); // stores the value of current Node
}

// Appraoch: LeftTraverse + leafNodes + rightTraverse. TC: O(n)
vector<int> traverseBoundary(TreeNode *root)
{
    vector<int> ans;
    // check for edge case..
    if (root == NULL)
        return ans;

    // Start by pushing the root Node Val into the ans.
    ans.push_back(root->data);

    // check if root Node is the leaf Node...
    if (root->left == NULL && root->right == NULL)
        return ans;

    leftTraverse(root->left, ans);
    leafNodes(root, ans);
    rightTraverse(root->right, ans);

    return ans;
}

/*
Logic: What are boundary Nodes ?
    1) All Nodes which are on the left side of the root, except the leaf Nodes. [consider putting Nodes before Recursion, Order of Nodes Changes]
    2) All the leaf Nodes of the tree..
    3) All Nodes Which are on the right side of the root, except the leaf Nodes. [consider putting Nodes after Recursion, Order of Nodes Changes]

Appraoch: [leftTraverse + leafNodes + rightTravese] TC: O(N)
    -- Check edge case: If root is NULL, return ans
    -- First push the root Node into ans.
    1) leftTraverse [except the leaf Nodes...]
     -- edge Case: If Leaf Node, return
     -- push the Node Val into the ans array..
     -- Use Recursion to traverse in the left side of the root.
     -- NOTE: here if left Node dont exsit, Go to the right Node...

    2) Leaf Ndoes: Inorder Traversal..
     -- EdgeCase:
        If you reach the leafNOde, Store the Node value in the ans arr and return
     -- Travel in left Node use Recursion
     -- Travel in right Node use Reccursion.

    3) rightTraverse [except the leaf Nodes...]
     -- edge Case: If Leaf Node, return
     -- Use Recursion to traverse in the right side of the root.
     -- NOTE: here if right Node dont exsit, Go to the left Node...
     -- push the Node Val into the ans array..
*/