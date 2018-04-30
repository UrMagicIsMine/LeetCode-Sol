/* Given an integer n, generate all structurally unique BST's (binary search trees)
that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include <vector>
#include <map>
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

vector<TreeNode*> _genTrees(map<pair<int, int>, vector<TreeNode*>>&treeMaps, int beg, int end) {

	vector<TreeNode*> resl;

	if (treeMaps.find(make_pair(beg, end)) != treeMaps.end())
		return treeMaps[make_pair(beg, end)];

	if (beg > end)
		resl.push_back(nullptr);
	else {
		for (int i = beg; i <= end; i++) {
			vector<TreeNode*> left = _genTrees(treeMaps, beg, i - 1);
			vector<TreeNode*> rght = _genTrees(treeMaps, i + 1, end);
			for (auto l : left) {
				for (auto r : rght) {
					TreeNode * root = new TreeNode(i);
					root->left = l;
					root->right = r;
					resl.push_back(root);
				}
			}
		}
	}

	treeMaps[make_pair(beg, end)] = resl;
	return resl;
}

vector<TreeNode*> generateTrees(int n) {

	if (n == 0)
		return vector<TreeNode*>();

	map<pair<int, int>, vector<TreeNode*>> treeMaps;
	return _genTrees(treeMaps, 1, n);
}

int main()
{
	int n = 3;
	vector<TreeNode*> trees = generateTrees(n);
	//assert(ret_itr == ans);
	return 0;
}
