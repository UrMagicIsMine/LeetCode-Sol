/* Merge two sorted linked lists and return it as a new list. The new list should
* be made by splicing together the nodes of the first two lists.
*
* Example:
*
* Input: 1->2->4, 1->3->4
* Output: 1->1->2->3->4->4
* 
*/

#include <vector>
#include <string>
#include <cassert>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
* Simple one pass solution, run-time O(N), space O(1)
*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	ListNode dummy(0), *pNode = &dummy;
	while (l1 && l2) {
		ListNode *& pTmp = (l1->val < l2->val) ? l1 : l2;
		pNode->next = pTmp;
		pNode = pNode->next;
		pTmp = pTmp->next;
	}
	pNode->next = l1 ? l1 : l2;
	return dummy.next;
}

int main()
{
	vector<ListNode> nums1 = { 1,2,4 }, nums2 = { 1,3,4 };
	for (int i = 0; i < nums1.size() - 1; i++)
		nums1[i].next = &nums1[i + 1];
	for (int i = 0; i < nums2.size() - 1; i++)
		nums2[i].next = &nums2[i + 1];

	ListNode * pRet = mergeTwoLists(&nums1[0], &nums2[0]);
	vector<int> ans = { 1,1,2,3,4,4 }, ret;
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}
	assert(ret == ans);
	return 0;
}
