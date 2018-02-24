/* Suppose an array sorted in ascending order is rotated
* at some pivot unknown to you beforehand.
*
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*
* Find the minimum element.
*
* You may assume no duplicate exists in the array.
*/

#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int findMin_Sol1(vector<int>& nums) {

	int N = nums.size();
	if (N < 1)
		return INT_MIN;

	/* keep a minum value during serach */
	int minValue = nums[0];
	int beg = 0;
	int end = N - 1;

	while (beg <= end) {

		int mid = (beg + end) / 2;
		if (nums[mid] < minValue)
			minValue = nums[mid];
		/* if mid value is large then the right value,
		* then the min value must be on the right, else if
		* may be the mid or on the left;
		* because mid is already checked, we can just search left;
		*/
		if (nums[mid] > nums[end])
			beg = mid + 1;
		else
			end = mid - 1;
	}
	return minValue;
}

int findMin_Sol2(vector<int>& nums) {

	int N = nums.size();
	if (N < 1)
		return INT_MIN;

	int beg = 0;
	int end = N - 1;

	while (beg < end) {

		int mid = (beg + end) / 2;
		/* if mid value is large then the right value,
		* then the min value must be on the right, else if
		* may be the mid or on the left;
		*/
		if (nums[mid] > nums[end])
			beg = mid + 1;
		else
			end = mid;
	}
	return min(nums[beg], nums[end]);
}

int main()
{
	vector<int> nums = { 3,4,5,6,7,1,2,3 };
	int ret1 = findMin_Sol1(nums);
	assert(ret1 == 1);

	int ret2 = findMin_Sol2(nums);
	assert(ret1 == 1);
	return 0;
}
