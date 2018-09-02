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

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() : _root(new TrieNode) {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode * pNode = _root.get();
		for (auto c : word) {
			auto it = pNode->children.find(c);
			if (it == pNode->children.end())
				pNode = pNode->children[c] = new TrieNode;
			else
				pNode = it->second;
		}
		pNode->isWord = true;
		return;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		TrieNode* pNode = _root.get();
		return _search(word, pNode, 0);
	}

private:

	struct TrieNode {
		bool isWord;
		unordered_map<char, TrieNode*> children;

		TrieNode() : isWord(false) {

		}

		~TrieNode() {
			for (auto & p : children)
				delete p.second;
		}

	};

	bool _search(const string & word, TrieNode* pNode, int pos) {
		if (pos == word.length()) {
			return pNode->isWord;
		}

		if (word[pos] == '.') {
			for (auto p : pNode->children) {
				if (_search(word, p.second, pos + 1))
					return true;
			}
			return false;
		}
		else {
			auto it = pNode->children.find(word[pos]);
			if (it == pNode->children.end())
				return false;
			return _search(word, it->second, pos + 1);
		}
		return false;
	}

	unique_ptr<TrieNode> _root;

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
