/* Implement an iterator over a binary search tree (BST). Your iterator will be
* initialized with the root node of a BST.
*
* Calling next() will return the next smallest number in the BST.
*
* Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
* where h is the height of the tree.
*/

#include <stack>
#include <vector>
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

/******************************************************************************/
/* solution start from here, use stack, save along the left branch */

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		_travelAlongLeft(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !m_stack.empty();
	}

	/** @return the next smallest number */
	int next() {

		TreeNode* pNode = m_stack.top();
		int ret = pNode->val;
		m_stack.pop();
		if (pNode->right)
			_travelAlongLeft(pNode->right);

		return ret;
	}

private:

	void _travelAlongLeft(TreeNode * pNode) {
		while (pNode) {
			m_stack.push(pNode);
			pNode = pNode->left;
		}
	}
	stack<TreeNode*> m_stack;

};

int main()
{
	vector<int> preorder = { 4,2,1,3,6,5,7 };
	vector<int> inorder = { 1,2,3,4,5,6,7 };
	TreeNode* root = buildTree(preorder, inorder);

	BSTIterator it = BSTIterator(root);
	vector<int> travResl;
	while (it.hasNext())
		travResl.push_back(it.next());

	assert(travResl == inorder);
	return 0;
}
