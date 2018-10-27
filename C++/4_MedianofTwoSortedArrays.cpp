/* There are two sorted arrays nums1 and nums2 of size m and n respectively.
*
* Find the median of the two sorted arrays. The overall run time complexity should
* be O(log (m+n)).
*
* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
*
* The median is 2.0
* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
*
* The median is (2 + 3)/2 = 2.5
*/

#include <string>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

double findMedianSortedArrays_ST1(vector<int>& nums1, vector<int>& nums2) {

	int N1 = nums1.size(), N2 = nums2.size(), N = N1 + N2;
	vector<int> nums(N);

	copy(nums1.begin(), nums1.end(), nums.begin());
	copy(nums2.begin(), nums2.end(), nums.begin() + N1);

	sort(nums.begin(), nums.end());

	if (N & 1)
		return nums[N >> 1];
	else
		return (nums[N >> 1] + nums[(N >> 1) - 1]) / 2.0;
}

double findMedianSortedArrays_ST2(vector<int>& nums1, vector<int>& nums2) {

	int N1 = nums1.size(), N2 = nums2.size(), N = N1 + N2;
	vector<int> nums(N);

	for (int i = 0, j = 0, k = 0; k < N; ) {
		if (j == N2 || (i < N1 && nums1[i] < nums2[j]))
			nums[k++] = nums1[i++];
		else
			nums[k++] = nums2[j++];
	}

	if (N & 1)
		return nums[N >> 1];
	else
		return (nums[N >> 1] + nums[(N >> 1) - 1]) / 2.0;
}

int main()
{
	vector<int> nums1 = { 1, 3 }, nums2 = { 2 };
	double ans = 2.0;
	double ret1 = findMedianSortedArrays_ST1(nums1, nums2);
	assert(abs(ret1 - ans) < 1E-12);
	double ret2 = findMedianSortedArrays_ST2(nums1, nums2);
	assert(abs(ret2 - ans) < 1E-12);
	return 0;
}
