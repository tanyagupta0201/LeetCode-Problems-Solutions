// Name: Vidushi Bhatnagar
// Date: 14/10/2022

class Solution {
  public:
    void deleteNode(ListNode * node) {
      node -> val = node -> next -> val; //Assigning next node value
      node -> next = node -> next -> next; //next pointer points to next next of node

    }
};
