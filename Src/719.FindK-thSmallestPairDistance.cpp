/*
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/

#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;


/*
Binary search algorithm with value range, see solution 378 for reference
key idea is to find the count that is <= mid
*/

int smallestDistancePair(vector<int>& nums, int k) {

	sort(nums.begin(), nums.end());
	int N = nums.size();
	int lo = 0;
	int hi = nums[N - 1] - nums[0];

	while (lo < hi) {

		int mid = (lo + hi) / 2;
		int cnt = 0, left = 0, right = 1;
		while (right < N) {
			if (nums[right] - nums[left] > mid)
				left++;
			else {
				cnt += right - left;
				right++;
			}
		}
		if (cnt < k) lo = mid + 1;
		else hi = mid;
	}

	return lo;

}


int main()
{
	vector<int> nums = { 1,3,1 };
	int k = 0, ans = 0;
	int ret = smallestDistancePair(nums, k);
	assert(ret = ans);
	return 0;
}
