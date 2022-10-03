// Author name : Shreya Jais
// Date: 3 October 2022

class Solution {
public:
    void deleteNode(ListNode* node) {
         node->val = node->next->val;
        ListNode *p = node->next;
        node->next = node->next->next;
        delete p;
        
    }
};
