// Link: https://leetcode.com/problems/delete-node-in-a-bst/
/*
    A BST you have, A Node you have, Delete the Node from the BST
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Creation...
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    // Appraoch: Recursion [SearchNode + Delete the Node if Found] TC: O(N)
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // base case:
        if (root == NULL)
            return NULL;

        // check if the currNode is the node to delete ?
        if (root->val == key)
        {
            // Now lets check what kind of node we are deleting ?
            if (root->left == NULL && root->right == NULL)
            { // 1) If node is a leaf Node..
                delete root;
                return NULL; // remove the currNode and return NULL to it.
            }
            else if (root->left != NULL && root->right == NULL)
            { // 2) If only left Child exist..
                TreeNode *temp = root->left;
                delete root;
                return temp; // store the left child link, remove currNode and return the left child...
            }
            else if (root->right != NULL && root->left == NULL)
            { // 2) If only right Child exist..
                TreeNode *temp = root->right;
                delete root;
                return temp; // store the right child link, remove currNode and return the right child...
            }
            else if (root->right != NULL && root->left != NULL)
            { // Both Child exist
                // Lets find the minVal in the right Child Tree.
                TreeNode *predNode = root->right;
                while (predNode->left != NULL) // Travese till left Node becomes NULL
                    predNode = predNode->left;

                // Now you have the mini Node from the right child Tree...
                root->val = predNode->val; // Replacing the currNode val with min Val.
                // Call DeleteNode on rightChild, delete the min val
                root->right = deleteNode(root->right, predNode->val);
                return root;
            }
        }
        else if (key < root->val)
        {
            // we should search in the leftChild Tree...
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            // we should serach in the rightChild tree..
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

/*
    Logic: So Any Node you delete, 3 possible Situations can happen:
        1) If Node is a leaf Node, Just delete it.
        2) If the Node has a single Child, Then curNode's Child should point to currNode's parent, Delete currNode.
        3) If the Node has 2 Childeren [2 options you have, either one you can use]
           1) You take the min Node from the right child Tree, replace the currNode and then Call delete in the right tree to delete the min Node.
           OR
           2) You take the max Node from the left child Tree, replace the currNode and then Call delete in the left tree to delete the max Node.

    Appraoch: [using Recursion]
        -- Call Recursion to search the Node in the BST.
        -- If the currNode is targetNode,
            -- Now check for Possible sitaution,
            1) If the currNode is leaf Node, Just delete the Node and return NULL
            2) If the currNode has 1 child, Delete the currNode Node and return the left or right Child.
            3) If the currNode has 2 child,
                -- Let Find out the min Node from the right child Tree. [Just traverse in left Link, you will find the min Node]
                -- Once Found, Replace the currNode with that value.
                -- Now For currNode->right, call DeleteNode for right child with targetNode as the min Node Val
        -- IF currNode is not targetNode,
            Based on the nodeVal and targetVal, traverse in left or right.
        -- return currNode
    [** Target Node Deleted **]

*/