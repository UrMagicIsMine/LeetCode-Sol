/* Find the contiguous subarray within an array (containing
* at least one number) which has the largest product.
*
* For example, given the array [2,3,-2,4],
* the contiguous subarray [2,3] has the largest product = 6.
*/

#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {

	int maxP = nums[0];
	/* maxr/minr stores the running max/min product of subarray that
      ends with the current number nums[i] */
	for (int i = 1, maxr = nums[0], minr = nums[0]; i < nums.size(); i++)
	{
		/* if nums[i] is negative, multiple a small number becomes big,
		* multiple a small number becomes big;
		*/
		if (nums[i] < 0)
			swap(maxr, minr);

		/* Update the running max/min product that ends with the
		* current number nums[i];
		*/
		maxr = max(nums[i], maxr*nums[i]);
		minr = min(nums[i], minr*nums[i]);

		/* the newly computed max value is a candidate for global result */
		maxP = max(maxP, maxr);

	}
	return maxP;
}

int main()
{
	vector<int> nums = {1,2,-3,5,-1};
	int ret = maxProduct(nums);
	assert(ret == 30);
	return 0;
}
