# Name: Soniya Parate
# Date: 21/10/2022

class Solution:
	# function will reverse list
	def reverse(self, head):
		if head is None or head.next is None:
			return head
		prev = None
		next = None
		curr = head
		while curr is not None:
			next = curr.next
			curr.next = prev
			prev = curr
			curr = next
		head = prev
		return head

	# function will add two number by linked list
	def addTwoLists(self, first, second):
		curr1 = self.reverse(first)
		curr2 = self.reverse(second)
		sum = 0
		carry = 0
		res = None
		prev = None
		while curr1 is not None or curr2 is not None:
		# while both lists have atleast one node
			sum = carry + (curr1.data if curr1 else 0) + 
				(curr2.data if curr2 else 0)
			carry = (1 if sum >= 10 else 0)
			sum = sum % 10
			temp = Node(sum)
			if res is None:
				res = temp
			else:
				prev.next = temp
			prev = temp
			if curr1:
				curr1 = curr1.next
			if curr2:
				curr2 = curr2.next
		if carry > 0:
			temp.next = Node(carry)
		ans = self.reverse(res)
		return ans


class Node:
	def __init__(self, data):
		self.data = data
		self.next = None


class LinkedList:
	def __init__(self):
		self.head = None
		self.tail = None
	# insert linked list
	def insert(self, val):
		if self.head is None:
			self.head = Node(val)
			self.tail = self.head
		else:
			self.tail.next = Node(val)
			self.tail = self.tail.next

def printList(n):
	while n:
		print(n.data, end = ' ')
		n = n.next
	print()
  
if __name__ == "__main__":
	# take a first list
	arr1 = [7, 5, 9, 4, 6]
	LL1 = LinkedList()
	for i in arr1:
		LL1.insert(i)
	print("First list is", end = " ")
	printList(LL1.head)
	# take 2nd list
	arr2 = [8, 4]
	LL2 = LinkedList()
	for i in arr2:
		LL2.insert(i)
	print("Second list is", end = " ")
	printList(LL2.head)

	# Function Call
	res = Solution().addTwoLists(LL1.head, LL2.head)
	print("Resultant list is", end = " ")
	printList(res)
