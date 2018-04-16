/* Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
*
* Your algorithm's runtime complexity must be in the order of O(log n).
*
* If the target is not found in the array, return [-1, -1].
*
* Example 1:
*
* Input: nums = [5,7,7,8,8,10], target = 8
* Output: [3,4]
* Example 2:
*
* Input: nums = [5,7,7,8,8,10], target = 6
* Output: [-1,-1]
*/

#include <vector>
#include <cassert>
using namespace std;

/* Binary Search with naive boundary detection */

vector<int> searchRange_Sln1(vector<int>& nums, int target) {

	int N = nums.size();
	vector<int> ret(2, -1);
	int low = 0, high = N - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] < target)
			low = mid + 1;
		else if (nums[mid] > target)
			high = mid - 1;
		else {
			int i = mid, j = mid;
			while (i > 0 && nums[i] == nums[i - 1])
				i--;
			ret[0] = i;
			while (j < N - 1 && nums[j] == nums[j + 1])
				j++;
			ret[1] = j;
			break;
		}
	}
	return ret;
}

/*
If A[mid] < target, then the range must begins on the right of mid (hence l = mid+1 for the next iteration)
If A[mid] > target, it means the range must begins on the left of mid (r = mid-1)
If A[mid] = target, then the range must begins on the left of or at mid (r= mid)

Since we would move the search range to the same side for case 2 and 3, we might
as well merge them as one single case so that less code is needed:

    If A[mid] >= target, r = mid;

No matter what the sequence originally is, as we narrow down the search range,
eventually we will be at a situation where there are only two elements in the
search range, unless the size of nums are 1.

Suppose our target is 5, then we have only 6 possible cases:

case 1: [6 7] (target < A[l] < A[r])    return condition l, r = l;
case 2: [5 7] (target = A[l] < A[r])	return condition l, r = l;
case 3: [4 6] (A[l] < target < A[r])	return condition l, r = r;
case 4: [5 5] (A[l] = target = A[r])	return condition l, r = l;
case 5: [4 5] (A[l] < target = A[r])	return condition l, r = r;
case 6: [3 4] (A[l] < A[r] < target)	return condition l, r = r;

we can determine if the target if found through two conditions:
 1) l is in range,
 2) nums[l] == target;

if found, the l will always be the left boundary of target;

For the right boundary, we can use the left rountine to search target+1,
the return value should be
1) if target+1 found, the left boundary of (target+1);
2) if not found, (the right boundary of target) + 1

*/

int left(vector<int>& nums, int target) {

	int l = 0, r = nums.size(), mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (nums[mid] < target)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

vector<int> searchRange_Sln2(vector<int>& nums, int target) {

	int N = nums.size();
	vector<int> ret(2, -1);
	int l = left(nums, target);
	if (l < 0 || l >= nums.size() || nums[l] != target)
		return ret;
	ret[0] = l;
	ret[1] = left(nums, target + 1) - 1;
	return ret;
}

vector<int> searchRange_Sln3(vector<int>& nums, int target) {

	int N = nums.size();
	vector<int> ret(2, -1);
	int l = 0, r = nums.size(), mid;
	// Search for the left one
	while (l < r) {
		mid = (l + r) / 2;
		if (nums[mid] < target)
			l = mid + 1;
		else
			r = mid;
	}
	if (l < 0 || l >= nums.size() || nums[l] != target)
		return ret;
	ret[0] = l;

	// Search for the right one
	r = nums.size() - 1; // We don't have to set i to 0 the second time.
	while (l < r) {
		mid = (l + r) / 2 + 1; // Make mid biased to the right
		if (nums[mid] > target)
			r = mid - 1;
		else
			l = mid;

	}
	ret[1] = r;
	return ret;
}

int main()
{
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> ans = { 3,4 };
	int target = 8;
	vector<int> ret1 = searchRange_Sln1(nums, target);
	assert(ret1 == ans);
	vector<int> ret2 = searchRange_Sln2(nums, target);
	assert(ret2 == ans);
	vector<int> ret3 = searchRange_Sln3(nums, target);
	assert(ret3 == ans);
	return 0;
}
