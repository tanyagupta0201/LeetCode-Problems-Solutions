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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=b->next;
        head=head->next;
        b=b->next;
        head->next=a;
        a->next=b;
        if(c==NULL) return head;
        while(c!=NULL){
            c=c->next;
            if(c==NULL) break;
            a->next=c;
            c=c->next;
            a->next->next=b;
            b->next=c;
            a=a->next;
            b=b->next;
            a=a->next;
        }
        return head;
    }
};