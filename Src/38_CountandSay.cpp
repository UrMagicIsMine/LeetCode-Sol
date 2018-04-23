/* The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

string countAndSay(int n) {

	if (n <= 0)
		return "";

	string work = "1#";

	while (--n) {
		vector<pair<char, int>> pattern;
		int cnt = 1;
		for (int i = 1; i < work.size(); i++) {
			if (work[i] != work[i - 1]) {
				pattern.push_back(make_pair(work[i - 1], cnt));
				cnt = 1;
			}
			else
			{
				cnt++;
			}
		}

		work = "";
		for (auto p : pattern)
			work += to_string(p.second) + string(1, p.first);
		work += '#';
	}
	return work.substr(0, work.size() - 1);
}

int main()
{
	int n = 6;
	string ans = "312211";
	string ret = countAndSay(n);
	assert(ret == ans);
	return 0;
}
