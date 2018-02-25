/* All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
* for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
* repeated sequences within the DNA.
*
* Write a function to find all the 10-letter-long sequences (substrings) that
* occur more than once in a DNA molecule.
*
* For example,
*
* Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
*
* Return:
* ["AAAAACCCCC", "CCCCCAAAAA"].
*/

#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;

/******************************************************************************/
/* Solution 1: transform the 10 characters into hash_key, use hash table to store
 * the occurance times of the 10 characters, save if it alrady existed before;
 */

/* A is 0x41, C is 0x43, G is 0x47, T is 0x54 or
* A is 0101, C is 0103, G is 0107, T is 0124.
* The last 3 digits are all unique for the 4 characters;
* Based on this, we can get the hash value out of it
*/

int _hashfunc(const string & substr) {

	int hash = 0;
	assert(substr.size() == 10);
	for (int i = 0; i < (int)substr.size(); i++)
		hash = (hash << 3) | (substr[i] & 7);
	return hash;

}

vector<string> findRepeatedDnaSequences_Sol1(string s) {

	unordered_map<int, int> uniSeqs;
	vector<string> resl;

  /* bre careful about the difference between size_t and int */
	for (int i = 0; i <= (int)s.size() - 10; i++) {

		int hash = _hashfunc(s.substr(i, 10));
		if ((++uniSeqs[hash]) == 2)
			resl.push_back(s.substr(i, 10));
	}
	return resl;
}

/******************************************************************************/
/* Solution 2: similar idea, brilliant idea, even fast then before;
 * use memory in trade of speed, O(n) complexity
 */

/* need to be global otherwise the stack will overflow,
* for global array, it automatically be initialized to zero */

int _hash_map[1 << 20];

vector<string> findRepeatedDnaSequences_Sol2(string s) {

	vector<string> resl;
	if (s.size() < 9)
		return resl;
	int state = 0;

	for (int i = 0; i < s.size(); i++) {
		/* shift 2 bits for the next character */
		state <<= 2;
		/* truncate the higher bit, reserve lower 20 bits */
		state = state & ((1 << 20) - 1);

		/* store the charatcer to the next two bits */
		if (s[i] == 'C')
			state |= 1;
		else if (s[i] == 'G')
			state |= 2;
		else if (s[i] == 'T')
			state |= 3;

		if (i < 9)
			continue;

		/* if already exist previously, save it to the results */
		if ((++_hash_map[state]) == 2)
			resl.push_back(s.substr(i - 9, 10));
	}
	return resl;

}

int main()
{
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> resl = { "AAAAACCCCC", "CCCCCAAAAA" };

	vector<string> ret1 = findRepeatedDnaSequences_Sol1(s);
	assert(ret1 == resl);
	vector<string> ret2 = findRepeatedDnaSequences_Sol2(s);
	assert(ret1 == resl);

	return 0;
}
