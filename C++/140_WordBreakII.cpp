/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/

// memorized DFS

vector<string> _DFS(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo){
    auto it = memo.find(s);
    if(it != memo.end()){
        return it->second;
    }

    vector<string> resl;

    if(dict.find(s)!=dict.end()){
        resl.push_back(s);
    }

    for(int i = 1; i < s.length(); i++){

        string pre = s.substr(0, i);
        string post = s.substr(i);
        if(dict.find(post)!=dict.end()){
            vector<string> pre_strs = _DFS(pre, dict, memo);
            for(auto & sz : pre_strs){
                sz += " " + post;
            }
            resl.insert(resl.end(), pre_strs.begin(), pre_strs.end());
        }

    }
    memo[s] = resl;
    return resl;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {

    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    unordered_map<string, vector<string>> memo;
    return _DFS(s, dict, memo);
}
