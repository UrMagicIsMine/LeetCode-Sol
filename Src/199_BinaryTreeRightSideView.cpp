/* Given a binary tree, imagine yourself standing on the right side of it,
* return the values of the nodes you can see ordered from top to bottom.
*
* For example:
* Given the following binary tree,
*    1            <---
*  /   \
* 2     3         <---
*  \     \
*   5     4       <---
* You should return [1, 3, 4].
*/

#include <vector>
#include <queue>
#include <cassert>
using namespace std;

/**
* Definition for binary tree
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* _buildTree(const vector<int>& preorder, int& iWork, const vector<int>& inorder, int ibeg, int iend) {

	/* to build tree from pre-Order array, recursion should use pre-Order fashion */
	while (ibeg <= iend) {
		int imid = find(inorder.begin() + ibeg, inorder.begin() + iend, preorder[iWork]) - inorder.begin();
		TreeNode * pNode = new TreeNode(preorder[iWork++]);
		pNode->left = _buildTree(preorder, iWork, inorder, ibeg, imid - 1);
		pNode->right = _buildTree(preorder, iWork, inorder, imid + 1, iend);
		return pNode;
	}
	return nullptr;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int N = preorder.size();
	int i = 0;
	return _buildTree(preorder, i, inorder, 0, N - 1);
}

vector<int> rightSideView(TreeNode* root) {

	vector<int> resl;
	if (root) {
		queue<TreeNode*> qTreeNode;
		qTreeNode.push(root);
		int Nsize = qTreeNode.size();
		while (Nsize--) {

			TreeNode * pNode = qTreeNode.front();
			if (pNode->left)
				qTreeNode.push(pNode->left);
			if (pNode->right)
				qTreeNode.push(pNode->right);
			qTreeNode.pop();
			/* save value of last node in this level */
			if (Nsize == 0) {
				resl.push_back(pNode->val);
				Nsize = qTreeNode.size();
			}
		}
	}
	return resl;
}

int main()
{
	vector<int> preorder = { 4,2,1,3,6,5,7 };
	vector<int> inorder = { 1,2,3,4,5,6,7 };
	TreeNode* root = buildTree(preorder, inorder);

	vector<int> ret = rightSideView(root);
	vector<int> ans = { 4,6,7 };
	assert(ret == ans);
	return 0;
}
