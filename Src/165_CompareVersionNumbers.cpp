/* Compare two version numbers version1 and version2.
* If version1 > version2 return 1,
* if version1 < version2 return -1,
* otherwise return 0.
*
* You may assume that the version strings are non-empty and contain only
* digits and the . character. The . character does not represent a decimal
* point and is used to separate number sequences. For instance, 2.5 is not
* "two and a half" or "half way to version three", it is the fifth second-level
* revision of the second first-level revision.
*
* Here is an example of version numbers ordering:
*
* 0.1 < 1.1 < 1.2 < 13.37
*/

#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

/******************************************************************************/
/* solution 1: 1) process the end 0s for each string
 *             2) compare each int version starting from beginning
 */
string _processEnd0_Sol1(const string &s) {

	size_t rpos = s.length()-1;
	while (true) {
		size_t rpos_n = s.find_last_of('.', rpos);
		if (rpos_n != std::string::npos)
		{
			int subver = stoi(s.substr(rpos_n + 1, rpos - rpos_n));
			if (subver != 0) {
				return s.substr(0, rpos+1);
			}
			else {
				rpos = rpos_n-1;
				continue;
			}
		}
		else {
			return s.substr(0, rpos+1);
		}
	}
}

int compareVersion_Sol1(string version1, string version2) {

	string ver1 = _processEnd0_Sol1(version1);
	string ver2 = _processEnd0_Sol1(version2);

	std::size_t pos1 = 0, pos2 = 0;
	std::size_t len1 = ver1.length();
	std::size_t len2 = ver2.length();
	while (true) {

		std::size_t pos1_nxt = ver1.find_first_of('.', pos1);
		std::size_t pos2_nxt = ver2.find_first_of('.', pos2);
		if (pos1_nxt != std::string::npos && pos2_nxt != std::string::npos) {
			int subv1 = stoi(ver1.substr(pos1, pos1_nxt - pos1));
			int subv2 = stoi(ver2.substr(pos2, pos2_nxt - pos2));
			if (subv1 != subv2)
				return subv1 > subv2 ? 1 : -1;
			else {
				pos1 = pos1_nxt + 1;
				pos2 = pos2_nxt + 1;
			}
		}
		else if (pos1_nxt == std::string::npos && pos2_nxt != std::string::npos) {

			int subv1 = stoi(ver1.substr(pos1, len1 - pos1));
			int subv2 = stoi(ver2.substr(pos2, pos2_nxt - pos2));
			if (subv1 != subv2)
				return subv1 > subv2 ? 1 : -1;
			else
				return -1;
		}
		else if (pos1_nxt != std::string::npos&& pos2_nxt == std::string::npos) {

			int subv1 = stoi(ver1.substr(pos1, pos1_nxt - pos1));
			int subv2 = stoi(ver2.substr(pos2, len2 - pos2));
			if (subv1 != subv2)
				return subv1 > subv2 ? 1 : -1;
			else
				return 1;
		}
		else {
			int subv1 = stoi(ver1.substr(pos1, len1 - pos1));
			int subv2 = stoi(ver2.substr(pos2, len2 - pos2));
			if (subv1 != subv2)
				return subv1 > subv2 ? 1 : -1;
			else
				return 0;
		}
	}
}

/******************************************************************************/
/* solution 2: 1) process the end 0s for each string
 *             2) store the int versions into a vector<int>
 *             3) compare processed vector<int>
 */
std::vector<int> _processStr(const string &s) {

	std::vector<int> verInts;
	string sNew;
	size_t rpos = s.length() - 1;
	while (true) {
		size_t rpos_n = s.find_last_of('.', rpos);
		if (rpos_n != std::string::npos)
		{
			int subver = stoi(s.substr(rpos_n + 1, rpos - rpos_n));
			if (subver != 0) {
				sNew = s.substr(0, rpos + 1);
				break;
			}
			else {
				rpos = rpos_n - 1;
				continue;
			}
		}
		else {
			sNew = s.substr(0, rpos + 1);
			break;
		}
	}
	size_t pos = 0;
	while (true) {
		size_t pos_nxt = sNew.find_first_of('.', pos);
		if (pos_nxt != std::string::npos)
		{
			verInts.push_back(stoi(sNew.substr(pos, pos_nxt - pos)));
			pos = pos_nxt + 1;
			continue;
		}
		else
		{
			verInts.push_back(stoi(sNew.substr(pos, s.length() - pos)));
			break;
		}

	}
	return verInts;
}

int compareVersion_Sol2(string version1, string version2) {

	std::vector<int> ver1 = _processStr(version1);
	std::vector<int> ver2 = _processStr(version2);
	if (ver1 == ver2)
		return 0;
	else if (ver1 > ver2)
		return 1;
	else
		return -1;
}

int main()
{
	string ver1 = "1.0.1.0";
	string ver2 = "1.0.01.0";

	int ret1 = compareVersion_Sol1(ver1, ver2);
	assert(ret1 = 1);
	int ret2 = compareVersion_Sol2(ver1, ver2);
	assert(ret2 = 1);
	return 0;
}
