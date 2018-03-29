/* Given an array of integers and an integer k, you need to find the total number
* of continuous subarrays whose sum equals to k.
* 
* Example 1:
* Input:nums = [1,1,1], k = 2
* Output: 2
* Note:
* The length of the array is in range [1, 20,000].
* The range of numbers in the array is [-1000, 1000] and the range of the integer
* k is [-1e7, 1e7].
*/

#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

/*
Time complexity : O(n^2). We need to consider every subarray possible.
Space complexity : O(n).
*/

int subarraySum_Sln1(vector<int>& nums, int k) {
	int ret = 0;
	int N = nums.size();
	vector<int> sum(N + 1, 0);
	for (int i = 0; i < N; i++)
		sum[i + 1] = sum[i] + nums[i];

	for (int bg = 0; bg < N; bg++)
		for (int ed = bg; ed < N; ed++)
			if (sum[ed + 1] - sum[bg] == k)
				ret++;

	return ret;
}

/*
Time complexity : O(n^2). We need to consider every subarray possible.
Space complexity : O(1). Constant space is used.
*/

int subarraySum_Sln2(vector<int>& nums, int k) {
	int ret = 0;
	int N = nums.size();

	for (int bg = 0; bg < N; bg++) {
		int sum = 0;
		for (int ed = bg; ed < N; ed++) {
			sum = sum + nums[ed];
			if (sum == k)
				ret++;
		}
	}

	return ret;
}

int subarraySum_Sln3(vector<int>& nums, int k) {
	int ret = 0;
	int N = nums.size();

	unordered_map<int, int> hashtbl;
	hashtbl[0] = 1;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += nums[i];

		if (hashtbl.find(sum - k) != hashtbl.end())
			ret += hashtbl[sum - k];
		hashtbl[sum]++;
	}

	return ret;
}

int main()
{
	vector<int> nums = { 1,1,1 };
	int k = 2;
	int ans = 2;
	int ret1 = subarraySum_Sln1(nums, 2);
	assert(ret1 == ans);

	int ret2 = subarraySum_Sln2(nums, 2);
	assert(ret2 == ans);

	int ret3 = subarraySum_Sln3(nums, 2);
	assert(ret3 == ans);
	return 0;
}
