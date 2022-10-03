/*
Author: Tasmiya Khan
Date: 2 October 2022
*/

class Solution {
  public:
    ListNode * deleteDuplicates(ListNode * head) {
      ListNode * ptr = head;
      if (head == nullptr) {
        return nullptr;
      }
      while (ptr -> next != nullptr) {
        if (ptr -> val == ptr -> next -> val) {
          ptr -> next = ptr -> next -> next;
        } else {
          ptr = ptr -> next;
        }
      }
      return head;
    }
};