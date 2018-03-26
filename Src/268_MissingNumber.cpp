/* Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
* find the one that is missing from the array.
*
* Example 1
*
* Input: [3,0,1]
* Output: 2
* Example 2
*
* Input: [9,6,4,2,3,5,7,0,1]
* Output: 8
*
* Note:
* Your algorithm should run in linear runtime complexity. Could you implement it
* using only constant extra space complexity?
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int missingNumber(vector<int>& nums) {

	int sum = nums.size() * (nums.size() + 1)/2;

	for (auto i : nums)
		sum -= i;

	return sum;

}
int main()
{
	vector<int> nums = { 9,6,4,2,3,5,7,0,1 };
	int ans = 8;
	int ret = missingNumber(nums);
	assert(ret == ans);
	return 0;
}
