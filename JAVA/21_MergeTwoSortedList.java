// Name: Madhu Saini
// Date: 05/10/22
class Solution {
  public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
    if (list1 == null || list2 == null) {
      return list1 != null ? list1 : list2;
    }

    ListNode c1 = list1, c2 = list2, dummy = new ListNode(-1), prev = dummy;
    while (c1 != null && c2 != null) {
      if (c1.val < c2.val) {
        prev.next = c1;
        c1 = c1.next;
      } else {
        prev.next = c2;
        c2 = c2.next;
      }
      prev = prev.next;
    }
    prev.next = c1 != null ? c1 : c2;
    ListNode head = dummy.next;
    dummy.next = null;
    return head;
  }
}
