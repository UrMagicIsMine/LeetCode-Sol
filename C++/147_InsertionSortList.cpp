/* Sort a linked list using insertion sort.
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

ListNode* _findInsertPos(ListNode* pNode, ListNode* pIter)
{
	while (pNode->next->val > pIter->next->val)
		pIter = pIter->next;
	return pIter;
}

ListNode* insertionSortList(ListNode* head) {

	if (!head)
		return nullptr;

	ListNode dummy(0);
	dummy.next = head;
	ListNode * pNode = head;

	/* start from the second node for insertion*/
	while (pNode->next)
	{
		/* if next node value is smaller than current node value, insert  */
		if (pNode->next->val < pNode->val) {
			/* find the location to insert */
			ListNode *pInsert = _findInsertPos(pNode, &dummy);
			/* remove pNode->next node */
			ListNode *pTmp = pNode->next;
			/* connect pNode to the node after removed node */
			pNode->next = pTmp->next;
			/* save the next node at inserted location */
			ListNode *pINext = pInsert->next;
			/* do insertion and connection */
			pInsert->next = pTmp;
			pTmp->next = pINext;
			/* pNode->next automatically points to next node for processing */
		}
		else
			pNode = pNode->next;
	}
	return dummy.next;
}

int main()
{
	vector<ListNode> NodeVec = { 4, 7, 2, 9, 1 };
	for (auto i = 0; i < NodeVec.size() - 1; i++)
		NodeVec[i].next = &NodeVec[i + 1];
	ListNode* pRet = insertionSortList(&NodeVec[0]);
	return 0;
}
