# Name: Aditya Chache
# Date: 06/11/2022

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        # Time and Space O(N)

        # if root doesn't exists return None
        if not root:
            return 

        # if only the root exists then return itself since there are not other nodes to invert
        if not root.left and not root.right:
            return root
        else:
            # traverse the left subtree
            if root.left:
                self.invertTree(root.left)
            
            # traverse the right subtree
            if root.right:
                self.invertTree(root.right)
                
            # swap the nodes once you reach the leaf nodes 
            root.left,root.right = root.right,root.left
            
            return root 
        