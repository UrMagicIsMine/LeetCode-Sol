/* Write a program to find the node at which the intersection of two singly linked lists begins.
*
*
* For example, the following two linked lists:
*
* A:           a1 -> a2
*                      ->
*                         c1 -> c2 -> c3
*                      ->
* B:     b1 -> b2 -> b3
* begin to intersect at node c1.
*
*
* Notes:
*  -- If the two linked lists have no intersection at all, return null.
*  -- The linked lists must retain their original structure after the function returns.
*  -- You may assume there are no cycles anywhere in the entire linked structure.
*  -- Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode_Sol1(ListNode *headA, ListNode *headB) {

	if (!headA || !headB)
		return nullptr;

	/* Step 1: count the length of ListA and ListB */

	int lenA = 1;
	ListNode * tailA = headA;
	while (tailA->next) {
		lenA++;
		tailA = tailA->next;
	}

	int lenB = 1;
	ListNode * tailB = headB;
	while (tailB->next) {
		lenB++;
		tailB = tailB->next;
	}

	/* Step 2: connect the tail to the head of the short list
	*   in order to make a circle;
	*/

	ListNode* tail = lenA > lenB ? tailB : tailA;
	ListNode* head_s = lenA > lenB ? headB : headA;
	ListNode* head_l = lenA > lenB ? headA : headB;
	tail->next = head_s;

	if (!head_l->next || !head_l->next->next) {
		tail->next = nullptr;
		return nullptr;
	}

	/* Step 3: two pointer (fast and slow) reach to the same place,
	*   then there must be an intersection point;
	*/

	ListNode* pSlow = head_l->next;
	ListNode* pFast = head_l->next->next;

	while (pFast && pFast->next)
	{
		if (pFast == pSlow)
			break;
		else
		{
			pFast = pFast->next->next;
			pSlow = pSlow->next;
		}
	}

	if (pFast != pSlow) {
		tail->next = nullptr;
		return nullptr;
	}

	/* Step 4: Mark simultaneously from the beginning of the longer
	*   list head and the meeting point from step 3, the next meeting
	*   point must be the starting of circle, which is the intersection;
	*/
	ListNode * pTarget = head_l;
	while (pSlow != pTarget) {
		pSlow = pSlow->next;
		pTarget = pTarget->next;
	}
	tail->next = nullptr;
	return pTarget;
}

ListNode *getIntersectionNode_Sol2(ListNode *headA, ListNode *headB) {

	if (!headA || !headB)
		return nullptr;

	/* Step 1: count the length of ListA and ListB */

	int lenA = 0;
	ListNode * pNodeA = headA;
	while (pNodeA) {
		lenA++;
		pNodeA = pNodeA->next;
	}

	int lenB = 0;
	ListNode * pNodeB = headB;
	while (pNodeB) {
		lenB++;
		pNodeB = pNodeB->next;
	}

	/* Step 2: March forward until the two list have the same remaining length */

	while (lenA > lenB)	{
		lenA--;
		headA = headA->next;
	}
	while (lenB > lenA)	{
		lenB--;
		headB = headB->next;
	}

	/* Step 3: March forward simultaneously for the two list
	* The first meeting point must be the intersection or nullptr */

	while (headA != headB) {
		headA = headA->next;
		headB = headB->next;
	}
	return headA;
}

int main()
{
	vector<ListNode> l1 = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < l1.size() - 1; i++)
		l1[i].next = &l1[i + 1];
	ListNode * pRet1 = getIntersectionNode_Sol1(&l1[0], &l1[0]);
	assert(pRet1->val == 1);
	ListNode * pRet2 = getIntersectionNode_Sol2(&l1[0], &l1[0]);
	assert(pRet1->val == 1);
	return 0;
}
