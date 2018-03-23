/* Given a Binary Search Tree (BST), convert it to a Greater Tree such that
* every key of the original BST is changed to the original key plus sum of all
* keys greater than the original key in BST.
*
* Example:
*
* Input: The root of a Binary Search Tree like this:
*               5
*             /   \
*            2     13
*
* Output: The root of a Greater Tree like this:
*              18
*             /   \
*           20     13
*/
#include<vector>
#include<stack>
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

/* in-Order traverse recursively */

void _BackInOrder(TreeNode* pNode, int & sum) {

	if (pNode) {
		_BackInOrder(pNode->right, sum);
		int tmp = pNode->val;
		pNode->val += sum;
		sum += tmp;
		_BackInOrder(pNode->left, sum);
	}
	return;
}

TreeNode* convertBST_DFS(TreeNode* root) {
	int sum = 0;
	_BackInOrder(root, sum);
	return root;
}

/* in-Order traverse iteratively using stack */

TreeNode* convertBST(TreeNode* root) {
	int sum = 0;

	stack<TreeNode*> StaNodes;
	TreeNode * pNode = root;
	while (pNode) {
		StaNodes.push(pNode);
		pNode = pNode->right;
	}

	while (!StaNodes.empty()) {

		pNode = StaNodes.top();
		int tmp = pNode->val;
		pNode->val += sum;
		sum = sum + tmp;
		StaNodes.pop();
		if (pNode->left) {
			pNode = pNode->left;
			while (pNode) {
				StaNodes.push(pNode);
				pNode = pNode->right;
			}
		}
	}
	return root;
}

int main()
{
	vector<TreeNode> btree = { 5,2,13 };
	btree[0].left = &btree[1];
	btree[0].right = &btree[2];
	convertBST(&btree[0]);

	return 0;
}
