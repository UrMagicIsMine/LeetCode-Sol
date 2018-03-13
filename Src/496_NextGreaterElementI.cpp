/* You are given two arrays (without duplicates) nums1 and nums2 where nums1’s
* elements are subset of nums2. Find all the next greater numbers for nums1's
* elements in the corresponding places of nums2.
*
* The Next Greater Number of a number x in nums1 is the first greater number to
* its right in nums2. If it does not exist, output -1 for this number.
*
* Example 1:
*   Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
*   Output: [-1,3,-1]
*   Explanation:
*     For number 4 in the first array, you cannot find the next greater number
*      for it in the second array, so output -1.
*     For number 1 in the first array, the next greater number for it in the
*      second array is 3.
*     For number 2 in the first array, there is no next greater number for it in
*      the second array, so output -1.
* Example 2:
*   Input: nums1 = [2,4], nums2 = [1,2,3,4].
*   Output: [3,-1]
*   Explanation:
*     For number 2 in the first array, the next greater number for it in the
*      second array is 3.
*     For number 4 in the first array, there is no next greater number for it in
*      the second array, so output -1.
*/

#include <stack>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

  /* use hash map for index, and to save the next larger element*/
	unordered_map<int, int> hash;
	for (auto it = findNums.begin(); it != findNums.end(); it++)
		hash[*it] = -1;

  /* use stack to get the next larger element*/
	stack<int> numsStack;
	for (int i = 0; i <nums.size(); i++) {
		while (!numsStack.empty() && nums[i] > numsStack.top()) {
			hash[numsStack.top()] = nums[i];
			numsStack.pop();
		}
		if (hash.find(nums[i]) != hash.end()) {
			numsStack.push(nums[i]);
		}
	}

  /* get the results*/
	int N = findNums.size();
	vector<int> resl(N, -1);
	for (int i = 0; i < N; i++)
		resl[i] = hash[findNums[i]];
	return resl;
  
}
int main()
{
	vector<int> findNums = {2,4};
	vector<int> nums = { 1,2,3,4 };
	vector<int> ans = { 3,-1 };
	auto ret1 = nextGreaterElement(findNums, nums);
	assert(ret1 == ans);
	return 0;
}
