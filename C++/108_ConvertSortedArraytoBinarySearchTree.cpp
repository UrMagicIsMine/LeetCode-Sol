/* Given an array where elements are sorted in ascending order,
* convert it to a height balanced BST.
*
* For this problem, a height-balanced binary tree is defined as a binary tree
* in which the depth of the two subtrees of every node never differ by more than 1.
*
*
* Example:
*
* Given the sorted array: [-10,-3,0,5,9],
*
* One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
*
*       0
*      / \
*    -3   9
*    /   /
*  -10  5
*
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

TreeNode* sortArraytoBST(const vector<int>& nums, int ift, int ibk) {

	if (ift <= ibk) {
		int imid = (ift + ibk) / 2;
		TreeNode * pNode = new TreeNode(nums[imid]);
		pNode->left = sortArraytoBST(nums, ift, imid - 1);
		pNode->right = sortArraytoBST(nums, imid + 1, ibk);
		return pNode;
	}
	else
		return nullptr;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {

	return sortArraytoBST(nums, 0, nums.size() - 1);
}

int main()
{
	vector<int> vec = { -10,-3,0,5,9 };

	TreeNode* ret = sortedArrayToBST(vec);
	return 0;
}
