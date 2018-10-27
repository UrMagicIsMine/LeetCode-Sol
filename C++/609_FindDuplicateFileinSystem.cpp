/* Given a list of directory info including directory path, and all the files
* with contents in this directory, you need to find out all the groups of duplicate
* files in the file system in terms of their paths.
*
* A group of duplicate files consists of at least two files that have exactly the
* same content.
*
* A single directory info string in the input list has the following format:
*
* "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
*
* It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content,
* f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note
* that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
*
* The output is a list of group of duplicate file paths. For each group, it contains
* all the file paths of the files that have the same content. A file path is a string
* that has the following format:
*
* "directory_path/file_name.txt"
*
* Example 1:
* Input:
* ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
* Output:
* [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
* Note:
* -- No order is required for the final output.
* -- You may assume the directory name, file name and file content only has
* letters and digits,
* and the length of file content is in the range of [1,50].
* -- The number of files given is in the range of [1,20000].
* -- You may assume no files or directories share the same name in the same directory.
* -- You may assume each given directory info represents a unique directory.
* Directory path and file info are separated by a single blank space.
* Follow-up beyond contest:
* -- Imagine you are given a real file system, how will you search files? DFS or BFS?
* -- If the file content is very large (GB level), how will you modify your solution?
* -- If you can only read the file by 1kb each time, how will you modify your solution?
* -- What is the time complexity of your modified solution? What is the most
* time-consuming part and memory consuming part of it? How to optimize?
* -- How to make sure the duplicated files you find are not false positive?
*/

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void _processPath(const string& sz, unordered_map<string, vector<string>>& hash) {

	int pos = sz.find_first_of(' ');
	string path = sz.substr(0, pos);
	while (true) {
		int tmp = sz.find_first_of(' ', pos + 1);
		string file = sz.substr(pos + 1, tmp - pos);

		int mark1 = file.find_first_of('(');
		string filename = file.substr(0, mark1);
		int mark2 = file.find_first_of(')');
		string filecont = file.substr(mark1 + 1, mark2 - mark1 - 1);

		hash[filecont].push_back(path + '/' + filename);

		if (tmp != string::npos)
			pos = tmp;
		else
			break;
	}

}

vector<vector<string>> findDuplicate(vector<string>& paths) {

	unordered_map<string, vector<string>> hash;

	for (int i = 0; i < paths.size(); i++)
		_processPath(paths[i], hash);

	vector<vector<string>> resl;
	for (auto it = hash.begin(); it != hash.end(); it++)
		if (it->second.size() > 1)
			resl.emplace_back(std::move(it->second));

	return resl;
}

int main()
{
	vector<string> paths1 = { "root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)" };
	vector<vector<string>> ans1 = { {"root/a/2.txt","root/c/d/4.txt","root/4.txt"},{"root/a/1.txt","root/c/3.txt"} };
	vector<vector<string>> ret1 = findDuplicate(paths1);
	assert(ret1 == ans1);

	vector <string> paths2 = { "root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)" };
	vector<vector<string>> ans2 = {};
	vector<vector<string>> ret2 = findDuplicate(paths2);
	assert(ret2 == ans2);

	return 0;
}
