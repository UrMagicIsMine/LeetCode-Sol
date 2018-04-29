/* Given a linked list and a value x, partition it such that all nodes less than
 x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two
partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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

ListNode* partition_Sln1(ListNode* head, int x) {
	ListNode dummy(0);
	dummy.next = head;
	ListNode *pBack = &dummy;
	while (pBack->next && pBack->next->val < x)
		pBack = pBack->next;

	ListNode *pFront = pBack->next;
	while (pFront && pFront->next) {

		while (pFront->next && pFront->next->val >= x)
			pFront = pFront->next;

		if (pFront->next) {
			ListNode* pTmp = pFront->next;
			ListNode* pNext = pTmp->next;
			pFront->next = pNext;

			ListNode* pBNext = pBack->next;
			pBack->next = pTmp;
			pTmp->next = pBNext;
			pBack = pTmp;
		}
	}
	return dummy.next;
}

ListNode* partition_Sln2(ListNode* head, int x) {
	ListNode node0(0), node1(0);
	ListNode* pS = &node0, *pB = &node1;
	while (head) {

		if (head->val < x) {
			pS->next = head;
			pS = head;
		}
		else {
			pB->next = head;
			pB = head;
		}
		head = head->next;
	}
	pS->next = node1.next;
	pB->next = nullptr;
	return node0.next;
}

int main()
{
	vector<ListNode> nodes = { 1,4,3,2,5,2 };
	for (int i = 0; i < nodes.size() - 1; i++)
		nodes[i].next = &nodes[i + 1];
	int x = 3;
	vector<int> ans = { 1,2,2,4,3,5 };
	vector<int> ret;
	ListNode* pRet = partition_Sln2(&nodes[0], x);
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}
	assert(ret == ans);
	return 0;
}
