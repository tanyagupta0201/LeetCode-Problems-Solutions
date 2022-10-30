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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* z = head;
        int cnt=1;
        while(cnt<left-1){
            z=z->next;
            cnt++;
        }
        ListNode* x = z->next;
        if(left==1){
            x=head;
            z=NULL;
        }
        ListNode* a = NULL;
        ListNode* b = x;
        ListNode* c = x->next;
        while(left<=right){
            b->next=a;
            a=b;
            b=c;
            if(c!=NULL) c=c->next;
            left++;
        }
        x->next=b;
        if(z!=NULL) z->next=a;
        else head = a;
        return head;
    }
        
};