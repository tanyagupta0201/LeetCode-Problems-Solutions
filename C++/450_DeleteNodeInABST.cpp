// Name: Aditya Byju
// Date: 26/10/2022

/*
    Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

    Eg:
        Input: root = [5,3,6,2,4,null,7], key = 3
        Output: [5,4,6,2,null,null,7]

    Time complexity: O(h)
    Space complexity: O(h)
    (h is the height of the BST)
*/

class Solution
{
private:
    // helper function to find minimum value in a BST
    TreeNode *FindMin(TreeNode *root)
    {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // if root node of the BST is NULL, then just return root
        if (!root)
            return root;

        // if value of root node is greater than that of key, then delete node from left subtree
        else if (root->val > key)
            root->left = deleteNode(root->left, key);

        // if value of root node is lesser than that of key, then delete node from right subtree
        else if (root->val < key)
            root->right = deleteNode(root->right, key);

        // if root node's values is equal to key then there are 3 cases to consider
        else
        {
            // Case 1: if both children of the node is NULL just delete that node
            if (!root->left && !root->right)
            {
                delete root;
                root = NULL;
            }

            // Case 2: if only one of the child node is NULL then replace the node with its child and then delete the node
            else if (!root->left)
            {
                TreeNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if (!root->right)
            {
                TreeNode *temp = root;
                root = root->left;
                delete temp;
            }

            // if both children are not NULL then replace the value of the node with the minimum value in its right subtree, and then delete the minimum value node from its right subtree
            else
            {
                TreeNode *temp = FindMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};