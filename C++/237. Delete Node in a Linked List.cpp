// Name: Vidushi Bhatnagar
// Date: 14/10/2022

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
        
    }
};
