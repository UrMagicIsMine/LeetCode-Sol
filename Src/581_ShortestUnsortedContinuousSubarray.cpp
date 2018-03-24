/* Given an integer array, you need to find one continuous subarray that if you
* only sort this subarray in ascending order, then the whole array will be sorted
* in ascending order, too.
*
* You need to find the shortest such subarray and output its length.
*
* Example 1:
* Input: [2, 6, 4, 8, 10, 9, 15]
* Output: 5
* Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the
* whole array sorted in ascending order.
* Note:
* Then length of the input array is in range [1, 10,000].
* The input array may contain duplicates, so ascending order here means <=.
*/
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

/* Solution 1: sorted and do comparison */

int findUnsortedSubarray_Sln1(vector<int>& nums) {

	int N = nums.size();

	vector<int> sorted(nums.begin(), nums.end());
	sort(sorted.begin(), sorted.end());

	int beg = 0, end = N - 1;

	while (beg < N && nums[beg] == sorted[beg])
		beg++;
	while (end >= 0 && nums[end] == sorted[end])
		end--;

	if (beg > end)
		return 0;
	else
		return end - beg + 1;

}

int main()
{
	vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
	int ret = findUnsortedSubarray_Sln1(nums);
	int ans = 5;
	assert(ret == ans);
	return 0;
}
