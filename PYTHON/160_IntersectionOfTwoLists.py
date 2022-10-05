# Name: Aditya Chache
# Date: 05/10/2022




# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        
        myhash = {} 
    
        l1 = headA
        l2 = headB
        
        while l1:               # store all the nodes in a hash table since we don't know on which node
            myhash[l1] = 1      # the second list is gonna intersect
            l1 = l1.next
            
        while l2:
            if l2 in myhash:    # loop through the second list and if it contains any node that's in the 
                return l2       # hash table then return that node.
            l2 = l2.next
        
        return None             # if you don't find any node in hash table then return None since the 
                                # second list doesn't intersect the first
        
        
        # brute force with O(1) memory doesn't work (time limit exceeded)
#         l1 = headA
#         l2 = headB
        
#         while l1:
#             while l2:
#                 if l1 == l2:
#                     return l1
#                 l2 = l2.next
#             l1 = l1.next
#             l2 = headB
            
#         return None
        