/* Given a binary tree, return the postorder traversal of its nodes' values.
*
* For example:
* Given binary tree [1,null,2,3],
*    1
*     \
*      2
*     /
*    3
* return [3,2,1].
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

TreeNode* _buildTree(const vector<int>& inorder, const vector<int>& postorder,
	int& iWork, int ibeg, int iend) {

	/* to build tree from post-Order array, traversal from back to front of post-Order array */
	while (ibeg <= iend) {

		int imid = find(inorder.begin() + ibeg, inorder.begin() + iend, postorder[iWork]) - inorder.begin();
		TreeNode * pNode = new TreeNode(postorder[iWork--]);
		pNode->right = _buildTree(inorder, postorder, iWork, imid + 1, iend);
		pNode->left = _buildTree(inorder, postorder, iWork, ibeg, imid - 1);
		return pNode;
	}
	return nullptr;

}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	int N = inorder.size();
	int iWork = N - 1;
	return _buildTree(inorder, postorder, iWork, 0, N - 1);
}

void _postOrderTree_Rcv(TreeNode* pNode, vector<int> & nums)
{
	if (pNode) {
		_postOrderTree_Rcv(pNode->left, nums);
		_postOrderTree_Rcv(pNode->right, nums);
		nums.push_back(pNode->val);
	}
	return;
}

vector<int> postorderTraversal_Rcv(TreeNode* root) {

	vector<int> resl;
	_postOrderTree_Rcv(root, resl);
	return resl;

}

vector<int> postorderTraversal_Itv(TreeNode* root) {

	vector<int> resl;
	if (!root)
		return resl;

	stack<TreeNode*> pNodeStack;
	TreeNode* pNode = root;
  /*sentinel pointer pointing to last visited node */
	TreeNode* pLastNode = nullptr;

	while (pNode || !pNodeStack.empty()) {
		/* travel to the left-most and push to stack along the way */
		if (pNode)
		{
			pNodeStack.push(pNode);
			pNode = pNode->left;
		}
		else {

			TreeNode* topNode = pNodeStack.top();
			/* test the top node, if has right child and haven't visited yet
			* switch to right child, repeat above again;
			*/
			if (topNode->right && pLastNode != topNode->right) {
				pNode = topNode->right;
			}
			else {
				/* if no right child, or right child have been visited by last step
				* pop the node from stack, update last visited pointer;
				*/
				resl.push_back(topNode->val);
				pNodeStack.pop();
				pLastNode = topNode;
			}
		}
	}
	return resl;

}

int main()
{
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };
	TreeNode* root = buildTree(inorder, postorder);

	vector<int> ret_Rcv = postorderTraversal_Rcv(root);
	vector<int> ret_Itv = postorderTraversal_Itv(root);
	return 0;
}
