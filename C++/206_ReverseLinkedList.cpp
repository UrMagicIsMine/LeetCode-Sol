/* Reverse a singly linked list.
*/

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

ListNode* reverseList(ListNode* head) {

	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* pNext = head->next;
	head->next = nullptr;

	while (pNext) {
		ListNode *pTmp = pNext;
		pNext = pNext->next;
		pTmp->next = head;
		head = pTmp;
	}
	return head;
}

int main()
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);

	p1->next = p2;
	p2->next = p3;

	ListNode* pHead = reverseList(p1);

	assert(pHead->val == 3);
	assert(pHead->next->val == 2);
	assert(pHead->next->next->val == 1);
	return 0;
}
