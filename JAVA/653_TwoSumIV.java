// Author - Manjunath GB
//Date-09/10/2022

 /*Two Sum IV - Input is a BST
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105 */
 public class Two_Sum_IV {
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
         ArrayList<Integer> al =  new ArrayList<Integer>();
         public void tra(TreeNode r){
             if(r==null)
                 return ;
             tra(r.left);
             al.add(r.val);
             tra(r.right);
             return ;
         }
         public boolean findTarget(TreeNode root, int k) {
             tra(root);
             int i=0,j=al.size()-1;
             while(i<j){
                 if(al.get(i)+al.get(j)==k)
                     return true;
                 else if(al.get(i)+al.get(j)>k)
                     j--;
                 else
                     i++;
             }
             return false;
         }
 }

