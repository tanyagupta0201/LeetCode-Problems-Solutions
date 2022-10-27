//Name:Ritika Rastogi
//Date:27-10-2022

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
   public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
      ListNode ptr1 = headA;
      ListNode ptr2 = headB;
      if (ptr1 == null || ptr2 == null)
         return null;
      while (ptr1 != ptr2) {
         ptr1 = ptr1.next;
         ptr2 = ptr2.next;
         if (ptr1 == ptr2)
            return ptr1;
         if (ptr1 == null)
            ptr1 = headA;
         if (ptr2 == null)
            ptr2 = headB;

      }
      return ptr1;

   }
}