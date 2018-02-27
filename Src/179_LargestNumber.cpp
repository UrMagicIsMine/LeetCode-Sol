/* Given a list of non negative integers, arrange them such that they form the largest number.
*
* For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*
* Note: The result may be very large, so you need to return a string instead of an integer.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
using namespace std;

class Solution {

public:

	string tranfunc(int i) {
		return to_string(i);
	}

	bool compfunc(string &a, string &b) {
		return a + b > b + a;
	}

	string largestNumber(vector<int>& nums) {

		int N = nums.size();
		vector<string> szNums(N);

		using namespace std::placeholders;
		//function<string(int)> tranfcn = &this->tranfunc;
		auto tran_func = std::bind(&Solution::tranfunc, *this, _1);
		transform(nums.begin(), nums.end(), szNums.begin(), tran_func);

		auto comp_func = std::bind(&Solution::compfunc, *this, _1, _2);
		sort(szNums.begin(), szNums.end(), comp_func);

		string ret = accumulate(szNums.begin(), szNums.end(), string(""));
		if (ret.length() > 1 && ret[0] == '0')
			return "0";

		return ret;

	}

};

string _tran(int i) {
	return to_string(i);
}

bool _comp(string &a, string &b) {
	return a + b > b + a;
}

string largestNumber(vector<int>& nums) {

	int N = nums.size();
	vector<string> szNums(N);

	transform(nums.begin(), nums.end(), szNums.begin(), _tran);
	sort(szNums.begin(), szNums.end(), _comp);

	string ret = accumulate(szNums.begin(), szNums.end(), string(""));
	if (ret.length() > 1 && ret[0] == '0')
		return "0";
	return ret;

}

int main()
{
	Solution sln;
	vector<int> nums = { 4312,7645,98,8323 };
	string ret1 = sln.largestNumber(nums);
	string ans = "98832376454312";
	assert(ret1 == ans);

	string ret2 = largestNumber(nums);
	assert(ret2 == ans);
	return 0;
}
