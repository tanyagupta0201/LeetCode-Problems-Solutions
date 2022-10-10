//  Name:  Amit singh Bisht
//  Date:  10/10/2022

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
      ListNode *temp,*h=new ListNode; // create a new listnode and allocate data 
        h=NULL;
        int sum=0;       // to store the sum 
        while(head!=NULL)
        {
           head=head->next;
           if(head==0) continue;  // for the first node it is always 0
           sum+=head->val;
            if(head->val==0) // check whether the head node is 0 or not
            {
            ListNode *ans=new ListNode; // create a new listnode and allocate data 
              if(h==NULL)    
              {
                  ans->val=sum; 
                  temp=ans;
                  h=ans;   
                  sum=0;
              }
              else    // if it is zero assign sum to  the newly created node and reassign sum=0
              {
               ans->val=sum;
               h->next=ans;
               h=ans;  sum=0;
              }
                    
            }
        }
        return temp;
    }
};