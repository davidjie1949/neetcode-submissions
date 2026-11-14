class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums.at(i) + nums.at(j) == target) {
                    return {i, j};
                }
            }
        }

        return {};

        // Hash map
        std::unordered_map<int, int> seen;
        for (auto i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = seen.find(complement);
            if (it != seen.end()) {
                return {it->second, i};
            }

            // Value -> Index
            seen[nums[i]] = i;
        }

        return {};
    }
};
