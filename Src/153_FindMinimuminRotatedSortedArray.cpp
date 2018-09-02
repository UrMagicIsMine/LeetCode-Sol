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

int findMin(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)
		return INT_MIN;

	int low = 0, high = n - 1;
	int mid;
	while (low < high) {
		mid = low + (high - low) / 2;
		/* if mid value is large then the right value,
		* then the min value must be on the right, else if
		* may be the mid or on the left;
		*/
		if (nums[mid] > nums[high]) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return nums[low];
}


int main()
{
	vector<int> nums = { 3,4,5,6,7,1,2,3 };
	int ret1 = findMin(nums);
	assert(ret1 == 1);
	return 0;
}
