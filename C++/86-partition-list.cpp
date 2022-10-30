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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* z = head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        while(z!=NULL){
            if(z->val<x){
                if(a==NULL) {
                    a=z;
                    head=a;
                }
                else{
                    a->next=z;
                    a=a->next;
                }
            }
            else{
                if(b==NULL){
                    b=z;
                    c=b;
                }
                else{
                    b->next=z;
                    b=b->next;
                }
            }
            z=z->next;
        }
        if(b!=NULL) b->next=NULL;
        if(a!=NULL) {
            a->next=c;
            return head;
        }
        else return c;
    }
};