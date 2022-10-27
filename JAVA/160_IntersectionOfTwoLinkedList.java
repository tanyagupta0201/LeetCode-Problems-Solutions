// Name : Ritika Rastogi
// Date : 27-10-2022

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
      // If any of the two nodes is null then the linked list has
      // no intersection point.
      if (ptr1 == null || ptr2 == null)
         return null;
      // Traverse the list until the intersection point is found.
      while (ptr1 != ptr2) {
         ptr1 = ptr1.next;
         ptr2 = ptr2.next;
         // If at any point ptr1==ptr2 return that node.
         if (ptr1 == ptr2)
            return ptr1;
        // The main logic behind this problem is once both the pointers go through re-assigning, they will be equidistant from the
        // collision point.
         if (ptr1 == null)
            ptr1 = headA;
         if (ptr2 == null)
            ptr2 = headB;

      }
      return ptr1;

   }
}
