// Name - Sneha Aggarwal
// Date - 05/10/2022

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
    void ReverseLL(ListNode *&head) {
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *next;
        while (temp != NULL) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // Recursive case
        ListNode *temp = head;
        for (int i = 0; i < k and temp != NULL; i++) {
            temp = temp->next;
        }
        ListNode *shead = reverseKGroup(temp, k);
        // Reverse the LL of after first k elements and mark their head as small
        // head Reverse current smaller LL of k elements
        temp = head;
        ListNode *oldHead = head;  // Store address of current head seperately
        for (int i = 0; i < k - 1; i++) {
            if(temp->next ==NULL){
                return head;
            }
            else{
                temp = temp->next;
            }
        }
        temp->next = NULL;  // Make current list of only k or lesser elements
        ReverseLL(head);    // Reverse the current smaller list
        oldHead->next = shead;
        // Point the smaller head of previously reversed list to current head
        return head;  // Return the reversed head
    }
};