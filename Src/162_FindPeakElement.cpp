/* A peak element is an element that is greater than its neighbors.
*
* Given an input array where num[i] != num[i+1], find a peak element
* and return its index. The array may contain multiple peaks, in that
* case return the index to any one of the peaks is fine. You may imagine
* that num[-1] = num[n] = -oo.
*
* For example, in array [1, 2, 3, 1], 3 is a peak element and your
* function should return the index number 2.
*
* Note: Your solution should be in logarithmic complexity.
*/

#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

/******************************************************************************/
/* elegant solution: iteratively march to the peak  */

int findPeakElement(vector<int>& nums) {

	int N = nums.size();
	int beg = 0;
	int end = N - 1;

	int mid;
	while (beg<end) {
		mid = (beg + end) / 2;
    /* mid1 won't overflow in any case */
		int mid1 = mid + 1;
    /* awalys march to the peak direction */
		if (nums[mid] < nums[mid1])
			beg = mid1;
		else
			end = mid;
	}
	return beg;
}
int main()
{
	vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
	int ret = findPeakElement(nums);
  assert(ret == 8);
	return 0;
}
