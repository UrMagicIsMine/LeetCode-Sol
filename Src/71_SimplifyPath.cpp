/* Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.

Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together,
such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
#include <vector>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

string simplifyPath(string path) {
	stack<string> stPaths;
	int i = 0, n = path.size();
	while (i < n) {
		while (i < n && path[i] == '/')
			i++;

		int pos = i;
		while (i < n && path[i] != '/')
			i++;

		string sz = path.substr(pos, i - pos);
		if (sz == "." || sz.empty()) {
			continue;
		}
		else if (sz == "..") {
			if (!stPaths.empty())
				stPaths.pop();
		}
		else {
			stPaths.push(sz);
		}
	}

	if (stPaths.empty())
		return "/";
	string ret;
	while (!stPaths.empty()) {
		ret = "/" + stPaths.top() + ret;
		stPaths.pop();
	}
	return ret;
}

int main()
{
	string path = "/a/./b/../../c/";
	string ans = "/c";
	string ret = simplifyPath(path);
	assert(ret == ans);
	return 0;
}
