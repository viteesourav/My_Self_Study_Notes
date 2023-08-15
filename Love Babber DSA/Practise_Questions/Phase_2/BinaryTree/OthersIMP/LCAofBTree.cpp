// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/*
    We have a Btree, You have 2 Nodes n1 and n2, Need to find the immediate ancestor of n1 and n2.
    This immediate ancestor is also called lowest Common Ancestor (LCA)
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    // Appraoch: Recursive [Traverse, find p and q in the tree]
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // baseCase:
        if (root == NULL)
            return NULL; // 1) If reached the end of tree, return NULL
        // 2) At current NOde, see if that matches p or q, If matches return the current Node..
        if (root->val == p->val || root->val == q->val)
            return root;

        // Now See for leftNode and rightNode...
        TreeNode *leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightNode = lowestCommonAncestor(root->right, p, q);

        // lets have tempNode
        TreeNode *temp = NULL;

        // Now at the currentNode...
        // 1) If left and right Nodes both are not null, return currentNode..
        if (leftNode != NULL && rightNode != NULL)
            temp = root;
        // 2) If left is there but right is not there or vise-versa, return the one which is not null
        else if (leftNode != NULL && rightNode == NULL)
            temp = leftNode;
        else if (leftNode == NULL && rightNode != NULL)
            temp = rightNode;
        // 3) If both are null, return NULL
        else if (leftNode == NULL && rightNode == NULL)
            temp = NULL;

        return temp;
    }
};

/*
Logic:
    you traverse the tree, If any Node matches with n1 or n2, retrun that node value up, else return null.
    At a praticular node, If left and right already returing some value, means Current Node is the ancestor of n1 and n2,
    So return the current node.

TC: O(n) SC: O(n) [Function stack will be equal to max dept.]
Appraoch: Recursion [Inorder Recursion]
    -- baseCase:
        1) If node is null comeback..
        2) If the current Node is either n1 or n2, Return the value of this node...
    -- Call Recursion for the leftNode and rightNode...
    -- Check for 3 conditions:
       1) If leftNode and rightNode both are not null, Return the current rootNode.
       2) IF leftNode is not NULL but rightNOde is null, return leftNode.
       3) If rightNode is not NULL but leftNode is null, return rightNOde.
       4) If both are null, Return NULL
    At the end you will get the LCA Node for n1 and n2.
[**DONE**]

*/