/*The thief has found himself a new place for his thievery again. There is only
* one entrance to this area, called the "root." Besides the root, each house has
* one and only one parent house. After a tour, the smart thief realized that
* "all houses in this place forms a binary tree". It will automatically contact
* the police if two directly-linked houses were broken into on the same night.
*
* Determine the maximum amount of money the thief can rob tonight without
* alerting the police.
*
* Example 1:
*      3
*     / \
*    2   3
*     \   \
*      3   1
* Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
* Example 2:
*      3
*     / \
*    4   5
*   / \   \
* 1   3   1
* Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, int> _rob(TreeNode* pNode) {
	pair<int, int> resl(0, 0);
	if (pNode) {
		pair<int, int> pl = _rob(pNode->left);
		pair<int, int> pr = _rob(pNode->right);
		pNode->val = max(pNode->val + pl.second + pr.second, pl.first + pr.first);
		resl.first = pNode->val;
		resl.second = pl.first + pr.first;
	}
	return resl;
}

int rob(TreeNode* root) {

	pair<int, int> money = _rob(root);
	return max(money.first, money.second);
}

int main()
{
	vector<TreeNode> nums = { 4,1,2,3 };
	nums[0].left = &nums[1];
	nums[1].left = &nums[2];
	nums[2].left = &nums[3];
	int ans = 7;
	int ret = rob(&nums[0]);
	assert(ret == ans);
	return 0;
}
