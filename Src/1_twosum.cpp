/* Given an array of integers, return indices of the two numbers such that they
* add up to a specific target.
*
* You may assume that each input would have exactly one solution, and you may
* not use the same element twice.
*
* Example:
*
* Given nums = [2, 7, 11, 15], target = 9,
*
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

/*While we iterate and inserting elements into the table, we also look back to
* check if current element's complement already exists in the table. If it exists,
* we have found a solution and return immediately.
* run-time O(N), memory O(N)
*/

vector<int> twoSum_HT(vector<int>& nums, int target) {

	unordered_map<int, int> hashtbl;
	for (int i = 0; i < nums.size(); i++) {
		auto it = hashtbl.find(target - nums[i]);
		if (it != hashtbl.end())
			return vector<int>{it->second, i};
		else
			hashtbl.emplace(nums[i], i);
	}
	return vector<int>{0, 0};
}

/* sort the original array, use two pointer to search for the sum target,
* run-time O(NlogN), memory O(N)
*/

vector<int> twoSum_ST(vector<int>& nums, int target) {

	vector<int> num_copy(nums.size());
	copy(nums.begin(), nums.end(), num_copy.begin());
	sort(num_copy.begin(), num_copy.end());
	int low = 0, high = (int)nums.size() - 1;
	vector<int> targetnum(2);
	while (low < high) {
		if (num_copy[low] + num_copy[high] == target) {
			targetnum[0] = num_copy[low];
			targetnum[1] = num_copy[high];
			break;
		}
		else if (num_copy[low] + num_copy[high] < target)
			low++;
		else
			high--;
	}

	vector<int> resl;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == targetnum[0] || nums[i] == targetnum[1])
			resl.push_back(i);
	}
	return resl;
}

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> ans = { 0,1 };
	vector<int> ret1 = twoSum_HT(nums, target);
	assert(ret1 == ans);
	vector<int> ret2 = twoSum_ST(nums, target);
	assert(ret2 == ans);
	return 0;
}
