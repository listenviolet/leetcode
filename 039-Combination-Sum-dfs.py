
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.allRes = []
        sorted(candidates)
        self.helper(candidates, target, [])
        return self.allRes
        
    def helper(self, candidates, target, tmp):
        if(target == 0):
            self.allRes.append(tmp[:])
        for i in range(len(candidates)):
            if(target >= candidates[i]):
                tmp.append(candidates[i])
                self.helper(candidates[i:], target - candidates[i], tmp)
                tmp.pop()

# Runtime: 48 ms, faster than 93.24% of Python online submissions for Combination Sum.
# Memory Usage: 11.7 MB, less than 5.02% of Python online submissions for Combination Sum.

# Given a set of candidate numbers (candidates) (without duplicates) 
# and a target number (target), 
# find all unique combinations in candidates where the candidate numbers sums to target.

# The same repeated number may be chosen from candidates unlimited number of times.

# Note:

# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
# Example 1:

# Input: candidates = [2,3,6,7], target = 7,
# A solution set is:
# [
#   [7],
#   [2,2,3]
# ]
# Example 2:

# Input: candidates = [2,3,5], target = 8,
# A solution set is:
# [
#   [2,2,2,2],
#   [2,3,3],
#   [3,5]
# ]