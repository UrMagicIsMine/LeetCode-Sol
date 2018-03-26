/* Find the kth largest element in an unsorted array. Note that it is the kth
* largest element in the sorted order, not the kth distinct element.
* For example,
* Given [3,2,1,5,6,4] and k = 2, return 5.
*
* Note:
* You may assume k is always valid, 1 <= k <= array's length.
*
*/

#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

int findKthLargest_ST(vector<int>& nums, int k) {

	auto lambda = [&](int i, int j) {return i>j;};
	sort(nums.begin(), nums.end(), lambda);
	return nums[k - 1];
}

int findKthLargest_HP(vector<int>& nums, int k) {

	priority_queue<int> heap(nums.begin(), nums.end());
	while (--k)
		heap.pop();

	return heap.top();

}

int main()
{
	vector<int> nums = { 3,2,1,5,6,4 };
	int K = 2;
	int ans = 5;
	int ret1 = findKthLargest_ST(nums, K);
	assert(ret1 == ans);

	int ret2 = findKthLargest_HP(nums, K);
	assert(ret2 == ans);
	return 0;
}
