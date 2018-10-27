/* A website domain like "discuss.leetcode.com" consists of various subdomains.
* At the top level, we have "com", at the next level, we have "leetcode.com",
* and at the lowest level, "discuss.leetcode.com". When we visit a domain like
* "discuss.leetcode.com", we will also visit the parent domains "leetcode.com"
* and "com" implicitly.
*
* Now, call a "count-paired domain" to be a count (representing the number of
* visits this domain received), followed by a space, followed by the address.
* An example of a count-paired domain might be "9001 discuss.leetcode.com".
*
* We are given a list cpdomains of count-paired domains. We would like a list of
* count-paired domains, (in the same format as the input, and in any order),
* that explicitly counts the number of visits to each subdomain.
*
* Example 1:
* Input:
* ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
* Output:
* ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org",
* "1 intel.mail.com","951 com"]
* Explanation:
* We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com"
* once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com"
* 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.
*
* Notes:
*
* The length of cpdomains will not exceed 100.
* The length of each domain name will not exceed 100.
* Each address will have either 1 or 2 "." characters.
* The input count in any count-paired domain will not exceed 10000.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {

	unordered_map<string, int> hashtbl;

	for (int i = 0; i < cpdomains.size(); i++) {

		int pos = cpdomains[i].find_first_of(' ', 0);
		int num = stoi(cpdomains[i].substr(0, pos));
		int len = cpdomains[i].length();
		while (pos != string::npos) {

			hashtbl[cpdomains[i].substr(pos + 1, len - pos - 1)] += num;
			pos = cpdomains[i].find_first_of('.', pos + 1);
		}

	}
	vector<string> resl;
	for (auto &it : hashtbl)
		resl.push_back(to_string(it.second) + ' ' + it.first);

	return resl;
}

int main()
{
	vector<string> cpdomains = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
	vector<string> ans = { "900 google.mail.com", "901 mail.com", "951 com", "50 yahoo.com", "1 intel.mail.com", "5 org", "5 wiki.org" };
	vector<string> ret = subdomainVisits(cpdomains);
	assert(ret == ans);
	return 0;
}
