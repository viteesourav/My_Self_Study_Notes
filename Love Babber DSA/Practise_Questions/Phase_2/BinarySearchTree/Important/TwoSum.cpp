// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
/*
    Given a BST, You have given a target Sum, Check if there exist any 2 Nodes where the given sum exist.
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
private:
    // BST, InorderTraversal -> Morris Traversal TC: O(N) SC: O(1)
    void fetchInorderTraversal(TreeNode *root, vector<TreeNode *> &inOrderList)
    {
        // let's take the root as currNode..
        TreeNode *currNode = root;

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
                TreeNode *predNode = currNode->left;
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

public:
    // Appraoch: Inroder Traversal + 2-pointer Search For target.
    bool findTarget(TreeNode *root, int k)
    {

        // A vector to store the inorder Traversal of the BST  //SC: O(N)
        vector<TreeNode *> inOrderList;
        fetchInorderTraversal(root, inOrderList);

        // Now we have the sorted Nodes in Inorder, 2-Pointer for target search... TC: O(N)
        int s = 0, e = inOrderList.size() - 1;
        while (s < e)
        {
            if (inOrderList[s]->val + inOrderList[e]->val == k)
                return true;
            else if (inOrderList[s]->val + inOrderList[e]->val > k)
                e--;
            else
                s++;
        }
        return false;
    }
};

/*
    Approach: TC: O(N) SC: O(N)
        -- Get the inorder of the BST. [sorted Node List] -> Use Morris Traversal [TC: O(N) SC: O(1)]
        -- Use 2 pointer search in the inorder and check if the sum exist.

*/