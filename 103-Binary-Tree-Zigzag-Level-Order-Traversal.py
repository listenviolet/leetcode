# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        
        queue = collections.deque()
        if not root: return []
        queue.append((root, 1))
        
        allRes = [[]]
        while queue:
            node, d = queue.popleft()
            if d > len(allRes):
                allRes.append([])
            allRes[d - 1].append(node.val)
            if node.left: queue.append((node.left, d + 1))
            if node.right: queue.append((node.right, d + 1))
                
        for i in range(len(allRes)):
            if i % 2:
                allRes[i].reverse()
        return allRes

# Runtime: 40 ms, faster than 79.95% of Python3 online submissions.
# Memory Usage: 13.6 MB, less than 5.36% of Python3 online submissions.

# Given a binary tree, return the zigzag level order traversal of its nodes' values. 
# (ie, from left to right, then right to left for the next level and alternate between).

# For example:
# Given binary tree [3,9,20,null,null,15,7],
#     3
#    / \
#   9  20
#     /  \
#    15   7
# return its zigzag level order traversal as:
# [
#   [3],
#   [20,9],
#   [15,7]
# ]