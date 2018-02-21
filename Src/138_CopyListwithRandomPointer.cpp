/* A linked list is given such that each node contains an additional
* random pointer which could point to any node in the list or null.
*
* Return a deep copy of the list.
*
*/
#include <vector>

using namespace std;

/**
* Definition for singly-linked list with a random pointer.
*/
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {

	RandomListNode* pNode = head;

	/* step 1: make copy of each node and connect them in
	*  the following fashion;
	*    |org1|->|cpy1|->|org2|->|cpy2|->|org3|->|cpy3|->0
	*/
	while (pNode) {
		RandomListNode* pOrgNext = pNode->next;
		pNode->next = new RandomListNode(pNode->label);
		pNode->next->next = pOrgNext;
		pNode = pOrgNext;
	}

	/* step 2: assign the random field of copied node
	*    |org1|->|cpy1|->|org2|->|cpy2|->|org3|->|cpy3|->0
	*/

	pNode = head;
	while (pNode) {

		if (pNode->random != nullptr) {
			pNode->next->random = pNode->random->next;
		}
		pNode = pNode->next->next;
	}

	/* step 3: seperate the copied node from the whole linked list,
	*  the original list is then restored as well;
	*  change "|org1|->|cpy1|->|org2|->|cpy2|->|org3|->|cpy3|->0"
	*  to "|org1|->|org2|->|org3|->0" and "|cpy1|->|cpy2|->|cpy3|->0"
	*/

	pNode = head;
	RandomListNode dummy(0);
	RandomListNode* pCpyNode = &dummy;

	while (pNode) {
		pCpyNode->next = pNode->next;
		pNode->next = pNode->next->next;
		pNode = pNode->next;
		pCpyNode = pCpyNode->next;
	}
	pCpyNode->next = nullptr;

	return dummy.next;
}

int main()
{
	vector<RandomListNode> nums =  { 6, 6, 6, 3, 4, 2 };
	for (int i = 0; i < nums.size() - 1; i++)
		nums[i].next = &nums[i+1];
	nums[2].random = &nums[4];

	RandomListNode* pRet = copyRandomList(&nums[0]);

	return 0;
}
