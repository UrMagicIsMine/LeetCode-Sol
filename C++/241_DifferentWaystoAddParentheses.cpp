/* Given a string of numbers and operators, return all possible results from
computing all the different possible ways to group numbers and operators. The
valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
*/

#include <vector>
#include <string>
#include <cassert>
using namespace std;

vector<int> diffWaysToCompute(string input) {
	vector<int> ret;
	for (int i = 0; i < input.size(); i++) {

		if (!isdigit(input[i])) {
			vector<int> left = diffWaysToCompute(input.substr(0, i));
			vector<int> rght = diffWaysToCompute(input.substr(i + 1));

			for (auto l : left) {
				for (auto r : rght) {
					if (input[i] == '+')
						ret.push_back(l + r);
					else if (input[i] == '-')
						ret.push_back(l - r);
					else if (input[i] == '*')
						ret.push_back(l*r);
				}
			}

		}

	}
	return ret.size() > 0 ? ret : vector<int>{ stoi(input) };
}

int main() {
	string  input = "2*3-4*5";
	vector<int> ret = diffWaysToCompute(input);
	vector<int> ans = { -34,-10,-14,-10,10 };
	assert(ret == ans);
	return 0;
}
