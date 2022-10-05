// Name: Simarprit Virdi
// Date: 05/10/2022

class Solution
{
    int sum;

public:
    int help(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = max(0, help(root->left));
        int right = max(0, help(root->right));
        /*** key parts : embedding the max-value-find in the recursion process ***/
        sum = max(sum, left + right + root->val);
        /*** get the max-value-ended-at-root ***/
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        sum = INT_MIN;
        help(root);
        return sum;
    }
};
