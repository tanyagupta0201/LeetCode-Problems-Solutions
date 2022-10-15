#Author name:Chengalva Sai Harikha
#Date:15/10/2022
#Time complexity:O(n)
#Space Complexity:O(1)
class Solution(object):
    def swapPairs(self,head):
       #if head is None then the linked list is empty so return head
       if not head:
           return head
       #3 variables assigned to store 1st node and next node
       previous,current,answer=None,head,head.next
       #loop runs till current or current.next is not None 
       while current and current.next:
           adj=current.next
           if previous:
               previous.next=adj
           current.next,adj.next=adj.next,current
           previous,current=current,current.next
       return answer or head