# Name: Aditya Chache
# Date: 05/10/2022


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        

        newnode = ListNode()            # create a new linked list
        current_node = newnode          # node to update
        
        while list1 and list2:   
            if list1.val < list2.val:
                current_node.next = list1
                list1 = list1.next
            else:
                current_node.next = list2
                list2 = list2.next
            
            current_node = current_node.next   
            
            
        if list1:                       # after loop has ended if one of the list is still having elements then add
                                        # those elements to the end of our list
            current_node.next = list1
        elif list2:
            current_node.next = list2
            
        return newnode.next             # return the new list

        
# [1,2,3,4,5]
# [1,3,7]
            