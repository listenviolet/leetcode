class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 这里设的也很巧妙， 同号为TRUE，异号False
        positive = (dividend < 0) is (divisor < 0)    
        dividend, divisor = abs(dividend), abs(divisor)
        res = 0
        while dividend >= divisor:
            temp, i = divisor, 1
            while dividend >= temp:
                dividend -= temp
                res += i
                # 这里的temp 左移*2， 对应i*2 也是为了做temp的记录，可以减少时间复杂度
                i <<= 1
                temp <<= 1
        if not positive:
            res = -res
        return min(max(-2147483648, res), 2147483647)


# Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

# Return the quotient after dividing dividend by divisor.

# The integer division should truncate toward zero.

# Example 1:

# Input: dividend = 10, divisor = 3
# Output: 3
# Example 2:

# Input: dividend = 7, divisor = -3
# Output: -2
# Note:

# Both dividend and divisor will be 32-bit signed integers.
# The divisor will never be 0.
# Assume we are dealing with an environment which could only store integers 
# within the 32-bit signed integer range: [−231,  231 − 1]. 
# For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.