// Link: https://www.codingninjas.com/studio/problems/maximum-sum-of-nodes-in-a-binary-tree-such-that-no-two-nodes-are-adjacent_1118112
/*
    we have a binary Tree. Need to Find the max possible sum of the Nodes which are not adjacent to each other.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// Approach1: Recursion + pairs<Sum consider curr Node, Sum Dont consider curr Node>
pair<int, int> solve(TreeNode *node)
{
    // baseCase: If you reached a null Node
    if (node == NULL)
        return make_pair(0, 0); // In this case both sum will be 0.

    // Now Recursion fetch me the leftChild pair and rightChild pair...
    pair<int, int> leftChild = solve(node->left);
    pair<int, int> rightChild = solve(node->right);

    // Now, lets decide what we want to send for the current Node..
    pair<int, int> pt;

    // Case1: If you consider the current Node, Don't consider the child Nodes...
    pt.first = node->data + leftChild.second + rightChild.second; // curr Node + sum2 of left and right node.

    // case2: If you dont consider the current Node, Consider the child Nodes...
    pt.second = max(leftChild.first, leftChild.second) + max(rightChild.first, rightChild.second);

    return pt;
}

int maximumSumOfNodes(TreeNode *root)
{
    // It returns a final pair, <sum consider root, sum without consider root>
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second); // whichever is max, that is ans.
}

/*
Logic: Using Recusrion + pair
    Basically we will traverse all the Nodes and For each Node, we will Find 2 things and store in a pair
        1) sum1 -> consider the Current Node. [In this case, Dont consider child Nodes in sum]
        1) sum2 -> Don't consider the Current Node. [In this case, Consider child Nodes in sum]

Appraoch: TC: O(n) [All nodes are visited once] SC: O(n) [Recursion, Call stack can be the max height]
    Base Case,
        -- If you reach a null Node, return both the sums should be 0.
    -- Call Recursion,
        pairLeft -> REcursion, fetch me the sums from the left child.
        pairRight -> Recursion, fetch me the sums from the right child.
    -- now based on the pairleft and pairRight, we decide what to send from the current Node ? [**VIMP**]
        -- For sum1: [consider the current Node]
            -- take currNode + sum2 of pairLeft + sum2 of pairRight. [as it will give me sum where are child nodes are not considered.]
        -- For sum2:  [if we dont consider the current Node]
            -- I have 4 options to choose,
                For left child, I have sum if i consider it and if i don't
                For right child, I have sum if i consider it and if i don't
            -- Find of sum of max between the sums of leftChild and max between the sum of rightChild.
    -- After the recursion,
        Return the max between sum1 and sum2.
    [** DONE **]
*/