# Author name:Chengalva Sai Harikha
# Date:15/10/2022
# Time complexity:O(n) where n is the length
# Space Complexity:O(1)
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        # 3 variables assigned to store 1st node and next node
        previous, current, answer = None, head, head.next
        # loop runs till current or current.next is not None
        while current and current.next:
            # adj variable stores the next variable to current
            adj = current.next
            if previous:
                previous.next = adj
            current.next, adj.next = adj.next, current
            previous, current = current, current.next
        return answer or head
