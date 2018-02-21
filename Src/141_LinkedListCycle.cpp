/* Given a linked list, determine if it has a cycle in it.
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

/* Use two pointers, pfast and pslow. pslow moves step by step.
* pfast moves two steps at time. If the Linked List has a cycle,
* then pfast and pslow will meet at some point.
*/

bool hasCycle(ListNode *head) {

	ListNode *pFast = head;
	ListNode *pSlow = head;

	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;

		if (pFast == pSlow)
			return true;
	}
	return false;
}

int main()
{
	vector<ListNode> nums =  { 6, 6, 6, 3, 4, 2 };
	for (int i = 0; i < nums.size() - 1; i++)
		nums[i].next = &nums[i+1];
	nums[nums.size() - 1].next = &nums[3];

	bool ret = hasCycle(&nums[0]);

	return 0;
}
