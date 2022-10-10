//Name: Supriya
//Date:10/10/2022
//Question:Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
/*Approach: Fast and Slow pointer Method
step-1: Find the length of the cycle
step-2: Make first and second pointer which points to head and traverse second pointer upto length of the cycle
step-3: Traverse while first and second pointers are not equals null */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast=head;
        ListNode slow=head;
        int len=0;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if(fast==slow){
                len=lengthCycle(slow);
                break;
            }
        }
            if(len==0){
                return null;
            }
            ListNode f=head;
            ListNode s=head;
            while(len>0){
                s=s.next;
                len--;
                
            }
            while(f!=s){
                f=f.next;
                s=s.next;
            }
        
        return s;
        
    }
    public int lengthCycle(ListNode head){
        ListNode fast=head;
        ListNode slow=head;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if(slow==fast){
                int length=0;
                ListNode temp=slow;
                do{
                    temp=temp.next;
                    length++;
                }while(temp!=slow);
            
              return length;
            }
        }
        return 0;
      
    }
}
