// Name: Ayush Sharma
// Date: 24/10/2022

/*
Problem Statement :
328. Odd Even Linked List (LEETCODE - Medium)
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even
indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Solution Explanation :-
We can execute this task by simply creating two fake heads "odd" and "even". In first fake head "odd" we will simply
traverse through the entire linked list and joining all the nodes on odd indices to the fake head. Now we do the same
for fake head "even", traversing entire linked list to join the nodes on even indices. Next up we just have to join the
tail of odd list with the head of even list. And return the head of the final list.

Time Complexity - O(N)
Space Complexity - O(1)
*/


class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {
        this.val = val;
    }
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode even = new ListNode(-1);
        ListNode odd = new ListNode(-1);
        ListNode even1 = even;
        ListNode odd2 = odd;
        ListNode curr = head;
        if (head == null || head.next == null) return head;
        ListNode curr1 = head.next;
        while (curr != null && curr.next != null) {
            odd.next = new ListNode(curr.val);
            curr = curr.next.next;
            odd = odd.next;
        }
        if (curr != null) {
            odd.next = new ListNode(curr.val);
            odd = odd.next;
        }
        while (curr1 != null && curr1.next != null) {
            even.next = new ListNode(curr1.val);
            curr1 = curr1.next.next;
            even = even.next;
        }
        if (curr1 != null) {
            even.next = new ListNode(curr1.val);
            even = even.next;
        }
        odd.next = even1.next;
        return odd2.next;
    }
}
