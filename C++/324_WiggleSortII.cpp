/* Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/

#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

/* Sort and then write the smaller half of the numbers on the even indexes and
* the larger half of the numbers on the odd indexes, both from the back. Example:
*
* Small half:    4 . 3 . 2 . 1 . 0 .
* Large half:    . 9 . 8 . 7 . 6 . 5
* ----------------------------------
* Together:      4 9 3 8 2 7 1 6 0 5
* So write nums from the back, interweaving sorted[0..4] (indexed by j) and s
* orted[5..9] (indexed by k).
*/

void wiggleSort(vector<int>& nums) {
	int N = nums.size();
	if (N < 2)
		return;
	vector<int> sortedNums(nums);
	sort(sortedNums.begin(), sortedNums.end());

	int mid = (N - 1) / 2 + 1;
	int i = 0;
	int j = mid;
	for (int idx = N - 1; idx >= 0; idx--) {
		/* odd idx, must be larger number, even idx, must be smaller number */
		nums[idx] = sortedNums[idx & 1 ? j++ : i++];
	}

	return;
}

int main()
{
	vector<int> nums = { 2,3,4,1,6,7,5,9,8,0 };
	vector<int> ans = { 4,9,3,8,2,7,1,6,0,5 };
	wiggleSort(nums);
	assert(nums == ans);
	return 0;

}
