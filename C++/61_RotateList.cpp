// Name : Adarsh Gupta
// Date : 03/10/2022

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode * rotateRight(ListNode * head, int k) {
      ListNode * last = head;
      int c = 0;
      if (head == NULL || k == 0)
        return head;
      while (last -> next != nullptr) {
        c++;
        last = last -> next;
      }

      last -> next = head;
      k = k % (c + 1);
      int jump = c - k;
      last = head;
      while (jump--) {
        last = last -> next;
      }
      ListNode * newhead = last -> next;
      last -> next = NULL;

      return newhead;
    }
};
