// Link: https://leetcode.com/problems/diameter-of-binary-tree/
/*
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
    This path may or may not pass through the root.

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
    // Utility Function to find the max dept of a Node [using Recursion] TC: O(N)
    int findDept(TreeNode *node)
    {
        // BaseCase:
        if (node == NULL)
            return 0;

        int left = findDept(node->left);   // Recursion find dept on the left.
        int right = findDept(node->right); // Recursion find dept on the right.

        int maxDept = max(left, right) + 1;
        return maxDept;
    }
    // Appraoch1: using Recursion and height Calculation. [TC: O(n2)]
    int findDiameter1(TreeNode *root)
    {
        // BaseCondition:
        if (root == NULL)
            return 0;

        // Possiblility for Diameter at current Node...
        int opt1 = findDiameter1(root->left);  // Diamter might be on the left of current Node.
        int opt2 = findDiameter1(root->right); // Diamter might be on the right of current Node.
        // At the current Node...
        int opt3 = findDept(root->left) + findDept(root->right); // If the Node itself is included +1 to opt3

        // Calculate diameter and return it..
        int dia = max(opt1, max(opt2, opt3)); // maximum out of the three options...
        return dia;
    }

    // Approach2: Efficient Recursion using pairs TC: O(n)
    pair<int, int> findDiameter2(TreeNode *root)
    {
        // Base Case:
        if (root == NULL)
            return make_pair(0, 0); // Pair<Diameter, Dept>

        // Fetch the diameter data from the left and right Node...
        pair<int, int> leftData = findDiameter2(root->left);   // Recursion will fetch from left
        pair<int, int> rightData = findDiameter2(root->right); // Recursion will fetch from right

        // Possiblility for Diameter at current Node...
        int opt1 = leftData.first;  // Diamter might be on the left of current Node.
        int opt2 = rightData.first; // Diamter might be on the right of current Node.
        // At the current Node...
        // diameter = leftSide Height + rightSide Height;
        int opt3 = leftData.second + rightData.second;

        // Calculate new diameter and height and return it.
        pair<int, int> newPair;
        newPair.first = max(opt1, max(opt2, opt3));                  // Diamter = max(opt1, opt2 and opt3)
        newPair.second = max(leftData.second, rightData.second) + 1; // height = max(leftHeight, rightHeight) + 1
        return newPair;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // return findDiameter1(root);
        return findDiameter2(root).first; // First element of the pair represent diameter at root.
    }
};

/*

To Find a Diameter at a node N 3 Options:
    1)opt1: Either it will be on the left-side of the node.
    2)opt2: Either it will be on the right-side of the node.
    3)opt3: At the NOde, Find the height of left side, height of right Side + 1 [Include the Node it self, depending upon the question asked].

Now Diameter at node is max(opt1, opt2, opt3) -> this gives the diameter...

Appraoch1: Use Recursive, TC: O(n2) [Reason: along with Recursion, For each Node am calling height To find the max dept]
    -- Base case: If the Node becomes null, Retrun 0;
    -- WE will list down the possible options:
       1) Opt1: call Recursion on the left Node. [Recursion will bring diameter from the left Node]
       2) Opt2: call Recursion on the Right Node. [Recursion will bring diameter from the right Node]
       3) Opt3: If at a Node, Diamter =  leftHeight + rightHeight + 1;
    -- Thus Diamter is max out of Opt1, opt2 and Opt3.
    -- Return Diameter. [**DONE***]

PROBLEM:
    -- Approach 1 Follows Recursive on Finding the Diameter, So each Node will be visited once. O(n)
       For each NODE, again we need to Find the left and Right Height, TC of height is O(n)
       TC of Appraoch 1: O(n2)

Appraoch 2: Same Recursive Appraoch [We will Pairs<Diamter, height>] [TC: O(n), visiting all Node atleast once]
    -- Base Case: If node is null, return (0, 0)
    -- Fetch the diaData from the left and right side... [this is a pair]
       leftData: call Recursion on the left Node. [Recursion will bring diameter from the left Node]
       rightData: call Recusrsion on the Right Node. [Recursion will bring diameter from the right Node]
    -- WE will list down the possible options:
       1) Opt1: leftData.first [diameter of the leftSide]
       2) Opt2: rightData.first [diameter of the rightSide]
       3) Opt3: At a node, Diamter =  leftData.second + rightData.second; [leftNode height + rightNode height]

    -- Thus Diameter = max(opt1, opt2, opt3) and Height = max(leftheight, rightHeight) + 1
    -- retrun the new pair.
    [***DONE***]
*/