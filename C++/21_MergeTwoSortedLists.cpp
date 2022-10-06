// Name: Md Farhan Sajid
// Date: 03/10/2022

class Solution {
  public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
      if (l1 == NULL) {
        return l2;
      }

      if (l2 == NULL) {
        return l1;
      }

      ListNode * head = NULL;

      if (l1 -> val < l2 -> val) {
        head = l1;
        l1 = l1 -> next;
      } else {
        head = l2;
        l2 = l2 -> next;
      }

      ListNode * p;
      p = head;

      while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
          p -> next = l1;
          l1 = l1 -> next;
        } else {
          p -> next = l2;
          l2 = l2 -> next;
        }

        p = p -> next;
      }

      if (l1 != NULL) {
        p -> next = l1;
      } else {
        p -> next = l2;
      }

      return head;
    }
};
