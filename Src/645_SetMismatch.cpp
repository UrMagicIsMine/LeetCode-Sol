/* The set S originally contains numbers from 1 to n. But unfortunately, due to
* the data error, one of the numbers in the set got duplicated to another number
* in the set, which results in repetition of one number and loss of another number.
*
* Given an array nums representing the data status of this set after the error.
* Your task is to firstly find the number occurs twice and then find the number
* that is missing. Return them in the form of an array.
*
* Example 1:
* Input: nums = [1,2,2,4]
* Output: [2,3]
* Note:
* The given array size will in the range [2, 10000].
* The given array's numbers won't have any order.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {

	vector<int> resl(2, 0);
	for (int i = 0; i< nums.size(); i++) {
		if (nums[abs(nums[i]) - 1] < 0)
			resl[0] = abs(nums[i]);
		else
			nums[abs(nums[i]) - 1] *= -1;
	}

	for (int i = 0; i< nums.size(); i++) {
		if (nums[i] > 0)
			resl[1] = i + 1;
	}

	return resl;
}

int main()
{
	vector<int> nums = { 1,2,2,4 };
	vector<int> ans = {2,3};
	vector<int> ret = findErrorNums(nums);
	assert(ret == ans);
	return 0;
}
