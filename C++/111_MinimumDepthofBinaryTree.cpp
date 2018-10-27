/* Given a binary tree, find its minimum depth.
*
*  The minimum depth is the number of nodes along the shortest path
* from the root node down to the nearest leaf node.
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

/**
* This function check the depth of the node recursively
* if it is null, minDepth(p) = 0;
* if it has 1 child, minDepth(p) = minDepth(child) + 1
* if it has 2 child, minDepth(p) = minDepth(lchild,rchild) + 1
*/

int minDepth_Sln1(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL) return minDepth_Sln1(root->right) + 1;
	if (root->right == NULL) return minDepth_Sln1(root->left) + 1;
	return min(minDepth_Sln1(root->left), minDepth_Sln1(root->right)) + 1;
}

int minDepth_Sln2(TreeNode* root) {
		if(!root)
				return 0;
		queue<TreeNode*> QueNodes;
		QueNodes.push(root);
		int lvl = 1;
		while(!QueNodes.empty()){

				int N = QueNodes.size();
				while(N--){

						TreeNode* p = QueNodes.front();
						QueNodes.pop();
						if(!p->left && !p->right)
								return lvl;
						if(p->left)
								QueNodes.push(p->left);
						if(p->right)
								QueNodes.push(p->right);

				}
				lvl++;
		}
		return -1;
}

int main()
{

	vector<TreeNode> vec = { 3,9,20,15,7 };
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vec[2].right = &vec[4];

	int ret = minDepth_Sln2(&vec[0]);
	return 0;
}
