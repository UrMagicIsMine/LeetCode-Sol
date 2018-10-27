/* Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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

ListNode* deleteDuplicates(ListNode* head) {
	ListNode dummy(0);
	dummy.next = head;
	ListNode *pFront = head;
	ListNode *pBack = &dummy;

	while (pFront) {

		while (pFront->next && pFront->next->val == pFront->val) {
			ListNode *pTmp = pFront;
			pFront = pFront->next;
			//delete pTmp;
		}

		if (pBack->next == pFront) {
			pBack = pBack->next;
			pFront = pFront->next;
		}
		else {
			ListNode *pTmp = pFront;
			pFront = pFront->next;
			pBack->next = pFront;
			//delete pTmp;
		}
	}
	return dummy.next;
}

int main()
{
	vector<ListNode> nodes = { 1,2,3,3,4,4,5 };
	for (int i = 0; i < nodes.size() - 1; i++)
		nodes[i].next = &nodes[i + 1];
	vector<int> ans = { 1,2,5 };
	vector<int> ret;
	ListNode* pRet = deleteDuplicates(&nodes[0]);
	while (pRet) {
		ret.push_back(pRet->val);
		pRet = pRet->next;
	}

	assert(ret == ans);
	return 0;
}
