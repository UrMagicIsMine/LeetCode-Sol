/* Given a pattern and a string str, find if str follows the same pattern.
*
* Here follow means a full match, such that there is a bijection between a letter
* in pattern and a non-empty word in str.
*
* Examples:
* pattern = "abba", str = "dog cat cat dog" should return true.
* pattern = "abba", str = "dog cat cat fish" should return false.
* pattern = "aaaa", str = "dog cat cat dog" should return false.
* pattern = "abba", str = "dog dog dog dog" should return false.
* Notes:
* You may assume pattern contains only lowercase letters, and str contains lowercase
* letters separated by a single space.
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>
#include <cassert>
using namespace std;

bool wordPattern_Sln1(string pattern, string str) {

	vector<string> ctow(26);
	unordered_set<string> usedstr;

	int pos1 = 0;
	int pos2 = 0;
	for (int i = 0; i < pattern.size(); i++) {

		pos2 = str.find_first_of(' ', pos1);

		if (pos2 == string::npos && i + 1 != pattern.size())
			return false;

		int len = 0;
		if (pos2 == string::npos)
			len = str.length() - pos1;
		else
			len = pos2 - pos1;

		string subsz = str.substr(pos1, len);
		if (ctow[pattern[i] - 'a'].length() == 0) {

			if (usedstr.find(subsz) != usedstr.end())
				return false;
			ctow[pattern[i] - 'a'] = subsz;
			usedstr.insert(subsz);
		}

		if (ctow[pattern[i] - 'a'] != subsz)
			return false;

		pos1 = pos2 + 1;

	}

	return pos2 == string::npos;
}

bool wordPattern_Sln2(string pattern, string str) {

	istringstream sstrm(str);
	string stmp;
	vector<string> strVec;

	while (sstrm >> stmp) {
		strVec.push_back(stmp);
	}

	if (pattern.length() != strVec.size())
		return false;

	vector<string> ctow(26);
	unordered_set<string> usedstr;

	for (int i = 0; i < pattern.size(); i++) {

		if (ctow[pattern[i] - 'a'].length() == 0) {

			if (usedstr.find(strVec[i]) != usedstr.end())
				return false;
			ctow[pattern[i] - 'a'] = strVec[i];
			usedstr.insert(strVec[i]);
		}
		else if (ctow[pattern[i] - 'a'] != strVec[i])
			return false;
	}

	return true;
}

int main()
{
	string pattern = "abba", str = "dog cat cat dog";
	bool ret1 = wordPattern_Sln1(pattern, str);
	assert(ret1 == true);
	bool ret2 = wordPattern_Sln2(pattern, str);
	assert(ret2 == true);
	return 0;
}
