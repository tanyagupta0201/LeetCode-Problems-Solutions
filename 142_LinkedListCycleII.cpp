// Name : Adarsh Gupta
// Date : 03/10/2022

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode * detectCycle(ListNode * head) {
      ListNode * slow = head;
      ListNode * fast = head;
      ListNode * meet = head;
      while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast) {
          while (slow != meet) {
            meet = meet -> next;
            slow = slow -> next;
          }
          return meet;
        }
      }
      return NULL;
    }
};
