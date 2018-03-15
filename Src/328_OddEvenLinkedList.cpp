/* Given a singly linked list, group all odd nodes together followed by the even
* nodes. Please note here we are talking about the node number and not the value
* in the nodes.
*
* You should try to do it in place. The program should run in O(1) space complexity
* and O(nodes) time complexity.
*
* Example:
* Given 1->2->3->4->5->NULL,
* return 1->3->5->2->4->NULL.
*
* Note:
* The relative order inside both the even and odd groups should remain as it was
* in the input.
* The first node is considered odd, the second node even and so on ...
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

ListNode* oddEvenList(ListNode* head) {

	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode dummyOdd(0);
	dummyOdd.next = head;
	ListNode *pOdd = head;

	ListNode dummyEvn(0);
	dummyEvn.next = head->next;
	ListNode *pEven = head->next;

	while (pEven && pEven->next) {

		pOdd->next = pEven->next;
		pOdd = pOdd->next;

		pEven->next = pOdd->next;
		pEven = pEven->next;
	}
	pOdd->next = dummyEvn.next;
	return dummyOdd.next;
}

int main()
{
	vector<ListNode> num1 = { 1,2,3,4,5,6,7,8 };
	for (int i = 0; i < int(num1.size()) - 1; i++)
		num1[i].next = &num1[i+1];
	vector<int> ans = { 1,3,5,7,2,4,6,8 };
	ListNode* ret = oddEvenList(&num1[0]);
	vector<int> retv;
	while (ret) {
		retv.push_back(ret->val);
		ret = ret->next;
	}

	assert(retv == ans);
	return 0;
}
