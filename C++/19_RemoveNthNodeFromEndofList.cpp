/* Given a linked list, remove the n-th node from the end of list and return its head.
*
* Example:
*
* Given linked list: 1->2->3->4->5, and n = 2.
*
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
*
* Given n will always be valid.
*
* Follow up:
*
* Could you do this in one pass?
*
*/

#include <vector>
#include <numeric>
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

/* two pointer, one pass, run-time O(N), memory O(1) */

ListNode* removeNthFromEnd(ListNode* head, int n) {

	ListNode dummy(0);
	dummy.next = head;
	ListNode * pFront = &dummy, *pBack = &dummy;
	while (n--)
		pFront = pFront->next;

	while (pFront->next) {
		pFront = pFront->next;
		pBack = pBack->next;
	}

	ListNode * pNext = pBack->next->next;
	delete pBack->next;
	pBack->next = pNext;

	return dummy.next;
}

int main()
{
	int i =1, total = 5;
	ListNode dummy(0), *pNode = &dummy;
	while (i <= total) {
		pNode->next = new ListNode(i++);
		pNode = pNode->next;
	}

	int n = 2;
	ListNode* pRet = removeNthFromEnd(dummy.next, n);
	vector<int> ret;
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}
	vector<int> ans = { 1,2,3,5 };
	assert(ret == ans);
	return 0;
}
