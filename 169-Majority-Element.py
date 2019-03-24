class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dict = {}
        M = 0
        
        for i in range(n):
            if nums[i] in dict.keys():
                dict[nums[i]] += 1
            else:
                dict[nums[i]] = 1
            if dict[nums[i]] > M:
                M = dict[nums[i]]
                K = nums[i]
        return K

# Description
# Given an array of size n, find the majority element. 
# The majority element is the element that appears more than ⌊ n/2 ⌋ times.

# You may assume that the array is non-empty 
# and the majority element always exist in the array.

# Example 1:

# Input: [3,2,3]
# Output: 3
# Example 2:

# Input: [2,2,1,1,1,2,2]
# Output: 2


# Beats: 2.49%
# Runtime: 132ms
# easy