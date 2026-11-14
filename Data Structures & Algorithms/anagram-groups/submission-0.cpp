class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> temp {};
        unordered_map<string, vector<string>> t;
        for (auto i = 0; i < strs.size(); ++i) {
            string sorted_s = strs[i];
            sort(sorted_s.begin(), sorted_s.end());
            t[sorted_s].push_back(strs[i]);
        }

        for (auto const& [key, val] : t) {
            temp.push_back(val);
        }

        return temp;
    }
};
