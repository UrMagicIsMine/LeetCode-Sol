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

public int reverse(int x) {
    boolean isPositive = (x >= 0)? true : false;
    long result = 0;
    long absX = Math.abs(x);
    while(absX != 0) {
        result = result * 10 + absX%10;
        absX /= 10;
    }
    if (!isPositive) {
        result = -result;
    }
    if (result > Integer.MAX_VALUE || result < Integer.MIN_VALUE) {
        return 0;
    }
    return (int)result;
}
