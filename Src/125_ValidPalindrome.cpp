/* Given a string, determine if it is a palindrome, considering
* only alphanumeric characters and ignoring cases.
*
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
*
* Note:
* Have you consider that the string might be empty? This is a good
* question to ask during an interview.
*
* For the purpose of this problem, we define empty string as valid palindrome.
*
*/
#include <cctype>
#include <string>

using namespace std;

/* key API function: isalnum, toupper both defined in <cctype> */

bool isPalindrome(string s) {

	int N = s.size();
	int i = 0, j = N - 1;
	while (i < j) {

		if (!isalnum(s[i])) {
			i++;
			continue;
		}

		if (!isalnum(s[j])) {
			j--;
			continue;
		}
		if (toupper(s[i]) == toupper(s[j])) {
			i++;
			j--;
			continue;
		}
		else
			return false;
	}
	return true;
}

/* same logic as above, but more simple/succinct solution*/
bool isPalindrome_simple(string s) {

	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		while (isalnum(s[i]) == false && i < j)
			i++;
		while (isalnum(s[j]) == false && i < j)
			j--;
		if (toupper(s[i]) != toupper(s[j]))
			return false;
	}
	return true;
}

int main()
{
	string sz = "A man, a plan, a canal: Panama";
	bool ret1 = isPalindrome(sz);
	bool ret2 = isPalindrome_simple(sz);
	return 0;
}
