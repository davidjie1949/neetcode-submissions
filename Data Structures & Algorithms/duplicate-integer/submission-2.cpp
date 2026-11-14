class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Brute Force
        // for (int i = 0; i < nums.size(); ++i) {
        //     for (int j = i + 1; j < nums.size(); ++j) {
        //         if (nums.at(i) == nums.at(j)) return true;
        //     }
        // }
        // return false;

        // Hash Table
        for (auto i = 0; i < nums.size(); ++i) {
            temp[nums.at(i)]++;
        }
        
        for (auto it = temp.begin(); it != temp.end(); ++it) {
            if (it->second > 1) return true;
        }
        return false;
        
        // sort + check adjecent value
        // if (nums.empty()) return false;
        // std::sort(nums.begin(), nums.end(), [](const auto& a, const auto& b) {return a < b;});

        // for (auto i = 0; i < nums.size() - 1; ++i) {
        //     if (nums.at(i) == nums.at(i + 1)) return true;
        // }
        // return false;
    }
private:
    std::unordered_map<int, int> temp{};
};