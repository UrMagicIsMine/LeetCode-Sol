/* Rotate an array of n elements to the right by k steps.
*
* For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7]
* is rotated to [5,6,7,1,2,3,4].
*
* Note:
* Try to come up as many solutions as you can, there are at least
* 3 different ways to solve this problem.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* Solution 1: copy and swap, run-time O(N) and space O(N) */

void rotate_Sol1(vector<int>& nums, int k) {

	int N = nums.size();
	k = k % N;
	assert(N >= k);
	vector<int> resl(N, 0);
	int j = 0;
	for (int i = N - k; i<N; i++)
		resl[j++] = nums[i];

	for (int i = 0; i < N - k; i++)
		resl[j++] = nums[i];

	nums.swap(resl);
	return;
}

/* Solution 2: three reverse operation, run-time O(N) and space O(1) */

void rotate_Sol2(vector<int>& nums, int k) {

	int N = nums.size();
	k = k % N;
	assert(N >= k);

	/* illustrate if k = 4 */
	/*+---+---+---+---+---+---+---+
	| 1 | 2 | 3 | 4 | 5 | 6 | 7 |
	+---+---+---+---+---+---+---+*/
	/* reverse the first N-K element */
	reverse(nums.begin(), nums.begin() + N - k);
	/*+---+---+---+---+---+---+---+
	| 3 | 2 | 1 | 4 | 5 | 6 | 7 |
	+---+---+---+---+---+---+---+*/
  /* reverse the last K element */
	reverse(nums.begin() + N - k, nums.end());
	/*+---+---+---+---+---+---+---+
	| 3 | 2 | 1 | 7 | 6 | 5 | 4 |
	+---+---+---+---+---+---+---+*/
  /* reverse the whole array */
	reverse(nums.begin(), nums.end());
	/*+---+---+---+---+---+---+---+
	| 4 | 5 | 6 | 7 | 1 | 2 | 3 |
	+---+---+---+---+---+---+---+*/
}

int main()
{
	vector<int> nums1 = { 1,2,3,4,5,6,7 };
	vector<int> nums2 = { 1,2,3,4,5,6,7 };
	vector<int> resl = { 3,4,5,6,7,1,2 };

	rotate_Sol1(nums1, 5);
	assert(nums1 == resl);

	rotate_Sol2(nums2, 5);
	assert(nums2 == resl);
	return 0;
}
