/*
In this chapter, we discuss the problem of Trie or Prefix tree
*/

class Trie{

public:

  Trie() : _root(new TrieNode){
  }

  bool search(const string & str){
    TrieNode * p = find(str);
    return p && p->isWord;
  }

  bool startsWith(const string& str){
    TrieNode *p = find(str);
    return p != nullptr;
  }

  void insert(const string& str){
    TrieNode *p = _root.get();
    for(auto c: str){
      if(p->children[c - 'a'] == nullptr)
        p->children[c - 'a'] = new TrieNode;
      p = p->children[c - 'a'];
    }
    p->isWord = true;
    return;
  }

private:

  struct TrieNode{

    TrieNode() : isWord(false), children(26, nullptr){
    }

    ~TrieNode(){
      for(auto p : children)
        delete p;
    }

    bool isWord;
    vector<TrieNode*> children;
  };

  TrieNode * find(const string & str){
    TrieNode* p = _root.get();

    for(auto c : str){
      p = p->children[c-'a'];
      if(p == nullptr)
        break;
    }

    return p;
  }

private:

  unique_ptr<TrieNode> _root;

};
