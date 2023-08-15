// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
/*
    You have a BTree. Print the Nodes inOrder travesal with SC: O(1) [Morris Traversal]
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
public:
    // Approach: Morris Traversal [TC:O(n), SC: O(1)]
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        // check if edge case of root as null
        if (root == NULL)
            return ans;

        // First of all lets take the root Node as currentNode..
        TreeNode *currNode = root;

        // till currNode is not becoming NULL...
        while (currNode != NULL)
        {

            // Check if the left child exist ?
            if (!currNode->left)
            {
                // If doesn't exist..print the currNode, update currNode to rightChild..
                ans.push_back(currNode->val);
                currNode = currNode->right;
            }
            else
            {
                // Find the predecessor of the currNode...
                TreeNode *predNode = currNode->left; // Go LeftChild..
                // traverse till right is not NULL and right should not becomes currNode...
                while (predNode->right != NULL && predNode->right != currNode)
                    predNode = predNode->right;

                // Now check if tempNode's right is null or not [i.e check if link to currNdoe exist or not ?]
                if (predNode->right == NULL)
                {
                    predNode->right = currNode; // Make a link between temp and currNode..
                    currNode = currNode->left;  // update currNode to left.
                }
                else
                {
                    predNode->right = NULL; // break the link between temp and currNode..
                    ans.push_back(currNode->val);
                    currNode = currNode->right; // Move in the rightChild.
                }
            }
        }
        return ans;
    }
};

/*
**Morris Algorithm:
    -- All Traversal algorithm like Recursion and Level Order Need extra space.
    -- Morris algorithm, SC:O(1)
    -- It works based on creating and deleting temporary links to go back to parent Nodes while traversal with using Recursion

NOTE:
    -- Here predessor we are finding is inOrder predecessor.[It will bring data in form LNR]

**Approach Step:
    -- Consider root as currNode.
    -- while currNode
        -- If Left doesn't exsit
           -- print the current Node,
           -- update the current Node to right child
        -- ELse
           -- find the predecessor Of currentNode.[For predecessor: First go left, then go right till Null or you reach current Node]
           -- IF predecessor rightChild is NULL i.e link dont exist before   [**Creation of temp Link**]
              -- Create the predecessot right-link to Current Node.
              -- update current Node to go to left.
           -- If predecessor right child is not NULL i.e already link exist [**Removal of temp Link**]
              -- remove the right-link to Current.
              -- print currentNode and Move current to right.
    [**DONE**]
*/