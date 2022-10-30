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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *a=head,*b=head->next,*e=NULL;
        while(a!=NULL){
            if(a->next==NULL){
                if(e==NULL){
                    head=a;
                    e=a;
                }
                else{
                    e->next=a;
                    e=e->next;
                }
                e->next=NULL;
                break;
            }
            if(b->next!=NULL && a->val==b->next->val){
                delete a;
            }
            else if(a->val==b->val){
                ListNode* d=b;
                b=d->next;
                delete a;
                delete d;
                if(b==NULL) break;
            }
            else{
                if(e==NULL){
                    head=a;
                    e=a;
                }
                else{
                    e->next=a;
                    e=a;
                }
                e->next=NULL;
            }
            a=b;
            b=b->next;
        }
        if(e==NULL) return NULL;
        return head;
    }
};