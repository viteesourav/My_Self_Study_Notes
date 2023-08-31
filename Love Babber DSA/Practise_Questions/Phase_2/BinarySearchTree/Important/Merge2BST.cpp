// Link: https://www.codingninjas.com/studio/problems/merge-two-bsts_920474
/*
    You have 2 BST, merge them into a single Balanced BST and return the the Inorder Sorted Traversal.
    NOTE:
        -- In this Question, Just We need to return the Nodes List for the merged BST.
        -- WE may need to create a new BST from this sorted Node List. [**VIMP**]
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Creation...
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// 1) Inroder Traversal For a BST... TC: O(N) SC: O(N) [Recursive way]
void inorderTraversal(TreeNode *currNode, vector<int> &res)
{
    // edgeCase: If you reached end, just return..
    if (currNode == NULL)
        return;

    inorderTraversal(currNode->left, res);  // Traverse to left...
    res.push_back(currNode->data);          // Store the data
    inorderTraversal(currNode->right, res); // Traverse to Right...
}

// 2) Merging 2 sorted arrays using 2-pointer approach...
void mergeSortedArr(vector<int> &v1, vector<int> &v2, vector<int> &ans)
{
    // Lets have pointer for first elements of both v1 and v2..
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size())
    {

        // check who is smaller, put it in the ans vector...
        if (v1[i] < v2[j])
        {
            ans.push_back(v1[i]);
            i++;
        }
        else
        {
            ans.push_back(v2[j]);
            j++;
        }
    }

    // check for left out elements and push it to ans..
    while (i < v1.size())
    {
        ans.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        ans.push_back(v2[j]);
        j++;
    }
}

// construct BST from inroder NodeVal Array.. [Recursive way]
TreeNode *constructBST(vector<int> &arr, int start, int end)
{
    // baseCase: If start exceeds end, return NULL Node
    if (start > end)
        return NULL;

    // find the mid NodeVal, create a node with that...
    int mid = end - (end - start) / 2;
    TreeNode *newNode = new TreeNode(arr[mid]);

    // Now recursion will handle craeting the left and right sub-tree...
    newNode->left = constructBST(arr, start, mid - 1);
    newNode->right = constructBST(arr, mid + 1, end);

    return newNode;
}

// Appraoch1: Using vectors, inorder Traversal and merging Sorted Arrays..
// TC: O(M+N) SC: O(M+N)
vector<int> solve1(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans, inorderBST1, inorderBST2, mergedArr;

    // 1) Now use inorder Traversal to fetch, sorted Nodevals for both BST...
    inorderTraversal(root1, inorderBST1);
    inorderTraversal(root2, inorderBST2);

    // 2) Now we have 2 sorted NodesVal -> Use 2-pointer to merge them..
    mergeSortedArr(inorderBST1, inorderBST2, mergedArr); //[**As per question we can just return mergedArr]

    // Not Need by question but Important, 3) make a new BST form the merged Nodes.. [useRecursion]
    int start = 0;
    int end = mergedArr.size() - 1;
    TreeNode *newHead = constructBST(mergedArr, start, end);

    // To get the sorted inorder Arr...
    inorderTraversal(newHead, ans);

    return ans;
}

/////////////////////////////////////// Appraoch 2 //////////////////////////////////////////////////////////////

// 1) Converting a BST to doublly linkedList [Recursion is used]
void flatternBSTtoDLL(TreeNode *root, TreeNode *&head)
{
    // edgeCase: If root becomes NULL
    if (root == NULL)
        return;

    // Recursion Find me head from right tree...
    flatternBSTtoDLL(root->right, head);

    // connect the head to root...
    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root; // update the head to root..

    // REcursion Find me the list from left tree..
    flatternBSTtoDLL(root->left, head);
}

// 2) Merge 2 sorted Doubly Linked-List...[2-pointer Appraoch]
TreeNode *sortLinkedList(TreeNode *&head1, TreeNode *&head2)
{
    // Lets have a starting pointer for the mergedList's head and tail...
    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    // iterate both the list...
    while (head1 != NULL && head2 != NULL)
    {

        // check who has the less val ?
        if (head1->data < head2->data)
        {
            // check if this is the first Node we are adding ?
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            // check if this is the first Node we are adding ?
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    // Need to solve for the Rest of the remaining ListItems..
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// 3) Creating a BST from the Doubly LinkedList... [Recursion]
// Function to find the totol number of Nodes in sorted List..
int countNodes(TreeNode *&head)
{
    TreeNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

// Takes the sorted Inorder List for Nodes and the count of Nodes...
TreeNode *constructBSTFromList(TreeNode *&head, int n)
{
    // baseCae: If the count becomes zero or head becomes NULL
    if (n <= 0 || head == NULL)
        return NULL;

    // construct Tree for left side, use nodes till n/2... [Recursion will do]
    TreeNode *leftTree = constructBSTFromList(head, n / 2);

    // Now make the current head as root Node and move the head to the next Node...
    TreeNode *root = head;
    root->left = leftTree;

    head = head->right;

    // Now construct right Tree From the remaining Nodes...
    root->right = constructBSTFromList(head, n - n / 2 - 1);

    return root;
}

// Appraoch2: using LinkedList, Convert BST to doublyList, merge Sorted List, create Tree...
// TC: O(M+N) SC: O(h1+h2) [Advantage, space is optimized]
vector<int> solve2(TreeNode *root1, TreeNode *root2)
{

    // 1) convert the given BSTs to Flattern Doubly Linked List [Without using additional Space]
    TreeNode *head1 = NULL;
    TreeNode *head2 = NULL;

    flatternBSTtoDLL(root1, head1);
    head1->left = NULL;
    flatternBSTtoDLL(root2, head2);
    head2->left = NULL;

    // 2) Sort the 2 linked List,
    TreeNode *mergedList = sortLinkedList(head1, head2); //[As per question, upto this you have the sorted NodeList]

    // Additoanl, 3) Construct a BST using the sorted List...
    TreeNode *newHead = constructBSTFromList(mergedList, countNodes(mergedList));

    // Now to get the inorder Array List...
    vector<int> ans;
    inorderTraversal(newHead, ans);

    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // return solve1(root1, root2);  //solved using vector..
    return solve2(root1, root2); // Solved using LinkedList...
}

/*
    [Easy Appraoch, using vector]
    Approach1: TC: O(M+N) SC: O(M+N) [M and N are total Nodes for BST1 and BST2]
        1) DO the Inorder Traversal, store the Nodes in a vector1 and vector2 for BST1 and BST2 resp.
        2) Apply the merge 2 Sorted array concept to merge vector1 and vector2 into a single merged Array [2-pointer Approach]
        3) Now you have the sorted Array, Create a new Balanced BST. [Not required by question but important]
           -- use Recursion, take the mid, make it as root Node.
           -- Left part of BST will be done by Recursion.
           -- right part of BST will be done by Recursion.

    [A Bit Efficient, but LinkedList Used so more code]
    Appraoch2: Optimal Method, we can reduce the SC to O(h1+h2) [h1 and h2 are the height of the BST1 and BST2]
        1) Convert both the given BST into Doublly Linked List. [**IMP**]
            -- First Convert the right Tree into LinkedList. [Recursion will do it]
            -- update the link between the head and root Node.
            -- Then update the head to root Node.
            -- Then Convert the left Tree into List [Recursion will do it]
            -- return the head.
        2) Now Apply Concept for merging 2 Linked List. -> Gives a Sorted List.
            --
        3) From the new LinkedList, create a Balanced BST. [Use Recursion] [**IMP**]
            -- Find the total no. of Nodes. N
            -- For First N/2 -> left Tree Recursion will make.
            -- The mid Node will be root Node.
            -- For next N-N/2-1, we will make the right Tree using Recursion.
            -- return the root Node.
        Meerged BST is ready..
*/