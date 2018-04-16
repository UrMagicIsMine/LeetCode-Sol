/* Given a sorted linked list, delete all duplicates such that each element appear
* only once.
*
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
*/

#include <vector>
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

/* One pass solution, run-time O(N), space O(1)
*/

ListNode* deleteDuplicates(ListNode* head) {

	if (head == nullptr)
		return head;
	ListNode * pNode = head, *pNext = head->next;
	while (pNode && pNext) {

		if (pNode->val == pNext->val) {
			// delete pNode->next
			ListNode *pTmp = pNext->next;
			pNode->next = pTmp;
			delete pNext;
			pNext = pTmp;
		}
		else {
			pNode = pNext;
			pNext = pNext->next;
		}

	}
	return head;
}

int main()
{
	ListNode dummy(0), *pNode = &dummy;
	vector<int> nums = { 0,1,2,3,3,4,4,5,6,8,9 };
	for (int i = 0; i < nums.size(); i++) {
		pNode->next = new ListNode(nums[i]);
		pNode = pNode->next;
	}
	ListNode * pRet = deleteDuplicates(dummy.next);
	vector<int> ret;
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}
	vector<int> ans = { 0,1,2,3,4,5,6,8,9 };
	assert(ret == ans);
	return 0;
}
