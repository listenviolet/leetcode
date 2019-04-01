# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
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

# Runtime: 40ms
# Beats: 89.94%
# Memory beats: 32.86%