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
	stack<string> paths;
	size_t pos1 = path.find_first_of('/', 0), pos2 = 0;
	while (pos1 != string::npos) {
		pos2 = path.find_first_of('/', pos1 + 1);
		string folder;
		if (pos2 != string::npos)
			folder = path.substr(pos1 + 1, pos2 - pos1 - 1);
		else
			folder = path.substr(pos1 + 1, path.length() - pos1 - 1);
		pos1 = pos2;
		if (folder == "")
			continue;
		else if (folder == ".")
			continue;
		else if (folder == "..") {
			if (!paths.empty())
				paths.pop();
		}
		else
			paths.push(folder);
	}
	string ret;
	if (paths.empty())
		return "/";
	else {
		while (!paths.empty()) {
			ret = "/" + paths.top() + ret;
			paths.pop();
		}
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
