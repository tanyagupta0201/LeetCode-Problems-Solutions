// Name: Aaditya Raj
// Github Profile: aaditya1612
// Date: 14/10/2022



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
  public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

    ListNode dummy = new ListNode(-1);

    ListNode pt1 = list1;
    ListNode pt2 = list2;
    ListNode pt3 = dummy;

    while (pt1 != null && pt2 != null) {
      if (pt1.val < pt2.val) {
        pt3.next = pt1;
        pt1 = pt1.next;
      } else {
        pt3.next = pt2;
        pt2 = pt2.next;
      }
      pt3 = pt3.next;
    }
    while (pt1 != null) {
      pt3.next = pt1;
      pt1 = pt1.next;
      pt3 = pt3.next;
    }
    while (pt2 != null) {
      pt3.next = pt2;
      pt2 = pt2.next;
      pt3 = pt3.next;
    }
    return dummy.next;

  }
}
