/* Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting
node to any node in the tree along the parent-child connections. The path must
contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/

#include <vector>
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

int _DFS(TreeNode *pNode, int& maxP) {
	if (pNode) {

		int sumL = max(0, _DFS(pNode->left, maxP));
		int sumR = max(0, _DFS(pNode->right, maxP));
		maxP = max(sumL + sumR + pNode->val, maxP);
		return max(sumL, sumR) + pNode->val;

	}
	return 0;
}

int maxPathSum(TreeNode* root) {
	int maxP = INT_MIN;
	_DFS(root, maxP);
	return maxP;
}

int main()
{
	vector<TreeNode> nums = { 1,2,3 };
	nums[0].left = &nums[1];
	nums[0].right = &nums[2];
	int ans = 6;
	int ret = maxPathSum(&nums[0]);
	assert(ret == ans);
	return 0;
}
