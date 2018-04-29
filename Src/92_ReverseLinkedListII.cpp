/* Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 <= m <= n <= length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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

ListNode* reverseBetween_Sln1(ListNode* head, int m, int n) {
	ListNode dummy(0);
	dummy.next = head;
	m = m - 1;
	ListNode*pf = &dummy, *pb = &dummy;
	while (m--)
		pb = pb->next;
	while (n--)
		pf = pf->next;

	ListNode* pfNext = pf->next;
	pf->next = nullptr;
	pf = pb->next;
	ListNode *p1 = pfNext, *tmp;
	while (pf) {
		tmp = pf->next;
		pf->next = p1;
		p1 = pf;
		pf = tmp;
	}
	pb->next = p1;
	return dummy.next;
}

ListNode* reverseBetween_Sln2(ListNode* head, int m, int n) {
	ListNode dummy(0);
	dummy.next = head;
	int i = m - 1;
	ListNode*pf = nullptr, *pb = &dummy;
	while (i--)
		pb = pb->next;
	pf = pb->next;

	for (i = 0; i < n - m; i++) {
		ListNode* ptmp = pf->next;
		pf->next = ptmp->next;
		ptmp->next = pb->next;
		pb->next = ptmp;
	}
	return dummy.next;
}

int main()
{
	vector<ListNode> nodes = { 1,2,3,4,5 };
	for (int i = 0; i < nodes.size() - 1; i++)
		nodes[i].next = &nodes[i + 1];
	int m = 2, n = 4;
	vector<int> ans = { 1,4,3,2,5 };
	vector<int> ret;
	ListNode* pRet = reverseBetween_Sln2(&nodes[0], m, n);
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}
	assert(ret == ans);
	return 0;
}
