// Link: https://leetcode.com/problems/balanced-binary-tree/
/*
    Basically, A balanced Binary Tree, the height at the left and right, cannot Exceed more than 1
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
private:
    // Utility Function to cal height/dept for Node [TC: O(n)]
    int getHeight(TreeNode *node)
    {
        // baseCase:
        if (node == NULL)
            return 0;

        // Recusrion will fetch the height of the left and right..
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // So the height for the current Node..
        return max(leftHeight, rightHeight) + 1; //+1 to include the current node in height.
    }

    // Appraoch1: Recursion + height Calculation for each Node [TC: O(n2)]
    bool appraoch1(TreeNode *root)
    {
        // baseCase:
        if (root == NULL)
            return true; // If current Node is NULL, defaualt case

        // Recusion will check if left and right part are balanced or not ?
        bool isLeftBalanced = appraoch1(root->left);
        bool isRightBalanced = appraoch1(root->right);

        // For the current Node..
        bool isBalanced = abs(getHeight(root->left) - getHeight(root->right)) <= 1;

        // For The current Node to be balanced, all above 3 should be true...
        return isLeftBalanced && isRightBalanced && isBalanced;
    }

    // Appraoch2: Using Recursion + pairs [pair<isBalance, height>]
    pair<bool, int> appraoch2(TreeNode *root)
    {
        // baseCase
        if (root == NULL)
            return make_pair(true, 0); // At Null NOde, it is balanced and height 0

        // Recusrion, fetch the left and right balanced and height..
        pair<bool, int> leftNode = appraoch2(root->left);
        pair<bool, int> rightNode = appraoch2(root->right);

        // If the current Node is balanced or not based on height..
        bool isbalanced = abs(leftNode.second - rightNode.second) <= 1;

        // At current Node...
        pair<bool, int> newPair;
        // Overall current Node is balanced, if above 3 are balanced...
        newPair.first = leftNode.first && rightNode.first && isbalanced;
        // height at the current Node..
        newPair.second = max(leftNode.second, rightNode.second) + 1;
        return newPair;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        // return appraoch1(root);
        return appraoch2(root).first; // First part says if balanced or not ?
    }
};

/*
Appraoch1: REcursion + height at each Node..
        -- Base Case: If Current Node is Null, Return 0...
        -- check if the left node is a balanced Tree. [use REcursion]
        -- check if the right node is a balanced Tree. [use Recursion]
        -- At the current Node,
            -- Find height of left Node (leftHeight) and right Node (right height)
            -- iscurrent Node balanced: abs(leftHeight - rightHeight) <= 1 [condition for balanced Tree]
        If the above is true, return true else false.
    [**DONE**]

Problem: Same, For each Node you calling height, TC: O(n2)

Appraoch2: Recursion + pair [use pair<isbalanced, height>] [TC: O(n), visiting all Node atleast once]
    -- Base Case,
        If you at null node, It is balanced and height is 0 by default.
    -- Recursion will fetch the data for the left and right child.
    -- Calculate if the current Node is balanced based on the left and right child height.
    -- Overall Tree will be balanced if,
        leftChild, right child and the current Node is balanced. [true or false]
    -- Calculate the new height of the current child...
        height = max(leftchild, rightChild) +1;
    put in a new Pair and return the new pair.

    [**DONE**]
*/