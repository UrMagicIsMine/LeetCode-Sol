/*
* Sort a linked list in O(n log n) time using constant space complexity.
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
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * _mergeSort(ListNode* pHead, int N) {

	if (N<2)
		return pHead;

	ListNode * ptmp = pHead;
	int adv = N / 2 - 1;
	while (adv--) {
		ptmp = ptmp->next;
	}

	ListNode * ph1 = pHead;
	ListNode * ph2 = ptmp->next;
	ptmp->next = nullptr;

	ph1 = _mergeSort(ph1, N / 2);
	ph2 = _mergeSort(ph2, N - N / 2);

	ListNode dummy(0);
	ListNode * pNode = &dummy;
	while (ph1 && ph2) {
		ListNode * & p = (ph1->val < ph2->val) ? ph1 : ph2;
		pNode->next = p;
		p = p->next;
		pNode = pNode->next;
	}
	pNode->next = ph1 ? ph1 : ph2;
	return dummy.next;
}

ListNode* sortList(ListNode* head) {

	int N = 0;
	ListNode *pNode = head;
	while (pNode) {
		N++;
		pNode = pNode->next;
	}
	return _mergeSort(head, N);

}

int main()
{
	vector<ListNode> vecNode = { 1,2,4,3,7,3,2 };
	for (int i = 0; i < vecNode.size() - 1; i++)
		vecNode[i].next = &vecNode[i + 1];

	ListNode* pNode = sortList(&vecNode[0]);

	vector<int> ret(vecNode.size(), 0);
	vector<int> ans = { 1,2,2,3,3,4,7 };
	int i = 0;
	while (pNode) {
		ret[i++] = pNode->val;
		pNode = pNode->next;
	}
	assert(ret == ans);
	return 0;
}
