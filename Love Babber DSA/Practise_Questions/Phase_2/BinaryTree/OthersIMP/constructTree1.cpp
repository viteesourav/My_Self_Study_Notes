// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
/*
    You have 2 arrays of Node Values in InOrder [LNR] and PRE-Order [NLR]. Construct a BTree From this...
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
private:
    // Utility Function: To Find the post of the node from the Given Array... TC: O(n)
    int findNodePosition(vector<int> &inorder, int nodeData)
    {
        // Find nodeData in inorder Array...
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == nodeData)
                return i;
        }
        return -1; // If nodeData not found
    }

    // Utility Fun: have map that stores the element-index mapping for inOrder.. SC: O(N)
    void createIndexMapping(vector<int> &inorder, unordered_map<int, int> &mt)
    {
        for (int i = 0; i < inorder.size(); i++)
            mt[inorder[i]] = i;
    }

    // Approach: Recursion, create the left child and right child with NodeValues...
    // TC: O(n^2) [for loop for node post] OR TC: O(n) [hashMap for node post]
    TreeNode *solve(int &index, int inOrderStart, int inOrderEnd, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mt)
    {
        // baseCase: If we considerd all Nodes in pre-Order OR inOrderstart > inOrderEnd
        if (index >= preorder.size() || inOrderStart > inOrderEnd)
            return NULL;

        // Now take the first Node form the pre-order arr and create a new Node...
        int nodeData = preorder[index++]; // Take the curr Node and increment index
        TreeNode *newNode = new TreeNode(nodeData);

        // Now find the postion of nodeData in InOrder arr..
        // int post = findNodePosition(inorder, nodeData);
        int post = mt[nodeData];

        // Now you have node pos and based on postion you know the left and right childs...
        newNode->left = solve(index, inOrderStart, post - 1, preorder, inorder, mt);
        newNode->right = solve(index, post + 1, inOrderEnd, preorder, inorder, mt);

        return newNode;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int index = 0;
        int inOrderStart = 0, inOrderEnd = inorder.size() - 1;
        // Optimization: inorder element-index Mapping...
        unordered_map<int, int> mt;
        createIndexMapping(inorder, mt);
        TreeNode *root = solve(index, inOrderStart, inOrderEnd, preorder, inorder, mt);
        return root;
    }
};

/*
Appraoch: Recursion
    From InOrder Array:
        -- Find a Node's Position: All Elements on left are under the left Child, All Elements on Right are under the right Child.
        -- Can maintain an unordered HashMap to Store NodeVal and Position in InOrder arr. [TC:O(logn), SC: O(N)]
           OR use a Loop to iterate an Find the Postion of a Node. [TC: O(N), SC: O(N)]

    From PreOrder Array:
        -- Have an index that goes from Left to right, Pick the Node Values.
        -- Find that node in the Inorder Array

    -- Call Recursion for fetching the Tree for the current Node for left and right Child.
    -- return the new Node back..

    NOTE: Remember to send the index of preOrder array by reference. [we want to retain the value for all call stack in Recursion]
    [** DONE **]
*/