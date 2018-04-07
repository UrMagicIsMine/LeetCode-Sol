/* Given a Binary Search Tree and a target number, return true if there exist
* two elements in the BST such that their sum is equal to the given target.
*
* Example 1:
* Input:
*     5
*    / \
*   3   6
*  / \   \
* 2   4   7
*
* Target = 9
*
* Output: True
*/

#include <vector>
#include <unordered_set>
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


void _DFS_Sln1(TreeNode* pNode, unordered_set<int> & nums) {

	if (pNode) {
		nums.insert(pNode->val);
		_DFS_Sln1(pNode->left, nums);
		_DFS_Sln1(pNode->right, nums);
	}
	return;
}

bool findTarget_Sln1(TreeNode* root, int k) {

	unordered_set<int> hashtbl;
	_DFS_Sln1(root, hashtbl);

	for (auto i : hashtbl) {
		if (k - i != i && hashtbl.find(k - i) != hashtbl.end())
			return true;
	}
	return false;
}

bool _DFS_Sln2(TreeNode* pNode, int k, unordered_set<int> & nums) {

	if (pNode) {

		if (nums.find(k - pNode->val) != nums.end())
			return true;
		nums.insert(pNode->val);
		return _DFS_Sln2(pNode->left, k, nums) || _DFS_Sln2(pNode->right, k, nums);
	}
	return false;
}

bool findTarget_Sln2(TreeNode* root, int k) {

	unordered_set<int> nums;
	return _DFS_Sln2(root, k, nums);
}

int main()
{
	vector<TreeNode> nums = { 5,3,7,2,4,6,7 };
	nums[0].left = &nums[1];
	nums[0].right = &nums[2];
	nums[1].left = &nums[3];
	nums[1].right = &nums[4];
	nums[2].left = &nums[5];
	nums[2].right = &nums[6];
	int k = 9;
	bool ans = true;
	bool ret1 = findTarget_Sln1(&nums[0], k);
	assert(ret1 == ans);
	bool ret2 = findTarget_Sln1(&nums[0], k);
	assert(ret2 == ans);
	return 0;
}
