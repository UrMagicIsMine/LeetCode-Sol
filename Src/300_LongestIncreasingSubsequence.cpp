/* Given an unsorted array of integers, find the length of longest increasing
* subsequence.
*
* For example,
* Given [10, 9, 2, 5, 3, 7, 101, 18],
* The longest increasing subsequence is [2, 3, 7, 101], therefore the length is
* 4. Note that there may be more than one LIS combination, it is only necessary
* for you to return the length.
*
* Your algorithm should run in O(n2) complexity.
*
* Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Time complexity : O(n^2).
Space complexity : O(n).
*/

int lengthOfLIS_Sln1(vector<int>& nums) {

	int N = nums.size();
	if (N < 1)
		return 0;

	vector<int> dp(N, 1);

	for (int i = 0; i < N; i++) {
		int max_dp = 0;
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j] && dp[j] > max_dp)
				max_dp = dp[j];
		}
		dp[i] = max_dp + 1;
	}

	return *max_element(dp.begin(), dp.end());

}

/*
Time complexity : O(nlogn).
Space complexity : O(n).
*/

int lengthOfLIS_Sln2(vector<int>& nums) {

	int N = nums.size();

	vector<int> lis_array;

	for (int i = 0; i < N; i++) {

		auto it = lower_bound(lis_array.begin(), lis_array.end(), nums[i]);
		if (it == lis_array.end())
			lis_array.push_back(nums[i]);
		else
			*it = nums[i];
	}

	return lis_array.size();

}

/*
Time complexity : O(nlogn).
Space complexity : O(n).
*/

int _getLargerNum(vector<int>& nums, int val) {

	int N = nums.size();
	if (N == 0)
		return -1;
	if (val < nums[0])
		return 0;
	if (val > nums[N - 1])
		return -1;

	int low = 0, high = N - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (nums[mid] == val)
			return mid;
		if (nums[mid] < val && val <= nums[mid + 1])
			return mid + 1;
		else if (val < nums[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

}

int lengthOfLIS_Sln3(vector<int>& nums) {

	int N = nums.size();

	vector<int> lis_array;

	for (int i = 0; i < N; i++) {

		int it = _getLargerNum(lis_array, nums[i]);
		if (it == -1)
			lis_array.push_back(nums[i]);
		else
			lis_array[it] = nums[i];
	}

	return lis_array.size();

}

int main()
{
	vector<int> nums = { 1,3,6,7,9,4,10,5,6 };
	int ans = 6;
	int ret1 = lengthOfLIS_Sln1(nums);
	assert(ret1 == ans);

	int ret2 = lengthOfLIS_Sln2(nums);
	assert(ret2 == ans);

	int ret3 = lengthOfLIS_Sln3(nums);
	assert(ret3 == ans);

	return 0;
}
