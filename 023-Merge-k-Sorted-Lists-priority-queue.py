# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from Queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next

# In python, not python3
# Differences between python and python3:
# 1. python:  from Queue import PriorityQueue
#    python3: from queue import PriorityQueue
# 2. python:  q.put((l.val, l)) is correct
#    python3: TypeError: '<' not supported between instances of 'ListNode' and 'ListNode'
#    SOlution: add __lt__() function in class defination

# Runtime: 188ms
# Beats: 19.45%
# Memory beats: 7.03%