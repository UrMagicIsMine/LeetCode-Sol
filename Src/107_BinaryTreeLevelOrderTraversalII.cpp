/* Given a binary tree, return the bottom-up level order traversal of its
* nodes' values. (ie, from left to right, level by level from leaf to root).
*
* For example:
* Given binary tree [3,9,20,null,null,15,7],
* 3
* / \
* 9  20
* /  \
* 15   7
* return its bottom-up level order traversal as:
* [
* [15,7],
* [9,20],
* [3]
* ]
*/
#include <vector>
#include <queue>

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
typedef vector<int> vec1D;
typedef vector<vec1D> vec2D;

vector<vector<int>> levelOrderBottom(TreeNode* root) {

	vec2D reslTmp;
	if (root) {
		queue<TreeNode*> queNode;
		queNode.push(root);

		while (!queNode.empty()) {

			vec1D vTmp;
			int N = queNode.size();
			vTmp.reserve(2 * N);
			TreeNode * pTmp = nullptr;
			while (N--) {

				pTmp = queNode.front();
				if (pTmp->left)
					queNode.push(pTmp->left);
				if (pTmp->right)
					queNode.push(pTmp->right);

				vTmp.push_back(pTmp->val);
				queNode.pop();
			}
			reslTmp.push_back(std::move(vTmp));
		}
	}
	return vec2D(reslTmp.rbegin(), reslTmp.rend());
}

int main()
{
	vector<TreeNode> vec = { 3,9,20,15,7 };
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vec[2].right = &vec[4];

	vec2D ret = levelOrderBottom(&vec[0]);
	return 0;
}
