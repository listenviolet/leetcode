# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next: return True
        new_list = []
        
        slow = fast = head
        while fast and fast.next:
            new_list.insert(0, slow.val)
            slow = slow.next
            fast = fast.next.next
            
        if fast: # odd
            slow = slow.next
        
        for val in new_list:
            if val != slow.val:
                return False
            slow = slow.next
        return True

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
            
# Runtime: 176ms
# Beats: 5.52%
# Memory beats: 9.63%