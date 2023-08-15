// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/*
You have a binary Tree. Starting from root Level, Print Nodes Values.
    NOTE: Level Wise print the Node Values in alternative manner...
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
    // Appraoch1: Queue and temp arr with Level order Travesal...
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        // edge Case:
        if (root == NULL)
            return res;
        // Let decalre a Queue and a flag that helps us Store the Node vals...
        queue<TreeNode *> qt;
        bool isLeftToRightTraversal = true; // initially we start with left to Right..

        // Push the root Node in the Queue...
        qt.push(root);

        // For Level order Traversal...
        while (!qt.empty())
        {
            int size = qt.size();      // get the size of the Queue..
            vector<int> tempVal(size); // lets declare a temp vector to hold the nodes for each level...

            // use a loop to iterate the Nodes present in Queue for a particular level...
            for (int i = 0; i < size; i++)
            {
                // take the front Node form the Queue and pop it..
                TreeNode *temp = qt.front();
                qt.pop();

                // Normal Insert or reverse insert into the temp arr..
                int index = isLeftToRightTraversal ? i : size - 1 - i; // either leftToRight or rightTo left..
                tempVal[index] = temp->val;

                // Push the left and right child of the current Node in the Queue...
                if (temp->left != NULL)
                    qt.push(temp->left);
                if (temp->right != NULL)
                    qt.push(temp->right);
            }

            // Change the direction of storing and store the temp arr in result..
            isLeftToRightTraversal = !isLeftToRightTraversal;
            res.push_back(tempVal);
        }
        return res;
    }
};

/*
Logic: Do a Level order traveral, maintain a flag that alternates on each Level, Based in this flag decide how to push Node Values in the ans.

Approach: Queue [Since we are doing level Order Travesal] TC: O(N)
    -- Define a Queue that will hold the Nodes For level Order Travesal.
    -- Define a flag, isLeftToRight intialy set true.
    -- Push the first root element into the Queue.
    -- Run loop till Queue is empty
       -- take the size of the Queue
       -- take a temp vector, same as size of the Queue.
       Run a loop, to process all Nodes present at a particular level..
        -- Take the front Node from Queue, pop it from Queue.
        -- based on the flag, decide if you want to Push data in temp Vector, leftTORight or rightToLeft.
        -- check if left child or right child exist ?
           -- if exist, push it in queue.
    [**DONE**]
*/