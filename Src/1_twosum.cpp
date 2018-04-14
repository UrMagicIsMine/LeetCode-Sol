#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

	using SizeType = int;
	using ValueToIndexMapType = unordered_map<int, SizeType>;
	ValueToIndexMapType map;
	for (SizeType index = 0; index < nums.size(); ++index)
	{
		const auto foundIterator = map.find(target - nums[index]);
		if (foundIterator != end(map))
			return vector<int>{ index, foundIterator->second };
		else
			map.emplace(nums[index], index);
	}
	throw std::runtime_error("Solution not found");
}

int main()
{

	vector<int> nums = { 3,2,4 };
	vector<int> ret = twoSum(nums, 6);
	return 0;
}
