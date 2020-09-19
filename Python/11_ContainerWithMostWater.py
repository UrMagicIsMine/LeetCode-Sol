# Given n non-negative integers a1, a2, ..., an, where each represents a point
# at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
# of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
# forms a container, such that the container contains the most water.
#
# Note: You may not slant the container and n is at least 2.
#

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        low = 0
        high = len(height) - 1
        while low < high:
            area = min(height[high], height[low]) * (high - low)
            max_area = max(max_area, area)
            if height[low] < height[high]:
                low += 1
            else:
                high -= 1

        return max_area
