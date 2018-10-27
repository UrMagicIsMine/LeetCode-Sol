/* Given a linked list, return the node where the cycle begins.
*  If there is no cycle, return null.
*
* Note: Do not modify the linked list.
*
* Follow up:
* Can you solve it without using extra space?
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

/* 1) Use two pointers, pfast and pslow. pslow moves step by step.
* pfast moves two steps at time. If the Linked List has a cycle,
* then pfast and pslow will meet at some point.
*  2) starting from the head pointer, pSlow and pDummy will meet
* at the node where the cycle begins. Can you prove it?
*
* [Prove]: 1> from begining to the node where pSlow == pFast, suppose
*             pSlow traveled k step, then pfast must traveled 2k step,
*             we have (2k - k = N * Len(Cycle) ) ==> k = N * Len(Cycle);
*          2> If we have another pointer travel from head with speed of
*             1 node/step, by the time it reaches the begin of cycle, it
*             must meet pslow there.
*/

ListNode *detectCycle(ListNode *head) {

	bool hasCycle = false;

	ListNode *pFast = head;
	ListNode *pSlow = head;
	ListNode *pDummy = head;
	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;

		if (pFast == pSlow) {
			while (pSlow != pDummy)
			{
				pSlow = pSlow->next;
				pDummy = pDummy->next;
			}
			return pDummy;
		}
	}
	return nullptr;

}

int main()
{
	vector<ListNode> nums =  { 6, 6, 6, 3, 4, 2 };
	for (int i = 0; i < nums.size() - 1; i++)
		nums[i].next = &nums[i+1];
	nums[nums.size() - 1].next = &nums[3];

	ListNode* pRet = detectCycle(&nums[0]);

	return 0;
}
