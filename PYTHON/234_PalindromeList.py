# Name: Aditya Chache
# Date: 05/10/2022



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
         
        stack = [] 
        
        # add all the nodes in the stack
        curr_node = head
        
        while curr_node:
            stack.append(curr_node)
            curr_node = curr_node.next
            
        
        # check val from original list and stack
        
        while head:
            if head.val != stack[-1].val:
                return False
            else:
                stack.pop()
                head = head.next
        
        return True
        
#         og = ""
#         rev = ""
        
#         curr = head
#         while curr:
#             og += str(curr.val)
#             curr = curr.next
        
#         first = head
#         second = first.next
#         while second:
#             temp = second.next
#             second.next = first
#             first = second
#             second = temp
            
#         head.next = None
#         head = first
        
#         curr2 = head
#         while curr2:
#             rev += str(curr2.val)
#             curr2 = curr2.next
        
        
#         return int(og) == int(rev)
            
    
    