#%%
#Author name:Chengalva Sai Harikha
#Date:15/10/2022
class Solution(object):
    def swapPairs(self,head):
       if not head:
           return head
       previous,current,answer=None,head,head.next
       while current and current.next:
           adj=current.next
           if previous:
               previous.next=adj
           current.next,adj.next=adj.next,current
           previous,current=current,current.next
       return answer or head