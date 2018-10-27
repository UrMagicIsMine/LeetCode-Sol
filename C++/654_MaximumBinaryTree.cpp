/* Given an integer array with no duplicates. A maximum tree building on this
* array is defined as follow:
*
* The root is the maximum number in the array.
* The left subtree is the maximum tree constructed from left part subarray
* divided by the maximum number.
* The right subtree is the maximum tree constructed from right part subarray
* divided by the maximum number.
* Construct the maximum tree by the given array and output the root node of this
* tree.
*
* Example 1:
* Input: [3,2,1,6,0,5]
* Output: return the tree root node representing the following tree:
*
*       6
*     /   \
*    3     5
*     \    /
*      2  0
*        \
*         1
* Note:
* The size of the given array will be in the range [1,1000].
*/

#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* _constructMBT(vector<int>& nums, int low, int high) {

	if (low >= high)
		return nullptr;

	int pos = max_element(nums.begin() + low, nums.begin() + high) - nums.begin();
	TreeNode* pNode = new TreeNode(nums[pos]);
	pNode->left = _constructMBT(nums, low, pos);
	pNode->right = _constructMBT(nums, pos + 1, high);
	return pNode;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	return _constructMBT(nums, 0, nums.size());
}

void traverse(TreeNode *root, vector<int>& resl) {

	queue<TreeNode*> queNodes;
	queNodes.push(root);
	while (!queNodes.empty()) {

		int N = queNodes.size();
		while (N--) {
			TreeNode *pTop = queNodes.front();

			if (pTop == nullptr)
				resl.push_back(INT_MIN);
			else {
				resl.push_back(pTop->val);
				if (pTop->left != nullptr || pTop->right != nullptr) {
					queNodes.push(pTop->left);
					queNodes.push(pTop->right);
				}
			}
			queNodes.pop();
		}
	}
	return;
}


int main()
{
	vector<int> nums = { 3,2,1,6,0,5 };
	TreeNode* root = constructMaximumBinaryTree(nums);
	vector<int> ret;
	traverse(root, ret);
	vector<int> ans = { 6,3,5,INT_MIN,2,0,INT_MIN,INT_MIN,1 };
	assert(ret == ans);
	return 0;
}
