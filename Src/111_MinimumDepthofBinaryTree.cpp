/* Given a binary tree, find its minimum depth.
*
*  The minimum depth is the number of nodes along the shortest path
* from the root node down to the nearest leaf node.
*
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

/**
* This function check the depth of the node recursively
* if it is null, minDepth(p) = 0;
* if it has 1 child, minDepth(p) = minDepth(child) + 1
* if it has 2 child, minDepth(p) = minDepth(lchild,rchild) + 1
*/

int minDepth(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL) return minDepth(root->right) + 1;
	if (root->right == NULL) return minDepth(root->left) + 1;
	return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main()
{

	vector<TreeNode> vec = { 3,9,20,15,7 };
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vec[2].right = &vec[4];

	int ret = minDepth(&vec[0]);
	return 0;
}
