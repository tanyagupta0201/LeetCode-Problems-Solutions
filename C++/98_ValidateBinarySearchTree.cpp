// Name: Aditya Byju
// Date: 26/10/2022

/*
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:
        - The left subtree of a node contains only nodes with keys less than the node's key.
        - The right subtree of a node contains only nodes with keys greater than the node's key.
        - Both the left and right subtrees must also be binary search trees.

    Eg:
        Input: root = [2,1,3]
        Output: true

    Time complexity: O(n)
    (n is the number of nodes in the binary tree)
    Space complexity: O(h)
    (h is the height of the binary tree)
*/

class Solution
{
private:
    // helper function to determine if a binary tree is a valid BST
    // here we are storing the maximum and minimum values of a node to compare the values of child nodes and determine whether the binary tree is a valid BST
    bool isBST(TreeNode *root, long minValue = LONG_MIN, long maxValue = LONG_MAX)
    {
        // a null binary tree is trivially a valid BST
        if (!root)
            return true;

        // check if the current node has value between minValue and maxValue, and also check if the right and left subtrees are valid BSTs
        if (root->val > minValue && root->val < maxValue && isBST(root->left, minValue, root->val) && isBST(root->right, root->val, maxValue))
            return true;
        else
            return false;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isBST(root);
    }
};