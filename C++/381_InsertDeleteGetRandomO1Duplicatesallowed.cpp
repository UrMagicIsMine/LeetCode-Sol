/* Design a data structure that supports all following operations in average
* O(1) time.
*
* Note: Duplicate elements are allowed.
* insert(val): Inserts an item val to the collection.
* remove(val): Removes an item val from the collection if present.
* getRandom: Returns a random element from current collection of elements. The
* probability of each element being returned is linearly related to the number of
* same value the collection contains.
* Example:
*
* // Init an empty collection.
* RandomizedCollection collection = new RandomizedCollection();
*
* // Inserts 1 to the collection. Returns true as the collection did not contain 1.
* collection.insert(1);
*
* // Inserts another 1 to the collection. Returns false as the collection contained 1.
* Collection now contains [1,1].
* collection.insert(1);
*
* // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
* collection.insert(2);
*
* // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
* collection.getRandom();
*
* // Removes 1 from the collection, returns true. Collection now contains [1,2].
* collection.remove(1);
*
* // getRandom should return 1 and 2 both equally likely.
* collection.getRandom();
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {

		auto it = _hstbl.find(val);
		bool ret = (it == _hstbl.end());

		_hstbl[val].push_back(_nums.size());
		_nums.push_back(make_pair(val, _hstbl[val].size() - 1));

		return ret;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		auto it = _hstbl.find(val);
		bool ret = (it != _hstbl.end());
		if (ret) {
			int idx = _hstbl[val].back();
			pair<int, int> last = _nums.back();
			_hstbl[last.first][last.second] = idx;
			_nums[idx] = last;
			_nums.pop_back();
			_hstbl[val].pop_back();
			if (_hstbl[val].empty())
				_hstbl.erase(val);
		}

		return ret;
	}

	/** Get a random element from the collection. */
	int getRandom() {

		return _nums[rand() % _nums.size()].first;

	}

/*
  There are two data member in the solution
  1) a vector nums: _nums, Each element of nums is a pair, the first element of
  the pair is val itself, the second element of the pair is an index into the array
  of _hstbl[val].
  2) an unordered_map: _hstbl, The key of _hstbl is the val, the value of _hstbl
  is a vector contains indices where the val appears in _nums.
*/
	vector<pair<int, int>> _nums;
	unordered_map<int, vector<int>> _hstbl;
};

int main()
{
	RandomizedCollection rc;
	bool ret;
	ret = rc.insert(1); assert(ret == true);
	ret = rc.insert(1); assert(ret == false);
	ret = rc.insert(2); assert(ret == true);
	int ans = rc.getRandom(); assert(ans == 1 || ans == 2);
	ret = rc.remove(1); assert(ret == true);
	ret = rc.remove(1); assert(ret == true);
	ans = rc.getRandom(); assert(ans == 2);
	return 0;
}
