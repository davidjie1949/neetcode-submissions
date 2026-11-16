class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        std::sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrack(candidates, 0, target, path, res);

        return res;
    }

private:
    void backtrack(vector<int>& c, int start, int remaining, vector<int> path, vector<vector<int>>& res) {
        if (remaining == 0) {
            res.push_back(path);
            return;
        }

        for (auto i = start; i < c.size(); ++i) {
            if (i > start && c[i] == c[i-1]) continue; // same value at this level was already tried
            if (c[i] > remaining) break;
            path.push_back(c[i]);
            backtrack(c, i + 1, remaining - c[i], path, res);
            path.pop_back();
        }
    }
};
