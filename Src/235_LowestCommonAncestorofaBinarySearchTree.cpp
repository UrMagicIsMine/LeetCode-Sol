/* Given a binary search tree (BST), find the lowest common ancestor (LCA) of two
* given nodes in the BST.
*
* According to the definition of LCA on Wikipedia: “The lowest common ancestor is
* defined between two nodes v and w as the lowest node in T that has both v and w
* as descendants (where we allow a node to be a descendant of itself).”
*
*         _______6______
*        /              \
*     ___2__          ___8__
*    /      \        /      \
*    0      _4       7       9
*          /  \
*          3   5
* For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another
* example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself
* according to the LCA definition.
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


bool _DFS(TreeNode * pNode, TreeNode * pTarget, vector<TreeNode*>& ancestors) {

	if (pNode) {

		ancestors.push_back(pNode);
		if (pNode == pTarget) {
			return true;
		}
		else if (pTarget->val < pNode->val) {
			bool retl = _DFS(pNode->left, pTarget, ancestors);
			if (retl)
				return true;
		}
		else {
			bool ret2 = _DFS(pNode->right, pTarget, ancestors);
			if (ret2)
				return true;
		}
		ancestors.pop_back();
	}
	return false;

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	vector<TreeNode*> pAns, qAns;
	_DFS(root, p, pAns);
	_DFS(root, q, qAns);

	TreeNode * pRet = nullptr;
	int minSize = min<int>(pAns.size(), qAns.size());
	for (int i = 0; i < minSize; i++) {
		if (pAns[i] == qAns[i]) {
			pRet = pAns[i];
		}
		else
			break;
	}
	return pRet;
}

int main()
{
	vector<TreeNode> tree = { 2,1 };
	tree[0].left = &tree[1];
	TreeNode* ret = lowestCommonAncestor(&tree[0], &tree[0], &tree[1]);
	TreeNode* ans = &tree[0];
	assert(ret == ans);
	return 0;
}
