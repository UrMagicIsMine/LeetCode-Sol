/* Given a non-negative integer represented as a non-empty array of digits, plus
* one to the integer.
*
* You may assume the integer do not contain any leading zero, except the number
* 0 itself.
*
* The digits are stored such that the most significant digit is at the head of
* the list.
*/

#include <vector>
#include <cassert>
using namespace std;

/* One pass solution, run-time O(N), space O(1)
*/

vector<int> plusOne(vector<int>& digits) {
	int N = digits.size(), carry = 1;
	for (int i = N - 1; i >= 0; i--) {
		digits[i] += carry;
		if (digits[i] > 9) {
			digits[i] -= 10;
			carry = 1;
		}
		else {
			carry = 0;
			break;
		}
	}
	if (carry)
		digits.insert(digits.begin(), 1);
	return digits;
}

int main()
{
	vector<int> nums = { 9,9,9 };
	vector<int> ans = { 1,0,0,0 };
	vector<int> ret = plusOne(nums);
	assert(ret == ans);
	return 0;
}
