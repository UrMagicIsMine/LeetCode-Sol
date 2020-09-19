/* Given n non-negative integers a1, a2, ..., an, where each represents a point
* at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
* of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
* forms a container, such that the container contains the most water.
*
* Note: You may not slant the container and n is at least 2.
*/

func maxArea(height []int) int {
    low, high, maxArea := 0, len(height) - 1, 0
    for low < high {
        area := min(height[low], height[high]) * (high - low)
        maxArea = max(area, maxArea)
        if height[low] < height[high] {
            low++
        } else {
            high--
        }
    }
    return maxArea
}

func max(x, y int) int {
    if x < y {
        return y
    }
    return x
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
