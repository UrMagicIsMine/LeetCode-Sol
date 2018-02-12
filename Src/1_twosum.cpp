vector<int> twoSum(vector<int>& nums, int target) {

    using SizeType = remove_reference_t<decltype(nums)>::size_type;
    using ValueToIndexMapType = unordered_map<int, SizeType>;
    ValueToIndexMapType map;
    vector<int> indices(2);
    for (SizeType index = 0; index < nums.size(); ++index)
    {
        const auto foundIterator = map.find(target - nums[index]);
        if (foundIterator != end(map) && foundIterator->second != index )
            return vector<int>{ index, foundIterator->second };
        else
            map.emplace(nums[index], index);
    }
    throw std::runtime_error("Solution not found");
}
