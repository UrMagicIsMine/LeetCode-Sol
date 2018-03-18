/* Design a data structure that supports the following two operations:
*
* void addWord(word)
* bool search(word)
* search(word) can search a literal word or a regular expression string containing
* only letters a-z or .. A . means it can represent any one letter.
*
* For example:
*
* addWord("bad")
* addWord("dad")
* addWord("mad")
* search("pad") -> false
* search("bad") -> true
* search(".ad") -> true
* search("b..") -> true
* Note:
* You may assume that all words are consist of lowercase letters a-z.
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

struct TrieNode {
	char cval;
	bool isLeaf;
	vector<TrieNode*> childs;
	TrieNode(char c) : cval(c), isLeaf(false) {
	}

	TrieNode* getChild(char c) {
		for (int i = 0; i<childs.size(); i++) {
			if (childs[i]->cval == c)
				return childs[i];
		}
		return nullptr;
	}

	TrieNode* insert(char c) {
		TrieNode* ptmp = new TrieNode(c);
		childs.push_back(ptmp);
		return ptmp;
	}
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() : m_root(' ') {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {

		TrieNode * pNode = &m_root;
		for (auto i : word) {
			TrieNode *ptmp = pNode->getChild(i);
			if (ptmp == nullptr)
				pNode = pNode->insert(i);
			else
				pNode = ptmp;
		}
		pNode->isLeaf = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		TrieNode* pNode = &m_root;
		return _search(word, 0, pNode);
	}

	bool _search(const string& word, int ichar, TrieNode* pNode) {

		if (ichar == word.length()) {
			if (pNode->isLeaf)
				return true;
			else
				return false;
		}
		else {
			if (word[ichar] == '.') {
				for (int i = 0; i < pNode->childs.size(); i++) {
					if (_search(word, ichar + 1, pNode->childs[i]) == true)
						return true;
				}
				return false;
			}
			else
			{
				pNode = pNode->getChild(word[ichar]);
				if (pNode == nullptr)
					return false;
				return _search(word, ichar + 1, pNode);
			}
		}
	}

	TrieNode m_root;
};

int main()
{
	WordDictionary wd;
	wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");
	int ret1 = wd.search("pad");
	assert(ret1 == false);
	int ret2 = wd.search("bad");
	assert(ret2 == true);
	int ret3 = wd.search(".ad");
	assert(ret3 == true);
	int ret4 = wd.search("d..");
	assert(ret4 == true);
	return 0;
}
