# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        rev = None
        slow = fast = head
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast is not None:
            slow = slow.next
        while rev is not None and rev.val == slow.val:
            slow = slow.next
            rev = rev.next
        return not rev
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
# Copied from the fastest accepted solution.
# reverse the left part of the linked list while traverse
# rev, rev.next, slow = slow, rev, slow.next
# Notice:
# This has to be written in one line, 
# to use the old value of each variable
# otherwise, it will be in endless loop.

# Runtime: 80ms
# Beats: 68.36%
# Memory beats: 10.88%
