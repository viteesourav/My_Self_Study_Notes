// Link: https://www.codingninjas.com/studio/problems/is-binary-heap-tree_893136
/*
Basically, You have given a Binary Tree, Check if its a heap or not ?
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
};

// Function to Find the totoal Nodes in the given BT... [Recursion -> InOrder Traversal]
void findTotalNodes(BinaryTreeNode<int> *node, int &count)
{
    // baseCase:
    if (node == NULL)
    {
        return;
    }

    findTotalNodes(node->left, count);  // Move in the left Tree...
    count++;                            // Take the Count at the Node..
    findTotalNodes(node->right, count); // Move in the right Tree...
}

// Function to check if it's a valid CBT or NOT [Recursion]
bool isCBT(BinaryTreeNode<int> *currNode, int currIndex, int totalNodes)
{
    // baseCase:
    if (currNode == NULL)
        return true;
    if (currIndex > totalNodes)
        return false; // If the currNode Index exceeds the total Nodes..

    // Recursion fetch, if the left and right child are CBT or not ?  //If parent Index is i
    bool left = isCBT(currNode->left, 2 * currIndex, totalNodes);       // left Child index is 2i
    bool right = isCBT(currNode->right, 2 * currIndex + 1, totalNodes); // rightChild index is 2i+1

    // for the currNode, send the it up...
    return left && right;
}

// Function to check if it satisfy the Max Heap Condition..
bool isMaxHeap(BinaryTreeNode<int> *currNode)
{
    // baseCase:
    if (currNode == NULL) // Null Nodes are by default MAX Heap...
        return true;

    // For currNode lets check the heap condition...
    bool isValid;
    if (currNode->left == NULL && currNode->right == NULL) // For Leaf Nodes...
    {
        isValid = true;
    }
    else if (currNode->right == NULL) // only left child exist
    {
        isValid = currNode->data >= currNode->left->data; // check if left child satisfy the heap Condtiion
    }
    else // If both the child exist
    {
        isValid = (currNode->data >= currNode->left->data && currNode->data >= currNode->right->data);
    }

    // Recursion fetch me for the currNode if left and right child are valid heap or not ?
    bool left = isMaxHeap(currNode->left);
    bool right = isMaxHeap(currNode->right);

    // For currNode, send this up...
    return left && right && isValid;
}

// Appraoch: Check if isCBT[CompleteBinaryTree] And if maxHeap...
bool isBinaryHeapTree(BinaryTreeNode<int> *root)
{
    int totalNodes = 0;
    findTotalNodes(root, totalNodes);
    int rootIndex = 1; // NOTE: using 1-base Index, thus, if parent is i, child are at 2i and 2i + 1
    return isCBT(root, rootIndex, totalNodes) && isMaxHeap(root);
}

/*
Idea:
A valid heap should satisfy 2 things..
    1) It should be a CBT [Complete Binary Tree]
    2) Every Node Should satisfy the Heap Condition. [either max heap or min Heap]

HOw to check for CBT or not ?
    -- If the index of a child exceeds the total Number of Nodes then definetly it's not a CBT.

Appraoch:
    -- Check If CBT and If Max Heap TC:O(N) SC: O(N)

1) checkCBT [using Recursion]
    -- Take the current Index from the root Node, and Also keep total Number of Nodes.
    -- Now at any give Node,
        If the Node is null then IT's a CBT by-default
        If the Node's current index is more than totalNo Of Nodes, Then it's not a CBT.
    -- Recursion will fetch the left and right to see if they are CBT or not.

2) CheckMaxHeap [using Recursion]
    -- Start from the Root.
    -- If the node is Null, then Return True. [Null Nodes are by default MaxHeap]
    -- If the Node has only left Child. [Check if its satisfy the heap condition]
    -- If the Node has both child. [Check the heap condition]
    -- Recursion will fetch the if the left and right child are maxHeap or not ?

-- Both 1 and 2 must satisfy for a BT as a valid heap.

*/