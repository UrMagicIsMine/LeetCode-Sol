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
*  need further analysis
*/

int singleNumber(vector<int>& nums) {

	int ones = 0, twos = 0;
	for (int i = 0; i < nums.size(); i++) {
		int tmp = ones ^ nums[i];
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
