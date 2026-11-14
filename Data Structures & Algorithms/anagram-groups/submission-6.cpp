class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort char and group them
        // unordered_map<string, vector<string>> groups;
        // for (const string& s : strs) {
        //     string key = s;
        //     sort(key.begin(), key.end());
        //     groups[key].push_back(s);
        // }

        // vector<vector<string>> result;
        // result.reserve(groups.size());
        // for (auto& [key, val] : groups) {
        //     result.push_back(std::move(val));
        // }
        // return result;

        // count characters instead of sorting
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            array<int, 26> count{};
            for (char c : s) ++count[c - 'a'];
            string key(count.begin(), count.end()); // 26-byte signature
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [_, group] : groups) {
            result.push_back(std::move(group));
        }
        return result;
    }
};
