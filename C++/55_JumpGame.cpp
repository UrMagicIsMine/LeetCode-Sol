/* Given an array of non-negative integers, you are initially positioned at the
* first index of the array.
*
* Each element in the array represents your maximum jump length at that position.
*
* Determine if you are able to reach the last index.
*
* Example 1:
*
* Input: [2,3,1,1,4]
* Output: true
* Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
* Example 2:
*
* Input: [3,2,1,0,4]
* Output: false
* Explanation: You will always arrive at index 3 no matter what. Its maximum
*            jump length is 0, which makes it impossible to reach the last index.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* use two pointers to track the ranges it can make:
1) keep update of fast pointer for the next step it can make;
2) if fast is larger than the previous step, slow can be updated to fast + 1, because
all the pointers previously have been visited;
3) if fast is larger then N-1, then it means it can reach to the end, return true;
4) after N visited, not return true, then it must stake somewhere, so return false;

run-time O(N^2), can be optimized;
 */

bool canJump_Sln1(vector<int>& nums) {

	int N = nums.size();
	int fast = 0, slow = 0;
	for (int i = 0; i < N; i++) {
		int l = slow, r = fast;
		for (int cur = l; cur <= r; cur++) {
			fast = max(nums[cur] + cur, fast);
		}
		if (fast > r)
			slow = r + 1;
		if (fast >= N - 1)
			return true;
	}
	return false;
}

/* if fast >= i, means fast is reachable, update it value greedy
 */

bool canJump_Sln2(vector<int>& nums) {

	int N = nums.size();
	int fast = 0, slow = 0;
	for (int i = 0; i < N; i++) {
		if (fast >= i) {
			fast = max(i + nums[i], fast);
		}
	}
	return fast >= N - 1;
}

int main()
{
	vector<int> nums = { 2,3,1,1,4 };
	bool ans = true;
	bool ret1 = canJump_Sln1(nums);
	assert(ret1 == ans);

	bool ret2 = canJump_Sln1(nums);
	assert(ret2 == ans);
	return 0;
}
