/* Given a binary search tree, write a function kthSmallest to find the kth
* smallest element in it.
*
* Note:
* You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/

#include <vector>
#include <unordered_map>
#include <stack>
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

bool _DFS(TreeNode* pNode, int& k, int & resl) {
	if (pNode) {
		bool retl = _DFS(pNode->left, k, resl);
		k--;
		if (retl)
			return true;
		if (k == 0) {
			resl = pNode->val;
			return true;
		}
		bool retr = _DFS(pNode->right, k, resl);
		if (retr)
			return true;
	}
	return false;
}

int kthSmallest(TreeNode* root, int k) {
	int resl = 0;
	_DFS(root, k, resl);
	return resl;
}


int main()
{
	vector<TreeNode> nums = { 2, 1, 3 };
	nums[0].left = &nums[1];
	nums[0].right = &nums[2];
	int k = 1;
	int ans = 1;
	int ret = kthSmallest(&nums[0], k);
	assert(ret == ans);
	return 0;
}
