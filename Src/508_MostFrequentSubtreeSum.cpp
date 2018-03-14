/* Given the root of a tree, you are asked to find the most frequent subtree sum.
* The subtree sum of a node is defined as the sum of all the node values formed
* by the subtree rooted at that node (including the node itself). So what is the
* most frequent subtree sum value? If there is a tie, return all the values with
* the highest frequency in any order.
*
* Examples 1
* Input:
*
*   5
*  /  \
* 2   -3
* return [2, -3, 4], since all the values happen only once, return all of them
* in any order.
* Examples 2
* Input:
*
*   5
*  /  \
* 2   -5
* return [2], since 2 happens twice, however -5 only occur once.
* Note: You may assume the sum of values in any subtree is in the range of 32-bit
* signed integer.
*/

#include <unordered_map>
#include <vector>
#include <algorithm>
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

int _getSum(TreeNode* root, unordered_map<int, int>& sumFreq, int & maxSum) {

	if (root) {
		int sum = root->val + _getSum(root->left, sumFreq, maxSum)
							+ _getSum(root->right, sumFreq, maxSum);
		int freq = (++sumFreq[sum]);
		maxSum = max(maxSum, freq);
		return sum;
	}
	return 0;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
	unordered_map<int, int> sumFreq;
	int maxSum = 0;
	_getSum(root, sumFreq, maxSum);
	vector<int> resl;
	for (auto it = sumFreq.begin(); it != sumFreq.end(); it++)
		if (it->second == maxSum)
			resl.push_back(it->first);

	return resl;

}

int main()
{
	vector<TreeNode> treenode = { 5,2,-3 };
	treenode[0].left = &treenode[1];
	treenode[0].right = &treenode[2];
	vector<int> ans = {2,-3,4};
	TreeNode * root = &treenode[0];
	vector<int> ret = findFrequentTreeSum(root);
	assert(ret == ans);

	return 0;
}
