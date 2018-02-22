/* Given a binary tree, return the preorder traversal of its nodes' values.
*
* For example:
* Given binary tree [1,null,2,3],
*    1
*     \
*      2
*     /
*    3
* return [1,2,3].
*
* Note: Recursive solution is trivial, could you do it iteratively?
*
*/
#include <vector>
#include <stack>
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

/* Recursive solution */

void _preOrderTree_Rcv(TreeNode * p, vector<int> & nums) {

	if (p) {
		nums.push_back(p->val);
		_preOrderTree_Rcv(p->left, nums);
		_preOrderTree_Rcv(p->right, nums);
	}
	return;
}

vector<int> preorderTraversal_Rcv(TreeNode* root) {

	vector<int> resl;
	_preOrderTree_Rcv(root, resl);
	return resl;

}

/* Iterative solution using stack */

vector<int> preorderTraversal_Itv(TreeNode* root) {

	vector<int> resl;

	if (!root)
		return resl;
	stack<TreeNode*> pNodeStack;

	/* treat root as a regular node, push it into stack,
	 * this can avoid dupicated call of traveling along the left
	*/
	TreeNode* pNode = root;
	pNodeStack.push(root);

	while (!pNodeStack.empty()) {

		TreeNode* pTmp = pNodeStack.top();
		pNodeStack.pop();

		while (pTmp)
		{
			if (pTmp->right)
				pNodeStack.push(pTmp->right);
			resl.push_back(pTmp->val);
			pTmp = pTmp->left;
		}

	}

	return resl;

}

int main()
{
	vector<int> preOrder = { 5,4,11,7,2,8,13,4,1 };
	vector<int> inOrder = { 7,11,2,4,5,13,8,4,1 };
	TreeNode* root = buildTree(preOrder, inOrder);

	vector<int> ret_Rcv = preorderTraversal_Rcv(root);
	vector<int> ret_Itv = preorderTraversal_Itv(root);
	return 0;
}
