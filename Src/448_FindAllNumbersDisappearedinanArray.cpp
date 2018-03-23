/* Given an array of integers where 1 <= a[i] <= n (n = size of array), some
* elements appear twice and others appear once.
*
* Find all the elements of [1, n] inclusive that do not appear in this array.
*
* Could you do it without extra space and in O(n) runtime? You may assume the
* returned list does not count as extra space.
*
* Example:
*
* Input:
* [4,3,2,7,8,2,3,1]
*
* Output:
* [5,6]
*/
#include<vector>
#include <cassert>
using namespace std;

/* O(N) solution, no extra space */

vector<int> findDisappearedNumbers_Sln1(vector<int>& nums) {

	for (int i = 0; i < nums.size(); i++) {
		int nextNum = nums[i];
		while (nums[nextNum - 1] != nextNum) {
			int tmp = nums[nextNum - 1];
			nums[nextNum - 1] = nextNum;
			nextNum = tmp;
		}
	}
	std::vector<int> resl;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != i + 1) {
			resl.push_back(i + 1);
		}
	}
	return resl;
}

vector<int> findDisappearedNumbers_Sln2(vector<int>& nums) {

	for (int i = 0; i<nums.size(); i++) {
		int & tmp = nums[abs(nums[i]) - 1];
		if (tmp>0)
			tmp = -tmp;
	}

	vector<int> resl;
	for (int i = 0; i<nums.size(); i++) {
		if (nums[i] > 0)
			resl.push_back(i + 1);
	}
	return resl;
}

vector<int> findDisappearedNumbers_Sln3(vector<int>& nums) {
	vector<bool> numflags(nums.size(), false);
	for (int i = 0; i<nums.size(); i++)
		numflags[nums[i] - 1] = true;

	vector<int> resl;
	for (int i = 0; i<numflags.size(); i++)
		if (numflags[i] == false)
			resl.push_back(i + 1);

	return resl;

}

int main()
{
	vector<int> nums1 = { 4,3,2,7,8,2,3,1 };
	vector<int> ans = { 5,6 };
	vector<int> ret1 = findDisappearedNumbers_Sln1(nums1);
	assert(ret1 == ans);
	vector<int> nums2 = { 4,3,2,7,8,2,3,1 };
	vector<int> ret2 = findDisappearedNumbers_Sln2(nums2);
	assert(ret2 == ans);
	vector<int> nums3 = { 4,3,2,7,8,2,3,1 };
	vector<int> ret3 = findDisappearedNumbers_Sln3(nums3);
	assert(ret3 == ans);
	return 0;
}
