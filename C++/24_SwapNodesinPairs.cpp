/* Given a linked list, swap every two adjacent nodes and return its head.
*
* Example:
*
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* Note:
*
* Your algorithm should use only constant extra space.
* You may not modify the values in the list's nodes, only nodes itself may be
* changed.
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

/* one pass solution, run-time O(N), space O(1) */

ListNode* swapPairs(ListNode* head) {
	ListNode dummy(0), *pNode;
	dummy.next = head;
	pNode = &dummy;
	while (pNode->next && pNode->next->next) {

		ListNode * p1 = pNode->next, *p2 = p1->next, *pNext = p2->next;
		pNode->next = p2;
		p2->next = p1;
		p1->next = pNext;
		pNode = p1;
	}
	return dummy.next;
}

int main()
{
	int n = 3;
	vector<ListNode> nums = { 1,2,3,4 };
	for (int i = 0; i < nums.size() - 1; i++)
		nums[i].next = &nums[i + 1];
	ListNode* pRet = swapPairs(&nums[0]);

	vector<int> ans = { 2,1,4,3 }, ret;
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}
	assert(ret == ans);
	return 0;
}
