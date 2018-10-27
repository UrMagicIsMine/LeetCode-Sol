/* Given two non-empty binary trees s and t, check whether tree t has exactly
* the same structure and node values with a subtree of s. A subtree of s is a
* tree consists of a node in s and all of this node's descendants. The tree s
* could also be considered as a subtree of itself.
*
* Example 1:
* Given tree s:
*
*      3
*     / \
*    4   5
*   / \
*  1   2
* Given tree t:
*    4
*   / \
*  1   2
* Return true, because t has the same structure and node values with a subtree of s.
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

bool isSametree(TreeNode * t1, TreeNode* t2) {

	if (!t1 && !t2)
		return true;
	if (t1 && t2)
		return t1->val == t2->val && isSametree(t1->left, t2->left)
          && isSametree(t1->right, t2->right);
	return false;
}

bool isSubtree(TreeNode* s, TreeNode* t) {

	if (isSametree(s, t))
		return true;
	if (s->left && isSubtree(s->left, t))
		return true;
	if (s->right && isSubtree(s->right, t))
		return true;
	return false;

}

int main()
{
	vector<TreeNode> btree = { 1,1,1,2 };
	btree[0].right = &btree[1];
	btree[1].right = &btree[2];
	btree[2].left = &btree[3];

	vector<TreeNode> stree = { 1,2 };
	stree[0].left = &stree[1];

	bool ret = isSubtree(&btree[0], &stree[0]);
	assert(ret == true);
	return 0;
}
