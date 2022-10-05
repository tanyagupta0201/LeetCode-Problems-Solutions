# Name: Aditya Chache
# Date: 05/10/2022



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
     
        if not head.next:
            return head
        
        s = head
        f = s
        
        while f and f.next:
            f = f.next.next
            s = s.next
            
        
        return s