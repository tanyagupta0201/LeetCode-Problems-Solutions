# Name: Aditya Chache
# Date: 06/10/2022


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        # if only head is there then there's no middle node so return None
        if not head.next:
            return None
        
        # Else create a dummy node at the start of the list so the list will be like dummy->1->2->3->4->5
        dummy = ListNode()  
        dummy.next = head
        
        # Initialize two pointers slow and fast
        s = dummy
        f = head
        
        # increment slow by one and fast by two
        while f and f.next:
            f = f.next.next
            s = s.next
            

        # After the above loop slow will be automatically at a position one node behind our target node 
        s.next = s.next.next

        # delete the target node and return the original list
        return head