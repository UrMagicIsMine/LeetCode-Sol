/* Given a singly linked list where elements are sorted in ascending
* order, convert it to a height balanced BST.
*
* For this problem, a height-balanced binary tree is defined as a binary
* tree in which the depth of the two subtrees of every node never differ by more than 1.
*
*
* Example:
*
* Given the sorted linked list: [-10,-3,0,5,9],
*
*  One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
*
*       0
*      / \
*    -3   9
*    /   /
*  -10  5
*
*/
#include <vector>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/******************************************************************************/
/* convert through vector, random-iterator : memory O(N), run-time O(N) */
TreeNode* _sortArraytoBST(const vector<int>& nums, int ift, int ibk) {

	if (ift <= ibk) {
		int imid = (ift + ibk) / 2;
		TreeNode * pNode = new TreeNode(nums[imid]);
		pNode->left = _sortArraytoBST(nums, ift, imid - 1);
		pNode->right = _sortArraytoBST(nums, imid + 1, ibk);
		return pNode;
	}
	else
		return nullptr;
}

TreeNode* sortedListToBST_RI(ListNode* head) {

	vector<int> nums;
	while (head) {
		nums.push_back(head->val);
		head = head->next;
	}
	return _sortArraytoBST(nums, 0, nums.size() - 1);
}

/******************************************************************************/
/* in-place convert: memory O(1), run-time O(N) */
TreeNode* _sortedListToBST(ListNode* &head, int start, int end) {
    if (start > end)
        return nullptr;
    int mid = start + (end-start)/2;
    TreeNode *left_child = _sortedListToBST(head, start, mid-1);
    TreeNode *node = new TreeNode(head->val);
    node->left = left_child;
    head = head->next;
    node->right = _sortedListToBST(head, mid+1, end);
    return node;
}
TreeNode* sortedListToBST_IP(ListNode* head) {
    if (!head)
        return nullptr;

    ListNode *tmp = head;
    int sz = 0;
    while (tmp) {
        sz++;
        tmp = tmp->next;
    }

    return _sortedListToBST(head, 0, sz-1);
}
/******************************************************************************/

int main()
{
	vector<ListNode> vec = { -10,-3,0,5,9 };
	for (int i = 0; i < vec.size() - 1; i++)
		vec[i].next = &vec[i + 1];

  /* solution 1: through vector, random-iterator */
	TreeNode* ret1 = sortedListToBST_RI(&vec[0]);
  /* solution 2: through vector, in-place */
  TreeNode* ret2 = sortedListToBST_IP(&vec[0]);
	return 0;
}
