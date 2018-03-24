/* You are given a binary tree in which each node contains an integer value.
*
* Find the number of paths that sum to a given value.
*
* The path does not need to start or end at the root or a leaf, but it must go
* downwards (traveling only from parent nodes to child nodes).
*
* The tree has no more than 1,000 nodes and the values are in the range
* -1,000,000 to 1,000,000.
*
* Example:
*
* root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
*
*       10
*      /  \
*     5   -3
*    / \    \
*   3   2   11
*  / \   \
* 3  -2   1
*
* Return 3. The paths that sum to 8 are:
*
* 1.  5 -> 3
* 2.  5 -> 2 -> 1
* 3. -3 -> 11
*/
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Recursive solution */

void _DFS(TreeNode *pNode, vector<int>&Parents, int target, int& num) {

	if (pNode) {

		Parents.push_back(pNode->val);
		int N = Parents.size();
		int sum = pNode->val;
		if (sum == target)
			num++;
		for (int i = N - 2; i >= 0; i--) {
			sum += Parents[i];
			if (sum == target)
				num++;
		}

		_DFS(pNode->left, Parents, target, num);
		_DFS(pNode->right, Parents, target, num);

		Parents.pop_back();

	}
	return;
}

int pathSum(TreeNode* root, int sum) {
	vector<int> Parents;
	int num = 0;
	_DFS(root, Parents, sum, num);
	return num;
}

int main()
{
	vector<TreeNode> btree = { 1,1,1,2 };
	btree[0].right = &btree[1];
	btree[1].right = &btree[2];
	btree[2].left = &btree[3];
	int ans = 3;
	int ret = pathSum(&btree[0], 2);
	assert(ret == ans);
	return 0;
}
