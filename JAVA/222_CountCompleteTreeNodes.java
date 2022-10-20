// Name : Nihar Vira  
// Date : 20-10-2022


/*

Approach
The simplest approach to solve the given tree problem is to perform the DFS Traversal on the given tree &
count the number of nodes in it

*/

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
  public int countNodes(TreeNode root) {
    // calling the recursive function
    return count(root);
  }
  public int count(TreeNode root) {
    // if null value found then return
    if (root == null) {
      return 0;
    }
    
    // count each and add value to it simple recursion
    return 1 + count(root.left) + count(root.right);
  }
}
