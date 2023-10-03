/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode curr = new ListNode(-1);
        ListNode head = curr;
        ListNode curr_2 = l2;
        int carry = 0;
        while(l1!=null && l2!=null){
            int a = l1.val+l2.val+carry;
            carry = a/10; a %= 10;
            curr.next = new ListNode(a);
            l1 = l1.next; l2 = l2.next; curr = curr.next;
        }
        while(l1!=null){
            int a = l1.val+carry;
            carry = a/10; a %= 10;
            curr.next = new ListNode(a);
            l1 = l1.next; curr = curr.next;
        }
        while(l2!=null){
            int a = l2.val+carry;
            carry = a/10; a %= 10;
            curr.next = new ListNode(a);
            l2 = l2.next; curr = curr.next;
        }
        if (carry!=0) curr.next = new ListNode(1);
        return head.next;
    }
}