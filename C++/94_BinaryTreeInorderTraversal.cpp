// Name: Ukesh Shrestha
// Date: 02/10/2022

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<TreeNode *> stack;
        vector<int> v;

        while (stack.size() > 0 || root != NULL)
        {
            if (root != NULL)
            {
                stack.push_back(root);
                root = root->left;
            }
            else
            {
                if (stack.size() > 0)
                {
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return v;
    }
};
