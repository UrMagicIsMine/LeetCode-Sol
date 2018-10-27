/* Given inorder and postorder traversal of a tree, construct the binary tree.
*
* Note:
* You may assume that duplicates do not exist in the tree.
*
* For example, given
*
* inorder = [9,3,15,20,7]
* postorder = [9,15,7,20,3]
* Return the following binary tree:
*
*     3
*    / \
*   9  20
*     /  \
*    15   7
*
*/
#include <vector>

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

int main()
{
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };

	TreeNode* ret = buildTree(inorder, postorder);
	return 0;
}
