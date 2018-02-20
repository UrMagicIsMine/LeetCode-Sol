/* Given a binary tree containing digits from 0-9 only, each
* root-to-leaf path could represent a number.
*
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
*
* Find the total sum of all root-to-leaf numbers.
*
* For example,
*
*     1
*    / \
*   2   3
* The root-to-leaf path 1->2 represents the number 12.
* The root-to-leaf path 1->3 represents the number 13.
*
* Return the sum = 12 + 13 = 25.
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

/***********************************************************************/

bool _isLeaf(TreeNode * pNode)
{
	return (pNode->left == nullptr) && (pNode->right == nullptr);
}

void _DFSTraverse(TreeNode * pNode, int pathSum, int &totalSum) {

	if (pNode) {

		pathSum = pathSum * 10 + pNode->val;
		if (_isLeaf(pNode)) {
			totalSum += pathSum;
			return;
		}
		_DFSTraverse(pNode->left, pathSum, totalSum);
		_DFSTraverse(pNode->right, pathSum, totalSum);
	}
	return;
}

int sumNumbers(TreeNode* root) {

	int totalSum = 0, pathSum = 0;
	_DFSTraverse(root, pathSum, totalSum);
	return totalSum;

}

int main()
{
	vector<int> preOrder = { 5,4,1,7,2,8,3,4,5,1 };
	vector<int> inOrder = { 7,1,2,4,5,3,8,5,4,1 };
	TreeNode* root = buildTree(preOrder, inOrder);

	int ret = sumNumbers(root);
	return 0;
}
