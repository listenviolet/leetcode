# class Solution:
#     def removeDuplicates(self, nums: List[int]) -> int:
#         if not nums: return 0
#         i = len(nums) - 1
#         length = 0

#         while i >= 0:
#             cnt = 0
#             j = i - 1
#             # print('i = ', i, " j = ", j)
#             # print('nums = ', nums)
#             while j >= 0 and nums[j] == nums[i]:
#                 cnt += 1
#                 j -= 1
#                 # print('i = ', i, " j = ", j)
#             start = j + 1
            
#             k = start + 1
#             # print('cnt = ', cnt, 'k = ', k)
#             if cnt > 0: 
#                 tmp = 0
#                 while tmp < length:
#                     nums[k] = nums[k + cnt]
#                     k += 1
#                     tmp += 1
#             i = start - 1

#             length += 1
#         return length

# Time Limit Exceeded

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums: return 0
        i = 0
        for j in range(len(nums)):
            if nums[i] != nums[j]:
                i += 1
                nums[i] = nums[j]
        return i + 1

# Runtime: 80 ms, faster than 97.94% of Python3 online submissions for Remove Duplicates from Sorted Array.
# Memory Usage: 14.4 MB, less than 99.18% of Python3 online submissions for Remove Duplicates from Sorted Array.