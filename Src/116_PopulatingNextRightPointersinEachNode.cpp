/* Given a binary tree
*
*     struct TreeLinkNode {
*       TreeLinkNode *left;
*       TreeLinkNode *right;
*       TreeLinkNode *next;
*     }
*
* Populate each next pointer to point to its next right node. If
* there is no next right node, the next pointer should be set to NULL.
*
* Initially, all next pointers are set to NULL.
*
* Note:
*
* You may only use constant extra space.
* You may assume that it is a perfect binary tree (ie, all leaves
* are at the same level, and every parent has two children).
* For example,
* Given the following perfect binary tree,
*          1
*        /  \
*       2    3
*      / \  / \
*     4  5  6  7
* After calling your function, the tree should look like:
*          1 -> NULL
*        /  \
*       2 -> 3 -> NULL
*      / \  / \
*     4->5->6->7 -> NULL
*
*/

#include <vector>
#include <queue>
#include <cassert>
using namespace std;

/**
* Definition for binary tree with next pointer.
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* _buildTree(const vector<int>& preorder, int& iWork, const vector<int>& inorder, int ibeg, int iend) {

	/* to build tree from pre-Order array, recursion should use pre-Order fashion */
	while (ibeg <= iend) {
		int imid = find(inorder.begin() + ibeg, inorder.begin() + iend, preorder[iWork]) - inorder.begin();
		TreeLinkNode * pNode = new TreeLinkNode(preorder[iWork++]);
		pNode->left = _buildTree(preorder, iWork, inorder, ibeg, imid - 1);
		pNode->right = _buildTree(preorder, iWork, inorder, imid + 1, iend);
		return pNode;
	}
	return nullptr;
}

TreeLinkNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int N = preorder.size();
	int i = 0;
	return _buildTree(preorder, i, inorder, 0, N - 1);
}

/******************************************************************************/
/* Solution 1 start from here, use queue to do level tranverse */

void connect_Sln1(TreeLinkNode *root) {

	if (root) {
		queue<TreeLinkNode*> qNodes;
		qNodes.push(root);
		int N = qNodes.size();
		while (!qNodes.empty())
		{
			TreeLinkNode *pNode = qNodes.front();

			if (pNode->left)
				qNodes.push(pNode->left);
			if (pNode->right)
				qNodes.push(pNode->right);

			qNodes.pop();
			N--;
			if (N == 0) {
				pNode->next = nullptr;
				N = qNodes.size();
			}
			else
				pNode->next = qNodes.front();
		}
	}
	return;
}

/******************************************************************************/
/* Solution 2 start from here, connect each level */

void connect_Sln2(TreeLinkNode *root) {

	if (!root)
		return;

	TreeLinkNode *pLeft = root;
	TreeLinkNode *pCur = nullptr;

	while (pLeft->left) {

		pCur = pLeft;
		while (pCur) {
			pCur->left->next = pCur->right;
			if (pCur->next) {
				pCur->right->next = pCur->next->left;
			}
			pCur = pCur->next;
		}
		pLeft = pLeft->left;
	}
	return;
}

vector<int> BFtranverse(TreeLinkNode* root)
{
	vector<int> resl;
	TreeLinkNode* pLeft = root;
	while (pLeft) {

		TreeLinkNode* pCur = pLeft;
		while (pCur) {
			resl.push_back(pCur->val);
			pCur = pCur->next;
		}
		pLeft = pLeft->left;

	}
	return resl;
}

int main()
{
	vector<int> preOrder = { 1,2,4,5,3,6,7 };
	vector<int> inOrder = { 4,2,5,1,6,3,7 };
	TreeLinkNode* root1 = buildTree(preOrder, inOrder);
	TreeLinkNode* root2 = buildTree(preOrder, inOrder);

	connect_Sln1(root1);
	vector<int> tran_Sln1 = BFtranverse(root1);

	connect_Sln2(root2);
	vector<int> tran_Sln2 = BFtranverse(root1);

	assert(tran_Sln1 == tran_Sln2);
	return 0;
}
