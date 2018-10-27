/* Given an integer array nums, find the sum of the elements between indices i
* and j (i <= j), inclusive.
*
* The update(i, val) function modifies nums by updating the element at index i to val.
* Example:
* Given nums = [1, 3, 5]
*
* sumRange(0, 2) -> 9
* update(1, 2)
* sumRange(0, 2) -> 8
* Note:
* The array is only modifiable by the update function.
* You may assume the number of calls to update and sumRange function is distributed evenly.
* 
*/

#include <vector>
#include <cassert>
using namespace std;

struct SegmentTreeNode {
	int beg;
	int end;
	int sum;
	SegmentTreeNode *left;
	SegmentTreeNode *right;
	SegmentTreeNode(int i, int j) : beg(i), end(j), sum(0), left(nullptr), right(nullptr)
	{}
};

class NumArray {
public:
	NumArray(vector<int> nums) : _root(nullptr) {
		int N = nums.size();
		if (N == 0)
			return;
		_root = _buildTree(0, N - 1, nums);
	}

	void update(int i, int val) {
		_updateTree(_root, i, val);
	}

	int sumRange(int i, int j) {
		return _sumRange(_root, i, j);
	}

private:

	SegmentTreeNode * _buildTree(int bg, int ed, const vector<int> & nums) {
		SegmentTreeNode* pNode = nullptr;

		if (bg == ed) {
			pNode = new SegmentTreeNode(bg, bg);
			pNode->sum = nums[bg];
		}
		else {
			pNode = new SegmentTreeNode(bg, ed);
			int mid = (bg + ed) / 2;
			pNode->left = _buildTree(bg, mid, nums);
			pNode->right = _buildTree(mid + 1, ed, nums);
			pNode->sum = pNode->left->sum + pNode->right->sum;
		}
		return pNode;
	}

	int _updateTree(SegmentTreeNode* pNode, int i, int val) {

		if (pNode->beg == pNode->end && pNode->beg == i) {
			int diff = val - pNode->sum;
			pNode->sum += diff;
			return diff;
		}

		int mid = (pNode->beg + pNode->end) / 2;
		int diff = 0;
		if (i <= mid)
			diff = _updateTree(pNode->left, i, val);
		else
			diff = _updateTree(pNode->right, i, val);

		pNode->sum += diff;
		return diff;
	}

	int _sumRange(SegmentTreeNode* pNode, int i, int j) {

		if (pNode->beg == i && pNode->end == j)
			return pNode->sum;
		int mid = (pNode->beg + pNode->end) / 2;
		if (j <= mid)
			return _sumRange(pNode->left, i, j);
		if (i > mid)
			return _sumRange(pNode->right, i, j);
		return _sumRange(pNode->left, i, mid) + _sumRange(pNode->right, mid + 1, j);

	}

private:
	SegmentTreeNode * _root;
};

int main()
{
	vector<int> nums = { 1,3,5,4,2 };
	NumArray nArray(nums);

	int ret1 = nArray.sumRange(0, 2);
	assert(ret1 == 9);

	nArray.update(2, 4);

	int ret2 = nArray.sumRange(0, 3);
	assert(ret2 == 12);
	return 0;

}
