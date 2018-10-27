/* Given a collection of numbers that might contain duplicates, return all
* possible unique permutations.
*
* Example:
*
* Input: [1,1,2]
* Output:
* [
*   [1,1,2],
*   [1,2,1],
*   [2,1,1]
* ]
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

bool _nextPermute(vector<int>& nums) {

	int N = nums.size();
	int i = N - 2;
	while (i >= 0 && nums[i] >= nums[i + 1])
		i--;

	if (i == -1) {
		reverse(nums.begin(), nums.end());
		return false;
	}

	// find the first that is larger than nums[i]
	int k = N - 1;
	while (nums[k] <= nums[i])
		k--;

	swap(nums[k], nums[i]);
	reverse(nums.begin() + i + 1, nums.end());
	return true;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> resl;
	int N = nums.size();
	if (N <= 1) {
		resl.push_back(nums);
		return resl;
	}

	sort(nums.begin(), nums.end());
	do {
		resl.push_back(nums);
	} while (_nextPermute(nums));
	return resl;
}

int main()
{
	vector<int> nums = { 1,1,2 };
	vector<vector<int>> ans = { {1,1,2},{1,2,1},{2,1,1} };
	vector<vector<int>> ret = permuteUnique(nums);
	assert(ret == ans);
	return 0;
}
