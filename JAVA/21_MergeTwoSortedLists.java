// Name: Aaditya Raj
// Github Profile: aaditya1612
// Date: 14/10/2022



/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
    
    // Create a dummy Linked List to store the resultant merged list.
    // This linked list has hed value -1.
    ListNode dummy = new ListNode(-1);
    
    // Declare three objects of ListNode initialized with head of list1, list2 and dummy.
    ListNode pt1 = list1;
    ListNode pt2 = list2;
    ListNode pt3 = dummy;
    
    // Iterate through list1 and list2
    while (pt1 != null && pt2 != null) {
      if (pt1.val < pt2.val) {
        pt3.next = pt1;  // Append node store in pt1 into pt3
        pt1 = pt1.next; // Move pt1 to next node
      } else {
        pt3.next = pt2; // Append node store in pt2 into pt3
        pt2 = pt2.next; // Move pt1 to next node
      }
      pt3 = pt3.next; // Always move pt3 to next node
    }
    
    // Check if there is stil any node left in pt1, if yes then append it to pt3
    while (pt1 != null) { 
      pt3.next = pt1;
      pt1 = pt1.next;
      pt3 = pt3.next;
    }
    
    // Check if there is stil any node left in pt2, if yes then append it to pt3
    while (pt2 != null) {
      pt3.next = pt2;
      pt2 = pt2.next;
      pt3 = pt3.next;
    }
    
    // Return dummy.next because head has -1 and actual resultant list is starting after head.
    return dummy.next;

  }
}
