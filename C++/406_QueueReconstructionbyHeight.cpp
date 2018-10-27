/* Suppose you have a random list of people standing in a queue. Each person is
* described by a pair of integers (h, k), where h is the height of the person
* and k is the number of people in front of this person who have a height greater
* than or equal to h. Write an algorithm to reconstruct the queue.
*
* Note:
* The number of people is less than 1,100.
*
* Example
*
* Input:
* [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
*
* Output:
* [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

/* Solution 1: sort and do comparison */

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {


	/* sort height in descending order, if height equals, sort #people in front in ascending order  */
	auto lambda = [](pair<int, int>& p1, pair<int, int>& p2) {
		return p1.first > p2.first || ((p1.first == p2.first) && p1.second < p2.second);
	};

	sort(people.begin(), people.end(), lambda);

	/* insert each person to the right place */
	vector<pair<int, int>> resl;
	for (auto person : people) {

		resl.insert(resl.begin() + person.second, person);

	}
	return resl;
}

int main()
{
	vector<pair<int, int>> people = { {7,0 },{ 4,4 },{ 7,1 },{ 5,0 },{ 6,1 },{ 5,2 } };
	vector<pair<int, int>> ret = reconstructQueue(people);
	vector<pair<int, int>> ans = { { 5, 0}, { 7, 0}, { 5, 2}, { 6, 1}, { 4, 4}, {7, 1} };
	assert(ret == ans);
	return 0;
}
