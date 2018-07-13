/* Implement a trie with insert, search, and startsWith methods.
*
* Note:
* You may assume that all inputs are consist of lowercase letters a-z.
*/

#include <string>
#include <cassert>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : isLeaf(false) {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* pNode = this;
        for(auto c : word){
            if(pNode->children[c-'a'] == nullptr){
                pNode->children[c-'a'] = new Trie;
            }
            pNode = pNode->children[c-'a'];
        }
        pNode->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* pNode = this;
        for(auto c : word){
            if(pNode->children[c-'a'] == nullptr){
                return false;
            }
            pNode = pNode->children[c-'a'];
        }
        return pNode->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* pNode = this;
        for(auto c : prefix){
            if(pNode->children[c-'a'] == nullptr){
                return false;
            }
            pNode = pNode->children[c-'a'];
        }
        return true;
    }

private:
    bool isLeaf;
    Trie* children[26];
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
