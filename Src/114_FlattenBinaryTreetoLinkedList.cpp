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


void _flatten(TreeNode* root, TreeNode*& pre) {
		if(!root)
				return;
		_flatten(root->right, pre);
		_flatten(root->left, pre);
		root->right = pre;
		root->left = nullptr;
		pre = root;
}

void flatten1(TreeNode* root) {
		TreeNode* p = nullptr;
		_flatten(root, p);
		return;
}

void flatten2(TreeNode* root) {
		TreeNode dummy(0);
		TreeNode* p = &dummy;
		stack<TreeNode*> stNodes;
		TreeNode *pNode = root;
		while(pNode){

				if(pNode->right)
						stNodes.push(pNode->right);
				p->right = pNode;
				pNode = pNode->left;
				p->right->left = nullptr;
				p->right->right = nullptr;
				p = p->right;

				if(!pNode && !stNodes.empty()){
						pNode = stNodes.top();
						stNodes.pop();
				}
		}
		return;
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
