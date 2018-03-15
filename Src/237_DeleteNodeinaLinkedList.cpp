/* Write a function to delete a node (except the tail) in a singly linked list,
* given only access to that node.
*
* Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node
* with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*
*/

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

void deleteNode(ListNode* node) {

	node->val = node->next->val;
	ListNode * p = node->next;
	node->next = p->next;
	delete p;

}

int main()
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);

	p1->next = p2;
	p2->next = p3;

	deleteNode(p2);

	assert(p1->next->val == 3);
	return 0;
}
