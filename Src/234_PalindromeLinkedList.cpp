/* Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/
#include<vector>
#include<algorithm>
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

/*
* 1) count the number of nodes;
* 2) reverse the first half nodes;
* 3) compare two lists;
*/

bool isPalindrome(ListNode* head) {

	int N = 0;
	ListNode *pNode = head;
	while (pNode) {
		N++;
		pNode = pNode->next;
	}
	if (N <= 1)
		return true;

	int half = N / 2;

	pNode = head;
	ListNode *pheadRev = nullptr;
	ListNode *ptmp;
	while (half--) {
		ptmp = pNode->next;
		pNode->next = pheadRev;
		pheadRev = pNode;
		pNode = ptmp;
	}

	if (N % 2)
		pNode = pNode->next;
	half = N / 2;
	while (half--) {

		if (pNode->val != pheadRev->val)
			return false;
		pNode = pNode->next;
		pheadRev = pheadRev->next;
	}
	return true;
}

int main()
{
	vector<ListNode> ListNodes = { 1,2,3,2,1 };
	for (int i = 0; i < ListNodes.size()-1; i++) {

		ListNodes[i].next = &ListNodes[i + 1];
	}
	bool ret = isPalindrome(&ListNodes[0]);
	bool ans = true;
	assert(ret == ans);
	return 0;
}
