// Author: Garv Luthra
// Date: 14/10/22


// link of the leetcode problem below:

// https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode * head) {
      ListNode * h = head;
      ListNode * p = head;

      // h moves twice as fast as p

      bool collision = false;
      while (h and h -> next) {
        h = h -> next -> next;
        p = p -> next;

        // if h and p collides then, we have a cyclic linked list
        // else we don't have a cyclic linked list

        if (h == p) {

            // collision
          cout << p -> val << " " << h -> val << endl;
          collision = true;
          break;
        }
      }

      return collision;

    }
};
