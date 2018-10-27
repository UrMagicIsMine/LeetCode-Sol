/*Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include <vector>
#include <stack>
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


ListNode* removeElements(ListNode* head, int val) {

	ListNode dummy(0);
	dummy.next = head;

	ListNode * pNode = &dummy;
	while (pNode->next) {

		if (pNode->next->val == val) {
			ListNode * pNext = pNode->next->next;
			delete pNode->next;
			pNode->next = pNext;
		}
		else
			pNode = pNode->next;
	}
	return dummy.next;
}

int main()
{
	ListNode *pHead = new ListNode(1);
	ListNode *p1 = new ListNode(2);
	pHead->next = p1;
	ListNode* ret = removeElements(pHead, 2);
	assert(ret->next == nullptr);
	return 0;
}
