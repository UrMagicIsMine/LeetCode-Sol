/* Given a binary tree, you need to compute the length of the diameter of the
* tree. The diameter of a binary tree is the length of the longest path between
* any two nodes in a tree. This path may or may not pass through the root.
*
* Example:
* Given a binary tree
*           1
*          / \
*         2   3
*        / \
*       4   5
* Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
*
* Note: The length of path between two nodes is represented by the number of
* edges between them.
*/
#include<vector>
#include<algorithm>
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

/* Recursive solution */

int diameterOfBinaryTree_Sln1(TreeNode* pNode, int & maxD) {

	if (!pNode->right && !pNode->left)
		return 0;
	else if (!pNode->right) {
		int ld = diameterOfBinaryTree_Sln1(pNode->left, maxD) + 1;
		maxD = max(ld, maxD);
		return ld;
	}
	else if (!pNode->left) {
		int rd = diameterOfBinaryTree_Sln1(pNode->right, maxD) + 1;
		maxD = max(rd, maxD);
		return rd;
	}
	else {
		int ld = diameterOfBinaryTree_Sln1(pNode->left, maxD) + 1;
		int rd = diameterOfBinaryTree_Sln1(pNode->right, maxD) + 1;
		maxD = max(ld + rd, maxD);
		return max(ld, rd);
	}
}

int diameterOfBinaryTree_Sln1(TreeNode* root) {

	if (!root)
		return 0;

	int maxD = 0;
	diameterOfBinaryTree_Sln1(root, maxD);
	return maxD;
}

/* Simplified Solution, if null, return -1 */

int diameterOfBinaryTree_Sln2(TreeNode* pNode, int & maxD) {

	if (pNode) {
		int ld = diameterOfBinaryTree_Sln2(pNode->left, maxD) + 1;
		int rd = diameterOfBinaryTree_Sln2(pNode->right, maxD) + 1;
		maxD = max(ld + rd, maxD);
		return max(ld, rd);
	}
	return -1;
}

int diameterOfBinaryTree_Sln2(TreeNode* root) {

	int maxD = 0;
	diameterOfBinaryTree_Sln2(root, maxD);
	return maxD;
}

int main()
{
	vector<TreeNode> btree = { 5,2,13 };
	btree[0].left = &btree[1];
	btree[0].right = &btree[2];
	int ans = 2;
	int ret1 = diameterOfBinaryTree_Sln1(&btree[0]);
	assert(ret1 == ans);
	int ret2 = diameterOfBinaryTree_Sln1(&btree[0]);
	assert(ret2 == ans);
	return 0;
}
