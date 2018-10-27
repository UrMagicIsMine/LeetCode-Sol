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

int missingNumber_Sln1(vector<int>& nums) {

	int sum = nums.size() * (nums.size() + 1)/2;

	for (auto i : nums)
		sum -= i;

	return sum;

}

int missingNumber_Sln2(vector<int>& nums) {

		int ret = 0;
		for(int i = 0; i < nums.size(); i++){
				ret ^= i;
				ret ^= nums[i];
		}
		ret ^= nums.size();
		return ret;

}

int main()
{
	vector<int> nums = { 9,6,4,2,3,5,7,0,1 };
	int ans = 8;
	int ret1 = missingNumber_Sln1(nums);
	assert(ret1 == ans);
	int ret2 = missingNumber_Sln2(nums);
	assert(ret2 == ans);
	return 0;
}
