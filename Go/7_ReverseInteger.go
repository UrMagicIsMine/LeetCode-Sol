/* Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only
store integers within the 32-bit signed integer range: [-2^31,  2^31 - 1].
For the purpose of this problem, assume that your function returns 0 when the
reversed integer overflows.
*/

func reverse(x int) int {
    isPositive := true
    if x < 0 {
        isPositive = false
    }
    var absX int64 = Abs(int64(x))
    var value int64 = 0
    for absX != 0 {
        value = value * 10 + absX%10
        absX /= 10
    }
    if isPositive == false {
        value = - value
    }
    if value > math.MaxInt32  || value < math.MinInt32 {
        return 0
    }
    return int(value)
}

func Abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}
