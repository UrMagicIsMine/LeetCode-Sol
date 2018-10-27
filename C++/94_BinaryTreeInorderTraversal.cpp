/* Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
#include <vector>
#include <stack>
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

void _inOrderTraversal(vector<int>& resl, TreeNode* pNode) {
	if (pNode) {
		_inOrderTraversal(resl, pNode->left);
		resl.push_back(pNode->val);
		_inOrderTraversal(resl, pNode->right);
	}
	return;
}

vector<int> inorderTraversal_Rec(TreeNode* root) {
	vector<int> resl;
	_inOrderTraversal(resl, root);
	return resl;
}

// succint iterative solution using stack

vector<int> inorderTraversal_Itr(TreeNode* root) {

	vector<int> resl;
	stack<TreeNode*> stackNodes;
	TreeNode *p = root;
	while (p || !stackNodes.empty()) {

		while (p) {
			stackNodes.push(p);
			p = p->left;
		}

		p = stackNodes.top();
		resl.push_back(p->val);
		stackNodes.pop();
		p = p->right;

	}
	return resl;
}

int main()
{
	vector<TreeNode> nodes = { 1,2,3 };
	nodes[0].right = &nodes[1];
	nodes[1].left = &nodes[2];
	vector<int> ans = { 1,3,2 };
	vector<int> ret_rec = inorderTraversal_Rec(&nodes[0]);
	assert(ret_rec == ans);
	vector<int> ret_itr = inorderTraversal_Itr(&nodes[0]);
	assert(ret_itr == ans);
	return 0;
}
