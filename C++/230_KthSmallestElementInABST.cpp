// Name : Stuti Verma
// Date : 22/10/2022

class Solution {
public:
    int ans;
    
    // Using Recursion
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
    
    void inorder(TreeNode* root, int& k) {
        if (!root) return;
        inorder(root->left, k);
        if (--k == 0){
            ans = root->val;
            return;
        } 
        inorder(root->right, k);
    }  
};

// Time complexity: O(n)
