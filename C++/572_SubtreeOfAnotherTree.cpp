// Name: Mahima Chauhan
// Date: 18/10/2022
class Solution {
  bool checkfunc(TreeNode * root, TreeNode * subRoot) {
    // If the root is null then check condition if subroot is null or not.
    if (root == NULL) {
      return subRoot == NULL;
    }
    // If the subroot is null then check condition if root is null or not.
    if (subRoot == NULL) {
      return root == NULL;
    }
    // If the value of root is same as subroot then check if the data of both roots is same and data of left and right subtrees are also same
    if (root -> val == subRoot -> val) {
      return checkfunc(root -> left, subRoot -> left) && checkfunc(root -> right, subRoot -> right);
    }
    return false;

  }
  public:
    bool isSubtree(TreeNode * root, TreeNode * subRoot) {
      // If the root is null then we will check the condition if subRoot is also null or not.
      if (root == NULL) {
        return subRoot == NULL;
      }
      // If the value of root in the tree is same as value of subRoot in the subtree then we will check the boolean value of checkfun()
      if (root -> val == subRoot -> val) {
        if (checkfunc(root, subRoot)) return true;
      }
      // else check in the left or right part of tree and subtree.
      return (isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot));

    }
};