# Name: Aditya Chache
# Date: 05/10/2022



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        myhash = {}
        
        curr_node = head
        while curr_node:
            myhash[curr_node] = 1
            if curr_node.next in myhash:
                return curr_node.next
            curr_node = curr_node.next
            
        return None


#         Alternate Approach
#         if not head:
#             return None
#         else:
#             slow = head
#             fast = head
            
#             while fast and fast.next:
#                 slow = slow.next
#                 fast = fast.next.next
#                 if slow == fast:
#                     slow = head
#                     while slow != fast:
#                         slow = slow.next
#                         fast = fast.next
#                     return fast
#             return None
                    
            
        

        

        