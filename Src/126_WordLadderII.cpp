/*
Given two words (beginWord and endWord), and a dictionary's word list, find all
shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a
transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible
transformation.
*/

void _getPathDFS(vector<vector<string>> & resl,
                 unordered_map<string, vector<string>>& graphs,
                 vector<string>& paths,
                 string &Word,
                 string &target){

    if(Word == target){
        resl.push_back(paths);
        return;
    }

    auto it = graphs.find(Word);
    if(it == graphs.end())
        return;

    for(int i = 0; i < it->second.size(); i++){
        paths.push_back(it->second[i]);
        _getPathDFS(resl, graphs, paths, it->second[i], target);
        paths.pop_back();
    }
    return;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

    vector<vector<string>> resl;
    unordered_map<string, vector<string>> graphs;
    unordered_set<string> dict(wordList.begin(), wordList.end()); // hash set for search
    if(!dict.count(endWord)) return resl;

    const int N = beginWord.size();
    unordered_set<string> q{beginWord}, p;
    bool found = false;

    while(!q.empty() && !found){

        for(auto & w : q)
            dict.erase(w);

        for(const string & word : q){
            string cur = word;
            for(int i = 0; i < N; i++){
                char ch = cur[i];
                for(int c = 'a'; c <= 'z'; c++){
                    cur[i] = c;
                    if(c == ch) continue;
                    if(cur == endWord)
                        found = true;
                    if(dict.count(cur)){
                        p.insert(cur);
                        graphs[word].push_back(cur);
                    }
                }
                cur[i] = ch;
            }
        }
        swap(p,q);
        p.clear();
    }

    if(found){
        vector<string> paths{beginWord};
        _getPathDFS(resl, graphs, paths, beginWord, endWord);
    }
    return resl;

}
