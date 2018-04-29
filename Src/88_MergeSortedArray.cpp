/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to
m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
#include <vector>
#include <cassert>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	for (int i = m + n - 1; n > 0 && i >= 0; i--) {
		if (m > 0 && nums1[m - 1] >= nums2[n - 1]) {
			nums1[i] = nums1[m - 1];
			m--;
		}
		else {
			nums1[i] = nums2[n - 1];
			n--;
		}
	}
	return;
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	int i = m + n - 1;
	m = m - 1, n = n - 1;
	while (m >= 0 && n >= 0) {
		if (nums1[m]>nums2[n])
			nums1[i--] = nums1[m--];
		else
			nums1[i--] = nums2[n--];
	}
	while (n >= 0)
		nums1[i--] = nums2[n--];
	return;
}

int main()
{
	vector<int> nums1 = { 0,0,3,0,0,0,0,0,0 };
	int m = 3, n = 6;
	vector<int> nums2 = { -1,1,1,1,2,3 };
	merge2(nums1, m, nums2, n);
	vector<int> ans = { -1,0,0,1,1,1,2,3,3 };
	assert(nums1 == ans);
	return 0;
}