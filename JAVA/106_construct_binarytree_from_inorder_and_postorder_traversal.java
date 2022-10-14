//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    private int postIdx;
    private int len;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        len = inorder.length;
        postIdx = len - 1;
        return construct(inorder, postorder, 0, len-1);
    }
    private TreeNode construct(int[] in, int[] post, int start, int end){
        if(start > end) return null;
        TreeNode root = new TreeNode(post[postIdx--]);
        int cur = findIdx(in, root.val);
        root.right = construct(in, post, cur+1, end);
        root.left = construct(in, post, start, cur-1);
        return root;  
    }
    private int findIdx(int[] inorder, int val){
        for(int i=len-1; i>=0; i--)
            if(inorder[i] == val)
                return i;
        return -1;
    }
}
