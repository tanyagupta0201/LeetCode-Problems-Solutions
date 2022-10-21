// Name: Chandan Sahu
// Date: 18/10/2022
class Solution {
  public:
    /* Compute the "maxDepth" of a tree -- the number of
        nodes along the longest path from the root node
        down to the farthest leaf node.*/
    int maxDepth(TreeNode * root) {
      if (root == NULL) 
         return 0;
      /* compute the depth of each subtree */
      int left = maxDepth(root -> left);
      int right = maxDepth(root -> right);
      /* return the larger one */
      return max(left, right) + 1;
    }
};
