/* Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

void _DFS(vector<string> & resl, const string& s, vector<string>& nums, int pos) {
	if (nums.size() == 4) {
		if (pos == s.length()) {
			string sz = nums[0] + '.' + nums[1] + '.' + nums[2] + '.' + nums[3];
			resl.push_back(sz);
		}
		return;
	}
	if (s[pos] == '0') {
		nums.push_back("0");
		_DFS(resl, s, nums, pos + 1);
		nums.pop_back();
	}
	else {
		for (int i = pos; i <= pos + 2 && i < s.size(); i++) {
			string subsz = s.substr(pos, i - pos + 1);
			int num = stoi(subsz);
			if (num <= 255) {
				nums.push_back(subsz);
				_DFS(resl, s, nums, i + 1);
				nums.pop_back();
			}
		}
	}
	return;
}

vector<string> restoreIpAddresses(string s) {
	vector<string> resl;
	vector<string> nums;
	_DFS(resl, s, nums, 0);
	return resl;
}

int main()
{
	string s = "010010";
	vector<string> ans = { "0.10.0.10","0.100.1.0" };
	vector<string> ret = restoreIpAddresses(s);
	assert(ret == ans);
	return 0;
}
