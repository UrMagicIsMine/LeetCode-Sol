/* Given an array of size n, find the majority element. The majority
* element is the element that appears more than [ n/2 ] times.
*
* You may assume that the array is non-empty and the majority element
* always exist in the array.
*/

#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

/* hash table solution, run-time O(N), memory O(N) */
int majorityElement_hash(vector<int>& nums) {
	unordered_map<int, int> hash;

	int N = nums.size();
	for (int i = 0; i < N; i++)
	{
		int & tmp = hash[nums[i]];
		tmp++;
		if (tmp > N / 2)
			return nums[i];
	}
	assert(0);
}

/* sorting algorithms: the majority element must be in the mid [N/2] location if
* the input vectors are sorted at least to the [N/2]-th element, or we can use the
* nth_element algorithm to get the [N/2]-th element without fully sorting the array
*/
/* run-time O(NlogN), memory in-place */
int majorityElement_sort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	return nums[nums.size() / 2];
}

int majorityElement_psort(vector<int>& nums) {
	partial_sort(nums.begin(), nums.begin() + nums.size() / 2 + 1, nums.end());
	return nums[nums.size() / 2];
}

int majorityElement_nthelem(vector<int>& nums) {
	nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
	return nums[nums.size() / 2];
}

/* Moore Voting Algorithm : A brilliant and easy-to-implement algorithm! */
/* run-time O(N), memory in-place */
int majorityElement_MV(vector<int>& nums) {

	int major, count = 0, N = nums.size();
	for (int i = 0; i < N; i++)
	{
		if (!count) {
			major = nums[i];
			count = 1;
		}
		else
			count += (major == nums[i] ? 1 : -1);
	}
	return major;
}

/* bit manipulation algorithms */

int majorityElement_BM(vector<int>& nums) {
	int major = 0, n = nums.size();
	for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
		int bitCounts = 0;
		for (int j = 0; j < n; j++) {
			if (nums[j] & mask) bitCounts++;
			if (bitCounts > n / 2) {
				major |= mask;
				break;
			}
		}
	}
	return major;
}

int main()
{
	vector<int> nums = {1,2,2,22,2,2,2,2,3,4,5,6,7,2,22,3,2,2,2,2};
	int ret_hash = majorityElement_hash(nums);
	assert(ret_hash == 2);

	int ret_sort = majorityElement_sort(nums);
	assert(ret_sort == 2);
	int ret_psort = majorityElement_psort(nums);
	assert(ret_psort == 2);
	int ret_nthelem = majorityElement_nthelem(nums);
	assert(ret_nthelem == 2);

	int ret_mv = majorityElement_MV(nums);
	assert(ret_mv == 2);

	int ret_bm = majorityElement_BM(nums);
	assert(ret_bm == 2);
	return 0;
}
