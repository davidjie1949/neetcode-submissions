class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> result (nums.size(), 1);
        // int idx = 0;
        // while (idx < nums.size()) {
        //     for (int i = 0; i < nums.size(); ++i) {
        //         if (idx == i) continue;
        //         result[idx] *= nums[i];
        //     }
        //     idx++;
        // }

        // return result;

        int n = nums.size();
        vector<int> result(n,1);

        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

// temp[0] = 1, nums[1] x nums[2] x nums[3]
// temp[1]      nums[0] x nums[2] x nums[3]
// temp[2]      nums[0] x nums[1] x nums[3]
// temp[3]      nums[0] x nums[1] x nums[2]


