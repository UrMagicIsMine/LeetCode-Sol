/* Given two binary trees, write a function to check if they are the same or not.
*
* Two binary trees are considered the same if they are structurally identical and
* the nodes have the same value.
*
* Example 1:
*
* Input:     1         1
*           / \       / \
*          2   3     2   3
*
*         [1,2,3],   [1,2,3]
*
* Output: true
*
*/

#include <vector>
#include <numeric>
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

/* DFS recursive solution, run-time O(N), memory O(logN) */

bool isSameTree(TreeNode* p, TreeNode* q) {

	if (p == nullptr && q == nullptr)
		return true;
	else if (p != nullptr && q != nullptr)
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	else
		return false;

}

int main()
{
	vector<TreeNode> tree1 = { 1,2,3 }, tree2 = { 1,2,3 };
	tree1[0].left = &tree1[1];
	tree1[0].right = &tree1[2];

	tree2[0].left = &tree2[1];
	tree2[0].right = &tree2[2];
	bool ans = true;

	bool ret = isSameTree(&tree1[0], &tree2[0]);
	assert(ret == ans);
	return 0;
}
