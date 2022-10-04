//Name : Simarprit Virdi
//Date : 04/10/2022

class Solution {
public:
    int solve(TreeNode* root,int& sum)
    {
        if(!root)
            return 0;
        int lh=solve(root->left,sum);
        int rh=solve(root->right,sum);
        int temp=max(max(lh,rh)+root->val,root->val);//either complete sum or if neagtive hen only root node
        int ans=max(temp,root->val+lh+rh);
        sum=max(ans,sum);
        return temp;
    }
    int maxPathSum(TreeNode* root) 
    {
        int sum=INT_MIN;
        solve(root,sum);
        return sum;
    }
};
