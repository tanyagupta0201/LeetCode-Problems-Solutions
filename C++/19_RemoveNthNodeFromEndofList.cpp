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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //Optimised Method
    //Time Complexity:- O(n) [One Pass]
    //Space Complexity:-O(1)
        
    //Let's keep a fast pointer and will traverse it over the list
    //till it reaches one node before the node to be deleted.     
        ListNode *fast=head;
        for(int i=0;i<n;i++)
            fast=fast->next;
    //If fast would have reached NULL this means the node to be deleted 
    //is equal to the number of nodes in the linked list.   
        if(fast==NULL)
        {
            ListNode *node=head;
            head=head->next;
            delete node;
            return head;
        }
    //And if not the above case, then let's keep a slow pointer which is 
    //assigned head. Now, move both slow and fast pointer simultaneously
    //till the fast pointer reaches the last node. Here,you will observe 
    //that slow pointer is standing one node before the node to be 
    //deleted.       
        ListNode *slow=head;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    //Simply delete the nth node from the end of the list.         
        ListNode *node=slow->next;
        slow->next=node->next;
        delete node;
        
    return head;
    }
};
