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
class cmp {
public:
    bool operator()(ListNode * l1, ListNode * l2)
    {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        int len=lists.size();
        
        for(int i = 0; i < len; i++)
            if(lists[i] != NULL)
                pq.push(lists[i]);
        
        ListNode* sol = new ListNode();
        ListNode* curr = sol;
        
        while (!pq.empty())
        {
            curr->next = pq.top();
            curr = curr->next;
            pq.pop();
            if(curr->next != NULL)
                pq.push(curr->next);
        }
        
        if(sol != NULL)
            sol = sol->next;
        return sol;
        
    }
};
