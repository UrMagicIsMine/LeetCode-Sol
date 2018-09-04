/*
There is a box protected by a password. The password is n digits, where each
letter can be one of the first k digits 0, 1, ..., k-1.

You can keep inputting the password, the password will automatically be matched
against the last n digits entered.

For example, assuming the password is "345", I can open it when I type "012345",
but I enter a total of 6 digits.

Please return any string of minimum length that is guaranteed to open the box after
the entire string is inputted.

Example 1:
Input: n = 1, k = 2
Output: "01"
Note: "10" will be accepted too.
Example 2:
Input: n = 2, k = 2
Output: "00110"
Note: "01100", "10011", "11001" will be accepted too.
Note:
n will be in the range [1, 4].
k will be in the range [1, 10].
k^n will be at most 4096.
*/

#include <string>
#include <unordered_set>

bool _DFS(string & resl, unordered_set<string> & visited, int n, int k, int total){

    if(visited.size() == total)
        return true;
    string strsub = resl.substr(resl.size()-n+1);
    strsub.push_back('0');
    for(int i = 0; i < k; i++){
        strsub[n-1] = '0' + i;
        if( visited.count(strsub) ) continue;
        visited.insert(strsub);
        resl.push_back('0' + i);
        if(_DFS(resl, visited, n, k, total))
            return true;
        resl.pop_back();
        visited.erase(strsub);
    }
    return false;
}

string crackSafe(int n, int k) {
    int total = pow(k, n);
    string resl(n, '0');
    unordered_set<string> visited{resl};
    _DFS(resl, visited, n, k, total);
    return resl;
}
