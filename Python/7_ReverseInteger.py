# Given a 32-bit signed integer, reverse digits of an integer.
#
#Example 1:
#
#Input: 123
#Output: 321
#Example 2:
#
#Input: -123
#Output: -321
#Example 3:
#
#Input: 120
#Output: 21
#Note:
#Assume we are dealing with an environment which could only
#store integers within the 32-bit signed integer range: [-2^31,  2^31 - 1].
#For the purpose of this problem, assume that your function returns 0 when the
#reversed integer overflows.
#

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        value = 0
        sign = True if x > 0 else False
        x = abs(x)
        while x != 0:
            value = value * 10 + x % 10
            x /= 10

        value = value if sign == True else -value
        if value > 2**31 - 1 or value < -2**31:
            return 0
        else:
            return value
