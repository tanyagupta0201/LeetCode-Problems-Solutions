// Name: Shubham Kushwaha
// Date: 22 Oct, 2022

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
    ListNode * removeNthFromEnd(ListNode * head, int n) {
      // Create a new  Linked List (start) and next of start print to head.

      ListNode * start = new ListNode();
      start -> next = head;
      ListNode * slow = start;
      ListNode * fast = start;
      int c = 0;

      // We take two ListNodes and initialize them with start.
      // Start traverse to the nth node.

      for (int i = 1; i <= n; i++) {
        fast = fast -> next;
      }

      // Now again start traversing both the nodes(slow and fast) by one step. While fast of next not pointiing to null. 

      while (fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next;
      }

      // At the end slow's next point to slow's next to next .

      slow -> next = slow -> next -> next;

      // At the end return start of next.

      return start -> next;
    }
};
