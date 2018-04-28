/* The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

string getPermutation(int n, int k) {
	vector<int> nPerms(n + 1, 1), nums;
	for (int i = 1; i <= n; i++) {
		nPerms[i] = nPerms[i - 1] * i;
		nums.push_back(i);
	}
	//nums.push_back(n);

	string ans;
	for (int i = n - 1; i >= 0; i--) {
		int j = (k - 1) / nPerms[i];
		ans += string(1, '0' + nums[j]);
		nums.erase(nums.begin() + j);
		k -= j * nPerms[i];
	}
	return ans;
}

int main()
{
	int n = 3, k = 3;
	string ans = "213";
	string ret = getPermutation(n, k);
	assert(ret == ans);
	return 0;
}
