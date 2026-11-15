class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, target, path, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start, int remain, vector<int>& path, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] > remain) break;
            path.push_back(nums[i]);
            backtrack(nums, i, remain - nums[i], path, res);
            path.pop_back();
        }
    }
};
