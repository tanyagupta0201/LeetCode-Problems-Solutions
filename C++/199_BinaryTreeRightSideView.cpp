// Name: Simarprit Virdi
// Date: 05/10/2022

// Reverse Level Order Traversal's first element is Right View
class Solution
{
public:
    void RightViewBT(TreeNode *root, int lvl, map<int, int> &mp)
    {
        if (!root)
            return;
        if (mp.find(lvl) == mp.end())
            mp[lvl] = root->val;
        RightViewBT(root->right, lvl + 1, mp);
        RightViewBT(root->left, lvl + 1, mp);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        map<int, int> mp;
        RightViewBT(root, 0, mp);
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};