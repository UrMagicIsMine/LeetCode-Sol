/* You are given two non-empty linked lists representing two non-negative integers.
* The most significant digit comes first and each of their nodes contain a single
* digit. Add the two numbers and return it as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the
* number 0 itself.
*
* Follow up:
* What if you cannot modify the input lists? In other words, reversing the lists
* is not allowed.
*
* Example:
*
* Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 8 -> 0 -> 7
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	l1 = reverseList(l1);
	l2 = reverseList(l2);
	ListNode dummy(0);
	ListNode *pHead = &dummy;
	bool adv = 0;
	while (l1 || l2 || adv) {

		int tmp = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + adv;
		if (tmp > 9) {
			tmp = tmp - 10;
			adv = 1;
		}
		else
			adv = 0;

		pHead->next = new ListNode(tmp);
		pHead = pHead->next;
		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}

	return reverseList(dummy.next);
}

int main()
{
	vector<ListNode> num1 = { 7,2,4,3 };
	for (int i = 0; i < int(num1.size()) - 1; i++)
		num1[i].next = &num1[i+1];

	vector<ListNode> num2 = { 5,6,4 };
	for (int i = 0; i < int(num2.size()) - 1; i++)
		num2[i].next = &num2[i + 1];
	vector<int> ans = { 7,8,0,7 };

	ListNode* ret = addTwoNumbers(&num1[0], &num2[0]);
	vector<int> retv;
	while (ret) {
		retv.push_back(ret->val);
		ret = ret->next;
	}

	assert(retv == ans);
	return 0;
}
