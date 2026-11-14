class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result (nums.size(), 1);
        int idx = 0;
        while (idx < nums.size()) {
            for (int i = 0; i < nums.size(); ++i) {
                if (idx == i) continue;
                result[idx] *= nums[i];
            }
            idx++;
        }

        return result;
    }
};