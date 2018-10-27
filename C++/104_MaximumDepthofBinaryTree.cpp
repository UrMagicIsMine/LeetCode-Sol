/* Given a binary tree, find its maximum depth.
*
* The maximum depth is the number of nodes along the longest path
* from the root node down to the farthest leaf node.
*
* For example:
* Given binary tree [3,9,20,null,null,15,7],
*
*   3
*  / \
* 9  20
*   /  \
*  15   7
* return its depth = 3.
*/
#include <vector>
#include <algorithm>

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

int maxDepth(TreeNode* root) {
	if (!root) return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
	vector<TreeNode> vec = { 3,9,20,15,7 };
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vec[2].right = &vec[4];

	int ret = maxDepth(&vec[0]);
	return 0;
}
