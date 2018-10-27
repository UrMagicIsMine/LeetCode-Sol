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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> resl;
		if(!root)
				return resl;
		queue<TreeNode*> QueNodes;
		QueNodes.push(root);
		while(!QueNodes.empty()){
				int N = QueNodes.size();
				vector<int> levels;
				while(N--){
						TreeNode* pNode = QueNodes.front();
						QueNodes.pop();
						if(pNode->left)
								QueNodes.push(pNode->left);
						if(pNode->right)
								QueNodes.push(pNode->right);
						levels.push_back(pNode->val);
				}
				resl.emplace_back(levels);
		}
		reverse(resl.begin(), resl.end());
		return resl;
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
