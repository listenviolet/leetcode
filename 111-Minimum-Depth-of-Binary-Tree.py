# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        queue = collections.deque()
        
        queue.append((root, 1))
        
        while queue:
            node, d = queue.popleft()
            if not node.left and not node.right: return d
            
            if node.left: queue.append((node.left, d + 1))
            if node.right: queue.append((node.right, d + 1))

# Runtime: 48 ms, faster than 94.47% of Python3 online submissions.
# Memory Usage: 14.5 MB, less than 66.06% of Python3 online submissions.

# Given a binary tree, find its minimum depth.

# The minimum depth is the number of nodes along the shortest path 
# from the root node down to the nearest leaf node.

# Note: A leaf is a node with no children.

# Example:

# Given binary tree [3,9,20,null,null,15,7],

#     3
#    / \
#   9  20
#     /  \
#    15   7
# return its minimum depth = 2.


