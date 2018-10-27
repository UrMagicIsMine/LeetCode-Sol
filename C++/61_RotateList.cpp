/* Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
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

ListNode* rotateRight(ListNode* head, int k) {

	if (head == nullptr)
		return head;

	ListNode dummy(0);
	dummy.next = head;
	ListNode *pfast = &dummy, *pslow = &dummy;
	int cnt = 0;
	while (head) {
		head = head->next;
		cnt++;
	}
	k = k % cnt;
	if (k == 0)
		return dummy.next;

	while (k--)
		pfast = pfast->next;

	while (pfast->next) {
		pfast = pfast->next;
		pslow = pslow->next;
	}

	pfast->next = dummy.next;
	dummy.next = pslow->next;
	pslow->next = nullptr;
	return dummy.next;
}

int main()
{
	vector<ListNode> nums = { 0,1,2 };
	for (int i = 0; i < nums.size() - 1; i++)
		nums[i].next = &nums[i + 1];
	int k = 4;
	ListNode* pRet = rotateRight(&nums[0], k);
	vector<int> ans = { 2,0,1 };
	vector<int> ret;
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}
	assert(ret == ans);
	return 0;
}
