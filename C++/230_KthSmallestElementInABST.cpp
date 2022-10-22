// Name : Stuti Verma
// Date : 22/10/2022

class Solution 
{
    public void inorderSolve(TreeNode root, int k, int[] result)//BST inorder is ascendingly sorted 
    {
        if(root == null)  // Base Condition 
            return;
        
        inorderSolve(root.left, k, result);  // Recursing the Left side of the tree
        
        result[0]= result[0] + 1;   // increamenting the of index 
        
        if(result[0] == k)
        {
            // when the required index is found 
            result[1]= root.val;  // Storing the value with the value present at kth index & -1 is for index out of bound 
            return;
        }
        
        inorderSolve(root.right, k, result);  // Recursing the Right side of the tree
        
        return;//returning to the callinng function 
    }
    public int kthSmallest(TreeNode root, int k) 
    {
        int[] result= {0, -1};
        
        inorderSolve(root, k, result);  // calling the inorder function to get the samllest kth element 
        
        return result[1];    // if the index is out of bound then -1 is returned, else the value is returned 
    }
}
// Time complexity: O(n)
