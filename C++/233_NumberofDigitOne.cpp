/*iven an integer n, count the total number of digit 1 appearing in all
non-negative integers less than or equal to n.

Example:

Input: 13
Output: 6
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

int countDigitOne(int n) {
	int ret = 0, res = 0, i = 0, adv = 1, rem = 0;
	while (n) {
		res = n % 10;
		n /= 10;
		ret += res * i * (adv / 10);
		if (res > 1)
			ret += adv;
		else if (res == 1)
			ret += (rem + 1);
		rem += res * adv;
		adv *= 10;
		i++;
	}
	return ret;
}
