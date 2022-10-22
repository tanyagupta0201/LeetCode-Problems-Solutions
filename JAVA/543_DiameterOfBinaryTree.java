// Name: Kumar Shanu
// Date: 05/10/2022



// Diameter : Number of node in the longest path between any two nodes.

// There may be three cases in which diameter can be found.

// Case 1: The diameter lies in left sub-tree.
// Case 2: The diameter lies in right sub-tree.
// Case 3: The diameter lies by joining left + right subtree+ root.

// Now in order to calculate this we are using the height function.
// Height function tells us the number of nodes present in the subtree and by adding 1(including root) 
// and the right subtree height we can find the diameter of the tree.

// And from the above three cases the one which would be maximum would be returned as the answer.



class Solution {
    
    // recursive function to find height of the tree
    public int height(TreeNode root){
        if(root == null)
            return 0;
        
        int left = height(root.left);
        int right = height(root.right);
        
        return Math.max(left,right)+1;
        
    }
    
    
    public int diameterOfBinaryTree(TreeNode root) {
        
        if(root == null)
            return 0;
        
        // case 1 : the left subtree diameter
        int diam1 = diameterOfBinaryTree(root.left);
       
        // case 2 : the right subtree diameter
        int diam2 = diameterOfBinaryTree(root.right);
      
        // case 3: the left+right+root
        int diam3 = height(root.left) + height(root.right);
        
        return Math.max(Math.max(diam1, diam2), diam3);
        
    }
}
