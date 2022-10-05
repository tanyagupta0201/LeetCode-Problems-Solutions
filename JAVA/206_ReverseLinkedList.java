// Name: Kumar Shanu
// Date: 04/10/2022



// The easiest thing is to know how we can add the element at first.

// currNode -> for iteration
// result -> to store the reverse
// newNode -> Create node with values

// Step 1: Iterate through the head linkedlist.

// Step 2: Take a new node with value as currNode.val and next as null

// Step 3: Put next of newNode.next = result .

// Step 4: Put result = newNode

// For example, if there is an element 1 in the result and if the newnode has 2 then if we 
// put the next of new node as result then 2 will be added infront of the result, or we can say
// new node will get attached at before the result list. Now we will assign result = newnode so
// the head of the linkedlist will be result, our desired answer.


class Solution {
    public ListNode reverseList(ListNode head) {
        
        if(head == null || head.next==null) return head;
        
        ListNode currNode = head;
        ListNode result = null;
        
        while(currNode!=null){
            
            ListNode newNode = new ListNode(currNode.val);
            newNode.next = result;
            result = newNode;
            
            currNode = currNode.next;
        }
        return result;
    }
}
