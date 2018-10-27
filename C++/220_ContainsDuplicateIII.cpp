/* Given an array of n positive integers and a positive integer s, find the
* minimal length of a contiguous subarray of which the sum >= s. If there isn't
* one, return 0 instead.
*
* For example, given the array [2,3,1,2,4,3] and s = 7,
* the subarray [4,3] has the minimal length under the problem constraint.
*/

#include <vector>
#include <set>
#include <cassert>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

	set<long long> numset;
	for (int i = 0; i < nums.size(); i++) {
		if (i > k)
			numset.erase(nums[i - k - 1]);

		long long num_i = nums[i];
		long long num_t = t;
		long long bound = num_i - num_t;
		auto pos = numset.lower_bound(bound);
		if (pos != numset.end() && *pos - num_i <= t)
			return true;
		numset.insert(nums[i]);
	}
	return false;
}

int main()
{
	vector<int> nums = { 2,7,3,6,3 };
	int k = 2, t = 3;
	bool ans = true;
	bool ret = containsNearbyAlmostDuplicate(nums, k, t);
	assert(ret == ans);
	return 0;
}
