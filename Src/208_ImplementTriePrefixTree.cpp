/* Implement a trie with insert, search, and startsWith methods.
*
* Note:
* You may assume that all inputs are consist of lowercase letters a-z.
*/

#include <string>
#include <cassert>
using namespace std;


struct trieNode {
	char cval;
	bool isLeaf;
	trieNode * childs[26];
	trieNode(char c) : cval(c), isLeaf(false) { memset(childs, 0, sizeof(childs)); }
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() : m_root(' ') {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		trieNode * pNode = &m_root;
		for (auto i : word) {
			if (pNode->childs[i - 'a'] == nullptr) {
				pNode->childs[i - 'a'] = new trieNode(i);
			}
			pNode = pNode->childs[i - 'a'];
		}
		pNode->isLeaf = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		trieNode * pNode = &m_root;
		for (auto i : word) {
			if (pNode->childs[i - 'a'] == nullptr)
				return false;
			pNode = pNode->childs[i - 'a'];
		}
		return pNode->isLeaf;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		trieNode * pNode = &m_root;
		for (auto i : prefix) {
			if (pNode->childs[i - 'a'] == nullptr)
				return false;
			pNode = pNode->childs[i - 'a'];
		}
		return true;
	}

	trieNode m_root;

};

int main()
{
	Trie t;
	t.insert("abc");
	bool ret1 = t.search("abc");
	assert(ret1 == true);
	bool ret2 = t.search("ab");
	assert(ret2 == false);
	t.insert("ab");
	bool ret3 = t.search("ab");
	assert(ret3 == true);
	return 0;
}
