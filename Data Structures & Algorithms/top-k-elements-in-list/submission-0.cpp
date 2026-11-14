class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Buckets sort approach
        unordered_map<int, int> results; // num -> freq
        for (auto& num : nums) {
            results[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, count] : results) {
            buckets[count].push_back(num);
        }
        
        vector<int> result;
        for (auto i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};
