/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path
* such that adding up all the values along the path equals the given sum.
*
* For example:
* Given the below binary tree and sum = 22,
*
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \      \
*         7    2      1
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

bool _isLeaf(TreeNode * pNode) {
	return pNode->left == nullptr && pNode->right == nullptr;
}

typedef vector<int> vec1D;
typedef vector<vec1D> vec2D;

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vec1D preVecs;
    vec2D resl;
    _pathSumRecv(root, resl, sum, 0, preVecs);
    return resl;
}

void _pathSumRecv(TreeNode* pNode, vec2D& resl, int targetSum, int RunningSum, vec1D& path){

    if(pNode)
    {
        path.push_back(pNode->val);
        if( _isLeaf(pNode) && pNode->val + RunningSum == targetSum )
            resl.push_back(path);

        _pathSumRecv(pNode->left, resl, targetSum, RunningSum+pNode->val, path);
        _pathSumRecv(pNode->right, resl, targetSum, RunningSum+pNode->val, path);
        path.pop_back();
    }
    return;
}
bool _isLeaf(TreeNode * pNode){
    return pNode->left == nullptr && pNode->right == nullptr;
}

int main()
{

	vector<int> preOrder = { 5,4,11,7,2,8,13,4,1 };
	vector<int> inOrder = { 7,11,2,4,5,13,8,4,1 };
	TreeNode* root = buildTree(preOrder, inOrder);

	vec2D ret = pathSum(root, 22);
	return 0;
}