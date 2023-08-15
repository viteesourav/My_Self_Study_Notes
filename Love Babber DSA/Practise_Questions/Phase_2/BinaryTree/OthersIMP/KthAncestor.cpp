// Link: https://www.codingninjas.com/studio/problems/kth-ancestor-of-a-node-in-binary-tree_842561
/*
    In Binary Tree, A Node is given and value of K is given. Now, You need to find the kth Ancestor of given Node.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// Approach1: using vector to Store path till targetNode.. SC: O(N)
void solve1(TreeNode *node, vector<int> &path, int targetNodeVal, bool &isNodeFound)
{
    // edgeCase: If the node is null OR you already found the target Node.
    if (node == NULL || isNodeFound)
        return;

    // Push the current Node in the Path...
    path.push_back(node->data);

    // check if the currentNode is targetNodeVal ?
    if (node->data == targetNodeVal)
    { // If yes, then set the nodeFound flag and return...
        isNodeFound = true;
        return;
    }

    // Recursion, look for target Node in left and right...
    solve1(node->left, path, targetNodeVal, isNodeFound);
    solve1(node->right, path, targetNodeVal, isNodeFound);

    // Pop back the current Node from the path, as we didn't find the target Node here..
    if (!isNodeFound)
        path.pop_back();

    return;
}

// Aproach2: [Recursion]
TreeNode *solve2(TreeNode *node, int targetNodeVal, int &k)
{
    // baseCase:
    if (node == NULL)
        return NULL;

    // check if the current Node is target Node..
    if (node->data == targetNodeVal)
    {
        return node;
    }

    // Recursion, Fetch me the Nodes from left and right side..
    TreeNode *left = solve2(node->left, targetNodeVal, k);
    TreeNode *right = solve2(node->right, targetNodeVal, k);

    // Now check, there will 3 conditions...
    if ((left != NULL && right == NULL) || (right != NULL && left == NULL))
    {
        // Current Node is related to target Node...
        // If k is still not 0 then decrement k and return the current Node.
        if (k > 0)
        {
            k--;
            return node;
        }
        else
        {
            // If k is already 0, then return the left or right whichever is not null..
            if (left != NULL)
                return left;
            else if (right != NULL)
                return right;
        }
    }

    return NULL; // This if left and right both are NULL
}

int findKthAncestor(TreeNode *root, int targetNodeVal, int k)
{

    // EdgeCase Check..
    if (root == NULL || root->data == targetNodeVal) // If root itself is null or the targetVal is root Node.
        return -1;

    // For Appraoch1 [with Vector]
    // vector<int> path;
    // bool isNodeFound = false;
    // solve1(root, path, targetNodeVal, isNodeFound);
    // //Now we know the path, we will look from back for the Kth index.
    // if(k >= path.size()) return -1; //Ancestor cannot exist outside the Tree...
    // return path[path.size()-(k+1)];

    // Appraoch2: [withOut using Vector, Just Recursion]
    TreeNode *ans = solve2(root, targetNodeVal, k);

    // Check if the ans is not null and k is still not 0,
    if (ans != NULL && k > 0)
        return -1;
    else
        return ans->data;
}

/*
Appraoch 1: use Vector.
    -- 2 edge case, you must check
        1) If the root node is NULL
        2) whatever k is if the target is the root Node then also return -1 [Root Node has no ancestor]
    -- Idea is to traverse the given Tree and Find the all the nodes in path till given Node.
    -- you got the vector path [use Recusrion]
        -- base Case:
            1) If the node is null
            2) Have a flag that checks if you found the target Node yet or not ? If yes just return back
        -- Push the current node in the path.
        -- If the current Node is target Node, Update the flag and return..
        -- Use Recursion, to look for target Node in left and right Node.
        -- After the above step on your way back, pop the current node from path. [As it cannot to in the path to the target Node]
    -- Now From the back, Look for the kth index from the back of the path.
    [**DONE**]

Problem: Additional Space we used as vector.

Apprach2: without Vector [Just using Recursion]
    -- Same base conditionm before we go into Recursion,
        1) If current Node is Null
        2) If the root node is the target Node.
    Logic For Recursion:
    -- Base check, If the node is NULL, return NULL
    -- If you found the targetNode, return the current Node.
    -- Recursion,
        fetch the Node from left and right. [** Love this part of appraoch **]
    -- Check Condition, If either left or right is not null then,
        Check if k > 0, if yes, decrement k and return the current Node.
        if no, return the left or right node whichever is not null.
    -- After the recursion fucntion,
    Check if retured node is not null and K is still > 0, return -1 since Ancestor doesnot exit
    else return node->data

    Thus, You got the kth Ancestor Node.
    [**Done**]

*/