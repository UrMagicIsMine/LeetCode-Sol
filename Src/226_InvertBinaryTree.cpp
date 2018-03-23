/*
* Invert a binary tree.
*      4
*    /   \
*   2     7
*  / \   / \
* 1   3 6   9
* to
*      4
*    /   \
*   7     2
*  / \   / \
* 9   6 3   1
*/
#include<vector>
#include <string>
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

TreeNode* invertTree(TreeNode* root) {
	if (root) {
		TreeNode *ptmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(ptmp);
	}
	return root;
}

int main()
{
	return 0;
}
