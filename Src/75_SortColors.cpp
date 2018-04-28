/* Given an array with n objects colored red, white or blue, sort them in-place
so that objects of the same color are adjacent, with the colors in the order red,
white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and
blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/
#include <vector>
#include <cassert>
using namespace std;

// two pass solution;
void sortColors_Sln1(vector<int>& nums) {
	vector<int> cnt(3, 0);
	for (int i = 0; i < nums.size(); i++)
		cnt[nums[i]]++;
	int colors = 0;
	for (int i = 0; i < nums.size(); i++) {
		// use while here;
		while (cnt[colors] == 0)
			colors++;

		cnt[colors]--;
		nums[i] = colors;
	}
	return;
}

void sortColors_Sln2(vector<int>& nums) {
	int len = nums.size();
	if (len <= 1)
		return;
	int idx0 = 0, idx2 = len - 1;
	for (int i = 0; i <= idx2; i++) {
		if (nums[i] == 0)
			swap(nums[idx0++], nums[i]);
		if (nums[i] == 2)
			swap(nums[i--], nums[idx2--]);
	}
	return;
}

int main()
{
	vector<int> nums1 = { 2,0,2,1,1,0 };
	vector<int> ans1 = { 0,0,1,1,2,2 };
	sortColors_Sln1(nums1);
	assert(nums1 == ans1);
	vector<int> nums2 = { 2,1,0,0,2,1,1,0 };
	vector<int> ans2 = { 0,0,0,1,1,1,2,2 };
	sortColors_Sln2(nums2);
	assert(nums2 == ans2);
	return 0;
}
