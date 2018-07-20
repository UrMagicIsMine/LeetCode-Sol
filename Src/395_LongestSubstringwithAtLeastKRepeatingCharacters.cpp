/*
Find the length of the longest substring T of a given string (consists of
lowercase letters only) such that every character in T appears no less than k
times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated
3 times.
*/

int longestSubstring(const std::string& s, int l, int h, const int k) {
    if(l >= h) return 0;
    vector<int> freq(26,0);

    for(int i = l; i < h; i++){
        freq[s[i] - 'a']++;
    }

    int maxLen = -1;
    int prev = l;
    for(int i = l; i < h; i++){
        if(freq[s[i]-'a'] < k){
            maxLen = max(maxLen, longestSubstring(s, prev, i, k));
            prev = i+1;
        }
    }

    if(maxLen >= 0){
        maxLen = max(maxLen, longestSubstring(s, prev, h, k));
    }
    else{
        maxLen = h -l;
    }
    return maxLen;
}

int longestSubstring(string s, int k) {
    return longestSubstring(s, 0, s.size(), k);
}
