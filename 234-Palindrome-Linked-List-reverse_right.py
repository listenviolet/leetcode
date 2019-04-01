# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next: return True
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        if fast:
            slow = slow.next
        right = self.reverseList(slow)
        while head and right:
            if head.val != right.val:
                return False
            head = head.next
            right = right.next
        return True
    
    def reverseList(self, head):
        if not head or not head.next: return head
        p1 = head
        p2 = p1.next
        p1.next = None
        while p2.next is not None:
            p3 = p2.next
            p2.next = p1
            p1 = p2 
            p2 = p3
        p2.next = p1
        return p2

# Description:
# Given a singly linked list, determine if it is a palindrome.

# Example 1:

# Input: 1->2
# Output: false
# Example 2:

# Input: 1->2->2->1
# Output: true
# Follow up:
# Could you do it in O(n) time and O(1) space?

# Alg:
# 判断回文主要是前半部分和后半部分的比较，
# 若能将后半部分反转（仍然是单链表），则可以方便的判断回文。 

# Runtime: 80ms
# Beats: 68.36%
# Memory beats: 12.14%
