/* Remember the story of Little Match Girl? By now, you know exactly what matchsticks
* the little match girl has, please find out a way you can make one square by using
* up all those matchsticks. You should not break any stick, but you can link them
* up, and each matchstick must be used exactly one time.
*
* Your input will be several matchsticks the girl has, represented with their stick
* length. Your output will either be true or false, to represent whether you could
* make one square using all the matchsticks the little match girl has.
*
* Example 1:
* Input: [1,1,2,2,2]
* Output: true
*
* Explanation: You can form a square with length 2, one side of the square came
* two sticks with length 1.
* Example 2:
* Input: [3,3,3,3,4]
* Output: false
*
* Explanation: You cannot find a way to form a square with all the matchsticks.
* Note:
* The length sum of the given matchsticks is in the range of 0 to 10^9.
* The length of the given matchstick array will not exceed 15.
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
using namespace std;

bool makesquare(vector<int>& nums) {
	if (nums.size() < 4)
		return false;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum & 3)
		return false;
	int len = sum >> 2;

	vector<int> sqlLeft(4, len);
	// optimize 2, sort in descending order make it fails rapidly if not satifsied
	sort(nums.begin(), nums.end(), greater<int>());

	return _DFS(nums, 0, sqlLeft);
}

bool _DFS(vector<int>&nums, int pos, vector<int>& sqlLeft) {

	if (pos == nums.size())
		return true;

	for (int iedge = 0; iedge < 4; iedge++) {
		if (nums[pos] <= sqlLeft[iedge]) { // optimize pruning 1

			// optimize pruning 3, no need to try if checked already in previous run
			int j = iedge - 1;
			while (j >= 0) {
				if (sqlLeft[iedge] == sqlLeft[j])
					break;
				j--;
			}
			if (j >= 0)
				continue;
			sqlLeft[iedge] -= nums[pos];
			bool ret = _DFS(nums, pos + 1, sqlLeft);
			if (ret)
				return true;
			sqlLeft[iedge] += nums[pos];
		}
	}
	return false;
}

int main()
{
	vector<int> nums = { 3, 3, 3, 3, 4 };
	bool ret = makesquare(nums);
	bool ans = false;
	assert(ret == ans);
	return 0;
}
