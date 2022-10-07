//  Name:  Amit singh Bisht
//  Date:  07/10/2022

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int r = 0;
        ListNode *head, *temp = new ListNode; // create a new listnode and allocate memory to it
        head = NULL;
        int c = 0;
        while (l1 != 0 && l2 != 0)
        {
            ListNode *a = new ListNode;
            int sum = l1->val + l2->val + r; // add the data in both the list
            if (sum < 10)
            {
                a->val = sum;  // if data is less than 10 push it to new list
                r = 0;
            }
            else
            {
                a->val = sum % 10; // data is greater than 10 so push the remainder two to the list and store its carry
                r = sum / 10;
            }
            if (head == NULL)
            {
                head = a;     // if head is null than point it to newly created list a
            }
            else
            {
                head->next = a; // keep tracking previous and next nodes in list
                head = a;
            }
            if (c == 0)
            {
                temp = head;
                c = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != 0)   //if  the list 1 is greater than list 2
        {
            ListNode *a = new ListNode;
            int sum = l1->val + r;
            if (sum < 10)
            {
                r = 0;
                a->val = sum;
            }
            else
            {
                a->val = sum % 10;
                r = sum / 10;
            }

            if (head == NULL)
            {
                head = a;
            }
            else
            {
                head->next = a;
                head = a;
            }
            if (c == 0)
            {
                temp = head;
                c = 1;
            }
            l1 = l1->next;
        }
        while (l2 != 0) //if  the list 2 is greater than list 1
        {
            ListNode *a = new ListNode;
            int sum = l2->val + r;
            if (sum < 10)
            {
                a->val = sum;
                r = 0;
            }
            else
            {
                a->val = sum % 10;
                r = sum / 10;
            }
            if (head == NULL)
            {
                head = a;
            }
            else
            {
                head->next = a;
                head = a;
            }
            l2 = l2->next;
            if (c == 0)
            {
                temp = head;
                c = 1;
            }
        }
        if (r > 0)
        {
            ListNode *a = new ListNode;
            a->val = r;
            head->next = a;
            head = a;
        }
        return temp; // return the address of head node of the final list
    }
};
