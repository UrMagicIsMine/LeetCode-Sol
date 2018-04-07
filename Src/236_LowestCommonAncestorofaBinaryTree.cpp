/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
* in the tree.
*
* According to the definition of LCA on Wikipedia: “The lowest common ancestor is
* defined between two nodes v and w as the lowest node in T that has both v and w
* as descendants (where we allow a node to be a descendant of itself).”
*
*         _______3______
*        /              \
*     ___5__          ___1__
*    /      \        /      \
*    6      _2       0       8
*          /  \
*          7   4
* For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another
* example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of
* itself according to the LCA definition.
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


bool _DFS(TreeNode * pNode, TreeNode* pTarget, vector<TreeNode*>& ancestors) {

	if (pNode) {
		ancestors.push_back(pNode);
		if (pNode == pTarget) {
			return true;
		}
		bool retl = _DFS(pNode->left, pTarget, ancestors);
		if (retl)
			return true;
		bool retr = _DFS(pNode->right, pTarget, ancestors);
		if (retr)
			return true;
		ancestors.pop_back();
	}
	return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	vector<TreeNode*> pAns, qAns;
	_DFS(root, p, pAns);
	_DFS(root, q, qAns);

	TreeNode* pRet = nullptr;
	int minsize = min<int>(pAns.size(), qAns.size());
	for (int i = 0; i < minsize; i++) {
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
	vector<TreeNode> tree = { 1,2 };
	tree[0].left = &tree[1];
	TreeNode* ret = lowestCommonAncestor(&tree[0], &tree[0], &tree[1]);
	TreeNode* ans = &tree[0];
	assert(ret == ans);
	return 0;
}
