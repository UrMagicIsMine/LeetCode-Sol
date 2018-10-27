/* Given a non-empty array containing only positive integers, find if the array
* can be partitioned into two subsets such that the sum of elements in both
* subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <cassert>
using namespace std;

/* DP solution
Time complexity : O(n^2).
Space complexity : O(n).
*/

bool canPartition_Sln1(vector<int>& nums) {
	int sum = accumulate(nums.begin(), nums.end(), int(0));
	if (sum & 1)
		return false;
	int target = sum >> 1;

	vector<int> sumDP(target + 1, 0);
	sumDP[0] = 1;
	vector<int> preSumDP(sumDP);
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j <= target - nums[i]; j++)
			if (preSumDP[j])
				sumDP[j + nums[i]] = 1;

		preSumDP = sumDP;
	}
	return sumDP[target];
}

bool canPartition_Sln2(vector<int>& nums) {
	int sum = accumulate(nums.begin(), nums.end(), int(0));
	if (sum & 1)
		return false;
	int target = sum >> 1;

	const int MAX_SUM_HALF = 200 * 100 / 2;
	bitset<MAX_SUM_HALF> bits;
	bits[0] = 1;

	for (auto i : nums)
		bits |= bits << i;

	return bits[target];
}

int main()
{
	vector<int> nums = { 1,2,5 };
	bool ans = false;
	bool ret1 = canPartition_Sln1(nums);
	assert(ret1 == ans);

	bool ret2 = canPartition_Sln2(nums);
	assert(ret2 == ans);
	return 0;
}
