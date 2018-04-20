/* Given a linked list, reverse the nodes of a linked list k at a time and return
* its modified list.
*
* k is a positive integer and is less than or equal to the length of the linked
* list. If the number of nodes is not a multiple of k then left-out nodes in the
* end should remain as it is.
*
* Example:
*
* Given this linked list: 1->2->3->4->5
*
* For k = 2, you should return: 2->1->4->3->5
*
* For k = 3, you should return: 3->2->1->4->5
*
* Note:
*
* Only constant extra memory is allowed.
* You may not alter the values in the list's nodes, only nodes itself may be
* changed.
*/

#include <vector>
#include <algorithm>
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

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k == 1)
		return head;

	ListNode dummy(0), *pNew = &dummy, *pHeadOrg = head;

	while (pHeadOrg) {

		// advance K element;
		ListNode *pNextHead = pHeadOrg;
		int i = k;
		while (pNextHead && i--) {
			pNextHead = pNextHead->next;
		}
		if (i > 0) {
			break;
		}

		// reverse K element
		ListNode * p1 = pHeadOrg, *pNewHead = nullptr;
		while (p1 != pNextHead) {
			ListNode* pNext = p1->next;
			p1->next = pNewHead;
			pNewHead = p1;
			p1 = pNext;
		}
		pNew->next = pNewHead;
		pNew = pHeadOrg;
		pHeadOrg = pNextHead;
	}
	pNew->next = pHeadOrg;
	return dummy.next;
}

int main()
{
	vector<ListNode> nums = { 1,2,3,4,5 };
	int k = 2;
	vector<int> ans = { 2, 1, 4, 3, 5 };
	for (int i = 0; i < nums.size() - 1; i++)
		nums[i].next = &nums[i + 1];
	ListNode* pRet = reverseKGroup(&nums[0], k);
	vector<int> ret;
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}
	assert(ret == ans);
	return 0;
}
