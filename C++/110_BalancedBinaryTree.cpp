/* Given a binary tree, determine if it is height-balanced.
*
* For this problem, a height-balanced binary tree is defined as:
*
* a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*
* Example 1:
*
* Given the following tree [3,9,20,null,null,15,7]:
*
*     3
*    / \
*   9  20
*     /  \
*    15   7
* Return true.
*
* Example 2:
*
* Given the following tree [1,2,2,3,3,null,null,4,4]:
*
*        1
*       / \
*      2   2
*     / \
*    3   3
*   / \
*  4   4
* Return false.
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
* This function check the balance of the node recursively
* if balance, return its height, else return -1 indicating unbalance failure
*/

int getHeight(TreeNode* pNode) {
	if (pNode) {
		int hleft = getHeight(pNode->left);
		if (hleft < 0)
			return hleft;

		int rleft = getHeight(pNode->right);
		if (rleft < 0)
			return rleft;

		if (abs(hleft - rleft) > 1)
			return -1;
		else
			return max(hleft, rleft) + 1;
	}
	return 0;
}

bool isBalanced(TreeNode* root) {
	return getHeight(root) >= 0 ? true : false;
}

int main()
{

	vector<TreeNode> vec = { 3,9,20,15,7 };
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vec[2].right = &vec[4];

	bool ret = isBalanced(&vec[0]);
	return 0;
}
