// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
/*
    Basically, You have a BST, You need to find the the kth smallest Element in the BST.
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
private:
    // InorderTraversal: TC:O(N) SC: O(N)
    void inOrderTraverse(TreeNode *root, vector<int> &inorderList)
    {
        // BaseCase:
        if (root == NULL)
            return;

        inOrderTraverse(root->left, inorderList);
        inorderList.push_back(root->val);
        inOrderTraverse(root->right, inorderList);
    }

    // Morris Traversal: Making/breaking TempLinks, Iterative and space efficient O(1)
    int morrisTraversal(TreeNode *root, int k)
    {
        int ans = -1;
        int countNode = 0;
        // Implement the morris traversal...
        TreeNode *currNode = root;
        while (currNode != NULL)
        {
            // If the left of the currNode doesn't exit..
            if (currNode->left == NULL)
            {
                countNode++;
                if (countNode == k)
                    ans = currNode->val;    // store Val of currNode..
                currNode = currNode->right; // If left don't Exist, move to right Node...
            }
            else
            {
                // If the left of currNode exist, Find the predNode..
                TreeNode *predNode = currNode->left;
                // Move right till, you reach a node where right don't exist and it links to currNode.
                while ((predNode->right != NULL) && (predNode->right != currNode))
                {
                    predNode = predNode->right;
                }

                // check the predNode...
                if (predNode->right == NULL)
                {
                    // make a temp Link to currNode...
                    predNode->right = currNode;
                    currNode = currNode->left; // Move currNode to left..
                }
                else
                {
                    // predNode points to the currNode...[break the temp Link]
                    predNode->right = NULL;
                    countNode++;
                    if (countNode == k)
                        ans = currNode->val;    // store the val of currNode...
                    currNode = currNode->right; // Move the currNode to the next right node..
                }
            }
        }

        return ans;
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        // Approach: Inorder traversal + vector to Store the Node List.. TC: O(N) SC: O(N)
        //  vector<int> inorderList;
        //  inOrderTraverse(root, inorderList);
        //  return inorderList[k-1]; //Fetch the (k-1)th Node since, vector is 0 based index..

        // Approach2: Using Morris Traversal, Iterative Way TC: O(N) + Space takes: O(1)
        return morrisTraversal(root, k);
    }
};

/*
Logic: The inorder Travesal of the BST is always a sorted List of all the Nodes.

NOTE: For finding the kth largest element, Use the same logic,
    The kth largets element is  totalNodes-kth smallest element from the front of the inorder node List.


Appraoch1: Inorder Traversal of BST [TC: O(N) SC:O(N)]
    -- You can do a Recursive Traversal of the Nodes, With a vector to store Node Vals...
    -- After you have the Node Vals, just return the k-1th Index Node val.
[**DONE**]

Appraoch2: Morris Inorder Traversal [TC: O(N) SC: O(1)]
    -- It is much faster and space efficient than Inorder traversal.
    -- Implement the Morris Algorithm,
        Whereever you are printing the Nodevals just check of the counter is equal to k, If yes store that node val in ans;
    -- return ans
[**DONE**]
*/