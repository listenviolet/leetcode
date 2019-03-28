# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root: return True
        return self.isBSTHelper(root, None, None)
        
    def isBSTHelper(self, node, lower_limit, upper_limit):
        if lower_limit is not None and node.val <= lower_limit: return False
        if upper_limit is not None and node.val >= upper_limit: return False
        
        left = self.isBSTHelper(node.left, lower_limit, node.val) if node.left else True
        if left:
            right = self.isBSTHelper(node.right, node.val, upper_limit) if node.right else True
            return right
        else:
            return False

# Runtime: 52ms
# Beats: 83.37%
# Memory Beats: 5.14%
# Time complexity: O(n)
# Space complexity: O(n)