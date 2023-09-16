// Link: https://www.codingninjas.com/studio/problems/convert-bst-to-min-heap_920498
/*
You Given a BST, [It is already mentioned that BST is a CBT], Convert that into a min heap.
*/
#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

// Inroder Tree Traversal..[Recursion]
void traverseBST(BinaryTreeNode *currNode, vector<int> &nodeList)
{
    // baseCase:
    if (currNode == NULL)
        return;

    // Traverse the Tree first left then Push Node and then to right...
    traverseBST(currNode->left, nodeList);
    nodeList.push_back(currNode->data);
    traverseBST(currNode->right, nodeList);
}

// Function to Traverse the BST in Pre-Order manner using the Nodes from inOrder List...[Recursion]
// NOTE: Here the currIndex, passing by reference, and is updated as we assign it to Node..[Thus during Recursion backtrack, It wont update to old value]
void fillNodesPreOrder(BinaryTreeNode *currNode, vector<int> nodeList, int &currIndex)
{
    // baseCase:
    if (currNode == NULL)
        return;

    // PreOrder: NLR
    // Thus first setting the value at currIndex at currNode...
    currNode->data = nodeList[currIndex++];
    fillNodesPreOrder(currNode->left, nodeList, currIndex);
    fillNodesPreOrder(currNode->right, nodeList, currIndex);
}

// Appraoch: Inroder traversal + Pre-Order Node Values Filling [For MinHeap]
BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    vector<int> nodeList;
    // Step1: Get the sorted Node List for the BST i.e inorderTraversal..
    traverseBST(root, nodeList);

    // Step2: For MinHeap: Node < left and Node < right And left < right i.e Node < left < right [NLR]
    int index = 0;
    fillNodesPreOrder(root, nodeList, index);

    return root;
}

/*
Idea:
  -- Since the given BST is already CBT, So Structure will be same. [WE just need to put Appropiate Node Values]
   1) You First get the Inorder traversal of the BST [Sorted Node List]
   2) Now Condition Given as per question and heap property.
       -- Node < left && Node < right
       -- left < right.
       -- Combine both of them: Node < left < right.
    -- Thus if we have sorted Node List, First we will fill Node, then left and then right.
[HEAP Done].

NOTE: If we are asked to convert BST to MaxHeap.
    -- Only the Condition will change.
    -- For Max heap:
        -- Node > left and Node > right and left < right.
        -- Combine: Left > right > Node i.e LRN [Post-order]
    Thus, if we have sorted node Lisr, we will first fill the left, then right and then Node Val.


*/