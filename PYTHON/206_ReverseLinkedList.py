# Name: Aditya Chache
# Date: 05/10/2022


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        # One Approach
        if not head:
            return None
        elif not head.next:
            return head
        else:
            sec_head = head
            while head.next:
                temp = head.next
                head.next = temp.next
                temp.next = sec_head
                sec_head = temp

            return temp

        # Another Approach
        # if not head:
        #     return None

        # else:
        #     first = head
        #     second = first.next

        #     while second:
        #         temp = second.next
        #         second.next = first
        #         first = second
        #         second = temp

        #     head.next = None
        #     head = first

        #     return head
