/* Merge k sorted linked lists and return it as one sorted list. Analyze and
* describe its complexity.
*
* Example:
*
* Input:
* [
*   1->4->5,
*   1->3->4,
*   2->6
* ]
* Output: 1->1->2->3->4->4->5->6
*/

#include <vector>
#include <queue>
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

ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode dummy(0), *pNode = &dummy;

	auto comp = [](ListNode *p1, ListNode *p2) {
		return p1->val > p2->val;
	};

	priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pNodesHeap(comp);
	for (auto p : lists) {
		if (p)
			pNodesHeap.push(p);
	}

	while (!pNodesHeap.empty()) {
		pNode->next = pNodesHeap.top();
		pNodesHeap.pop();
		ListNode * tmp = pNode->next->next;
		pNode = pNode->next;
		if (tmp)
			pNodesHeap.push(tmp);
	}
	return dummy.next;
}

int main()
{
	vector<vector<ListNode>> nums = { {1,4,5},{1,3,4},{2,6} };
	vector<ListNode*> lists;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[i].size() - 1; j++)
			nums[i][j].next = &nums[i][j + 1];
		lists.push_back(&nums[i][0]);
	}

	ListNode* pNode = mergeKLists(lists);
	vector<int> ret;
	while (pNode) {
		ret.push_back(pNode->val);
		pNode = pNode->next;
	}

	vector<int> ans = { 1,1,2,3,4,4,5,6 };
	assert(ans == ret);
	return 0;
}
