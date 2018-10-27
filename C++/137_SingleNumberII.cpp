/* Given an array of integers, every element appears three times
*  except for one, which appears exactly once. Find that single one.
*
* Note:
* Your algorithm should have a linear runtime complexity.
* Could you implement it without using extra memory?
* How about generize three to n?
*
*/
#include <vector>

using namespace std;

/*
*  Boolean logic. Consider a single bit input and how that would drive the internal
state of a bit counter in the state table below. An input value '0' does not change
the internal state. Input of '1' drives the counter from state 0, 1, 2 and resets
back to zero.

The state table can be implemented as a boolean circuit with two XOR, two AND,
and two NOT gates. That construction is reflected in the solution code. Other
constructions with identical functionality are also possible.

'A'  'twos'  'ones'    'twos'  'ones'
 0      0       0    |    0       0
 0      0       1    |    0       1
 0      1       0    |    1       0
 1      0       0    |    0       1
 1      0       1    |    1       0
 1      1       0    |    0       0

*/

int singleNumber(vector<int>& nums) {

	int ones = 0, twos = 0;
	for (int i = 0; i < nums.size(); i++) {
		ones = (ones ^ nums[i]) & ~twos;
		twos = (twos ^ nums[i]) & ~ones;
	}
	return ones;

}

int main()
{
	vector<int> nums =  { 6, 6, 6, 3 };
	int ret = singleNumber(nums);
	return 0;
}
