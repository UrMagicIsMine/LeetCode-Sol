/* Given a singly linked list L: L0->L1->...->Ln-1->Ln,
* reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->…
*
* You must do this in-place without altering the nodes' values.
*
* For example,
* Given {1,2,3,4}, reorder it to {1,4,2,3}.
*
*/
#include <vector>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void advance(ListNode*& pNode, int i)
{
	while (i--)
		pNode = pNode->next;
	return;
}

void reorderList(ListNode* head) {

	/* Count the total node in the list */

	int N = 0;
	ListNode * pIter = head;
	while (pIter) {
		N++;
		pIter = pIter->next;
	}

	if (N <= 2)
		return;

	/* Split the list to 2 lists in the middle */

	ListNode * pTail = head;
	advance(pTail, (N - 1) / 2);
	ListNode *pHeadRm = pTail->next;
	pTail->next = nullptr;

	/* Reverse the second list in place */

	ListNode* pHead2 = nullptr;
	while (pHeadRm) {
		ListNode* pTmp = pHeadRm;
		pHeadRm = pHeadRm->next;
		pTmp->next = pHead2;
		pHead2 = pTmp;
	}

	/* connect list1 and list2 in zigzag fashion */
	ListNode* p1 = head;
	ListNode* p2 = pHead2;
	while (p1 && p2) {
		ListNode* p1Next = p1->next;
		ListNode* p2Next = p2->next;
		p1->next = p2;
		p2->next = p1Next;
		p1 = p1Next;
		p2 = p2Next;
	}
	return;

}

int main()
{
	vector<ListNode> nums =  { 1, 2, 3, 4, 5, 6, 7 };
	for (int i = 0; i < nums.size() - 1; i++)
		nums[i].next = &nums[i+1];

	reorderList(&nums[0]);

	return 0;
}
