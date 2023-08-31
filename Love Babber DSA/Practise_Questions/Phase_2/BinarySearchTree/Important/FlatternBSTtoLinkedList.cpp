// Link: https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459
/*
    A BST is given, Flattern the given BST to a Linked List
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Creation...
template <typename T>
struct TreeNode
{
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

// Fucntion to Find the Inroder Traversal Of BST -> [Morris Appraoch]
void inorderTraversal(TreeNode<int> *root, vector<TreeNode<int> *> &inOrderList)
{
    // let's take the root as currNode..
    TreeNode<int> *currNode = root;

    while (currNode != NULL)
    {
        // Check if the left Exist ?
        if (currNode->left == NULL)
        { // NO, store the node and move right...
            inOrderList.push_back(currNode);
            currNode = currNode->right;
        }
        else
        { // Yes, find the predecessor Node...
            TreeNode<int> *predNode = currNode->left;
            while (predNode->right != NULL && predNode->right != currNode)
                predNode = predNode->right;

            if (predNode->right == NULL)
            { // Form the temp Link with CurrNode
                predNode->right = currNode;
                currNode = currNode->left;
            }
            else
            { // Break the temp Link with currNode, store the currNode, move to right...
                predNode->right = NULL;
                inOrderList.push_back(currNode);
                currNode = currNode->right;
            }
        }
    }
}

// Approach: Inroder Traversal + vector's Node Link Manipulation...
TreeNode<int> *flatten(TreeNode<int> *root)
{
    // Inorder Traversal For the given BST...
    vector<TreeNode<int> *> inOrderList;
    inorderTraversal(root, inOrderList);

    // Traverse the List and manipulate the link
    int size = inOrderList.size();
    for (int i = 0; i < size - 1; i++)
    {
        inOrderList[i]->left = NULL;
        inOrderList[i]->right = inOrderList[i + 1];
    }
    // For the last Node, update the links...
    inOrderList[size - 1]->left = NULL;
    inOrderList[size - 1]->right = NULL;

    // Update the head as the root...
    root = inOrderList[0];

    return root;
}

/*
    Appraoch: TC:O(N) SC: O(N)
        -- Find the Inorder Traversal of the Tree, Store the Nodes in the vector. -> Use Recursive Appraoch [TC:O(N) SC:O(N)]
        -- Traverse the vector, Manipulate the Links to form a right skewed tree.
*/