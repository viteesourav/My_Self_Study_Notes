// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
/*
    You have 2 arrays of Node Values in InOrder [LNR] and Post-Order [LRN]. Construct a BTree From this...
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
    // NOTE: Index moves from right to left, First right child we create and then left...
    TreeNode *solve(int &index, int inOrderStart, int inOrderEnd, vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> &mt)
    {
        // baseCase: If we considerd all Nodes in post-Order OR inOrderstart > inOrderEnd
        if (index < 0 || inOrderStart > inOrderEnd)
            return NULL;

        // Now take the last Node form the post-order arr and create a new Node...
        int nodeData = postorder[index--]; // Take the curr Node and decrement index [**IMP**]
        TreeNode *newNode = new TreeNode(nodeData);

        // Now find the postion of nodeData in InOrder arr..
        // int post = findNodePosition(inorder, nodeData);
        int post = mt[nodeData];

        // Now you have node pos and based on postion you know the right and then left child [**IMP**]
        newNode->right = solve(index, post + 1, inOrderEnd, postorder, inorder, mt);
        newNode->left = solve(index, inOrderStart, post - 1, postorder, inorder, mt);

        return newNode;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int index = postorder.size() - 1;
        int inOrderStart = 0, inOrderEnd = inorder.size() - 1;
        // Optimization: inorder element-index Mapping...
        unordered_map<int, int> mt;
        createIndexMapping(inorder, mt);
        TreeNode *root = solve(index, inOrderStart, inOrderEnd, postorder, inorder, mt);
        return root;
    }
};

/*
Appraoch: Recursion
    From InOrder Array:
        -- Find a Node's Position: All Elements on left are under the left Child, All Elements on Right are under the right Child.
        -- Can maintain an unordered HashMap to Store NodeVal and Position in InOrder arr. [TC:O(logn), SC: O(N)]
           OR use a Loop to iterate an Find the Postion of a Node. [TC: O(N), SC: O(N)]

    From PostOrder Array:
        -- Have an index that goes from right to left, Pick the Node Values.
        -- Find that node in the Inorder Array

    -- Call Recursion for fetching the Tree for the current Node for right and left Child. [*IMP*, The order of recursion matters here]
    -- return the new Node back..

    NOTE: Remember to send the index of preOrder array by reference. [we want to retain the value for all call stack in Recursion]
    [** DONE **]
*/