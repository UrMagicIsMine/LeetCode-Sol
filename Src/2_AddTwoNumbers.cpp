/* You are given two non-empty linked lists representing two non-negative integers.
* The digits are stored in reverse order and each of their nodes contain a single
* digit. Add the two numbers and return it as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the number
* 0 itself.
*
* Example
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* Explanation: 342 + 465 = 807.
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode dummy(0);
	ListNode * pNode = &dummy;
	int carry = 0;
	while (l1 || l2 || carry) {

		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
		carry = sum > 9 ? 1 : 0;
		pNode->next = new ListNode(sum % 10);
		l1 = l1 ? l1->next : nullptr;
		l2 = l2 ? l2->next : nullptr;
		pNode = pNode->next;
	}
	return dummy.next;
}

int main()
{
	vector<ListNode> nums1 = { 2, 7, 3, 9 };
	vector<ListNode> nums2 = { 1, 1, 1, 1 };
	vector<int> ans = { 3,8,4,0,1 };
	for (int i = 0; i < (int)nums1.size() - 1; i++) {
		nums1[i].next = &nums1[i + 1];
		nums2[i].next = &nums2[i + 1];
	}
	ListNode* pNode = addTwoNumbers(&nums1[0], &nums2[0]);
	vector<int> resl;
	while (pNode) {
		resl.push_back(pNode->val);
		pNode = pNode->next;
	}
	assert(resl == ans);
	return 0;
}
