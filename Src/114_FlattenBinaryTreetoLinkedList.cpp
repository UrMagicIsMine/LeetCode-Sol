/* Given a binary tree, flatten it to a linked list in-place.
*
* For example,
* Given
*
*          1
*         / \
*        2   5
*       / \   \
*      3   4   6
* The flattened tree should look like:
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
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

/******************************************************************************/
/* Solution 1: simple recrusive solution, less efficient (notice the while loop
* inside the if-condition syntax)
*/
void flatten1(TreeNode* root) {

	if (root)
	{
		flatten1(root->left);
		flatten1(root->right);

		if (root->left) {
			TreeNode* pRight = root->right;
			root->right = root->left;
			root->left = nullptr;
			TreeNode* pTmp = root->right;
			while (pTmp->right)
				pTmp = pTmp->right;
			pTmp->right = pRight;
		}
	}
	return;
}

/******************************************************************************/
/* Solution 2: efficient recrusive solution, _flattenRecv function returns a
* pointer pointing to the end of sub-tree; This avoids the while loop in the
* above solution 1;
*/

TreeNode* _flattenRecv(TreeNode *pNode) {

	if (pNode) {

		TreeNode * left_end = _flattenRecv(pNode->left);
		TreeNode * rght_end = _flattenRecv(pNode->right);

		if (left_end && rght_end) {
			left_end->right = pNode->right;
			pNode->right = pNode->left;
			pNode->left = nullptr;
			return rght_end;
		}
		if (left_end && !rght_end) {
			pNode->right = pNode->left;
			pNode->left = nullptr;
			return left_end;
		}
		if (rght_end && !left_end)
			return rght_end;

		return pNode;
	}
	return nullptr;

}

void flatten2(TreeNode* root) {

	_flattenRecv(root);
}


int main()
{
	vector<int> preOrder = { 5,4,11,7,2,8,13,4,5,1 };
	vector<int> inOrder = { 7,11,2,4,5,13,8,5,4,1 };
	TreeNode* root = buildTree(preOrder, inOrder);

  //flatten1(root);
	flatten2(root);
	return 0;
}
